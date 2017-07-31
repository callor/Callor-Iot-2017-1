/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define D2 16

#define USE_SERIAL Serial

String HTTP_SERVER = "http://192.168.0.65:3000/";

ESP8266WiFiMulti WiFiMulti;

void setup() {

  USE_SERIAL.begin(115200);
  // USE_SERIAL.setDebugOutput(true);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  WiFiMulti.addAP("****", "*****");
  pinMode(D2,OUTPUT);

}

String response = "";
void loop() {
  
  int value = analogRead(A0);
  USE_SERIAL.print("value:");
  USE_SERIAL.print(value);
  USE_SERIAL.print("\n");

  // 데이터를 서버로 보내고
  String request = HTTP_SERVER+"insert/001/" + String(value,DEC);
  http_Send(request);

  // 서버로 부터 컨트롤 데이터를 가져오기
  request = HTTP_SERVER+"getControl" ;
  http_Send(request);
  USE_SERIAL.print(response);
  if(response == "LED_ON"){
    digitalWrite(D2,HIGH);
  }
  
  delay(5000);
  
}


void http_Send(String req) {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;
    USE_SERIAL.print("[HTTP] begin...\n");
    // configure traged server and url
    //http.begin("https://192.168.1.12/test.html", "7a 9c f4 db 40 d3 62 5a 6e 21 bc 5c cc 66 c8 3e a1 45 59 38"); //HTTPS
    //        http.begin("http://192.168.0.65:3000/getserver/callor@callor.com"); //HTTP

    // String(숫자, base) = 숫자를 문자열 형태로 변환
    // base : DEC = 십진수, HEX = 16진수, BIN = 2진수
//    String req1 =  + String(value, DEC);
    USE_SERIAL.print(req);
    http.begin(req); //HTTP

    USE_SERIAL.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
//        String payload = http.getString();
        response = http.getString();
        USE_SERIAL.println(response);
      }
    } else {
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

//  delay(10000);
}

