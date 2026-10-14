# Mini-Projects
Mini Projects Utilizing Microcontrollers and Sensors to Solve Specific Problems in lives
<div align="center">

#  Embedded Systems & Mechatronics Mini-Projects
### Modular Hardware Interfacing, Signal Debouncing & Actuator Control on Arduino Uno

[![Platform: Arduino Uno](https://img.shields.io/badge/Platform-Arduino%20Uno-00979D.svg?logo=arduino)](https://www.arduino.cc/)
[![Language: C/C++](https://img.shields.io/badge/Language-Embedded%20C%2FC%2B%2B-00599C.svg)](https://isocpp.org/)
[![Course: Pioneer Academics](https://img.shields.io/badge/Program-Pioneer%20Academics-purple.svg)]()
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

**Author:** Jingkun Li (Jarred)  
**Advisor:** Prof. Carlotta Berry, Ph.D.  
*Introduction to Electronics, Microcontrollers, and Robotics (Summer 2026)*

</div>

---

##  Overview

This repository contains a progressive series of three embedded systems and mechatronics mini-projects developed on the **Arduino Uno (ATmega328P)** platform. Designed as a modular engineering progression, these labs advance from **multi-channel GPIO array sequencing (Project 1)**, to **asynchronous mechanical switch debouncing and serial display interfacing (Project 2)**, and finally to **closed-loop mechatronic servo actuation (Project 3)**.

Together, these modules established the hardware interfacing and non-blocking timing foundations for the final **[CaneVision Smart Assistive Cane](https://github.com/Jarredli/CaneVision_Smart_White_Cane_for_the_Visually_Impaired)** research project.

---

##  Repository Structure

```text
Embedded-Mechatronics-MiniProjects/
├── MiniProject_1_LED_Chaser/
│   └── MiniProject_1_LED_Chaser.ino       # 8-Channel Active-Low GPIO Array Sequencer
├── MiniProject_2_Quiz_Buzzer_V1/
│   └── MiniProject_2_Quiz_Buzzer_V1.ino   # Debounced Quiz Buzzer & 7-Segment Timer (V1)
├── MiniProject_3_Quiz_Buzzer_V2/
│   └── MiniProject_3_Quiz_Buzzer_V2.ino   # Mechatronic Buzzer with PWM Servo Arm (V2)
└── README.md                              # Documentation & Hardware Specifications
