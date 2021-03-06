EESchema Schematic File Version 4
EELAYER 30 0
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
Text GLabel 8150 700  0    50   Input ~ 0
LED01
Wire Wire Line
	8150 700  8200 700 
Wire Wire Line
	8200 700  8200 750 
$Comp
L power:GND #PWR0101
U 1 1 5F2774EC
P 8200 1150
F 0 "#PWR0101" H 8200 900 50  0001 C CNN
F 1 "GND" H 8205 977 50  0000 C CNN
F 2 "" H 8200 1150 50  0001 C CNN
F 3 "" H 8200 1150 50  0001 C CNN
	1    8200 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 950  7600 950 
Text GLabel 7550 950  0    50   Input ~ 0
D01
$Comp
L Device:C_Small C1
U 1 1 5F51B093
P 7900 1050
F 0 "C1" H 7700 1050 50  0000 L CNN
F 1 "100n" H 7500 950 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 1050 50  0001 C CNN
F 3 "~" H 7900 1050 50  0001 C CNN
	1    7900 1050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q1
U 1 1 5F271720
P 8100 950
F 0 "Q1" H 8307 996 50  0000 L CNN
F 1 "TIP120" H 8307 905 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 875 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 950 50  0001 L CNN
	1    8100 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1150 8200 1150
Connection ~ 8200 1150
Connection ~ 7900 950 
$Comp
L Device:R R1
U 1 1 5F2759A8
P 7750 950
F 0 "R1" V 7957 950 50  0000 C CNN
F 1 "3k3" V 7866 950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 950 50  0001 C CNN
F 3 "~" H 7750 950 50  0001 C CNN
	1    7750 950 
	0    -1   -1   0   
$EndComp
Text GLabel 9400 700  0    50   Input ~ 0
LED07
Wire Wire Line
	9400 700  9450 700 
Wire Wire Line
	9450 700  9450 750 
$Comp
L power:GND #PWR0102
U 1 1 5F53A46A
P 9450 1150
F 0 "#PWR0102" H 9450 900 50  0001 C CNN
F 1 "GND" H 9455 977 50  0000 C CNN
F 2 "" H 9450 1150 50  0001 C CNN
F 3 "" H 9450 1150 50  0001 C CNN
	1    9450 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 950  8850 950 
Text GLabel 8800 950  0    50   Input ~ 0
D07
$Comp
L Device:C_Small C7
U 1 1 5F53A472
P 9150 1050
F 0 "C7" H 8950 1050 50  0000 L CNN
F 1 "100n" H 8750 950 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9150 1050 50  0001 C CNN
F 3 "~" H 9150 1050 50  0001 C CNN
	1    9150 1050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q7
U 1 1 5F53A478
P 9350 950
F 0 "Q7" H 9557 996 50  0000 L CNN
F 1 "TIP120" H 9557 905 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9550 875 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 9350 950 50  0001 L CNN
	1    9350 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1150 9450 1150
Connection ~ 9450 1150
Connection ~ 9150 950 
Text GLabel 10650 700  0    50   Input ~ 0
LED12
Wire Wire Line
	10650 700  10700 700 
Wire Wire Line
	10700 700  10700 750 
$Comp
L power:GND #PWR0103
U 1 1 5F53CC6C
P 10700 1150
F 0 "#PWR0103" H 10700 900 50  0001 C CNN
F 1 "GND" H 10705 977 50  0000 C CNN
F 2 "" H 10700 1150 50  0001 C CNN
F 3 "" H 10700 1150 50  0001 C CNN
	1    10700 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 950  10100 950 
Text GLabel 10050 950  0    50   Input ~ 0
D12
$Comp
L Device:C_Small C12
U 1 1 5F53CC74
P 10400 1050
F 0 "C12" H 10200 1050 50  0000 L CNN
F 1 "100n" H 10000 950 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 10400 1050 50  0001 C CNN
F 3 "~" H 10400 1050 50  0001 C CNN
	1    10400 1050
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q12
U 1 1 5F53CC7A
P 10600 950
F 0 "Q12" H 10807 996 50  0000 L CNN
F 1 "TIP120" H 10807 905 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10800 875 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 10600 950 50  0001 L CNN
	1    10600 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 1150 10700 1150
Connection ~ 10700 1150
Connection ~ 10400 950 
Text GLabel 8150 1400 0    50   Input ~ 0
LED02
Wire Wire Line
	8150 1400 8200 1400
Wire Wire Line
	8200 1400 8200 1450
$Comp
L power:GND #PWR0104
U 1 1 5F56AFD0
P 8200 1850
F 0 "#PWR0104" H 8200 1600 50  0001 C CNN
F 1 "GND" H 8205 1677 50  0000 C CNN
F 2 "" H 8200 1850 50  0001 C CNN
F 3 "" H 8200 1850 50  0001 C CNN
	1    8200 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1650 7600 1650
Text GLabel 7550 1650 0    50   Input ~ 0
D02
$Comp
L Device:C_Small C2
U 1 1 5F56AFD8
P 7900 1750
F 0 "C2" H 7700 1750 50  0000 L CNN
F 1 "100n" H 7500 1650 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 1750 50  0001 C CNN
F 3 "~" H 7900 1750 50  0001 C CNN
	1    7900 1750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q2
U 1 1 5F56AFDE
P 8100 1650
F 0 "Q2" H 8307 1696 50  0000 L CNN
F 1 "TIP120" H 8307 1605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 1575 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 1650 50  0001 L CNN
	1    8100 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1850 8200 1850
Connection ~ 8200 1850
Connection ~ 7900 1650
Text GLabel 9400 1400 0    50   Input ~ 0
LED08
Wire Wire Line
	9400 1400 9450 1400
