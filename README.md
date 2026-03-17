# Bluetooth-Car-Control-With-LPC2129-using-UART-Protocol

A wireless robotic car control system built with the **LPC2129 Microcontroller** and **HC-05 Bluetooth Module**, enabling smartphone control via UART communication.

## 📌 Overview

This project demonstrates a complete implementation of a Bluetooth-controlled robotic car using embedded C programming on the LPC2129 ARM microcontroller. The car receives wireless commands from an Android smartphone through the HC-05 Bluetooth module and translates them into motor control signals via the L293D Motor Driver IC.

### Key Technologies:
- **Microcontroller**: ARM LPC2129
- **Wireless Module**: HC-05 Bluetooth Module
- **Motor Driver**: L293D Dual Motor Driver IC
- **Communication Protocol**: UART (Universal Asynchronous Receiver Transmitter)
- **Programming Language**: C

## ✨ Project Features

- ✅ **Wireless Control**: Control the car via smartphone using Bluetooth connectivity
- ✅ **Real-time Motor Control**: Smooth directional control (Forward, Backward, Left, Right, Stop)
- ✅ **UART Communication**: Reliable serial communication at 9600 baud rate
- ✅ **Status Display**: LCD display for real-time system status
- ✅ **Modular Code**: Well-organized header files for easy maintenance
- ✅ **Low Power Design**: Optimized for battery-powered operation

## 🔧 Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| LPC2129 Microcontroller | 1 | Main processing unit |
| HC-05 Bluetooth Module | 1 | Wireless communication |
| L293D Motor Driver IC | 1 | Motor control/driving |
| DC Motors | 2 | Wheel propulsion |
| 16x2 LCD Display | 1 | Status indication |
| Power Supply (5V) | 1 | System power |
| Wheels & Chassis | 1 Set | Mechanical structure |
| Connecting Wires | As needed | Interconnections |
| Resistors & Capacitors | Various | Supporting components |

## 💻 Software Requirements

- **IDE**: Keil uVision / LPC-Link IDE
- **Compiler**: ARM C Compiler
- **UART Driver**: LPC2129 UART Library
- **Bluetooth App**: Android Bluetooth Controller App

### Development Tools:
- ARM JTAG Debugger or programmer
- Serial port terminal (for debugging)
- Smartphone with Bluetooth support

## 📂 Project Structure

```
Bluetooth-Car-Control-With-LPC2129-using-UART-Protocol/
├── main.c                  # Main application code
├── UART_header.h          # UART communication functions
├── delay_header.h         # Delay/timing functions
├── lcd.h                  # LCD display control functions
└── README.md              # This file
```

### File Descriptions:

| File | Description |
|------|-------------|
| `main.c` | Core application logic, motor control, and Bluetooth command processing |
| `UART_header.h` | Functions for UART initialization and data transmission/reception |
| `delay_header.h` | Timing functions for delays and synchronization |
| `lcd.h` | LCD initialization and display functions for status messages |

## 🔌 Circuit Diagram

### Block Diagram:
```
Smartphone (Bluetooth App)
        ↓
   HC-05 Module
        ↓
  LPC2129 MCU (UART)
        ↓
   L293D Driver
        ↓
   DC Motors
```

### Pin Connections:

**HC-05 to LPC2129:**
- HC-05 TX → LPC2129 RX (Pin 0.0)
- HC-05 RX → LPC2129 TX (Pin 0.1)
- HC-05 GND → LPC2129 GND
- HC-05 VCC → 5V

**L293D to LPC2129:**
- Motor1 Control Pins → LPC2129 GPIO Pins (P1.16, P1.17)
- Motor2 Control Pins → LPC2129 GPIO Pins (P1.18, P1.19)
- Enable Pins → PWM pins for speed control

**LCD to LPC2129:**
- See `lcd.h` for detailed pin configuration

## 🚀 Installation & Setup

### 1. Hardware Assembly:
- Assemble the robotic car chassis with motors
- Connect the LPC2129 development board
- Wire the HC-05 Bluetooth module (ensure proper voltage levels with resistors)
- Connect the L293D motor driver
- Attach the LCD display
- Connect the power supply

### 2. Software Setup:
```bash
# Clone or download this repository
git clone https://github.com/Yuvi2003-linux/Bluetooth-Car-Control-With-LPC2129-using-UART-Protocol.git

# Open the project in Keil uVision 4
# Configure the build settings for LPC2129
# Compile the project
# Flash the compiled binary to the LPC2129
```

### 3. Configure UART:
- Set UART baud rate to **9600 bps**
- Ensure proper RX/TX pin assignment in `UART_header.h`

### 4. Smartphone Setup:
- Install a Bluetooth terminal/controller app
- Search for "HC-05" device
- Pair with PIN: **1234** (default)
- Establish connection

## 📱 Usage

### Starting the System:
1. Power on the robotic car
2. Open the Bluetooth app on your smartphone
3. Search for available Bluetooth devices
4. Connect to "HC-05"
5. Send commands via the app interface

### Control Commands:
| Command | Action |
|---------|--------|
| `F` or `1` | Move Forward |
| `B` or `2` | Move Backward |
| `L` or `3` | Turn Left |
| `R` or `4` | Turn Right |
| `S` or `0` | Stop |

The LCD will display the current motor status and command received.

## 🔄 Control Protocol

The UART communication uses a simple character-based protocol:

- **Baud Rate**: 9600
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Flow Control**: None

### Command Structure:
```
Single Character Command + <CR/LF>
Example: 'F' (Forward), 'S' (Stop)
```

The microcontroller processes incoming commands and immediately updates motor states accordingly.

## 📍 Pinout Configuration

### LPC2129 UART Pins:
- **UART0 TX**: P0.1 (for TX)
- **UART0 RX**: P0.0 (for RX)

### Motor Control GPIO Pins:
- **Motor1 Forward**: P1.16
- **Motor1 Backward**: P1.17
- **Motor2 Forward**: P1.18
- **Motor2 Backward**: P1.19

Refer to `main.c` and header files for complete pinout details.

## 🔧 Troubleshooting

| Issue | Solution |
|-------|----------|
| Car not responding | Check Bluetooth connection, verify baud rate settings |
| Motors not moving | Verify motor driver connections, check power supply |
| HC-05 not pairing | Reset HC-05 module, check power supply voltage |
| Garbled LCD display | Verify LCD pin connections, check initialization sequence |
| UART communication failing | Check RX/TX pin connections, verify voltage levels |

### Debugging Tips:
- Use a serial terminal to monitor UART output
- Check power supply voltage for all components
- Verify that all connections are secure


## 🚀 Future Enhancements

- [ ] Add obstacle detection using ultrasonic sensors
- [ ] Implement variable speed control using PWM
- [ ] Add line-following capability with IR sensors
- [ ] Integrate temperature and battery monitoring
- [ ] Improve Bluetooth protocol with acknowledgment messages
- [ ] Add mobile app with GUI interface
- [ ] Implement autonomous mode with preset paths
- [ ] Add camera module for FPV (First Person View)





---

**Happy Coding! 🚗💻**

*Last Updated: 2026-03-17*
