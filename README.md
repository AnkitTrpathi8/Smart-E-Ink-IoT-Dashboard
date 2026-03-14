# Smart-E-Ink-IoT-Dashboard
# Smart E-Ink IoT Dashboard

A low-power wall mounted smart dashboard built using an ESP32 and an E-Ink display that shows real-time information like weather, calendar events, news, environmental data, and more.

This project built for the Stasis Hackathon by Hack Club.

---

## Project Overview

The Smart E-Ink IoT Dashboard is a low-power IoT information display designed to show useful daily information in a clean, paper-like interface.

Unlike traditional screens, E-Ink displays only consume power when refreshing the image. Because of this, the dashboard can run for weeks or even months on a single battery charge.

The device connects to Wi-Fi, retrieves data from various online APIs, processes the information locally using an ESP32 microcontroller, and displays the data on an E-Ink screen.

The goal of this project was to build a customizable smart information display that could be used in homes, offices, or workspaces.

---

## Features

### Real-Time Information Dashboard

The dashboard displays several types of information:

- Current weather
- Temperature and humidity
- Calendar events
- News headlines
- Smart home data
- Financial updates
- Quote of the day
- System status

---

### Weather Information

Weather data is fetched from an online weather API and displayed on the dashboard.

Displayed data includes:

- Current temperature
- Humidity
- Weather condition
- Weather icons

---

### Calendar Events

The dashboard can display upcoming events such as:

- Meetings
- Deadlines
- Reminders

This helps users quickly check their daily schedule.

---

### News Headlines

The device fetches technology and global news from RSS feeds and displays the latest headlines.

This allows users to quickly stay updated with current events.

---

### Environmental Monitoring

Using an environmental sensor, the dashboard can measure room conditions such as:

- Temperature
- Humidity
- Air pressure

This data is displayed in the smart home section of the dashboard.

---

### Motion Activated Updates

A PIR motion sensor detects when someone enters the room.

When motion is detected:

- The device wakes up
- The dashboard refreshes
- New information is displayed

This helps reduce unnecessary updates and saves battery power.

---

### Low Power Operation

The system uses deep sleep mode to conserve energy.

Typical behavior:

1. Device wakes up
2. Connects to Wi-Fi
3. Fetches data from APIs
4. Updates the E-Ink display
5. Enters deep sleep again

This allows the dashboard to run for weeks on a battery.

---
(https://github.com/AnkitTrpathi8/Smart-E-Ink-IoT-Dashboard/blob/main/circuit/Screenshot%202026-03-14%20173620.jpg)

## Hardware Used

| Component | Purpose |
|----------|---------|
ESP32 | Main microcontroller and Wi-Fi connectivity |
4.2" E-Ink Display | Low power display for dashboard |
BME280 Sensor | Temperature, humidity, pressure |
BH1750 Sensor | Ambient light sensor |
PIR Motion Sensor | Detects movement |
18650 Battery | Power supply |
TP4056 Charger | Battery charging module |
AMS1117 | Voltage regulator |
Push Buttons | Page navigation |

---

## System Architecture