Wire Wire Line
	9450 1400 9450 1450
$Comp
L power:GND #PWR0105
U 1 1 5F56AFF0
P 9450 1850
F 0 "#PWR0105" H 9450 1600 50  0001 C CNN
F 1 "GND" H 9455 1677 50  0000 C CNN
F 2 "" H 9450 1850 50  0001 C CNN
F 3 "" H 9450 1850 50  0001 C CNN
	1    9450 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 1650 8850 1650
Text GLabel 8800 1650 0    50   Input ~ 0
D08
$Comp
L Device:C_Small C8
U 1 1 5F56AFF8
P 9150 1750
F 0 "C8" H 8950 1750 50  0000 L CNN
F 1 "100n" H 8750 1650 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9150 1750 50  0001 C CNN
F 3 "~" H 9150 1750 50  0001 C CNN
	1    9150 1750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q8
U 1 1 5F56AFFE
P 9350 1650
F 0 "Q8" H 9557 1696 50  0000 L CNN
F 1 "TIP120" H 9557 1605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9550 1575 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 9350 1650 50  0001 L CNN
	1    9350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 1850 9450 1850
Connection ~ 9450 1850
Connection ~ 9150 1650
$Comp
L Device:R R8
U 1 1 5F56B007
P 9000 1650
F 0 "R8" V 9207 1650 50  0000 C CNN
F 1 "3k3" V 9116 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 1650 50  0001 C CNN
F 3 "~" H 9000 1650 50  0001 C CNN
	1    9000 1650
	0    -1   -1   0   
$EndComp
Text GLabel 10650 1400 0    50   Input ~ 0
LED13
Wire Wire Line
	10650 1400 10700 1400
Wire Wire Line
	10700 1400 10700 1450
$Comp
L power:GND #PWR0106
U 1 1 5F56B010
P 10700 1850
F 0 "#PWR0106" H 10700 1600 50  0001 C CNN
F 1 "GND" H 10705 1677 50  0000 C CNN
F 2 "" H 10700 1850 50  0001 C CNN
F 3 "" H 10700 1850 50  0001 C CNN
	1    10700 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1650 10100 1650
Text GLabel 10050 1650 0    50   Input ~ 0
D13
$Comp
L Device:C_Small C13
U 1 1 5F56B018
P 10400 1750
F 0 "C13" H 10200 1750 50  0000 L CNN
F 1 "100n" H 10000 1650 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 10400 1750 50  0001 C CNN
F 3 "~" H 10400 1750 50  0001 C CNN
	1    10400 1750
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q13
U 1 1 5F56B01E
P 10600 1650
F 0 "Q13" H 10807 1696 50  0000 L CNN
F 1 "TIP120" H 10807 1605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10800 1575 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 10600 1650 50  0001 L CNN
	1    10600 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 1850 10700 1850
Connection ~ 10700 1850
Connection ~ 10400 1650
$Comp
L Device:R R13
U 1 1 5F56B027
P 10250 1650
F 0 "R13" V 10457 1650 50  0000 C CNN
F 1 "3k3" V 10366 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10180 1650 50  0001 C CNN
F 3 "~" H 10250 1650 50  0001 C CNN
	1    10250 1650
	0    -1   -1   0   
$EndComp
Text GLabel 8150 2100 0    50   Input ~ 0
LED03
Wire Wire Line
	8150 2100 8200 2100
Wire Wire Line
	8200 2100 8200 2150
$Comp
L power:GND #PWR0107
U 1 1 5F574F72
P 8200 2550
F 0 "#PWR0107" H 8200 2300 50  0001 C CNN
F 1 "GND" H 8205 2377 50  0000 C CNN
F 2 "" H 8200 2550 50  0001 C CNN
F 3 "" H 8200 2550 50  0001 C CNN
	1    8200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 2350 7600 2350
Text GLabel 7550 2350 0    50   Input ~ 0
D03
$Comp
L Device:C_Small C3
U 1 1 5F574F7A
P 7900 2450
F 0 "C3" H 7700 2450 50  0000 L CNN
F 1 "100n" H 7500 2350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 2450 50  0001 C CNN
F 3 "~" H 7900 2450 50  0001 C CNN
	1    7900 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q3
U 1 1 5F574F80
P 8100 2350
F 0 "Q3" H 8307 2396 50  0000 L CNN
F 1 "TIP120" H 8307 2305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 2275 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 2350 50  0001 L CNN
	1    8100 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2550 8200 2550
Connection ~ 8200 2550
Connection ~ 7900 2350
$Comp
L Device:R R3
U 1 1 5F574F89
P 7750 2350
F 0 "R3" V 7957 2350 50  0000 C CNN
F 1 "3k3" V 7866 2350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 2350 50  0001 C CNN
F 3 "~" H 7750 2350 50  0001 C CNN
	1    7750 2350
	0    -1   -1   0   
$EndComp
Text GLabel 9400 2100 0    50   Input ~ 0
LED09
Wire Wire Line
	9400 2100 9450 2100
Wire Wire Line
	9450 2100 9450 2150
$Comp
L power:GND #PWR0108
U 1 1 5F574F92
P 9450 2550
F 0 "#PWR0108" H 9450 2300 50  0001 C CNN
F 1 "GND" H 9455 2377 50  0000 C CNN
F 2 "" H 9450 2550 50  0001 C CNN
F 3 "" H 9450 2550 50  0001 C CNN
	1    9450 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2350 8850 2350
