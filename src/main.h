#ifndef _MAIN_H_
#define _MAIN_H_

//PIN
#define LF 25
#define LB 26
#define RF 27
#define RB 14
#define DoorLock_Pin 23
#define SolarPanel_Pin 22

#define frequen 5000
#define res 8
char cmd;
char customKey;
int lockOutput = 13;
byte data_count = 0;

//Servo position
#define Unlock 300
#define Lock 150

//Row and column size
#define ROWS 4
#define COLS 4

//Represent keys on keypad
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

//Connections to Arduino
byte rowPins[ROWS] = {21, 19, 18, 5};
byte colPins[COLS] = {17, 16, 4};

#define Password_Length 7
char Data[Password_Length];
char Master[Password_Length] = "123456";

void clearData();

#endif