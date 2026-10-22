# 🌡️ Digital Environmental Monitor (DHT11 & I2C LCD)

A 2nd-year ECE embedded systems project featuring a real-time environmental monitoring system built using an Arduino Uno, a DHT11 temperature and humidity sensor module, and a 16x2 I2C LCD display.

## 📌 Key Features
- **Single-Bus Digital Protocol:** Reads ambient temperature and relative humidity telemetry over a single digital data line using custom timing protocols.
- **Dual Temperature Display:** Simultaneously calculates and displays temperature in both Celsius (°C) and Fahrenheit (°F).
- **Real-Time Telemetry:** Continuous sampling at 0.5 Hz (every 2 seconds) with custom error handling for sensor communication failures.

## 🔌 Circuit Pinout

| Component | Pin Label | Arduino Uno Pin | Function / Notes |
| :--- | :--- | :--- | :--- |
| **I2C LCD** | VCC / GND | **5V / GND** | Display Power |
| **I2C LCD** | SDA / SCL | **A4 / A5** | I2C Communication Line (`0x27`) |
| **DHT11 Sensor** | **G** | **GND** | Ground |
| **DHT11 Sensor** | **V** | **5V** | Sensor Power (5V) |
| **DHT11 Sensor** | **D** | **Digital Pin 2** | Single-Bus Data Signal |

## 🛠️ Software & Libraries Required
- **Arduino IDE**
- **LiquidCrystal_I2C** Library
- **DHT sensor library** (by Adafruit)
- **Adafruit Unified Sensor** (Dependency)

## 📁 Repository Structure
```text
Environmental_Monitor/
├── Environmental_Monitor.ino   # Main Arduino C++ application code
└── README.md                   # Technical project documentation
