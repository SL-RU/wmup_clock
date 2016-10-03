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
L L200 U?
U 1 1 57EAE5ED
P 7500 3300
F 0 "U?" H 7750 3650 50  0000 C CNN
F 1 "L200" H 7300 3650 50  0000 C CNN
F 2 "" H 7500 3400 50  0000 C CNN
F 3 "" H 7500 3400 50  0000 C CNN
	1    7500 3300
	1    0    0    -1  
$EndComp
$Comp
L Diode_Bridge D?
U 1 1 57EAE628
P 5000 3500
F 0 "D?" H 4750 3800 50  0000 C CNN
F 1 "Diode_Bridge" H 5350 3150 50  0000 C CNN
F 2 "" H 5000 3500 50  0000 C CNN
F 3 "" H 5000 3500 50  0000 C CNN
	1    5000 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5000 3100 7100 3100
Wire Wire Line
	5000 3900 9200 3900
Wire Wire Line
	7300 3700 7300 3900
$Comp
L CP C?
U 1 1 57EAE8B2
P 6150 3500
F 0 "C?" H 6175 3600 50  0000 L CNN
F 1 "4000uF" H 6175 3400 50  0000 L CNN
F 2 "" H 6188 3350 50  0000 C CNN
F 3 "" H 6150 3500 50  0000 C CNN
	1    6150 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3350 6150 3100
Connection ~ 6150 3100
Wire Wire Line
	6150 3650 6150 3900
Connection ~ 6150 3900
$Comp
L D D?
U 1 1 57EAE97F
P 8350 3300
F 0 "D?" H 8350 3400 50  0000 C CNN
F 1 "D" H 8350 3200 50  0000 C CNN
F 2 "" H 8350 3300 50  0000 C CNN
F 3 "" H 8350 3300 50  0000 C CNN
	1    8350 3300
	-1   0    0    1   
$EndComp
$Comp
L RVAR R?
U 1 1 57EAE9E5
P 8250 3700
F 0 "R?" V 8330 3650 50  0000 C CNN
F 1 "6.8k" V 8170 3760 50  0000 C CNN
F 2 "" H 8250 3700 50  0000 C CNN
F 3 "" H 8250 3700 50  0000 C CNN
	1    8250 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 3700 8000 3700
$Comp
L R R?
U 1 1 57EAEC37
P 7650 3800
F 0 "R?" V 7730 3800 50  0000 C CNN
F 1 "820" V 7650 3800 50  0000 C CNN
F 2 "" V 7580 3800 50  0000 C CNN
F 3 "" H 7650 3800 50  0000 C CNN
	1    7650 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	7800 3800 7800 3700
Connection ~ 7800 3700
Wire Wire Line
	7500 3800 7300 3800
Connection ~ 7300 3800
Wire Wire Line
	8500 3300 8600 3300
Wire Wire Line
	8600 3300 8600 3700
Wire Wire Line
	8600 3700 8500 3700
Wire Wire Line
	7900 3300 8200 3300
$Comp
L R R?
U 1 1 57EAEF99
P 8050 3000
F 0 "R?" V 8130 3000 50  0000 C CNN
F 1 "R" V 8050 3000 50  0000 C CNN
F 2 "" V 7980 3000 50  0000 C CNN
F 3 "" H 8050 3000 50  0000 C CNN
	1    8050 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2850 7900 3100
Wire Wire Line
	8050 3150 8050 3300
Connection ~ 8050 3300
Wire Wire Line
	7900 2850 9200 2850
Connection ~ 8050 2850
Connection ~ 7300 3900
Wire Wire Line
	4250 2900 5400 2900
Wire Wire Line
	5400 2900 5400 3500
Wire Wire Line
	4600 3500 4600 3850
Wire Wire Line
	4600 3850 4250 3850
Text GLabel 4250 2900 0    60   Input ~ 0
in2
Text GLabel 4250 3850 0    60   Input ~ 0
in1
Text GLabel 9200 2850 2    60   Input ~ 0
out+
Text GLabel 9200 3900 2    60   Input ~ 0
out-
$Comp
L C C?
U 1 1 57EAF544
P 8800 3450
F 0 "C?" H 8825 3550 50  0000 L CNN
F 1 "1uF" H 8825 3350 50  0000 L CNN
F 2 "" H 8838 3300 50  0000 C CNN
F 3 "" H 8800 3450 50  0000 C CNN
	1    8800 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3300 8800 2850
Connection ~ 8800 2850
Wire Wire Line
	8800 3600 8800 3900
Connection ~ 8800 3900
$Comp
L R R?
U 1 1 57EAF8AD
P 6750 3300
F 0 "R?" V 6830 3300 50  0000 C CNN
F 1 "1k" V 6750 3300 50  0000 C CNN
F 2 "" V 6680 3300 50  0000 C CNN
F 3 "" H 6750 3300 50  0000 C CNN
	1    6750 3300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57EAF93D
P 6750 3700
F 0 "R?" V 6830 3700 50  0000 C CNN
F 1 "100" V 6750 3700 50  0000 C CNN
F 2 "" V 6680 3700 50  0000 C CNN
F 3 "" H 6750 3700 50  0000 C CNN
	1    6750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 3850 6750 3900
Connection ~ 6750 3900
Wire Wire Line
	6750 3550 6750 3450
Wire Wire Line
	6750 3150 6750 3100
Connection ~ 6750 3100
Wire Wire Line
	6750 3500 6950 3500
Wire Wire Line
	6950 3500 6950 4250
Wire Wire Line
	6950 4250 9200 4250
Connection ~ 6750 3500
$Comp
L R R?
U 1 1 57EAFAB0
P 9050 3150
F 0 "R?" V 9130 3150 50  0000 C CNN
F 1 "1k" V 9050 3150 50  0000 C CNN
F 2 "" V 8980 3150 50  0000 C CNN
F 3 "" H 9050 3150 50  0000 C CNN
	1    9050 3150
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57EAFB2C
P 9050 3600
F 0 "R?" V 9130 3600 50  0000 C CNN
F 1 "100" V 9050 3600 50  0000 C CNN
F 2 "" V 8980 3600 50  0000 C CNN
F 3 "" H 9050 3600 50  0000 C CNN
	1    9050 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3750 9050 3900
Connection ~ 9050 3900
Wire Wire Line
	9050 3000 9050 2850
Connection ~ 9050 2850
Wire Wire Line
	9050 3300 9050 3450
Wire Wire Line
	9050 3400 9150 3400
Wire Wire Line
	9150 3400 9150 4100
Wire Wire Line
	9150 4100 9200 4100
Connection ~ 9050 3400
Text GLabel 9200 4100 2    60   Input ~ 0
acb_volt
Text GLabel 9200 4250 2    60   Input ~ 0
in_volt
$EndSCHEMATC
