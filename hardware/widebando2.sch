EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:78025
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_9 P1
U 1 1 56646F5A
P 1600 2750
F 0 "P1" V 1550 2750 60  0000 C CNN
F 1 "CONN_9" V 1650 2750 60  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_WAGO-804_RM5mm_9pol" H 1600 2750 60  0001 C CNN
F 3 "" H 1600 2750 60  0000 C CNN
	1    1600 2750
	-1   0    0    1   
$EndComp
$Comp
L TL082 U1
U 2 1 56646FF3
P 4350 2050
F 0 "U1" H 4300 2250 60  0000 L CNN
F 1 "TL082" H 4300 1800 60  0000 L CNN
F 2 "Housings_DIP:DIP-8__300" H 4350 2050 60  0001 C CNN
F 3 "" H 4350 2050 60  0000 C CNN
	2    4350 2050
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 P2
U 1 1 56647048
P 7300 2500
F 0 "P2" V 7250 2500 60  0000 C CNN
F 1 "CONN_6" V 7350 2500 60  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_WAGO-804_RM5mm_6pol" H 7300 2500 60  0001 C CNN
F 3 "" H 7300 2500 60  0000 C CNN
	1    7300 2500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 56647133
P 4250 2500
F 0 "#PWR12" H 4250 2500 30  0001 C CNN
F 1 "GND" H 4250 2430 30  0001 C CNN
F 2 "" H 4250 2500 60  0000 C CNN
F 3 "" H 4250 2500 60  0000 C CNN
	1    4250 2500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR11
U 1 1 56647159
P 4250 1550
F 0 "#PWR11" H 4250 1640 20  0001 C CNN
F 1 "+5V" H 4250 1640 30  0000 C CNN
F 2 "" H 4250 1550 60  0000 C CNN
F 3 "" H 4250 1550 60  0000 C CNN
	1    4250 1550
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 56647170
P 3450 2700
F 0 "R4" V 3530 2700 40  0000 C CNN
F 1 "10K" V 3457 2701 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3380 2700 30  0001 C CNN
F 3 "" H 3450 2700 30  0000 C CNN
	1    3450 2700
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 56647193
P 4250 2700
F 0 "R7" V 4330 2700 40  0000 C CNN
F 1 "20K" V 4257 2701 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4180 2700 30  0001 C CNN
F 3 "" H 4250 2700 30  0000 C CNN
	1    4250 2700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR6
U 1 1 56647273
P 3150 2850
F 0 "#PWR6" H 3150 2850 30  0001 C CNN
F 1 "GND" H 3150 2780 30  0001 C CNN
F 2 "" H 3150 2850 60  0000 C CNN
F 3 "" H 3150 2850 60  0000 C CNN
	1    3150 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2850 3150 2700
Wire Wire Line
	3150 2700 3200 2700
Wire Wire Line
	3700 2700 4000 2700
Wire Wire Line
	3850 2150 3800 2150
Wire Wire Line
	3800 2150 3800 2700
Connection ~ 3800 2700
Wire Wire Line
	4250 2450 4250 2500
Wire Wire Line
	4950 2700 4500 2700
Wire Wire Line
	4950 1850 4950 2700
Wire Wire Line
	4850 2050 5050 2050
Wire Wire Line
	4250 1650 4250 1550
$Comp
L R R3
U 1 1 566473D4
P 3100 1950
F 0 "R3" V 3180 1950 40  0000 C CNN
F 1 "15K" V 3107 1951 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3030 1950 30  0001 C CNN
F 3 "" H 3100 1950 30  0000 C CNN
	1    3100 1950
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 56647413
P 3500 2200
F 0 "C1" H 3500 2300 40  0000 L CNN
F 1 "1uf" H 3506 2115 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 3538 2050 30  0001 C CNN
F 3 "" H 3500 2200 60  0000 C CNN
	1    3500 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 56647446
