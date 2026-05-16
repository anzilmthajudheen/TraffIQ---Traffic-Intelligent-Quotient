````markdown
# 🚦 Smart Traffic Management System with Emergency Vehicle Detection

An AI-powered Smart Traffic Management System using Python, OpenCV, and Arduino/ESP32 for real-time traffic density analysis and emergency vehicle prioritization.

---

# 📌 Project Overview

This project is designed to automate traffic signal management using Computer Vision and Embedded Systems.

The system captures live video using a webcam and divides the road into 3 lanes. It then calculates traffic density in each lane and automatically gives green signal priority to the lane with the highest traffic.

Additionally, the system detects emergency vehicles such as ambulances and immediately provides green signal priority for faster emergency response.

The project combines:
- OpenCV for Computer Vision
- Python for AI Logic
- Arduino/ESP32 for Signal Control
- Serial Communication for Hardware Integration

---

# ✨ Features

✅ Real-time Traffic Density Detection  
✅ Automatic Traffic Signal Switching  
✅ Emergency Vehicle Detection  
✅ Yellow Signal Transition Logic  
✅ Smart Traffic Management  
✅ Arduino/ESP32 Integration  
✅ Serial Communication using PySerial  
✅ Live Camera Processing  
✅ Safe Signal Switching Mechanism  
✅ AI-based Smart Traffic Control

---

# 🛠 Technologies Used

## Software
- Python
- OpenCV
- PySerial
- Arduino IDE

## Hardware
- Arduino / ESP32
- LEDs
- Webcam
- Breadboard
- Jumper Wires

---

# 📂 Project Structure

```bash
SmartTrafficManagement/
│
├── traffic.py               # Python OpenCV Code
├── traffic_signal.ino       # Arduino/ESP32 Code
├── README.md
└── assets/
```

---

# ⚙️ System Working

## 1️⃣ Traffic Density Detection

The webcam continuously captures live video frames.

The frame is divided into:
- Lane 1
- Lane 2
- Lane 3

The system processes each lane separately and calculates traffic density using:
- Grayscale Conversion
- Gaussian Blur
- Thresholding
- Pixel Counting

The lane with the highest traffic density gets green signal priority.

---

## 2️⃣ Emergency Vehicle Detection

The system detects emergency vehicles using bright white color detection.

If an ambulance/emergency vehicle is detected:
- Normal traffic logic is overridden
- The emergency lane immediately gets green signal
- Other lanes remain red

This helps reduce emergency response time.

---

## 3️⃣ Smart Signal Switching

The system prevents unsafe instant switching by:
- Adding Yellow Signal Transition
- Maintaining Minimum Green Time
- Avoiding Frequent Lane Changes

This ensures smoother and safer traffic flow.

---

# 🔌 Hardware Connections

# Lane 1 Connections

| Signal | GPIO Pin |
|--------|-----------|
| Red LED | 23 |
| Yellow LED | 22 |
| Green LED | 21 |

---

# Lane 2 Connections

| Signal | GPIO Pin |
|--------|-----------|
| Red LED | 19 |
| Yellow LED | 18 |
| Green LED | 5 |

---

# Lane 3 Connections

| Signal | GPIO Pin |
|--------|-----------|
| Red LED | 4 |
| Yellow LED | 2 |
| Green LED | 15 |

---

# 💻 Python Commands Sent to Arduino

| Command | Function |
|---------|-----------|
| L1 | Lane 1 Green |
| L2 | Lane 2 Green |
| L3 | Lane 3 Green |
| E1 | Emergency Lane 1 |
| E2 | Emergency Lane 2 |
| E3 | Emergency Lane 3 |

---

# ▶️ Installation Guide

# Step 1: Install Python Libraries

```bash
pip install opencv-python pyserial
```

---

# Step 2: Upload Arduino Code

1. Open Arduino IDE
2. Connect Arduino/ESP32
3. Select correct COM Port
4. Upload `traffic_signal.ino`

---

# Step 3: Configure COM Port

In Python code:

```python
ser = serial.Serial('COM7', 115200)
```

Replace `COM7` with your system COM port.

Example:
- COM3
- COM5
- COM8

---

# Step 4: Run Python Program

```bash
python traffic.py
```

---

# 🧠 Improvements Added in This Version

✅ Yellow Signal Logic  
✅ Safe Lane Transition  
✅ Reduced Signal Flickering  
✅ Minimum Green Time  
✅ Stable Emergency Handling  
✅ Improved Traffic Density Detection  
✅ Better Traffic Flow Management  
✅ Reduced Serial Communication Spam  

---

# 📸 Output

The system displays:
- Live Lane Monitoring
- Traffic Density Values
- Active Green Signal Lane
- Emergency Vehicle Alerts

---

# 🚀 Future Enhancements

This project can be further improved using:

- YOLOv8 Vehicle Detection
- AI Vehicle Counting
- Number Plate Recognition
- Firebase IoT Dashboard
- Cloud Monitoring
- Traffic Prediction using Machine Learning
- Smart City Integration
- Real Ambulance Siren Detection
- Mobile App Control

---

# 🎯 Applications

- Smart Cities
- Intelligent Transportation Systems
- Emergency Traffic Management
- AI-based Traffic Automation
- Urban Traffic Control

---

# 👨‍💻 Author

Anzil M Thajudheen

BTech Artificial Intelligence & Data Science

---

# 📜 License

This project is developed for educational and research purposes.

---

# ⭐ GitHub Repository Description

AI-powered Smart Traffic Management System using OpenCV and Arduino/ESP32 for real-time traffic density analysis and emergency vehicle prioritization.

---

# 🏷 GitHub Topics / Tags

```text
opencv
python
arduino
esp32
computer-vision
traffic-management
smart-traffic-system
ai
iot
emergency-vehicle-detection
traffic-light-control
smart-city
machine-learning
```
````