Text GLabel 8800 2350 0    50   Input ~ 0
D09
$Comp
L Device:C_Small C9
U 1 1 5F574F9A
P 9150 2450
F 0 "C9" H 8950 2450 50  0000 L CNN
F 1 "100n" H 8750 2350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9150 2450 50  0001 C CNN
F 3 "~" H 9150 2450 50  0001 C CNN
	1    9150 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q9
U 1 1 5F574FA0
P 9350 2350
F 0 "Q9" H 9557 2396 50  0000 L CNN
F 1 "TIP120" H 9557 2305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9550 2275 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 9350 2350 50  0001 L CNN
	1    9350 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 2550 9450 2550
Connection ~ 9450 2550
Connection ~ 9150 2350
$Comp
L Device:R R9
U 1 1 5F574FA9
P 9000 2350
F 0 "R9" V 9207 2350 50  0000 C CNN
F 1 "3k3" V 9116 2350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 2350 50  0001 C CNN
F 3 "~" H 9000 2350 50  0001 C CNN
	1    9000 2350
	0    -1   -1   0   
$EndComp
Text GLabel 10650 2100 0    50   Input ~ 0
LED14
Wire Wire Line
	10650 2100 10700 2100
Wire Wire Line
	10700 2100 10700 2150
$Comp
L power:GND #PWR0109
U 1 1 5F574FB2
P 10700 2550
F 0 "#PWR0109" H 10700 2300 50  0001 C CNN
F 1 "GND" H 10705 2377 50  0000 C CNN
F 2 "" H 10700 2550 50  0001 C CNN
F 3 "" H 10700 2550 50  0001 C CNN
	1    10700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 2350 10100 2350
Text GLabel 10050 2350 0    50   Input ~ 0
D14
$Comp
L Device:C_Small C14
U 1 1 5F574FBA
P 10400 2450
F 0 "C14" H 10200 2450 50  0000 L CNN
F 1 "100n" H 10000 2350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 10400 2450 50  0001 C CNN
F 3 "~" H 10400 2450 50  0001 C CNN
	1    10400 2450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q14
U 1 1 5F574FC0
P 10600 2350
F 0 "Q14" H 10807 2396 50  0000 L CNN
F 1 "TIP120" H 10807 2305 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10800 2275 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 10600 2350 50  0001 L CNN
	1    10600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 2550 10700 2550
Connection ~ 10700 2550
Connection ~ 10400 2350
$Comp
L Device:R R14
U 1 1 5F574FC9
P 10250 2350
F 0 "R14" V 10457 2350 50  0000 C CNN
F 1 "3k3" V 10366 2350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10180 2350 50  0001 C CNN
F 3 "~" H 10250 2350 50  0001 C CNN
	1    10250 2350
	0    -1   -1   0   
$EndComp
Text GLabel 8150 2800 0    50   Input ~ 0
LED04
Wire Wire Line
	8150 2800 8200 2800
Wire Wire Line
	8200 2800 8200 2850
$Comp
L power:GND #PWR0110
U 1 1 5F602EFD
P 8200 3250
F 0 "#PWR0110" H 8200 3000 50  0001 C CNN
F 1 "GND" H 8205 3077 50  0000 C CNN
F 2 "" H 8200 3250 50  0001 C CNN
F 3 "" H 8200 3250 50  0001 C CNN
	1    8200 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3050 7600 3050
Text GLabel 7550 3050 0    50   Input ~ 0
D04
$Comp
L Device:C_Small C4
U 1 1 5F602F05
P 7900 3150
F 0 "C4" H 7700 3150 50  0000 L CNN
F 1 "100n" H 7500 3050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 3150 50  0001 C CNN
F 3 "~" H 7900 3150 50  0001 C CNN
	1    7900 3150
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q4
U 1 1 5F602F0B
P 8100 3050
F 0 "Q4" H 8307 3096 50  0000 L CNN
F 1 "TIP120" H 8307 3005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 2975 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 3050 50  0001 L CNN
	1    8100 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3250 8200 3250
Connection ~ 8200 3250
Connection ~ 7900 3050
$Comp
L Device:R R4
U 1 1 5F602F14
P 7750 3050
F 0 "R4" V 7957 3050 50  0000 C CNN
F 1 "3k3" V 7866 3050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 3050 50  0001 C CNN
F 3 "~" H 7750 3050 50  0001 C CNN
	1    7750 3050
	0    -1   -1   0   
$EndComp
Text GLabel 9400 2800 0    50   Input ~ 0
LED10
Wire Wire Line
	9400 2800 9450 2800
Wire Wire Line
	9450 2800 9450 2850
$Comp
L power:GND #PWR0111
U 1 1 5F602F1D
P 9450 3250
F 0 "#PWR0111" H 9450 3000 50  0001 C CNN
F 1 "GND" H 9455 3077 50  0000 C CNN
F 2 "" H 9450 3250 50  0001 C CNN
F 3 "" H 9450 3250 50  0001 C CNN
	1    9450 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3050 8850 3050
Text GLabel 8800 3050 0    50   Input ~ 0
D10
$Comp
L Device:C_Small C10
U 1 1 5F602F25
P 9150 3150
F 0 "C10" H 8950 3150 50  0000 L CNN
F 1 "100n" H 8750 3050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9150 3150 50  0001 C CNN
F 3 "~" H 9150 3150 50  0001 C CNN
	1    9150 3150
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q10
U 1 1 5F602F2B
P 9350 3050
F 0 "Q10" H 9557 3096 50  0000 L CNN
F 1 "TIP120" H 9557 3005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9550 2975 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 9350 3050 50  0001 L CNN
	1    9350 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3250 9450 3250
