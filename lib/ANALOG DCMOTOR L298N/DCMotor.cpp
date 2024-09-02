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
    if(PWM>0){
        digitalWrite(forward, HIGH);
        digitalWrite(backward, LOW);
        analogWrite(enable, PWM);
    }
    else if(PWM<0){
        digitalWrite(forward, LOW);
        digitalWrite(backward, HIGH);
        analogWrite(enable, -PWM);
    }
    else{
        digitalWrite(forward, LOW);
        digitalWrite(backward, LOW);
        analogWrite(enable, 0);
    }
}
