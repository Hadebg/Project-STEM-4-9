#include <Arduino.h>
#include <BluetoothSerial.h>
#include <esp32_motor.h>
#include <main.h>
#include <ESP32Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DCMotor.h>

BluetoothSerial BluetoothController;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, 16, 2);
//esp32_motor leftMotor(LF, LB, 1, 2, frequen, res);
//esp32_motor rightMotor(RF, RB, 3, 4, frequen, res);
DCMotor leftMotor(LF, LB, ENA);
DCMotor rightMotor(RF, RB, ENB);
Servo DoorLocker;

void setup(){
  Serial.begin(9600);
  BluetoothController.begin("Goods Shipping Robot - ESP32");
  DoorLocker.attach(DoorLock_Pin);
  lcd.backlight();
  lcd.init();
}

void loop(){
   if (BluetoothController.available()) {
    lcd.setCursor(0, 0);
    lcd.print("Nhap mat khau:");
    cmd = BluetoothController.read();
    customKey = customKeypad.getKey();
    switch(cmd){
    //Movement
      case 'F':  
        leftMotor.Run(230);
        rightMotor.Run(230);
        break;
      case 'B':  
        leftMotor.Run(-230);
        rightMotor.Run(-230);
        break;
      case 'R':  
        leftMotor.Run(230);
        rightMotor.Run(-230);
        break;
      case 'L':
        leftMotor.Run(-230);
        rightMotor.Run(230);
        break;
      case 'I':
        leftMotor.Run(230);
        rightMotor.Run(140);
        break;
      case 'G':
        leftMotor.Run(140);
        rightMotor.Run(230);
        break;
      case 'J':
        leftMotor.Run(-230);
        rightMotor.Run(-100);
        break;
      case 'H':
        leftMotor.Run(-100);
        rightMotor.Run(-230);
        break;
      case 'S':
        leftMotor.Run(0);
        rightMotor.Run(0);
        break;
    }

  if (customKey){ //Get key from keypad
    Data[data_count] = customKey;
    data_count++;
    Serial.println(customKey);
    lcd.setCursor(data_count, 1);
    lcd.print(customKey);
    delay(300); //Prevent continuous press
  }
  //Check password
  if (data_count == Password_Length - 1){
    lcd.clear();
    if (!strcmp(Data, Master)){
      Serial.println("Password is correct!");
      lcd.print("Da mo khoa!");
      DoorLocker.write(Unlock);
      delay(10000); //Wait 10 seconds before locking the door
      DoorLocker.write(Lock);
    }
    else {
      Serial.println("Password is incorrect!");
      lcd.print("Sai! Thu lai");
      delay(3000);
    }
    lcd.clear();
    clearData();
  }
 }
}

void clearData() {
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
}
