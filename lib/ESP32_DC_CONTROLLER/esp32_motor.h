#include <Arduino.h>
class esp32_motor
{
private:
    /* data */
public:
    uint8_t forward, backward, channel;
    esp32_motor(int8_t forward_pin, int8_t backward_pin, int8_t channel_number, int8_t channel_number_backward, uint pwm_frequency, uint8_t resolution);
    void Run(int PWM);
};