# drowsiness_control_sys_ADAS

I am proud to share that our project focused on developing ِADAS applications to enhance driver safety by implementing a Drowsiness Detection System that can control another ADAS application to force the car to park if the driver loses control of the vehicle.
Some of the ADAS we implemented:
1-Emergency brake.
2-Adaptive Cruise Control
3-Drowsiness Detection System

The Drowsiness Detection System can enable all exterior ADAS if the driver's drowsiness is detected at the same time until the driver returns to driving again.

If the drowsiness exists just for a while, the car sends a warning sound to the driver and moves to self-driving mode using adaptive cruise control, lane detection, lane keeping systems, etc.
If the driver doesn't respond and returns to driving the car, the car sends an emergency SOS and self-drive to emergency parking.

We built this project based on the layer architecture (App layer - RTE layer - ECU layer - MCAL) to achieve the SOLID principle.

Using a stm32f401ccu microcontroller based on an ARM cortex M4 (black pill kit).

Project video: https://lnkd.in/eqVn7fBx

read Software_Architecture.png and connection.png to gain more info about this project.