Connection ~ 9450 3250
Connection ~ 9150 3050
$Comp
L Device:R R10
U 1 1 5F602F34
P 9000 3050
F 0 "R10" V 9207 3050 50  0000 C CNN
F 1 "3k3" V 9116 3050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 3050 50  0001 C CNN
F 3 "~" H 9000 3050 50  0001 C CNN
	1    9000 3050
	0    -1   -1   0   
$EndComp
Text GLabel 10650 2800 0    50   Input ~ 0
LED15
Wire Wire Line
	10650 2800 10700 2800
Wire Wire Line
	10700 2800 10700 2850
$Comp
L power:GND #PWR0112
U 1 1 5F602F3D
P 10700 3250
F 0 "#PWR0112" H 10700 3000 50  0001 C CNN
F 1 "GND" H 10705 3077 50  0000 C CNN
F 2 "" H 10700 3250 50  0001 C CNN
F 3 "" H 10700 3250 50  0001 C CNN
	1    10700 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 3050 10100 3050
Text GLabel 10050 3050 0    50   Input ~ 0
D15
$Comp
L Device:C_Small C15
U 1 1 5F602F45
P 10400 3150
F 0 "C15" H 10200 3150 50  0000 L CNN
F 1 "100n" H 10000 3050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 10400 3150 50  0001 C CNN
F 3 "~" H 10400 3150 50  0001 C CNN
	1    10400 3150
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q15
U 1 1 5F602F4B
P 10600 3050
F 0 "Q15" H 10807 3096 50  0000 L CNN
F 1 "TIP120" H 10807 3005 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10800 2975 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 10600 3050 50  0001 L CNN
	1    10600 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 3250 10700 3250
Connection ~ 10700 3250
Connection ~ 10400 3050
$Comp
L Device:R R15
U 1 1 5F602F54
P 10250 3050
F 0 "R15" V 10457 3050 50  0000 C CNN
F 1 "3k3" V 10366 3050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10180 3050 50  0001 C CNN
F 3 "~" H 10250 3050 50  0001 C CNN
	1    10250 3050
	0    -1   -1   0   
$EndComp
Text GLabel 8150 3500 0    50   Input ~ 0
LED05
Wire Wire Line
	8150 3500 8200 3500
Wire Wire Line
	8200 3500 8200 3550
$Comp
L power:GND #PWR0113
U 1 1 5F602F5D
P 8200 3950
F 0 "#PWR0113" H 8200 3700 50  0001 C CNN
F 1 "GND" H 8205 3777 50  0000 C CNN
F 2 "" H 8200 3950 50  0001 C CNN
F 3 "" H 8200 3950 50  0001 C CNN
	1    8200 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3750 7600 3750
Text GLabel 7550 3750 0    50   Input ~ 0
D05
$Comp
L Device:C_Small C5
U 1 1 5F602F65
P 7900 3850
F 0 "C5" H 7700 3850 50  0000 L CNN
F 1 "100n" H 7500 3750 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 3850 50  0001 C CNN
F 3 "~" H 7900 3850 50  0001 C CNN
	1    7900 3850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q5
U 1 1 5F602F6B
P 8100 3750
F 0 "Q5" H 8307 3796 50  0000 L CNN
F 1 "TIP120" H 8307 3705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 3675 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 3750 50  0001 L CNN
	1    8100 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3950 8200 3950
Connection ~ 8200 3950
Connection ~ 7900 3750
$Comp
L Device:R R5
U 1 1 5F602F74
P 7750 3750
F 0 "R5" V 7957 3750 50  0000 C CNN
F 1 "3k3" V 7866 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 3750 50  0001 C CNN
F 3 "~" H 7750 3750 50  0001 C CNN
	1    7750 3750
	0    -1   -1   0   
$EndComp
Text GLabel 9400 3500 0    50   Input ~ 0
LED11
Wire Wire Line
	9400 3500 9450 3500
Wire Wire Line
	9450 3500 9450 3550
$Comp
L power:GND #PWR0114
U 1 1 5F602F7D
P 9450 3950
F 0 "#PWR0114" H 9450 3700 50  0001 C CNN
F 1 "GND" H 9455 3777 50  0000 C CNN
F 2 "" H 9450 3950 50  0001 C CNN
F 3 "" H 9450 3950 50  0001 C CNN
	1    9450 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3750 8850 3750
Text GLabel 8800 3750 0    50   Input ~ 0
D11
$Comp
L Device:C_Small C11
U 1 1 5F602F85
P 9150 3850
F 0 "C11" H 8950 3850 50  0000 L CNN
F 1 "100n" H 8750 3750 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 9150 3850 50  0001 C CNN
F 3 "~" H 9150 3850 50  0001 C CNN
	1    9150 3850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q11
U 1 1 5F602F8B
P 9350 3750
F 0 "Q11" H 9557 3796 50  0000 L CNN
F 1 "TIP120" H 9557 3705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9550 3675 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 9350 3750 50  0001 L CNN
	1    9350 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3950 9450 3950
Connection ~ 9450 3950
Connection ~ 9150 3750
$Comp
L Device:R R11
U 1 1 5F602F94
P 9000 3750
F 0 "R11" V 9207 3750 50  0000 C CNN
F 1 "3k3" V 9116 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 3750 50  0001 C CNN
F 3 "~" H 9000 3750 50  0001 C CNN
	1    9000 3750
	0    -1   -1   0   
$EndComp
Text GLabel 10650 3500 0    50   Input ~ 0
LED16
Wire Wire Line
	10650 3500 10700 3500
Wire Wire Line
	10700 3500 10700 3550
$Comp
L power:GND #PWR0115
U 1 1 5F602F9D
P 10700 3950
F 0 "#PWR0115" H 10700 3700 50  0001 C CNN
F 1 "GND" H 10705 3777 50  0000 C CNN
F 2 "" H 10700 3950 50  0001 C CNN
F 3 "" H 10700 3950 50  0001 C CNN
	1    10700 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 3750 10100 3750
