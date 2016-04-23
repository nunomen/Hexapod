#ifndef ROBOT_CONSTANTS_H
#define ROBOT_CONSTANTS_H
#include <stdint.h>


namespace configs
{
    // Digital pins assigned to each servo of the robot.
    const uint8_t c_shoulder_pins[] = { 44, 34, 42, 36, 40, 38 };
    const uint8_t c_elbow_pins[] = { 48, 30, 43, 37, 46, 32 };
    const uint8_t c_foot_pins[] = { 52, 26, 41, 39, 50, 28 };

    // Calibration of servo motor offsets.
    const int8_t c_shoulder_offsets[] = { 0, 0, 0, 0, 0, 0 };
    const int8_t c_elbow_offsets[] = { -5, 5, -5, -5, 0, 0 };
    const int8_t c_foot_offsets[] = { 0, 0, 0, 15, 0, 0 };

    // Assigning origin angles for the servo motors.
    const uint8_t c_shoulder_home(90);
    const uint8_t c_elbow_home(100);
    const uint8_t c_foot_home(120);

    // Digital pins assigned to the relay.
    const uint8_t c_ground(7);
    const uint8_t c_vcc(5);
    const uint8_t c_relay_pin(6);

    // Change this constant to true if relay is supposed to be activated.
    const bool c_relay(false);
}

#endif
