#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


int totalDevices = 3;


#define FIREBASE_HOST "sintios-2b9d4.firebaseio.com"
                     
#define FIREBASE_AUTH "qabBfsVtfHU8NEbgDstlC3mfEY7OEHYP2pq13494"

#define WIFI_SSID "TURBONETT_3289A1"
#define WIFI_PASSWORD "rije1347"

#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

String chipId = "Verduras";


void setup() {
//puertos
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  //////
  
  
  Serial.begin(9600);


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {
  // Get all entries.
  // TODO: Replace with streaming
  String path = chipId + "/Lechuga";
  FirebaseObject pixels = Firebase.get(path);
  if (Firebase.failed()) {
      Serial.println("Firebase get failed");
      Serial.println(Firebase.error());
      delay(1000);
      return;
  }
    int pixel = pixels.getInt("PH");
    Serial.println(pixel);
    delay(2000);
}