Text GLabel 10050 3750 0    50   Input ~ 0
D16
$Comp
L Device:C_Small C16
U 1 1 5F602FA5
P 10400 3850
F 0 "C16" H 10200 3850 50  0000 L CNN
F 1 "100n" H 10000 3750 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 10400 3850 50  0001 C CNN
F 3 "~" H 10400 3850 50  0001 C CNN
	1    10400 3850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q16
U 1 1 5F602FAB
P 10600 3750
F 0 "Q16" H 10807 3796 50  0000 L CNN
F 1 "TIP120" H 10807 3705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 10800 3675 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 10600 3750 50  0001 L CNN
	1    10600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10400 3950 10700 3950
Connection ~ 10700 3950
Connection ~ 10400 3750
$Comp
L Device:R R16
U 1 1 5F602FB4
P 10250 3750
F 0 "R16" V 10457 3750 50  0000 C CNN
F 1 "3k3" V 10366 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10180 3750 50  0001 C CNN
F 3 "~" H 10250 3750 50  0001 C CNN
	1    10250 3750
	0    -1   -1   0   
$EndComp
Text GLabel 8150 4200 0    50   Input ~ 0
LED06
Wire Wire Line
	8150 4200 8200 4200
Wire Wire Line
	8200 4200 8200 4250
$Comp
L power:GND #PWR0116
U 1 1 5F602FBD
P 8200 4650
F 0 "#PWR0116" H 8200 4400 50  0001 C CNN
F 1 "GND" H 8205 4477 50  0000 C CNN
F 2 "" H 8200 4650 50  0001 C CNN
F 3 "" H 8200 4650 50  0001 C CNN
	1    8200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4450 7600 4450
Text GLabel 7550 4450 0    50   Input ~ 0
D06
$Comp
L Device:C_Small C6
U 1 1 5F602FC5
P 7900 4550
F 0 "C6" H 7700 4550 50  0000 L CNN
F 1 "100n" H 7500 4450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 7900 4550 50  0001 C CNN
F 3 "~" H 7900 4550 50  0001 C CNN
	1    7900 4550
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:TIP120 Q6
U 1 1 5F602FCB
P 8100 4450
F 0 "Q6" H 8307 4496 50  0000 L CNN
F 1 "TIP120" H 8307 4405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 8300 4375 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 8100 4450 50  0001 L CNN
	1    8100 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 4650 8200 4650
Connection ~ 8200 4650
Connection ~ 7900 4450
$Comp
L Device:R R6
U 1 1 5F602FD4
P 7750 4450
F 0 "R6" V 7957 4450 50  0000 C CNN
F 1 "3k3" V 7866 4450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 4450 50  0001 C CNN
F 3 "~" H 7750 4450 50  0001 C CNN
	1    7750 4450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Female J17
U 1 1 5F6646A7
P 6650 950
F 0 "J17" H 6678 926 50  0000 L CNN
F 1 "PWMpair1" H 6678 835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6650 950 50  0001 C CNN
F 3 "~" H 6650 950 50  0001 C CNN
	1    6650 950 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J18
U 1 1 5F667197
P 6650 1450
F 0 "J18" H 6678 1426 50  0000 L CNN
F 1 "PWMpair2" H 6678 1335 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6650 1450 50  0001 C CNN
F 3 "~" H 6650 1450 50  0001 C CNN
	1    6650 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J20
U 1 1 5F66B34E
P 6650 2450
F 0 "J20" H 6678 2426 50  0000 L CNN
F 1 "PWMpair4" H 6678 2335 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6650 2450 50  0001 C CNN
F 3 "~" H 6650 2450 50  0001 C CNN
	1    6650 2450
	1    0    0    -1  
$EndComp
Text GLabel 6450 850  0    50   Input ~ 0
D01
Text GLabel 6450 950  0    50   Input ~ 0
D02
Text GLabel 6450 1050 0    50   Input ~ 0
D03
Text GLabel 6450 1150 0    50   Input ~ 0
D04
Text GLabel 6450 1350 0    50   Input ~ 0
D05
Text GLabel 6450 1450 0    50   Input ~ 0
D06
Text GLabel 6450 1550 0    50   Input ~ 0
D07
Text GLabel 6450 1650 0    50   Input ~ 0
D08
$Comp
L Connector:Conn_01x04_Female J19
U 1 1 5F6694D8
P 6650 1950
F 0 "J19" H 6678 1926 50  0000 L CNN
F 1 "PWMpair3" H 6678 1835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6650 1950 50  0001 C CNN
F 3 "~" H 6650 1950 50  0001 C CNN
	1    6650 1950
	1    0    0    -1  
