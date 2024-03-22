// Expose the type to C/C++
#[cxx::bridge]
pub mod ffi_gamepad {

    pub enum GamepadButton {
        A = 0x0,
        B = 0x1,
        X = 0x2,
        Y = 0x3,
        RB = 0x4,
        RT = 0x5,
        LB = 0x6,
        LT = 0x7,
        R = 0x8,
        L = 0x9,
        START = 0xA,
        BACK = 0xB,
        MAIN = 0xC,
        NONE = 0xD,
    }

    pub enum GamepadDPAD {
        UP = 0x0,
        DOWN = 0x1,
        LEFT = 0x2,
        RIGHT = 0x3,
        NONE = 0x4,
    }

    pub struct GamepadState {
        pub button: GamepadButton,
        pub dpad: GamepadDPAD,
        pub stick_left: [i16; 2],
        pub stick_right: [i16; 2],
        pub connected: bool,
    }
}
