#include <DCMotor.h>

DCMotor::DCMotor(int8_t forward_pin, int8_t backward_pin, int8_t enable_pin) {
    pinMode(forward_pin, OUTPUT);
    pinMode(backward_pin, OUTPUT);
    pinMode(enable_pin, OUTPUT);
    forward = forward_pin;
    backward = backward_pin;
    enable = enable_pin;
}

void DCMotor::Run(int PWM) {
    analogWrite(enable, (PWM>0)?(PWM):(0));
    analogWrite(enable, (PWM>0)?(0):(-PWM));
    if(PWM>0){
        digitalWrite(forward, HIGH);
        digitalWrite(backward, LOW);
    }
    else if(PWM<0){
        digitalWrite(forward, LOW);
        digitalWrite(backward, HIGH);
    }
    else{
        digitalWrite(forward, LOW);
        digitalWrite(backward, LOW);
    }
}