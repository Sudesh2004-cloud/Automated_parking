# Automated_parking
🚗 Smart Car Parking System using Arduino
This project is a Smart Car Parking System developed as part of a college project. It is designed to automate and manage vehicle entry and exit using an Arduino-based system. The primary goal is to demonstrate an intelligent solution for parking space management using sensors and basic electronics.


🛠️ Technologies & Components Used
Arduino Uno

Ultrasonic Sensors (HC-SR04) – to detect vehicle presence

Servo Motor – for gate control

LEDs – to indicate status (optional)

LCD Display (optional) – to show number of available spots

Jumper wires, Breadboard, Power Supply.


⚙️ Features
Automatic gate opens/closes based on vehicle presence

Real-time vehicle count monitoring

Prevents overfilling of parking lot

Compact and energy efficient



🚀 Getting Started
Connect the circuit according to the schematic.

Upload CarParking.ino to your Arduino board using the Arduino IDE.

Power the board and observe the system behavior as vehicles approach and leave.

🔍 How It Works
An ultrasonic sensor detects the presence of a vehicle.

A servo motor opens the gate if space is available.

A counter keeps track of the number of cars inside.

If parking is full, the gate does not open and an LED or message can indicate "Full".



📈 Future Improvements
Integrate with IoT for remote monitoring

Add a mobile app interface

Display available slots in real-time

License plate recognition (using camera + ML)



🎓 Developed For :
This project was created as part of an academic curriculum to demonstrate embedded systems and automation principles.

🧑‍💻 Author :   Sudesh Tonpe