P 3500 2450
F 0 "#PWR7" H 3500 2450 30  0001 C CNN
F 1 "GND" H 3500 2380 30  0001 C CNN
F 2 "" H 3500 2450 60  0000 C CNN
F 3 "" H 3500 2450 60  0000 C CNN
	1    3500 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2400 3500 2450
Wire Wire Line
	3350 1950 3850 1950
Wire Wire Line
	3500 2000 3500 1950
Connection ~ 3500 1950
Wire Wire Line
	2850 1950 2500 1950
Wire Wire Line
	2500 1950 2500 2350
Wire Wire Line
	2500 2350 1950 2350
$Comp
L R R9
U 1 1 5664760D
P 5300 2050
F 0 "R9" V 5380 2050 40  0000 C CNN
F 1 "1" V 5307 2051 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5230 2050 30  0001 C CNN
F 3 "" H 5300 2050 30  0000 C CNN
	1    5300 2050
	0    1    1    0   
$EndComp
Connection ~ 4950 2050
Wire Wire Line
	5550 2050 6400 2050
Wire Wire Line
	6400 2050 6400 2250
Wire Wire Line
	6400 2250 6950 2250
Wire Wire Line
	5650 2050 5650 1650
Connection ~ 5650 2050
Text Label 4950 1850 0    60   ~ 0
SHUNTHIGH
Text Label 5650 1650 0    60   ~ 0
SHUNTLOW
$Comp
L GND #PWR18
U 1 1 56647952
P 5500 2900
F 0 "#PWR18" H 5500 2900 30  0001 C CNN
F 1 "GND" H 5500 2830 30  0001 C CNN
F 2 "" H 5500 2900 60  0000 C CNN
F 3 "" H 5500 2900 60  0000 C CNN
	1    5500 2900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR15
U 1 1 5664796F
P 5050 2300
F 0 "#PWR15" H 5050 2390 20  0001 C CNN
F 1 "+5V" H 5050 2390 30  0000 C CNN
F 2 "" H 5050 2300 60  0000 C CNN
F 3 "" H 5050 2300 60  0000 C CNN
	1    5050 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 2350 6950 2350
Wire Wire Line
	5050 2350 5100 2350
Wire Wire Line
	5050 2300 5050 2400
Wire Wire Line
	5500 2650 5500 2900
$Comp
L C C3
U 1 1 56647B1C
P 5950 2600
F 0 "C3" H 5950 2700 40  0000 L CNN
F 1 "1uf" H 5956 2515 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 5988 2450 30  0001 C CNN
F 3 "" H 5950 2600 60  0000 C CNN
	1    5950 2600
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 56647B51
P 5050 2600
F 0 "C2" H 5050 2700 40  0000 L CNN
F 1 "1uf" H 5056 2515 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 5088 2450 30  0001 C CNN
F 3 "" H 5050 2600 60  0000 C CNN
	1    5050 2600
	1    0    0    -1  
$EndComp
Connection ~ 5050 2350
Wire Wire Line
	5050 2800 5950 2800
Connection ~ 5500 2800
Wire Wire Line
	5950 2400 5950 2350
Connection ~ 5950 2350
Connection ~ 6150 2350
$Comp
L TL082 U2
U 2 1 5664800F
P 5250 3450
F 0 "U2" H 5200 3650 60  0000 L CNN
F 1 "TL082" H 5200 3200 60  0000 L CNN
F 2 "Housings_DIP:DIP-8__300" H 5250 3450 60  0001 C CNN
F 3 "" H 5250 3450 60  0000 C CNN
	2    5250 3450
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR16
U 1 1 56648116
P 5350 3000
F 0 "#PWR16" H 5350 3090 20  0001 C CNN
F 1 "+5V" H 5350 3090 30  0000 C CNN
F 2 "" H 5350 3000 60  0000 C CNN
F 3 "" H 5350 3000 60  0000 C CNN
	1    5350 3000
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5664816B
P 6150 3050
F 0 "C4" H 6150 3150 40  0000 L CNN
F 1 ".5u" H 6156 2965 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 6188 2900 30  0001 C CNN
F 3 "" H 6150 3050 60  0000 C CNN
	1    6150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2350 6150 2850
