/*
    Example1_Listening.ino

    Basic example to demonstrate the use of the CEClient library
    The client is configured in promiscuous and monitor mode 
    to receive all the messages on the CEC bus
    
    No specific callback function is defined, therefore the client
    calls the default one, which prints the packets on the Serial port

    Use http://www.cec-o-matic.com/ to decode captured messages
*/

#include "CEClient.h"

#define CEC_PHYSICAL_ADDRESS    0x1000
#define CEC_INPUT_PIN           2
#define CEC_OUTPUT_PIN          3

// create a CEC client
CEClient ceclient(CEC_PHYSICAL_ADDRESS, CEC_INPUT_PIN, CEC_OUTPUT_PIN);


void setup() {

    Serial.begin(115200);

    // initialize the client with the default device type (PLAYBACK)
    ceclient.begin();

    // enable promiscuous mode (print all the incoming messages)
    ceclient.setPromiscuous(true);

    // enable monitor mode (do not transmit)
    ceclient.setMonitorMode(true);
}

void loop() {

    // run the client
    ceclient.run();
}