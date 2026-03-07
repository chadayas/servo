# Servo Config
Running ESP32 Devkit-C as the brain for controlling the servo, since I've gotten acustom to 
using the ESP-IDF toolchain. esp-idf places config data in structs, in this particular instance we 
had to access the `servo_config_t` struct, which is seen in the code
# Control
Hooked up power from 5V wall adapter with a barrell jack tip. Move the servo using 
PWM signals from the IO pin 14 using the left and right arrow keys.

# Just testing
Obviously with just servos the project doesn't amount to much, this is an addition to the esp cam
repo in which the cam will be mounted onto the servo. Code is short and can be used to power your 
servo using the esp-idf on a esp32 (change the `GPIO_PIN_NUM` selection to your desired GPIO pin
on your ESP mcu).

# Vid
![Breathalyzer demo](servo.gif)
