# STM32-Real-Time-Embedded-System
Real-time embedded system using STM32F4 integrating ADC-DMA data acquisition, PWM control, UART monitoring and decision logic.
# STM32 Real-Time Embedded System

This project demonstrates the design and implementation of a real-time embedded system using an STM32F4 microcontroller. The system integrates ADC-based data acquisition, DMA for efficient data transfer, PWM control, UART communication, and a decision-making mechanism.

---

## 📌 Project Overview

The system continuously samples analog input using ADC with DMA. The sampled data is processed to compute an average value, which is used for decision-making. Based on the processed data, the system controls an LED or actuator using PWM and transmits real-time data via UART.

---

## ⚙️ Features

- ADC-based sensor data acquisition
- DMA for efficient data transfer
- PWM signal generation for control
- UART communication for monitoring
- Threshold-based decision mechanism
- Real-time system operation

---

## 🧰 Hardware Used

- STM32F4 Development Board
- Potentiometer (Analog Input - PA0)
- LED (PWM Output - PA5)
- 220Ω Resistor
- USB Cable

---

## 🔌 System Description

- ADC reads analog signal from potentiometer
- DMA transfers data into memory buffer
- Software processes data (average calculation)
- Decision logic checks threshold condition
- PWM adjusts LED brightness or actuator output
- UART transmits system data for monitoring

---

## 💻 Software Used

- STM32CubeIDE
- HAL (Hardware Abstraction Layer)

---

## 📁 Project Structure

---

## 🔁 System Operation

1. ADC samples input signal continuously  
2. DMA transfers samples to memory buffer  
3. Average value is calculated  
4. Decision logic compares with threshold  
5. PWM output is adjusted accordingly  
6. UART sends real-time data  

---

## 📊 Example Output

Average ADC Value: 1200  
Average ADC Value: 2500  
Average ADC Value: 3200  
WARNING: Threshold Exceeded  

---

## 📌 Decision Mechanism

If the processed data exceeds a predefined threshold:
- LED brightness increases (PWM)
- Warning message is sent via UART

---

## 📌 Conclusion

This project demonstrates how multiple STM32 peripherals can be integrated into a real-time embedded system. It highlights efficient data handling using DMA, control using PWM, and system monitoring via UART.
