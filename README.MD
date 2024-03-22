# AERODIS SPACE AIRCRAFT CONTROLLER

# Overview
This project outlines the integration of embedded systems for the Aerodis Space platform, focusing on utilizing RP2040 and ESP32 microcontrollers. The RP2040 is designated for the aircraft, managing radio communications, servo motors, electronic speed controllers (ESC) for brushless DC motors (BLDC), and various sensors. Conversely, the ESP32 acts as the control unit, interfacing with our application through Bluetooth BLE for configuration and control, and managing radio module communication to relay commands to the aircraft.

## Microcontroller Roles
### RP2040 - Aircraft Controller

- Functionality: Manages aircraft operations including motor control through ESCs, reading from various sensors, and handling radio communications for command and telemetry data.
Components:

- Radio Module: For receiving commands and sending telemetry data.

- Servo Motors: To control aircraft movement.

- ESC + BLDC Motors: For propelling the aircraft.

- Sensors: Integration of multiple sensors for real-time data collection.

### ESP32 - Ground Control Unit

- Functionality: Serves as the interface between the user and the aircraft. It connects to the application via Bluetooth BLE for configuration and directly to a gamepad for manual control. The ESP32 reads gamepad inputs, converts them into control commands, and transmits these commands to the aircraft via a radio module.
Components:

- Bluetooth Module: For app connectivity and gamepad interaction.

- Radio Module: Communicates with the aircraft, placed on standard pins as per documentation.

- Configuration Capabilities: Allows for the configuration of motor and sensor pins and setting Wi-Fi credentials through the app.
## System Setup and Configuration
### ESP32 Setup

- Bluetooth Pairing: Connect the ESP32 to the application via Bluetooth for initial setup.

- Gamepad Connection: Pair a Bluetooth gamepad with the ESP32.

- Configuration: Use the app to configure motor and sensor pins on the RP2040, and set Wi-Fi credentials for the ESP32.

- Radio Module Connection: Ensure the radio module is connected to the ESP32 on the specified pins.

### RP2040 Setup

- Sensor and Motor Connection: Attach sensors and motors to the designated pins as configured through the ESP32.

- Radio Module Installation: Install the radio module for communication with the ESP32.
Operation Flow

- Start: Power up both the ESP32 and RP2040 units.

- Control: Use the connected gamepad to send control commands. The ESP32 reads these inputs, converts them to radio packets, and transmits them to the RP2040.

- Flight: The RP2040 receives commands, controls motors and servos accordingly, and sends sensor data back to the ESP32.

- Monitoring: Use the app connected to the ESP32 via Bluetooth for real-time monitoring and adjustments.
Safety and Precautions
Ensure all connections and configurations are tested thoroughly before flight.
Follow all safety guidelines for BLDC motors and LiPo battery handling.
Keep a safe distance during test flights and adhere to local regulations.
Development and Contribution
The project is open for development and contributions. Developers are encouraged to contribute to the codebase, suggest new features, or improve existing functionalities.
For contribution guidelines, please refer to the CONTRIBUTING.md file.