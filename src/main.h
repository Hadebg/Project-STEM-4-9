#ifndef _MAIN_H_
#define _MAIN_H_

//PIN
#define LF 25
#define LB 26
#define RF 27
#define RB 14
#define ENA 32
#define ENB 33
#define DoorLock_Pin 23

#define frequen 5000
#define res 8
char cmd;
char customKey;
int Convert;
byte data_count = 0;

//Servo position
#define Unlock 800
#define Lock 150

//Row and column size
#define ROWS 4
#define COLS 4

//Represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

//Connections to Arduino
byte rowPins[ROWS] = {19, 18, 5, 17};
byte colPins[COLS] = {16, 4, 2, 15};

#define Password_Length 9
char Data[Password_Length];
char Master[Password_Length] = "14B22222";

void clearData();

#endif
