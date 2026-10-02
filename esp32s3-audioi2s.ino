#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include "Audio.h"

#define I2S_BCLK 45
#define I2S_LRC  46
#define I2S_DOUT 42

#define SD_CS   10
#define SD_MOSI 11
#define SD_MISO 13
#define SD_SCK  12

Audio audio;

void audio_info(const char *info) {
  Serial.print("AUDIO: ");
  Serial.println(info);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("ESP32-S3 AUDIO WAV PLAYER");

  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  if (!SD.begin(SD_CS, SPI)) {
    Serial.println("SD Card gagal!");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("SD Card berhasil!");

  Serial.println();
  Serial.println("Cek file audio:");

  if (SD.exists("/JamPertama.wav")) {
    Serial.println("[OK] JamPertama.wav");
  } else {
    Serial.println("[ERROR] JamPertama.wav tidak ditemukan!");
  }

  if (SD.exists("/Istirahat.wav")) {
    Serial.println("[OK] Istirahat.wav");
  } else {
    Serial.println("[ERROR] Istirahat.wav tidak ditemukan!");
  }

  if (SD.exists("/Perhatikan.wav")) {
    Serial.println("[OK] Perhatikan.wav");
  } else {
    Serial.println("[ERROR] Perhatikan.wav tidak ditemukan!");
  }

  if (SD.exists("/Pulang.wav")) {
    Serial.println("[OK] Pulang.wav");
  } else {
    Serial.println("[ERROR] Pulang.wav tidak ditemukan!");
  }

  Serial.println();
  Serial.println("Inisialisasi I2S...");

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(21);

  Serial.println("I2S siap.");
  Serial.println();
  Serial.println("Sistem audio siap.");
  Serial.println("Ketik:");
  Serial.println("1 = Jam pertama");
  Serial.println("2 = Istirahat");
  Serial.println("3 = Perhatikan");
  Serial.println("4 = Pulang");
}

void loop() {
  audio.loop();

  if (Serial.available()) {
    char input = Serial.read();

    if (input == '\n' || input == '\r') {
      return;
    }

    if (input == '1') {
      Serial.println();
      Serial.println("Memutar: Jam pertama akan dimulai");

      if (SD.exists("/JamPertama.wav")) {
        if (audio.connecttoFS(SD, "/JamPertama.wav")) {
          Serial.println("File JamPertama.wav berhasil dibuka.");
        } else {
          Serial.println("GAGAL membuka JamPertama.wav!");
        }
      } else {
        Serial.println("File JamPertama.wav tidak ditemukan!");
      }
    }

    else if (input == '2') {
      Serial.println();
      Serial.println("Memutar: Waktunya istirahat");

      if (SD.exists("/Istirahat.wav")) {
        if (audio.connecttoFS(SD, "/Istirahat.wav")) {
          Serial.println("File Istirahat.wav berhasil dibuka.");
        } else {
          Serial.println("GAGAL membuka Istirahat.wav!");
        }
      } else {
        Serial.println("File Istirahat.wav tidak ditemukan!");
      }
    }

    else if (input == '3') {
      Serial.println();
      Serial.println("Memutar: Perhatikan");

      if (SD.exists("/Perhatikan.wav")) {
        if (audio.connecttoFS(SD, "/Perhatikan.wav")) {
          Serial.println("File Perhatikan.wav berhasil dibuka.");
        } else {
          Serial.println("GAGAL membuka Perhatikan.wav!");
        }
      } else {
        Serial.println("File Perhatikan.wav tidak ditemukan!");
      }
    }

    else if (input == '4') {
      Serial.println();
      Serial.println("Memutar: Waktunya pulang");

      if (SD.exists("/Pulang.wav")) {
        if (audio.connecttoFS(SD, "/Pulang.wav")) {
          Serial.println("File Pulang.wav berhasil dibuka.");
        } else {
          Serial.println("GAGAL membuka Pulang.wav!");
        }
      } else {
        Serial.println("File Pulang.wav tidak ditemukan!");
      }
    }

    else {
      Serial.println();
      Serial.println("Perintah tidak dikenal.");
      Serial.println("Gunakan 1, 2, 3, atau 4.");
    }
  }
}