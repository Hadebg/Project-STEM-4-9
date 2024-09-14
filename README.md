# Goods shipping robot (Project to display at NGT's opening ceremony of the new school year)
Coding date: 2/9/2024 - 3/9/2024 (DD/MM/YY) 

Requirement:
- ESP32 DOIT DEVKIT V1
- 2 or 4 DC motor engines
- LCD 16x2 I2C (0x27)
- Matrix keypad (4x4)
- Module H-bridge L298N
- Application: Bluetooth RC controller (download APK)
- 12V battery

Connection: 
- Connect 12V battery to 12V input in module H-bridge, connect 5V output from module H-bridge to ESP32 through VIN pin and GND pin
- LCD 16x2 I2C (5V): SCL -> 22, SDA -> 21
- Module H-bridge: IN1 -> 25, IN2 -> 26, IN3 -> 27, IN4 -> 14, ENA -> 32, ENB -> 33
- Matrix keypad 4x4: R1 -> 19, R2 -> 18, R3 -> 5, R4 -> TX2 (17), C1 -> RX2 (16), C2 -> 4, C3 -> 2, C4 -> 15
- DC Motor engines: Connect to the DC motor output in module H-bridge

Library used: BluetoothSerial, ESP32Servo, Keypad, LiquuidCrystal I2C, DCmotor (I wrote myself for L298N using analog, check lib)

IDE: PlatformIO in Visual Studio Code

Language showing on LCD screen is Vietnamese
