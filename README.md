🚀 Project Overview
Core Function: A motor-driven robot controlled via Serial commands with an integrated safety override system.
Obstacle Safety: Features an automatic "Emergency Stop" that triggers if the ultrasonic sensor detects an object within 5cm.
Audio Feedback: An active buzzer provides audible alerts for safety while reversing and as a confirmation for stopping.

🛠️ Hardware Connections
Motor Control (Pins 5, 6, 7, 8): Drives the H-Bridge motor controller for directional movement.
Ultrasonic Sensor (Pins 9, 10): Uses the HC-SR04 to measure distance via sound waves.
Buzzer (Pin 11): Connected to a digital output to signal movement changes.

🎮 Command Reference (9600 Baud)
'F' (Forward): Engages motors forward and activates the ultrasonic proximity check.
'B' (Backward): Reverses the motors and triggers a repeating pulse on the buzzer.
'L' (Left): Rotates the robot left while maintaining obstacle detection.
'R' (Right): Rotates the robot right while maintaining obstacle detection.
Other Keys: Triggers the stop() function, killing motor power and sounding a long confirmation beep.

⚙️ Technical Logic
Pulse Calculation: Converts the microsecond echo from the sensor into centimeters to determine proximity.
Serial Logic: Uses Serial.read() to parse incoming characters and execute the corresponding movement functions.
Development: Designed for the Arduino framework using VS Code for code management and deployment.
