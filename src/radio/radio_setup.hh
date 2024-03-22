#include <SPI.h>
#include <RF24.h>
#include "../config.hh"

extern RF24 radio;
const uint8_t RADIO_ADDRESSES[2][4] = {"000", "001"};
void radio_setup(uint8_t idx_address);

uint8_t *radio_send(uint8_t *data, uint8_t len);
uint8_t *radio_receive(uint8_t *data, uint8_t len);