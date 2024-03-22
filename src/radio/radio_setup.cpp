#include "radio_setup.hh"

RF24 radio(RADIO_CE_PIN, RADIO_CSN_PIN);

void radio_setup(uint8_t idx_address)
{
    Serial.println("Radio setup");
    if (!radio.begin())
    {
        Serial.println("Radio begin failed PINS:(" + String(RADIO_CE_PIN) + " | " + String(RADIO_CSN_PIN) + ")");
        return;
    }
    radio.setPALevel(RF24_PA_HIGH);
    radio.openWritingPipe(RADIO_ADDRESSES[idx_address]);
    radio.openReadingPipe(1, RADIO_ADDRESSES[!idx_address]);
    radio.printDetails();
    Serial.printf("Radio setup done AddresIDX: %d | CH.Def: %d\n", idx_address, radio.getChannel());
}

uint8_t *radio_send(uint8_t *data, uint8_t len)
{
    radio.stopListening();

    bool report = radio.write(data, len);
#ifdef DEBUG
    Serial.println(report ? "Sent" : "Failed");
#endif
    return nullptr
}

uint8_t *radio_receive(uint8_t *data, uint8_t len)
{
    radio.startListening();
    if (radio.available())
    {
        radio.read(data, len);
#ifdef DEBUG
        Serial.println("Received: ", data);
#endif
        return data;
    }
    return nullptr;
}