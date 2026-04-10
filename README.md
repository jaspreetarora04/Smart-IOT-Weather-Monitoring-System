# Smart IOT Weather Monitoring System

⚙️OVERVIEW 

This project is an intelligent IoT-based weather monitoring system built using ESP32 and environmental sensors such as DHT22 (temperature & humidity) and BMP280 (pressure). The system collects real-time environmental data and send it over WiFi to cloud platforms for monitoring and analysis.
Blynk IoT is used to create a live dashboard for real-time visualization and alerts, while ThingSpeak is used for storing data and analyzing trends through graphs. The circuit is validated using Wokwi simulation and designed using EasyEDA for real-world hardware implementation.

---

⚙️FEATURES
* 🌡️ Real-time monitoring of temperature, humidity, and pressure
* 📱 Live dashboard using Blynk IoT
* ☁️ Cloud data storage and visualization using ThingSpeak
* 🚨 Alert system for abnormal conditions (high temperature, humidity)
* 🧠 Basic decision logic (e.g., rain likelihood detection)
* ⚠️ Error handling for invalid sensor readings
* 🔌 Simulation using Wokwi
* 🛠️ Circuit design using EasyEDA
  
   ---

⚙️TECH STACK

* Microcontroller: ESP32
* Sensors:DHT22, BMP280, Rain Sensor
* IoT Platform: Blynk IoT,ThingSpeak
* Programming: Arduino IDE (Embedded C)
* Simulation: Wokwi
* Circuit Design: EasyEDA
  
  ---

⚙️SYSTEM WORKING
1. Sensors collect environmental data (temperature, humidity, pressure, rain).
2. ESP32 processes the data and applies basic decision logic.
3. Data is transmitted via WiFi to:
   * Blynk IoT → Real-time dashboard & alerts
   * ThingSpeak→ Data storage & graph visualization
4. Alerts are triggered when values exceed predefined thresholds.

   ---

⚙️SETUP INSTRUCTIONS

Before running the project, replace the following placeholders in the code:

* `BLYNK_TEMPLATE_ID`
* `BLYNK_AUTH_TOKEN`
* WiFi credentials (`SSID`, `Password`)
* ThingSpeak API Key
  
 ⚠️ Note: Sensitive information is not included in this repository for security reasons.
 
 ---

📊 RESULTS
 📱 Blynk Dashboard
![Blynk Dashboard](results/blynk_dashboard.png)

 ☁️ ThingSpeak Graph
[ThingSpeak Graph](results/thingspeak_output.png)
[live graph simulation](https://thingspeak.mathworks.com/channels/3336590)

 🧪 Wokwi Simulation
 [Simulation](simulation/Wowki_Simulation.png)
[Live Wokwi Simulation](https://wokwi.com/projects/460585295453155329)

---

🔮 FUTURE SCOPE

* AI/ML-based weather prediction
* Mobile app enhancement
* Integration with smart agriculture systems
* Additional sensors (air quality, wind speed)
  
  ---

 Author

* Jaspreet
* B.Tech ECE (Final Year)

---

