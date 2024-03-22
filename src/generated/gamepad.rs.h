#pragma once
#include <array>
#include <cstdint>
#include <type_traits>

enum class GamepadButton : ::std::uint8_t;
enum class GamepadDPAD : ::std::uint8_t;
struct GamepadState;

#ifndef CXXBRIDGE1_ENUM_GamepadButton
#define CXXBRIDGE1_ENUM_GamepadButton
enum class GamepadButton : ::std::uint8_t {
  A = 0,
  B = 1,
  X = 2,
  Y = 3,
  RB = 4,
  RT = 5,
  LB = 6,
  LT = 7,
  R = 8,
  L = 9,
  START = 10,
  BACK = 11,
  MAIN = 12,
  NONE = 13,
};
#endif // CXXBRIDGE1_ENUM_GamepadButton

#ifndef CXXBRIDGE1_ENUM_GamepadDPAD
#define CXXBRIDGE1_ENUM_GamepadDPAD
enum class GamepadDPAD : ::std::uint8_t {
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3,
  NONE = 4,
};
#endif // CXXBRIDGE1_ENUM_GamepadDPAD

#ifndef CXXBRIDGE1_STRUCT_GamepadState
#define CXXBRIDGE1_STRUCT_GamepadState
struct GamepadState final {
  ::GamepadButton button;
  ::GamepadDPAD dpad;
  ::std::array<::std::int16_t, 2> stick_left;
  ::std::array<::std::int16_t, 2> stick_right;
  bool connected;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_GamepadState
