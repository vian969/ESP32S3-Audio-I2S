# ESP32-S3 Audio I2S

Proyek ini menggunakan ESP32-S3 untuk memutar file audio WAV dari kartu SD melalui I2S. Pemutaran audio dikendalikan melalui Serial Monitor.

## File Audio

* `JamPertama.wav`
* `Istirahat.wav`
* `Perhatikan.wav`
* `Pulang.wav`

## Instalasi

1. Download proyek melalui **Code → Download ZIP**.
2. Ekstrak file ZIP.
3. Instal library ESP32-audioI2S.
4. Buka `esp32s3-audioi2s.ino` di Arduino IDE.
5. Siapkan kartu SD berisi file audio sesuai program.
6. Pilih board **ESP32S3 Dev Module**, lalu upload program.

## Cara Menggunakan

Buka Serial Monitor dengan baud rate **115200**, kemudian kirim perintah:

* `1` — Jam pertama
* `2` — Istirahat
* `3` — Perhatikan
* `4` — Pulang

## Library

ESP32-audioI2S: https://github.com/schreibfaul1/ESP32-audioI2S
