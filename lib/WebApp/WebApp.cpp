#include "WebApp.h"
#include "Game.h"

#include <Arduino.h>
#include <WiFi.h>


String header;

String getStyleSheet(){
    //TODO: Make This custom now that it's broken out
    String styleSheet = "";
    styleSheet += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
    styleSheet += ".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;";
    styleSheet += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
    styleSheet += ".button2 {background-color: #555555;}</style>";

    return styleSheet;
}

void GenerateWebsite(WiFiClient client, bool flags[]){

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println(getStyleSheet());
            client.println("</head>");

            // Web Page Heading
            client.println("<body><h1>Spooky controls</h1>");
            client.println("<table>");
           
            client.println("</table>");

            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop

        }

void ServeWebApp(WiFiClient client){

    
    String flag1 = "flag";

    if (client) {                             // If a new client connects,
        Serial.println("New Client.");          // print a message out in the serial port
        String currentLine = "";                // make a String to hold incoming data from the client
        while (client.connected()) {            // loop while the client's connected
        if (client.available()) {             // if there's bytes to read from the client,
            char c = client.read();             // read a byte, then
            Serial.write(c);                    // print it out the serial monitor
            header += c;
            if (c == '\n') {                    // if the byte is a newline character
            // if the current line is blank, you got two newline characters in a row.
            // that's the end of the client HTTP request, so send a response:
                if (currentLine.length() == 0) {
                    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                    // and a content-type so the client knows what's coming, then a blank line:
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-type:text/html");
                    client.println("Connection: close");
                    client.println();

                    // sets the flag values // TODO: change the flag values to uuids for the final badge
                    if (header.indexOf("GET /"+ (String)flag1 +"/on") >= 0) {
                        setFlagValue(1,true);
                    } else if (header.indexOf("GET /1/off") >= 0) {
                    setFlagValue(1,false);
                    }
                    
                    GenerateWebsite(client, flags);
                    break;
                } else { // if you got a newline, then clear currentLine
                    currentLine = "";
                }
                } else if (c != '\r') {  // if you got anything else but a carriage return character,
                currentLine += c;      // add it to the end of the currentLine
                }
            }
        }
        // Clear the header variable
        header = "";
        // Close the connection
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
  }
}