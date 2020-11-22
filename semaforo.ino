#include <WiFi.h>
#include <WiFiUDP.h>
#include <NTPClient.h>
#include <Wire.h>

const char* ssid = "nome_do_wifi";
const char* senha = "senha_da_rede";

const char* buscahora = "a.st1.ntp.br";

int fusoHorario = -10800;
int atualiza = 1800000;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, buscahora, fusoHorario, 60000);

int ledpin_s = 15;
int ledpin_a = 2;
int ledpin_g = 4;

void setup() {
  pinMode(ledpin_s, OUTPUT);
  pinMode(ledpin_a, OUTPUT);
  pinMode(ledpin_g, OUTPUT);
  Serial.begin (115200);
  delay(10);

  WiFi.begin(ssid, senha);

  timeClient.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  timeClient.update();
  String horas = timeClient.getFormattedTime();
  int horas1 = horas[0];
  delay(800);
  if (horas1 == 6 && horas1 < 8 || horas1 == 18 && horas1 <= 20)
  { digitalWrite (ledpin_s, 1);
    delay(21000);
    digitalWrite (ledpin_s, 0);
    digitalWrite (ledpin_g, 1);
    delay(20000);
    digitalWrite (ledpin_g, 0);
    digitalWrite (ledpin_a, 1);
    delay(3000);
    digitalWrite (ledpin_a, 0);
    digitalWrite(ledpin_s, 1);

}
else
{   digitalWrite (ledpin_s, 1);
    delay(26000);
    digitalWrite (ledpin_s, 0);
    digitalWrite (ledpin_g, 1);
    delay(25000);
    digitalWrite (ledpin_g, 0);
    digitalWrite (ledpin_a, 1);
    delay(3000);
    digitalWrite (ledpin_a, 0);
    digitalWrite (ledpin_s, 1);
  }
}
