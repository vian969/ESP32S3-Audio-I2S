# ESP32-S3 Audio I2S

Sistem pemutar audio menggunakan ESP32-S3 dengan file WAV yang tersimpan di SD Card. Audio dipilih melalui Serial Monitor dan diputar melalui speaker menggunakan komunikasi I2S.

## Alat dan Bahan

* ESP32-S3
* SD Card
* Speaker TR-WS 2014B
* Arduino IDE

## Library

ESP32-audioI2S: https://github.com/schreibfaul1/ESP32-audioI2S

## Cara Penggunaan

1. Unggah program ke ESP32-S3 melalui Arduino IDE.
2. Simpan file WAV di SD Card.
3. Buka Serial Monitor dengan baud rate 115200.
4. Masukkan angka 1–4 untuk memutar audio.

## Daftar Audio

* 1: Jam Pertama
* 2: Istirahat
* 3: Perhatikan
* 4: Pulang