Wire Wire Line
	6150 3250 6150 3550
Wire Wire Line
	6150 3550 5750 3550
$Comp
L GND #PWR19
U 1 1 56648226
P 5800 3400
F 0 "#PWR19" H 5800 3400 30  0001 C CNN
F 1 "GND" H 5800 3330 30  0001 C CNN
F 2 "" H 5800 3400 60  0000 C CNN
F 3 "" H 5800 3400 60  0000 C CNN
	1    5800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3350 5800 3350
Wire Wire Line
	5800 3350 5800 3400
$Comp
L GND #PWR10
U 1 1 56648342
P 4050 4000
F 0 "#PWR10" H 4050 4000 30  0001 C CNN
F 1 "GND" H 4050 3930 30  0001 C CNN
F 2 "" H 4050 4000 60  0000 C CNN
F 3 "" H 4050 4000 60  0000 C CNN
	1    4050 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3050 5350 3000
Wire Wire Line
	5350 3850 5350 3900
$Comp
L TL082 U1
U 1 1 56648796
P 3950 3550
F 0 "U1" H 3900 3750 60  0000 L CNN
F 1 "TL082" H 3900 3300 60  0000 L CNN
F 2 "Housings_DIP:DIP-8__300" H 3950 3550 60  0001 C CNN
F 3 "" H 3950 3550 60  0000 C CNN
	1    3950 3550
	-1   0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56648CD3
P 4050 4150
F 0 "R5" V 4130 4150 40  0000 C CNN
F 1 "20K" V 4057 4151 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3980 4150 30  0001 C CNN
F 3 "" H 4050 4150 30  0000 C CNN
	1    4050 4150
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 56648D50
P 3000 4150
F 0 "R2" V 3080 4150 40  0000 C CNN
F 1 "1000" V 3007 4151 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 2930 4150 30  0001 C CNN
F 3 "" H 3000 4150 30  0000 C CNN
	1    3000 4150
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR9
U 1 1 56648E21
P 4050 3100
F 0 "#PWR9" H 4050 3190 20  0001 C CNN
F 1 "+5V" H 4050 3190 30  0000 C CNN
F 2 "" H 4050 3100 60  0000 C CNN
F 3 "" H 4050 3100 60  0000 C CNN
	1    4050 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3450 4750 3450
Wire Wire Line
	4450 3650 4450 4150
Wire Wire Line
	4450 4150 4300 4150
Wire Wire Line
	3250 4150 3800 4150
Wire Wire Line
	3400 4150 3400 3550
Wire Wire Line
	2800 3550 3450 3550
Connection ~ 3400 4150
Wire Wire Line
	4050 3150 4050 3100
Wire Wire Line
	4050 3950 4050 4000
$Comp
L GND #PWR5
U 1 1 566491BF
P 2700 4250
F 0 "#PWR5" H 2700 4250 30  0001 C CNN
F 1 "GND" H 2700 4180 30  0001 C CNN
F 2 "" H 2700 4250 60  0000 C CNN
F 3 "" H 2700 4250 60  0000 C CNN
	1    2700 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4150 2700 4150
Wire Wire Line
	2700 4150 2700 4250
Text Label 2200 2450 0    60   ~ 0
SHUNTHIGH
Text Label 2200 2550 0    60   ~ 0
SHUNTLOW
Wire Wire Line
	2800 2650 2800 3550
Wire Wire Line
	1950 2650 2800 2650
Connection ~ 3400 3550
Text Label 6500 2450 0    60   ~ 0
NernstV
Text Label 2200 2750 0    60   ~ 0
NernstV
Wire Wire Line
	6950 2450 6500 2450
