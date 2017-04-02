// This #include statement was automatically added by the Particle IDE.
#include <HttpClient.h>

// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

/**
 * George Frick
 * 
 * This application will play a certain sound effect in a voice channel
 * when the button is pressed.
 * 
 * A simple http post when a button is pressed.
 * You don't have to go through the particle API.
 * 
 * In this example, we post to a Discord sound effect bot. 
 * @see https://github.com/Darkside138/DiscordSoundboard
 * 
 * You also need the above two libraries, HttpClient and InternetButton
 * https://github.com/spark/InternetButton
 * https://github.com/nmattisson/HttpClient
 *
 * To use the Serial output, have your internet button connected via usb
 * and type 'particle serial monitor'
 */

HttpClient http;
InternetButton b = InternetButton();
bool mashBlocker = false;

// Headers currently need to be set at init, useful for API keys etc.
http_header_t headers[] = {
    { "Content-Type", "application/x-www-form-urlencoded" },
    //  { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

void setup() {
    b.begin(); // pass 1 for older buttons (no shield)
    b.setBrightness(50); // limit overall brightness.
    Serial.begin(9600);
}

void loop(){

    if(b.buttonOn(2) && mashBlocker == false) {
        b.ledOn(3, 255, 255, 255);
        mashBlocker = true;
        
        Serial.println();
        Serial.println("Making web request...");

        request.hostname = "192.168.1.193";
        request.port = 8080;
        request.path = "/soundsApi/playFile";
        request.body = "soundFileId=sms1&username=gfrick-test";
    
        // Post request, it blocks. (blocking i/o)
        http.post(request, response, headers);

        Serial.print("Application>\tResponse status: ");
        Serial.println(response.status);
    
        Serial.print("Application>\tHTTP Response Body: ");
        Serial.println(response.body);

        b.ledOff(3);
        mashBlocker = false;
    }

}

