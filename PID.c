#define LAST_VALUE_SIZE 4
#undef PID_USE_INT
#define  PID_USE_FLOAT
#define PID_STATIC_INITIALIZE
#define PID_INT_FACTOR_BITS 10
#define PID_INT signed int32_t

#ifdef PID_USE_INT
/* For ints, I was thinking about multiplying the inputs by 100 or 1000.
 * That way, no floating point math.
 * Also, am going to add input low to all values, to make them all positive*/
struct PIDDataStruct {
	signed int kp;
	signed int kd;
	signed int ki;
	unsigned int goal;
	signed int inputHigh;
	signed int inputLow;
	signed int outputHigh;
	signed int outputLow;
	unsigned int timeBetweenUpdates;
	signed int lastErrs[LAST_VALUE_SIZE];
};
#endif
#ifdef PID_USE_FLOAT
struct PIDDataStruct {
	float kp;
	float kd;
	float ki;
	float goal;
	float inputHigh;
	float inputLow;
	float outputHigh;
	float outputLow;
	float timeBetweenUpdates;
	float lastErrs[LAST_VALUE_SIZE];
};
#endif

#ifdef PID_STATIC_INITIALIZE
#ifdef PID_USE_INT
int PIDInitialize(struct PIDDataStruct *PIDData, float kp, float kd, float ki,
		  signed int goal, signed int inputHigh, signed int inputLow,
		  signed int outputLow, signed int outputHigh,
		  unsigned int timeBetweenUpdates){
	int i;
	PIDData->kp = kp;
	PIDData->kd = kd;
	PIDData->ki = ki;
	PIDData->goal = (goal << PID_INT_FACTOR_BITS);
#endif
#ifdef PID_USE_FLOAT
int PIDInitialize(struct PIDDataStruct *PIDData, float kp, float kd,
		  float ki, float goal, float inputHigh, float inputLow,
		  float outputLow, float outputHigh,
		  float timeBetweenUpdates) {
	int i;
	PIDData->kp = (int)(kp * (1 << PID_INT_FACTOR_BITS));
	PIDData->ki = (int)(ki * (1 << PID_INT_FACTOR_BITS));
	PIDData->kd = (int)(kd * (1 << PID_INT_FACTOR_BITS));
	PIDData->goal = goal;
#endif
#endif
	PIDData->inputHigh = inputHigh;
	PIDData->inputLow = inputLow;
	PIDData->outputHigh = outputHigh;
	PIDData->outputLow = outputLow;
	PIDData->timeBetweenUpdates = timeBetweenUpdates;
	for (i = 0; i < LAST_VALUE_SIZE; i++) {
		PIDData->lastErrs[i] = 0;
	}
	return 0;
}

#ifdef PID_USE_INT
signed int PIDUpdate(struct PIDDataStruct *PIDData, unsigned int input) {
	unsigned int error;
	int i;
	unsigned int output;
	signed int deriv;
	signed int integral;
	signed int inputSign;
		if (input > PIDData->inputHigh) {
		input = PIDData->inputHigh;
	} else if (input < PIDData->inputLow) {
		input = PIDData->inputLow;
	}
	if (input < 0) {
	/* Then the input is negative, make positive, multiply, make negative */
		input *= -1;
		input >> PID_INT_FACTOR_BITS;
		input *= -1;
	} else {
		input >> PID_INT_FACTOR_BITS;
	}
	input += PIDData->inputLow;	/* Make the input positive */
	error = PIDData->goal - input;
	deriv = error - PIDData->lastErrs[0];	/* Could use an algorithm with the last values, but this is good enough. */
	for (i = 0; i < (LAST_VALUE_SIZE - 1); i++) {
		PIDData->lastErrs[i + 1] = PIDData->lastErrs[i];
		integral += PIDData->lastErrs[i + 1];
	}
	pidData->lastErrs[0] = error;
	integral *= PIDData->timeBetweenUpdates;
	output = PIDData->kp * error;
	output += pidData->kd * deriv;
	output += pidData->ki * integral;
	if (output < 0) {
		/* Then the output is negative, make positive, multiply, make negative */
		output *= -1;
		output << PID_INT_FACTOR_BITS;
		output *= -1;
	} else {
		output << PID_INT_FACTOR_BITS;
	}
	if (output > PIDData->outputHigh) {
		output = PIDData->outputHigh;
	} else if (output < PIDData->outputLow) {
		output = PIDData->outputLow;
	}
	return output;
}
#endif

#ifdef PID_USE_FLOAT
float PIDUpdate(struct PIDDataStruct *PIDData, float input) {
	float error;
	int i;
	float output;
	float deriv;
	float integral;
	integral = 0;
	if (input > PIDData->inputHigh) {
		input = PIDData->inputHigh;
	} else if (input < PIDData->inputLow) {
		input = PIDData->inputLow;
	}

	error = PIDData->goal - input;
	deriv = error - PIDData->lastErrs[0];
	for (i = 0; i < (LAST_VALUE_SIZE - 1); i++) {
		PIDData->lastErrs[i + 1] = PIDData->lastErrs[i];
		integral += PIDData->lastErrs[i + 1];
	}
	integral *= PIDData->timeBetweenUpdates;
	PIDData->lastErrs[0] = error;
	output = PIDData->kp * error;
	output += PIDData->kd * deriv;
	output += PIDData->ki * integral;
	if (output > PIDData->outputHigh) {
		output = PIDData->outputHigh;
	} else if (output < PIDData->outputLow) {
		output = PIDData->outputLow;
	}
	return output;
}
#endif


#ifdef PID_USE_FLOAT
float PIDSetGoal(struct PIDDataStruct *PIDData, float goal, float input) {
	float error;
	int i;
	float output;
	float deriv;
	float integral;
	PIDData->goal = goal;
	integral = 0;
	if (input > PIDData->inputHigh) {
		input = PIDData->inputHigh;
	} else if (input < PIDData->inputLow) {
		input = PIDData->inputLow;
	}

	error = PIDData->goal - input;
	deriv = error - PIDData->lastErrs[0];
	for (i = 0; i < (LAST_VALUE_SIZE - 1); i++) {
		PIDData->lastErrs[i + 1] = PIDData->lastErrs[i];
		integral += PIDData->lastErrs[i + 1];
	}
	integral *= PIDData->timeBetweenUpdates;
	PIDData->lastErrs[0] = error;
	output = PIDData->kp * error;
	output += PIDData->kd * deriv;
	output += PIDData->ki * integral;
	if (output > PIDData->outputHigh) {
		output = PIDData->outputHigh;
	} else if (output < PIDData->outputLow) {
		output = PIDData->outputLow;
	}
	return output;
}
#endif

