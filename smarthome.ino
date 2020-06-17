//Smart Sockets v2 system for ESP boards by revox
//libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "mainPage.h" //add webpage

const char *ssid = "ssid"; //wifi ssif
const char *password = "pass"; //wifi pass

//input pins
const int Load1 = 16;
const int Load2 = 14;
const int Load3 = 12; 
const int Load4 = 13; 
const int Load5 = 4; 
const int Load6 = 5; 

String L1Status, L2Status, L3Status, L4Status, Temperature, L5Status, L6Status;
ESP8266WebServer server(80);

void handleRoot() {
  String s = MAIN_page;
  s.replace("@@L1@@", L1Status); //variables for web - replace @@xx@@ for switch state
  s.replace("@@L2@@", L2Status);
  s.replace("@@L3@@", L3Status);
  s.replace("@@L4@@", L4Status);
  s.replace("@@L5@@", L5Status);
  s.replace("@@L6@@", L6Status);
  server.send(200, "text/html", s);
}
//obsluga klienta
void handleForm() {
  String t_state = server.arg("submit");

  if (t_state == "ON1")
  {
    L1Status = "(ON)";
    digitalWrite(Load1, HIGH);
  }

  if (t_state == "OFF1")
  {
    L1Status = "(OFF)";
    digitalWrite(Load1, LOW);
  }

  if (t_state == "ON2")
  {
    L2Status = "(ON)";
    digitalWrite(Load2, HIGH);
  }

  if (t_state == "OFF2")
  {
    L2Status = "(OFF)";
    digitalWrite(Load2, LOW);
  }

  if (t_state == "ON3")
  {
    L3Status = "(ON)";
    digitalWrite(Load3, HIGH);
  }

  if (t_state == "OFF3")
  {
    L3Status = "(OFF)";
    digitalWrite(Load3, LOW);
  }

  if (t_state == "ON4")
  {
    L4Status = "(ON)";
    digitalWrite(Load4, HIGH);
  }

  if (t_state == "OFF4")
  {
    L4Status = "(OFF)";
    digitalWrite(Load4, LOW);
  }

  if (t_state == "ON5")
  {
    L5Status = "(ON)";
    digitalWrite(Load5, HIGH);
  }

  if (t_state == "OFF5")
  {
    L5Status = "(OFF)";
    digitalWrite(Load5, LOW);
  }

  if (t_state == "ON6")
  {
    L6Status = "(ON)";
  }

  if (t_state == "OFF6")
  {
    L6Status = "(OFF)";
  }

  //everything is on single page thanks to this redirect
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");
  delay(100);
}

void setup() {
  delay(500);
  WiFi.mode(WIFI_AP_STA); //wifi config
  WiFi.begin(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/form", handleForm);
  server.begin();

  pinMode(Load1, OUTPUT); //pin configurations
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);
  pinMode(Load5, OUTPUT);
  pinMode(Load6, OUTPUT);
}

void loop() {
  server.handleClient(); //let ESP handle clients
}
