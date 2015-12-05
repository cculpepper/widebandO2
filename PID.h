#ifndef PID_H
#define PID_H


#define LAST_VALUE_SIZE 1
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
int PIDInitialize(volatile struct PIDDataStruct *PIDData, float kp, float kd, float ki,
		  signed int goal, signed int inputHigh, signed int inputLow,
		  signed int outputLow, signed int outputHigh,
		  unsigned int timeBetweenUpdates);
#endif
#ifdef PID_USE_FLOAT
int PIDInitialize(volatile struct PIDDataStruct *PIDData, float kp, float kd,
		  float ki, float goal, float inputHigh, float inputLow,
		  float outputLow, float outputHigh,
		  float timeBetweenUpdates) ;
#endif
#endif
#ifdef PID_USE_INT
signed int PIDUpdate(volatile struct PIDDataStruct *PIDData, unsigned int input) ;
#endif

#ifdef PID_USE_FLOAT
float PIDUpdate(volatile struct PIDDataStruct *PIDData, float input) ;
float PIDSetGoal(volatile struct PIDDataStruct *PIDData, float goal) ;

#endif


#endif
