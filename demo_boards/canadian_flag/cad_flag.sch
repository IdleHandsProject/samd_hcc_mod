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
LIBS:ws2812b
LIBS:mcp73831t
LIBS:mpu-9250
LIBS:acs712
LIBS:adxl345
LIBS:arduino
LIBS:samd_hcc_mod
LIBS:cad_flag-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "ARDUINO HCC MOD"
Date "2018-06-24"
Rev "0.1p"
Comp "Idle Hands Dev."
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR01
U 1 1 5AF559B5
P 5100 2650
F 0 "#PWR01" H 5100 2400 50  0001 C CNN
F 1 "GND" H 5100 2500 50  0000 C CNN
F 2 "" H 5100 2650 60  0000 C CNN
F 3 "" H 5100 2650 60  0000 C CNN
	1    5100 2650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5100 2550 5000 2550
Wire Wire Line
	5000 2250 5850 2250
Wire Wire Line
	5000 1950 5000 2150
$Comp
L +BATT #PWR02
U 1 1 5AF5A22E
P 5000 1950
F 0 "#PWR02" H 5000 1800 50  0001 C CNN
F 1 "+BATT" H 5000 2090 50  0000 C CNN
F 2 "" H 5000 1950 50  0001 C CNN
F 3 "" H 5000 1950 50  0001 C CNN
	1    5000 1950
	-1   0    0    -1  
$EndComp
Text GLabel 3150 3100 0    39   Input ~ 0
RESET
Text GLabel 3150 4100 0    39   Input ~ 0
A0/DAC
Text GLabel 3150 4200 0    39   Input ~ 0
A1
Text GLabel 3150 4300 0    39   Input ~ 0
A2
Text GLabel 3150 4400 0    39   Input ~ 0
A3
Text GLabel 3150 4500 0    39   Input ~ 0
A4
Text GLabel 4250 4650 2    39   Input ~ 0
RX/D0
Text GLabel 4250 4550 2    39   Input ~ 0
TX/D1
Text GLabel 4250 4350 2    39   Input ~ 0
D3
Text GLabel 4250 4250 2    39   Input ~ 0
D4
$Comp
L GND #PWR03
U 1 1 5AF924A7
P 3050 3250
F 0 "#PWR03" H 3050 3000 50  0001 C CNN
F 1 "GND" H 3050 3100 50  0000 C CNN
F 2 "" H 3050 3250 60  0000 C CNN
F 3 "" H 3050 3250 60  0000 C CNN
	1    3050 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2900 3100 2900
Wire Wire Line
	3100 2900 3100 2700
$Comp
L +3.3V #PWR04
U 1 1 5AF9B481
P 3100 2700
F 0 "#PWR04" H 3100 2550 50  0001 C CNN
F 1 "+3.3V" H 3100 2840 50  0000 C CNN
F 2 "" H 3100 2700 60  0000 C CNN
F 3 "" H 3100 2700 60  0000 C CNN
	1    3100 2700
	1    0    0    -1  
$EndComp
Text GLabel 3150 4600 0    39   Input ~ 0
A5
Text GLabel 3150 3600 0    39   Input ~ 0
CLK
Text GLabel 3150 3500 0    39   Input ~ 0
MOSI
Text GLabel 3150 3700 0    39   Input ~ 0
MISO
Text GLabel 4250 2950 2    39   Input ~ 0
SCL
Text GLabel 4250 4150 2    39   Input ~ 0
D5
Text GLabel 4250 4050 2    39   Input ~ 0
D6
Text GLabel 4250 3700 2    39   Input ~ 0
D9
Text GLabel 4250 3600 2    39   Input ~ 0
D10
Text GLabel 4250 3500 2    39   Input ~ 0
D11
Text GLabel 4250 3400 2    39   Input ~ 0
D12
Text GLabel 4250 3300 2    39   Input ~ 0
D13
Text GLabel 4250 3050 2    39   Input ~ 0
SDA
$Comp
L SAMD21_MOD U1
U 1 1 5B2FBA82
P 3700 3850
F 0 "U1" V 3600 2650 60  0000 C CNN
F 1 "SAMD21_MOD" H 3700 5000 60  0000 C CNN
F 2 "idlehands_libs:SAMD_HCC_G_FOOT" H 3700 3850 60  0001 C CNN
F 3 "" H 3700 3850 60  0001 C CNN
	1    3700 3850
	1    0    0    -1  
$EndComp
Text GLabel 3150 3000 0    39   Input ~ 0
AREF
Wire Wire Line
	3050 3250 3050 3200
Wire Wire Line
	3050 3200 3150 3200
