
#include <ESP8266WiFi.h>
const char* ssid     = "softbuzz";
const char* password = "softbuzz@0001";
const char* host = "abcsgsits.000webhostapp.com";
String line;
char data[20];
void setup() {
  Serial.begin(9600);          
  delay(10);
  // We start by connecting to a WiFi network
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println(WiFi.localIP());
}
void loop() {
  int i=0,j=0;
  //delay(1000);//
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }
  
  // We now create a URI for the request
  String url = "/fetch.php" ;
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      client.stop();
      return;
    }
  } 
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
   line = client.readStringUntil('\r');
   char d[line.length()];
   line.toCharArray(d,line.length());
   for(i=0;i<line.length();i++)
   {
    if(d[i]=='*')
    {
     break;
    }
   }
  for(i=i;i<line.length();i++)
  {
    data[j]=d[i];
    j++;
  }
  }












































































































































































































































































































































































































































































































































































































































































































































































































































































































































































   
  Serial.println(data);
}