$EndComp
Text GLabel 6450 1850 0    50   Input ~ 0
D09
Text GLabel 6450 1950 0    50   Input ~ 0
D10
Text GLabel 6450 2050 0    50   Input ~ 0
D11
Text GLabel 6450 2150 0    50   Input ~ 0
D12
Text GLabel 6450 2350 0    50   Input ~ 0
D13
Text GLabel 6450 2450 0    50   Input ~ 0
D14
Text GLabel 6400 3250 2    50   Input ~ 0
LED01
Text GLabel 6400 3350 2    50   Input ~ 0
LED02
Text GLabel 6400 3450 2    50   Input ~ 0
LED03
Text GLabel 6400 3550 2    50   Input ~ 0
LED04
Text GLabel 6400 3650 2    50   Input ~ 0
LED05
Text GLabel 6400 3750 2    50   Input ~ 0
LED06
Text GLabel 6400 3850 2    50   Input ~ 0
LED07
Text GLabel 6400 3950 2    50   Input ~ 0
LED08
Text GLabel 6400 4050 2    50   Input ~ 0
LED09
Text GLabel 5600 3250 2    50   Input ~ 0
LED10
Text GLabel 5600 3350 2    50   Input ~ 0
LED11
Text GLabel 5600 3450 2    50   Input ~ 0
LED12
Text GLabel 5600 3550 2    50   Input ~ 0
LED13
Text GLabel 5600 3650 2    50   Input ~ 0
LED14
Text GLabel 5600 3750 2    50   Input ~ 0
LED15
Text GLabel 5600 3850 2    50   Input ~ 0
LED16
$Comp
L Connector:Conn_01x04_Female J12
U 1 1 5F6B14E0
P 5750 950
F 0 "J12" H 5778 926 50  0000 L CNN
F 1 "GNDpair1" H 5778 835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5750 950 50  0001 C CNN
F 3 "~" H 5750 950 50  0001 C CNN
	1    5750 950 
	1    0    0    -1  
$EndComp
Text GLabel 5550 850  0    50   Input ~ 0
GND
Text GLabel 5550 950  0    50   Input ~ 0
GND
Text GLabel 5550 1050 0    50   Input ~ 0
GND
Text GLabel 5550 1150 0    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x04_Female J13
U 1 1 5F6B4EE5
P 5750 1450
F 0 "J13" H 5778 1426 50  0000 L CNN
F 1 "GNDpair2" H 5778 1335 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5750 1450 50  0001 C CNN
F 3 "~" H 5750 1450 50  0001 C CNN
	1    5750 1450
	1    0    0    -1  
$EndComp
Text GLabel 5550 1350 0    50   Input ~ 0
GND
Text GLabel 5550 1450 0    50   Input ~ 0
GND
Text GLabel 5550 1550 0    50   Input ~ 0
GND
Text GLabel 5550 1650 0    50   Input ~ 0
GND
Text GLabel 5550 1850 0    50   Input ~ 0
GND
Text GLabel 5550 1950 0    50   Input ~ 0
GND
Text GLabel 5550 2050 0    50   Input ~ 0
GND
Text GLabel 5550 2150 0    50   Input ~ 0
GND
Text GLabel 5550 2350 0    50   Input ~ 0
GND
Text GLabel 5550 2450 0    50   Input ~ 0
GND
Text GLabel 5550 2550 0    50   Input ~ 0
GND
Text GLabel 5550 2650 0    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x05_Female J9
U 1 1 5F6D63CD
P 4450 1000
F 0 "J9" H 4478 1026 50  0000 L CNN
F 1 "Inputs_PCA9685A" H 4478 935 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 4450 1000 50  0001 C CNN
F 3 "~" H 4450 1000 50  0001 C CNN
	1    4450 1000
	1    0    0    -1  
$EndComp
Text GLabel 4250 800  0    50   Input ~ 0
Vcc
Text GLabel 4250 900  0    50   Input ~ 0
SDA1
Text GLabel 4250 1000 0    50   Input ~ 0
SCL1
Text GLabel 4250 1100 0    50   Input ~ 0
DI11
Text GLabel 4250 1200 0    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x06_Male J2
U 1 1 5F6E1261
P 1550 2700
F 0 "J2" H 1658 3081 50  0000 C CNN
F 1 "Ard 03" H 1658 2990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 1550 2700 50  0001 C CNN
F 3 "~" H 1550 2700 50  0001 C CNN
	1    1550 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male J1
U 1 1 5F6E3010
P 1550 1750
F 0 "J1" H 1658 2231 50  0000 C CNN
F 1 "Ard 04" H 1658 2140 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 1550 1750 50  0001 C CNN
F 3 "~" H 1550 1750 50  0001 C CNN
	1    1550 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Male J5
U 1 1 5F6E5097
P 2550 1500
F 0 "J5" H 2658 2081 50  0000 C CNN
F 1 "Ard 01" H 2658 1990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 2550 1500 50  0001 C CNN
F 3 "~" H 2550 1500 50  0001 C CNN
	1    2550 1500
	1    0    0    -1  
$EndComp
Text GLabel 2750 1100 2    50   Input ~ 0
SCL1
Text GLabel 2750 1200 2    50   Input ~ 0
SDA1
Text GLabel 2750 1300 2    50   Input ~ 0
AREF
Text GLabel 2750 1400 2    50   Input ~ 0
GND
Text GLabel 2750 1600 2    50   Input ~ 0
DI12
Text GLabel 2750 1700 2    50   Input ~ 0
DI11
Text GLabel 2750 1800 2    50   Input ~ 0
DI10
Text GLabel 2750 1900 2    50   Input ~ 0
DI9
Text GLabel 2750 2000 2    50   Input ~ 0
DI8
Text GLabel 2750 2300 2    50   Input ~ 0
DI7
Text GLabel 2750 2400 2    50   Input ~ 0
DI6
Text GLabel 2750 2500 2    50   Input ~ 0
DI5
Text GLabel 2750 2700 2    50   Input ~ 0
DI3
Text GLabel 2750 2800 2    50   Input ~ 0
DI2
Text GLabel 2750 2900 2    50   Input ~ 0
DI1
Text GLabel 2750 3000 2    50   Input ~ 0
DI0
Text GLabel 1750 2500 2    50   Input ~ 0
A0
Text GLabel 1750 2600 2    50   Input ~ 0
A1
Text GLabel 1750 2700 2    50   Input ~ 0
A2
Text GLabel 1750 2800 2    50   Input ~ 0
A3
Text GLabel 1750 2900 2    50   Input ~ 0
A4
Text GLabel 1750 3000 2    50   Input ~ 0
A5
Text GLabel 1750 1650 2    50   Input ~ 0
RESET
Text GLabel 1750 1750 2    50   Input ~ 0
3V3+
Text GLabel 1750 1850 2    50   Input ~ 0
Vcc
Text GLabel 1750 1950 2    50   Input ~ 0
GND
Text GLabel 1750 2050 2    50   Input ~ 0
GND
Text GLabel 1750 2150 2    50   Input ~ 0
VIN
Text GLabel 1750 1450 2    50   Input ~ 0
GND
Text GLabel 1750 1550 2    50   Input ~ 0
IOREF
$Comp
L Connector:Conn_01x06_Female J4
U 1 1 5F6FF7BF
P 2250 2700
F 0 "J4" H 2278 2676 50  0000 L CNN
F 1 "Ard 03_1" H 2278 2585 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 2250 2700 50  0001 C CNN
F 3 "~" H 2250 2700 50  0001 C CNN
	1    2250 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x10_Female J7
