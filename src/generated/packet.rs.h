#pragma once
#include <cstdint>
#include <type_traits>

struct AircraftPacket;
struct GroundStationPacket;

#ifndef CXXBRIDGE1_STRUCT_AircraftPacket
#define CXXBRIDGE1_STRUCT_AircraftPacket
// Packet that is sent from the aircraft to the ground station
struct AircraftPacket final {
  ::std::uint8_t data;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_AircraftPacket

#ifndef CXXBRIDGE1_STRUCT_GroundStationPacket
#define CXXBRIDGE1_STRUCT_GroundStationPacket
// Packet that is sent from the ground station to the aircraft
// This packet is used to control the aircraft
struct GroundStationPacket final {
  ::std::uint16_t throttle;
  ::std::uint16_t brake;
  ::std::uint16_t aileron_left;
  ::std::uint16_t aileron_right;
  ::std::uint16_t rudder;
  ::std::uint16_t elevator;
  ::std::uint16_t button;
  bool connected;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_GroundStationPacket
