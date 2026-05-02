## Overview

This project uses an Arduino and an I2C temperature sensor to measure temperature, calculate an average over time, and display the result on a 16x2 LCD. The system samples temperature data every second, computes a rolling average, and updates the display at regular intervals for stable readings.

---

## Features

- Reads temperature data from an I2C sensor
- Converts raw sensor data to Celsius and Fahrenheit
- Averages readings over time for stability
- Updates LCD display every 10 seconds
- Clears and refreshes display for readability

---

## Hardware

- Arduino Mega (Elegoo Mega R3)
- I2C temperature sensor
- 16x2 LCD display
- Breadboard and jumper wires

---

## Calibration & Validation

Temperature readings were validated against local surface measurements rather than a wall thermostat. Differences were observed due to sensor placement and environmental conditions. The sensor was confirmed to produce consistent and accurate readings relative to its immediate surroundings.

A calibration offset variable is included in the code to allow adjustment if needed based on environment.

---

## What I Learned

- Debugging I2C communication issues
- Interpreting raw sensor data and correcting byte order
- Soldering and improving joint quality
- Implementing timing logic using "millis()"
- Validating sensor accuracy in real-world conditions