U 1 1 5F703E70
P 3300 1500
F 0 "J7" H 3328 1476 50  0000 L CNN
F 1 "Ard 01_1" H 3328 1385 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x10_P2.54mm_Vertical" H 3300 1500 50  0001 C CNN
F 3 "~" H 3300 1500 50  0001 C CNN
	1    3300 1500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Female J3
U 1 1 5F707676
P 2250 1750
F 0 "J3" H 2278 1726 50  0000 L CNN
F 1 "Ard04_1" H 2278 1635 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2250 1750 50  0001 C CNN
F 3 "~" H 2250 1750 50  0001 C CNN
	1    2250 1750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x08_Male J6
U 1 1 5F6E6BED
P 2550 2600
F 0 "J6" H 2658 3081 50  0000 C CNN
F 1 "Ard 02" H 2658 2990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2550 2600 50  0001 C CNN
F 3 "~" H 2550 2600 50  0001 C CNN
	1    2550 2600
	1    0    0    -1  
$EndComp
Text GLabel 2750 2600 2    50   Input ~ 0
DI4
$Comp
L Connector:Conn_01x08_Female J8
U 1 1 5F700D69
P 3300 2600
F 0 "J8" H 3328 2576 50  0000 L CNN
F 1 "Ard 02_1" H 3328 2485 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 3300 2600 50  0001 C CNN
F 3 "~" H 3300 2600 50  0001 C CNN
	1    3300 2600
	1    0    0    -1  
$EndComp
Text GLabel 2750 1500 2    50   Input ~ 0
DI13
Wire Wire Line
	2750 1100 3100 1100
Wire Wire Line
	3100 1200 2750 1200
Wire Wire Line
	2750 1300 3100 1300
Wire Wire Line
	3100 1400 2750 1400
Wire Wire Line
	2750 1500 3100 1500
Wire Wire Line
	3100 1600 2750 1600
Wire Wire Line
	2750 1700 3100 1700
Wire Wire Line
	3100 1800 2750 1800
Wire Wire Line
	2750 1900 3100 1900
Wire Wire Line
	3100 2000 2750 2000
Wire Wire Line
	3100 2300 2750 2300
Wire Wire Line
	2750 2400 3100 2400
Wire Wire Line
	3100 2500 2750 2500
Wire Wire Line
	2750 2600 3100 2600
Wire Wire Line
	3100 2700 2750 2700
Wire Wire Line
	2750 2800 3100 2800
Wire Wire Line
	3100 2900 2750 2900
Wire Wire Line
	2750 3000 3100 3000
Wire Wire Line
	2050 3000 1750 3000
Wire Wire Line
	1750 2900 2050 2900
Wire Wire Line
	2050 2800 1750 2800
Wire Wire Line
	1750 2700 2050 2700
Wire Wire Line
	2050 2600 1750 2600
Wire Wire Line
	1750 2500 2050 2500
Wire Wire Line
	2050 2150 1750 2150
Wire Wire Line
	1750 2050 2050 2050
Wire Wire Line
	2050 1950 1750 1950
Wire Wire Line
	1750 1850 2050 1850
Wire Wire Line
	2050 1750 1750 1750
Wire Wire Line
	1750 1650 2050 1650
Wire Wire Line
	2050 1550 1750 1550
Wire Wire Line
	1750 1450 2050 1450
$Comp
L Connector:Conn_01x20_Male J16
U 1 1 5F7F183A
P 6200 4150
F 0 "J16" H 6308 5231 50  0000 C CNN
F 1 "PINOUT conn 1" H 6308 5140 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 6200 4150 50  0001 C CNN
F 3 "~" H 6200 4150 50  0001 C CNN
	1    6200 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x20_Male J10
U 1 1 5F7F81D8
P 5400 4150
F 0 "J10" H 5508 5231 50  0000 C CNN
F 1 "PINOUT conn 2" H 5508 5140 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 5400 4150 50  0001 C CNN
F 3 "~" H 5400 4150 50  0001 C CNN
	1    5400 4150
	1    0    0    -1  
