#include <Arduino.h>
class DCMotor
{
private:
    /* data */
public:
    uint8_t forward, backward, enable;
    DCMotor(int8_t forward_pin, int8_t backward_pin, int8_t enable_pin);
    void Run(int PWM);
};