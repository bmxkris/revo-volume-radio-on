#include <WiFi.h>
#include "wifienv.h" // All my config for SSID, Password and IP addresses

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
        delay(500);
        Serial.print(".");
    }

    // Connection is complete
    Serial.println("");

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
  Serial.println("Start command request");

  WiFiClient client = server.available();
  
  if(client.connect(HOST_NAME, HTTP_PORT)) {
    Serial.println("Connected to server");
  } else {
    Serial.println("connection failed");
  }

  // send HTTP request header
  client.println(HTTP_METHOD + " " + PATH_NAME + "?button=" + GPIO_PIN + " HTTP/1.1");
  client.println("Host: " + String(HOST_NAME));
  client.println("Connection: close");
  client.println(); // end HTTP request header
  Serial.println("HTTP request finished");

  while(client.available())
  {
    // read an incoming byte from the server and print them to serial monitor:
    char c = client.read();
    Serial.print(c);
  }
  Serial.println("Come through here?");
  if(!client.connected())
  {
    // if the server's disconnected, stop the client:
    Serial.println("disconnected");
    client.stop();
  }
  Serial.println("and it looks like there isn't a client and there is a client");
}
