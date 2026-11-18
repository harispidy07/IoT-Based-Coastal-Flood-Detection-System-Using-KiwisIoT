# IoT-Based Coastal Flood Detection System Using KiwisIoT

## Project Overview

This project detects rising water levels in coastal areas using IoT technology. An ESP8266 NodeMCU collects water-level sensor data and sends the readings to the KiwisIoT platform for remote monitoring. The system helps identify potential flood conditions and provides early warnings to support coastal safety.

## Hardware Components

- ESP8266 NodeMCU
- Water Level Sensor
- Jumper Wires
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

Sensor connections depend on the hardware configuration used in the project.

## Working Principle

The water level sensor continuously monitors the surrounding water level and sends readings to the ESP8266 NodeMCU. The controller processes the data and transmits it to the KiwisIoT platform. When the water level reaches a predefined threshold, a flood warning can be generated through the monitoring system.

## KiwisIoT Dashboard

The dashboard displays water-level readings and flood status for remote monitoring.

| Data         | Description                   |
| ------------ | ----------------------------- |
| Water Level  | Measured water level          |
| Flood Status | NORMAL / WARNING              |
| Monitoring   | Real-time water-level updates |

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor coastal water levels through the KiwisIoT dashboard.

## Applications

- Coastal flood monitoring
- Early flood warning systems
- Water-level monitoring
- Coastal safety management
- Smart disaster management

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/iot-based-coastal-flood-detection-system-using-kiwisiot-e5756c](https://www.hackster.io/harispidy07/iot-based-coastal-flood-detection-system-using-kiwisiot-e5756c)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266, Water Level Sensor, and KiwisIoT for smart coastal flood monitoring._