Wire Wire Line
	1950 2750 2300 2750
Wire Wire Line
	1950 2550 2200 2550
Wire Wire Line
	1950 2450 2200 2450
$Comp
L GND #PWR14
U 1 1 5664A07C
P 4850 4900
F 0 "#PWR14" H 4850 4900 30  0001 C CNN
F 1 "GND" H 4850 4830 30  0001 C CNN
F 2 "" H 4850 4900 60  0000 C CNN
F 3 "" H 4850 4900 60  0000 C CNN
	1    4850 4900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR13
U 1 1 5664A082
P 4850 3950
F 0 "#PWR13" H 4850 4040 20  0001 C CNN
F 1 "+5V" H 4850 4040 30  0000 C CNN
F 2 "" H 4850 3950 60  0000 C CNN
F 3 "" H 4850 3950 60  0000 C CNN
	1    4850 3950
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5664A088
P 4050 5100
F 0 "R6" V 4130 5100 40  0000 C CNN
F 1 "10K" V 4057 5101 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3980 5100 30  0001 C CNN
F 3 "" H 4050 5100 30  0000 C CNN
	1    4050 5100
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5664A08E
P 4850 5100
F 0 "R8" V 4930 5100 40  0000 C CNN
F 1 "20K" V 4857 5101 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4780 5100 30  0001 C CNN
F 3 "" H 4850 5100 30  0000 C CNN
	1    4850 5100
	0    1    1    0   
$EndComp
$Comp
L GND #PWR8
U 1 1 5664A094
P 3750 5250
F 0 "#PWR8" H 3750 5250 30  0001 C CNN
F 1 "GND" H 3750 5180 30  0001 C CNN
F 2 "" H 3750 5250 60  0000 C CNN
F 3 "" H 3750 5250 60  0000 C CNN
	1    3750 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 5250 3750 5100
Wire Wire Line
	3750 5100 3800 5100
Wire Wire Line
	4300 5100 4600 5100
Wire Wire Line
	4450 4550 4400 4550
Wire Wire Line
	4400 4550 4400 5100
Connection ~ 4400 5100
Wire Wire Line
	4850 4850 4850 4900
Wire Wire Line
	5550 5100 5100 5100
Wire Wire Line
	4850 4050 4850 3950
$Comp
L GND #PWR17
U 1 1 5664A38E
P 5350 3900
F 0 "#PWR17" H 5350 3900 30  0001 C CNN
F 1 "GND" H 5350 3830 30  0001 C CNN
F 2 "" H 5350 3900 60  0000 C CNN
F 3 "" H 5350 3900 60  0000 C CNN
	1    5350 3900
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5664A791
P 5750 4450
F 0 "R10" V 5830 4450 40  0000 C CNN
F 1 "150" V 5757 4451 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5680 4450 30  0001 C CNN
F 3 "" H 5750 4450 30  0000 C CNN
	1    5750 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 4350 4450 4350
Wire Wire Line
	2300 2750 2300 4350
$Comp
L C C5
U 1 1 5664AD4B
P 6250 4450
F 0 "C5" H 6250 4550 40  0000 L CNN
F 1 ".5u" H 6256 4365 40  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4_W2.5_P2.5" H 6288 4300 30  0001 C CNN
F 3 "" H 6250 4450 60  0000 C CNN
	1    6250 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	5450 4450 5500 4450
Wire Wire Line
	6000 4450 6050 4450
Wire Wire Line
	6450 4450 6500 4450
Wire Wire Line
	6500 4450 6500 2450
