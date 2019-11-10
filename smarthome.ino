//biblioteki
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "mainPage.h" //dolaczamy przygotowana strone

//definiujemy piny wyjscia
const int Load1 = 16; //load1
const int Load2 = 14; //load 2
const int Load3 = 12; //load 3
const int Load4 = 13; //load 4
const int Load5 = 4; //load 5
const int Load6 = 5; //load 6, uzywane tu jako pin pwm

const char *ssid = "Dom"; //nazwa sieci
const char *password = "07251498"; //haslo do wifi

//sprawy od pwm
int brightness = 0; 
int fadeAmount = 5;  
unsigned long currentTime;
unsigned long loopTime;
int fade;

//zmienne i esp nasluchuje na porcie 80
ESP8266WebServer server(80);
String L1Status, L2Status, L3Status, L4Status, Temperature, L5Status, L6Status;

//zmiana @@dane@@ na realne dane w stronie
void handleRoot() {
  String s = MAIN_page;
  s.replace("@@L1@@", L1Status);
  s.replace("@@L2@@", L2Status);
  s.replace("@@L3@@", L3Status);
  s.replace("@@L4@@", L4Status);
  s.replace("@@TEMP@@", Temperature);
  s.replace("@@L5@@", L5Status);
  s.replace("@@L6@@", L6Status);
  server.send(200, "text/html", s);
}
//obsluga klienta
void handleForm() {
  String t_state = server.arg("submit");

  Temperature = 20; //jeszcze do zrobienia

  if (t_state == "ON1")
  {
    L1Status = "(Wlaczone)";
    digitalWrite(Load1, HIGH);
  }

  if (t_state == "OFF1")
  {
    L1Status = "(Wylaczone)";
    digitalWrite(Load1, LOW);
  }

  if (t_state == "ON2")
  {
    L2Status = "(Wlaczone)";
    digitalWrite(Load2, HIGH);
  }

  if (t_state == "OFF2")
  {
    L2Status = "(Wylaczone)";
    digitalWrite(Load2, LOW);
  }

  if (t_state == "ON3")
  {
    L3Status = "(Wlaczone)";
    digitalWrite(Load3, HIGH);
  }

  if (t_state == "OFF3")
  {
    L3Status = "(Wylaczone)";
    digitalWrite(Load3, LOW);
  }

  if (t_state == "ON4")
  {
    L4Status = "(Wlaczone)";
    digitalWrite(Load4, HIGH);
  }

  if (t_state == "OFF4")
  {
    L4Status = "(Wylaczone)";
    digitalWrite(Load4, LOW);
  }

  if (t_state == "ON5")
  {
    L5Status = "(Wlaczone)";
    digitalWrite(Load5, HIGH);
  }

  if (t_state == "OFF5")
  {
    L5Status = "(Wylaczone)";
    digitalWrite(Load5, LOW);
  }


  if (t_state == "ON6")
  {
    L6Status = "(Wlaczone)";
    fade = 1; //ustaw fade na 1 czyli wlacz pwm
  }

  if (t_state == "OFF6")
  {
    L6Status = "(Wylaczone)";
    fade = 0;
    digitalWrite(Load6, LOW);
  }
  //dzieki temu wszystko jest na jednej stronie
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");

  delay(500);
}

void setup() {
  delay(1000);
  WiFi.mode(WIFI_AP_STA); //konf. wifi
  WiFi.begin(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/form", handleForm);

  server.begin(); //konf. pinow
  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);
  pinMode(Load5, OUTPUT);
  pinMode(Load6, OUTPUT);
  currentTime = millis(); //sprawy od pwm
  loopTime = currentTime;
}


void loop() {
  server.handleClient(); //niech esp obsluzy klienta

  //Load 6 bedzie pinem PWM i robic powoli on-off
  if (fade == 1)
  {
    L6Status = "(Wlaczone)";

    currentTime = millis();
    if (currentTime >= (loopTime + 20)) {
      analogWrite(Load6, brightness);
      brightness = brightness + fadeAmount;
      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ;
      }
      loopTime = currentTime;
    }
  }
  
}