Wire Wire Line
	5100 2650 5100 2550
$Comp
L USB_B J2
U 1 1 5B2FB672
P 6150 2400
F 0 "J2" H 5950 2850 50  0000 L CNN
F 1 "USB_B" H 5950 2750 50  0000 L CNN
F 2 "Connectors_USB:USB_Micro-B_Molex-105017-0001" H 6300 2350 50  0001 C CNN
F 3 "" H 6300 2350 50  0001 C CNN
	1    6150 2400
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5000 2350 5400 2350
Wire Wire Line
	5400 2350 5400 2500
Wire Wire Line
	5400 2500 5850 2500
Wire Wire Line
	5000 2450 5650 2450
Wire Wire Line
	5650 2450 5650 2400
Wire Wire Line
	5650 2400 5850 2400
Wire Wire Line
	5850 2250 5850 2200
Wire Wire Line
	6150 2800 6150 2950
$Comp
L GND #PWR05
U 1 1 5B2FB8F1
P 6150 2950
F 0 "#PWR05" H 6150 2700 50  0001 C CNN
F 1 "GND" H 6150 2800 50  0000 C CNN
F 2 "" H 6150 2950 60  0000 C CNN
F 3 "" H 6150 2950 60  0000 C CNN
	1    6150 2950
	-1   0    0    -1  
$EndComp
Text Notes 3200 1400 0    60   ~ 0
Battery and VBUS isolated by HCC Mod.
Text GLabel 7750 5050 2    39   Input ~ 0
RX/D0
Text GLabel 7750 4950 2    39   Input ~ 0
TX/D1
Text GLabel 5850 5350 0    39   Input ~ 0
D3
Text GLabel 5850 5250 0    39   Input ~ 0
D4
Text GLabel 5850 5150 0    39   Input ~ 0
D5
Text GLabel 5850 5050 0    39   Input ~ 0
D6
Text GLabel 7750 4850 2    39   Input ~ 0
D9
Text GLabel 7750 4750 2    39   Input ~ 0
D10
Text GLabel 7750 4650 2    39   Input ~ 0
D11
Text GLabel 7750 4550 2    39   Input ~ 0
D12
Text GLabel 7750 4450 2    39   Input ~ 0
D13
Text GLabel 5850 4950 0    39   Input ~ 0
MOSI
Text GLabel 5850 4850 0    39   Input ~ 0
CLK
Text GLabel 5850 4750 0    39   Input ~ 0
MISO
$Comp
L +3.3V #PWR06
U 1 1 5B2FC31B
P 5750 4350
F 0 "#PWR06" H 5750 4200 50  0001 C CNN
F 1 "+3.3V" H 5750 4490 50  0000 C CNN
F 2 "" H 5750 4350 60  0000 C CNN
F 3 "" H 5750 4350 60  0000 C CNN
	1    5750 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5B2FC332
P 5650 5550
F 0 "#PWR07" H 5650 5300 50  0001 C CNN
F 1 "GND" H 5650 5400 50  0000 C CNN
F 2 "" H 5650 5550 60  0000 C CNN
F 3 "" H 5650 5550 60  0000 C CNN
	1    5650 5550
	1    0    0    -1  
$EndComp
Text GLabel 7750 5150 2    39   Input ~ 0
A0/DAC
Text GLabel 7750 5250 2    39   Input ~ 0
A1
Text GLabel 7750 5350 2    39   Input ~ 0
A2
Text GLabel 7750 5450 2    39   Input ~ 0
A3
Text GLabel 7750 5550 2    39   Input ~ 0
A4
Text GLabel 5850 5450 0    39   Input ~ 0
A5
Text GLabel 5850 4650 0    39   Input ~ 0
SDA
Text GLabel 5850 4550 0    39   Input ~ 0
SCL
$Comp
L Conn_01x12 J1
U 1 1 5B39013E
P 6050 4950
F 0 "J1" H 6050 5550 50  0000 C CNN
F 1 "Conn_01x12" H 6050 4250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12_Pitch2.54mm" H 6050 4950 50  0001 C CNN
F 3 "" H 6050 4950 50  0001 C CNN
	1    6050 4950
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x12 J3
U 1 1 5B3901FF
P 7550 5050
F 0 "J3" H 7550 5650 50  0000 C CNN
F 1 "Conn_01x12" H 7550 4350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x12_Pitch2.54mm" H 7550 5050 50  0001 C CNN
F 3 "" H 7550 5050 50  0001 C CNN
	1    7550 5050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5850 5550 5650 5550
Wire Wire Line
	5850 4450 5750 4450
Wire Wire Line
	5750 4450 5750 4350
$EndSCHEMATC