$Comp
L +5V #PWR1
U 1 1 5664B9DA
P 2000 3050
F 0 "#PWR1" H 2000 3140 20  0001 C CNN
F 1 "+5V" H 2000 3140 30  0000 C CNN
F 2 "" H 2000 3050 60  0000 C CNN
F 3 "" H 2000 3050 60  0000 C CNN
	1    2000 3050
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR3
U 1 1 5664BA03
P 2050 2950
F 0 "#PWR3" H 2050 2900 20  0001 C CNN
F 1 "+12V" H 2050 3050 30  0000 C CNN
F 2 "" H 2050 2950 60  0000 C CNN
F 3 "" H 2050 2950 60  0000 C CNN
	1    2050 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 5664BA2C
P 2000 3200
F 0 "#PWR2" H 2000 3200 30  0001 C CNN
F 1 "GND" H 2000 3130 30  0001 C CNN
F 2 "" H 2000 3200 60  0000 C CNN
F 3 "" H 2000 3200 60  0000 C CNN
	1    2000 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3150 2000 3150
Wire Wire Line
	2000 3150 2000 3200
Wire Wire Line
	1950 3050 2000 3050
Wire Wire Line
	1950 2950 2050 2950
Wire Wire Line
	1950 2850 2200 2850
Wire Wire Line
	2200 2850 2200 4800
Wire Wire Line
	2200 4750 2700 4750
$Comp
L MOSFET_N Q1
U 1 1 5664BC3E
P 2900 4750
F 0 "Q1" H 2910 4920 60  0000 R CNN
F 1 "MOSFET_N" H 2910 4600 60  0000 R CNN
F 2 "Transistors_TO-220:TO-220_FET-GDS_Vertical_MountedFromLS_LargePads" H 2900 4750 60  0001 C CNN
F 3 "" H 2900 4750 60  0000 C CNN
	1    2900 4750
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5664BD0F
P 2200 5050
F 0 "R1" V 2280 5050 40  0000 C CNN
F 1 "4.7K" V 2207 5051 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 2130 5050 30  0001 C CNN
F 3 "" H 2200 5050 30  0000 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5664BEB2
P 2500 5400
F 0 "#PWR4" H 2500 5400 30  0001 C CNN
F 1 "GND" H 2500 5330 30  0001 C CNN
F 2 "" H 2500 5400 60  0000 C CNN
F 3 "" H 2500 5400 60  0000 C CNN
	1    2500 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5300 3000 5300
Wire Wire Line
	2500 5300 2500 5400
Wire Wire Line
	3000 5300 3000 4950
Connection ~ 2500 5300
Connection ~ 2200 4750
Wire Wire Line
	3000 4550 3300 4550
Text Label 3050 4550 0    60   ~ 0
HEATERLOW
Text Label 6900 2750 2    60   ~ 0
HEATERLOW
$Comp
L +12V #PWR20
U 1 1 5664C1FB
P 6700 2600
F 0 "#PWR20" H 6700 2550 20  0001 C CNN
F 1 "+12V" H 6700 2700 30  0000 C CNN
F 2 "" H 6700 2600 60  0000 C CNN
F 3 "" H 6700 2600 60  0000 C CNN
	1    6700 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2750 6600 2750
Wire Wire Line
	6950 2650 6700 2650
Wire Wire Line
	6700 2650 6700 2600
$Comp
L TL082 U2
U 1 1 5664CA16
P 4950 4450
F 0 "U2" H 4900 4650 60  0000 L CNN
F 1 "TL082" H 4900 4200 60  0000 L CNN
F 2 "Housings_DIP:DIP-8__300" H 4950 4450 60  0001 C CNN
F 3 "" H 4950 4450 60  0000 C CNN
	1    4950 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4450 5500 5100
Connection ~ 5500 5100
$Comp
L 78025 U3
U 1 1 5664D9B2
P 5500 2400
F 0 "U3" H 5650 2204 60  0000 C CNN
F 1 "78025" H 5500 2600 60  0000 C CNN
F 2 "" H 5500 2400 60  0000 C CNN
F 3 "" H 5500 2400 60  0000 C CNN
	1    5500 2400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