$EndComp
Text GLabel 6400 4750 2    50   Input ~ 0
DI2
Text GLabel 6400 4850 2    50   Input ~ 0
DI0
Text GLabel 6400 4950 2    50   Input ~ 0
Vcc
Text GLabel 6400 5050 2    50   Input ~ 0
GND
Text GLabel 5600 4750 2    50   Input ~ 0
DI3
Text GLabel 5600 4850 2    50   Input ~ 0
DI1
Text GLabel 5600 4950 2    50   Input ~ 0
Vcc
Text GLabel 5600 5050 2    50   Input ~ 0
GND
Text GLabel 5600 5150 2    50   Input ~ 0
5V+
Text GLabel 5600 4250 2    50   Input ~ 0
A2
Text GLabel 5600 4350 2    50   Input ~ 0
A0
Text GLabel 5600 4450 2    50   Input ~ 0
DI9
Text GLabel 5600 4550 2    50   Input ~ 0
DI7
Text GLabel 5600 4650 2    50   Input ~ 0
DI5
Text GLabel 6400 4250 2    50   Input ~ 0
A3
Text GLabel 6400 4350 2    50   Input ~ 0
A1
Text GLabel 6400 4450 2    50   Input ~ 0
DI8
Text GLabel 6400 4550 2    50   Input ~ 0
DI6
Text GLabel 6400 4650 2    50   Input ~ 0
DI4
Text GLabel 5600 4050 2    50   Input ~ 0
A5
Text GLabel 5600 4150 2    50   Input ~ 0
A4
Text GLabel 5600 3950 2    50   Input ~ 0
GND
Text GLabel 6400 4150 2    50   Input ~ 0
GND
Text GLabel 6400 5150 2    50   Input ~ 0
5V+
$Comp
L Connector:Conn_01x03_Female J11
U 1 1 5F85A37A
P 5600 5450
F 0 "J11" H 5628 5476 50  0000 L CNN
F 1 "PINOUT IR" H 5628 5385 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5600 5450 50  0001 C CNN
F 3 "~" H 5600 5450 50  0001 C CNN
	1    5600 5450
	1    0    0    -1  
$EndComp
Text GLabel 5400 5450 0    50   Input ~ 0
Vcc
Text GLabel 5400 5350 0    50   Input ~ 0
GND
Text GLabel 5400 5550 0    50   Input ~ 0
DI10
$Comp
L Connector:Conn_01x04_Female J15
U 1 1 5F6B820A
P 5750 2450
F 0 "J15" H 5778 2426 50  0000 L CNN
F 1 "GNDpair1" H 5778 2335 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5750 2450 50  0001 C CNN
F 3 "~" H 5750 2450 50  0001 C CNN
	1    5750 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Female J14
U 1 1 5F6B68B5
P 5750 1950
F 0 "J14" H 5778 1926 50  0000 L CNN
F 1 "GNDpair1" H 5778 1835 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5750 1950 50  0001 C CNN
F 3 "~" H 5750 1950 50  0001 C CNN
	1    5750 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F56AFE7
P 7750 1650
F 0 "R2" V 7957 1650 50  0000 C CNN
F 1 "3k3" V 7866 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7680 1650 50  0001 C CNN
F 3 "~" H 7750 1650 50  0001 C CNN
	1    7750 1650
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R12
U 1 1 5F53CC83
P 10250 950
F 0 "R12" V 10457 950 50  0000 C CNN
F 1 "3k3" V 10366 950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10180 950 50  0001 C CNN
F 3 "~" H 10250 950 50  0001 C CNN
	1    10250 950 
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 5F53A481
P 9000 950
F 0 "R7" V 9207 950 50  0000 C CNN
F 1 "3k3" V 9116 950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8930 950 50  0001 C CNN
F 3 "~" H 9000 950 50  0001 C CNN
	1    9000 950 
	0    -1   -1   0   
$EndComp
Text GLabel 6450 2550 0    50   Input ~ 0
D15
Text GLabel 6450 2650 0    50   Input ~ 0
D16
$Comp
L Connector:Conn_01x05_Male J23
U 1 1 5FE3D255
P 2350 4500
F 0 "J23" H 2458 4881 50  0000 C CNN
F 1 "INPUTS_Ard02" H 2458 4790 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 2350 4500 50  0001 C CNN
F 3 "~" H 2350 4500 50  0001 C CNN
	1    2350 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J21
U 1 1 5FE437E3
P 1750 4500
F 0 "J21" H 1858 4881 50  0000 C CNN
F 1 "INPUTS_Ard02_01" H 1858 4790 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 1750 4500 50  0001 C CNN
F 3 "~" H 1750 4500 50  0001 C CNN
	1    1750 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J24
U 1 1 5FE48F42
P 1750 3750
F 0 "J24" H 1858 3931 50  0000 C CNN
F 1 "DeanTInput_01" H 1858 3840 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1750 3750 50  0001 C CNN
F 3 "~" H 1750 3750 50  0001 C CNN
	1    1750 3750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J22
U 1 1 5FE35C9A
P 2350 3750
F 0 "J22" H 2458 3931 50  0000 C CNN
F 1 "12VOutput" H 2458 3840 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2350 3750 50  0001 C CNN
F 3 "~" H 2350 3750 50  0001 C CNN
	1    2350 3750
	1    0    0    -1  
$EndComp
Text GLabel 1950 4400 2    50   Input ~ 0
GND
Text GLabel 2550 4400 2    50   Input ~ 0
GND
Text GLabel 2550 4300 2    50   Input ~ 0
12V+
Text GLabel 1950 4300 2    50   Input ~ 0
12V+
Text GLabel 1950 3750 2    50   Input ~ 0
5V+
Text GLabel 2550 3750 2    50   Input ~ 0
12V+
Text GLabel 2550 3850 2    50   Input ~ 0
GND
Text GLabel 1950 3850 2    50   Input ~ 0
GND
Text GLabel 1950 4500 2    50   Input ~ 0
SDA1
Text GLabel 1950 4600 2    50   Input ~ 0
SCL1
Text GLabel 2550 4500 2    50   Input ~ 0
SDA1
Text GLabel 2550 4600 2    50   Input ~ 0
SCL1
$EndSCHEMATC
