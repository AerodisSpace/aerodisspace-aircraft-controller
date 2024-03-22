#[cxx::bridge(namespace = "aircraft_controller")]
pub mod ffi_controller {
    extern "C++" {
        include!("aerodisspace_arc/src/include/bluepad.h");
        // type ControllerPtr;
        // type BP32;
    }
    pub enum GamepadButton {
        A,
        B,
        X,
        Y,
        RB,
        RT,
        LB,
        LT,
        R,
        L,
        START,
        BACK,
        MAIN,
        NONE,
    }

    pub enum GamepadDPAD {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE,
    }

    pub struct GamepadState {
        pub button: GamepadButton,
        pub dpad: GamepadDPAD,
        pub stick_left: [i16; 2],
        pub stick_right: [i16; 2],
        pub connected: bool,
    }
}
