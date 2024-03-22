#pragma once

// RADIO CONFIGURATION
#define IS_MASTER
#ifdef IS_MASTER
#define RADIO_CE_PIN 6
#define RADIO_CSN_PIN 5
#else
#define RADIO_CE_PIN 21
#define RADIO_CSN_PIN 22
#endif