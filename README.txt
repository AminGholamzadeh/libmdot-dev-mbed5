---------------------------------------
Getting Started with the mDot Library
---------------------------------------

This README should get you started using the mDot library with your MultiTech mDot.

License information can be found in the accompanying LICENSE file.

The mDot header has documentation for all the public functions that will be useful to consumers of the library.

The following source code provides an example application which configures the mDot, connects to a MultiTech Conduit gateway with matching configuration, and sends data packets to the gateway.

/**************
  SAMPLE CODE
**************/

#include "mbed.h"
#include "mDot.h"
#include <string>
#include <vector>

// these options must match the settings on your Conduit in
// /var/config/lora/lora-network-server.conf
static std::string config_network_name = "my_lora_network";
static std::string config_network_pass = "my_network_password";
static uint8_t config_frequency_sub_band = 1;

void log_error(mDot* dot, const char* msg, int32_t retval);

int main() {
    int32_t ret;
    mDot* dot;
    std::vector<uint8_t> data;
    std::string data_str = "hello world!";

    // get a mDot handle
    dot = mDot::getInstance();

    // reset to default config so we know what state we're in
    dot->resetConfig();

    // print library version information
    printf("version: %s\r\n", dot->getId().c_str());

    // set up the mDot with our network information
    printf("setting frequency sub band\r\n");
    if ((ret = dot->setFrequencySubBand(config_frequency_sub_band)) != mDot::MDOT_OK) {
        log_error(dot, "failed to set frequency sub band", ret);
    }
    printf("setting network name\r\n");
    if ((ret = dot->setNetworkName(config_network_name)) != mDot::MDOT_OK) {
        log_error(dot, "failed to set network name", ret);
    }
    printf("setting network password\r\n");
    if ((ret = dot->setNetworkPassphrase(config_network_pass)) != mDot::MDOT_OK) {
        log_error(dot, "failed to set network password", ret);
    }

    // attempt to join the network
    printf("joining network\r\n");
    while ((ret = dot->joinNetwork()) != mDot::MDOT_OK) {
        log_error(dot, "failed to join network", ret);
        wait(2);
    }

    // format data for sending to the gateway
    for (std::string::iterator it = data_str.begin(); it != data_str.end(); it++)
        data.push_back((uint8_t) *it);

    while (true) {
        // send the data
        // ACKs are enabled by default, so we're expecting to get one back
        if ((ret = dot->send(data)) != mDot::MDOT_OK) {
            log_error(dot, "failed to send", ret);
        } else {
            printf("successfully sent data to gateway\r\n");
        }

        wait(5);
    }

    return 0;
}

void log_error(mDot* dot, const char* msg, int32_t retval) {
    printf("%s - %ld:%s, %s\r\n", msg, retval, mDot::getReturnCodeString(retval).c_str(), dot->getLastError().c_str());
}
