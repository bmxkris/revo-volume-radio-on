#include <WiFi.h>
#include "wifienv.h" // All my config for SSID, Password and IP addresses
#include <HTTPClient.h>

/* Server and IP address ------------------------------------------------------*/
WiFiServer server(80); // Wifi server exemplar using port 80
IPAddress myIP;        // IP address in your local wifi net

/* The start time value ------------------------------------------------------*/
unsigned long startTime;

/* Server initialization -------------------------------------------------------*/
void Srvr__setup()
{
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

  if (WiFi.config(staticIP, gateway, subnet, dns, dns) == false) {
    Serial.println("Configuration failed.");
  }

    // Applying SSID and password
    WiFi.begin(ssid, password);

    // Waiting the connection to a router
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
        Serial.print(".");
    }

    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.println("Server started");

    // Show obtained IP address in local Wifi net
    Serial.println(myIP = WiFi.localIP());

    // Once connected, set start time
    startTime = millis();
}

void Request__command(int GPIO_PIN)
{
  HTTPClient http;

  http.begin("http://" + HOST_NAME + ":" + HTTP_PORT + PATH_NAME + "?button=" + GPIO_PIN); //Specify the URL
  int httpCode = http.GET();  //Make the request

  if (httpCode > 0) { //Check for the returning code

    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
  }

  else {
    Serial.println("Error on HTTP request");
  }

  http.end(); //Free the resources
}
