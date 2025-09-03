# Monitor-Tanaman-ESP8266


=====================================================================
Program Smart Farming IoT dengan ESP8266
=====================================================================


Program ini digunakan untuk otomatisasi penyiraman tanaman dan 
penyemprotan pestisida berbasis IoT menggunakan ESP8266. 
Sistem membaca kelembaban tanah, mendeteksi hujan, serta 
mengukur suhu dan kelembaban udara dengan sensor DHT11. 
Kontrol dapat dilakukan secara otomatis maupun manual 
melalui tombol fisik dan aplikasi Blynk.

Konfigurasi Pin:
- D0 (GPIO16) : Output relay pompa air (pompaA).
- A0          : Input sensor kelembaban tanah.
- D1 & D2     : SDA & SCL untuk LCD I2C.
- D3 (GPIO0)  : Input sensor suhu & kelembaban DHT11.
- D4 (GPIO2)  : Input sensor hujan.
- D5 (GPIO14) : Output relay pompa pestisida (pompaB).
- D6 (GPIO12) : Input tombol manual penyiraman (pull-up).
- D7 (GPIO13) : Input tombol manual pestisida (pull-up).

Fitur Utama:
1. **Penyiraman Otomatis**  
   - Membaca kelembaban tanah dari sensor analog (A0).  
   - Jika nilai kelembaban < 500 → pompa air ON.  
   - Jika kelembaban cukup → pompa OFF.  

2. **Kontrol Manual**  
   - Tombol D6 → menyalakan/mematikan pompa air.  
   - Tombol D7 → menyalakan/mematikan pompa pestisida.  

3. **Sensor Hujan**  
   - Jika sensor mendeteksi hujan (LOW) → kirim notifikasi ke Blynk.  

4. **Monitoring Suhu & Kelembaban**  
   - Membaca data DHT11.  
   - Menampilkan suhu & kelembaban di LCD I2C.  
   - Mengirim data ke aplikasi Blynk (V0 = suhu, V1 = kelembaban).  

Tujuan:
- Membuat sistem pertanian pintar yang dapat bekerja otomatis 
  maupun manual.  
- Memberikan notifikasi kondisi lingkungan melalui IoT.  
- Menampilkan data sensor secara real-time di LCD dan aplikasi Blynk.  

