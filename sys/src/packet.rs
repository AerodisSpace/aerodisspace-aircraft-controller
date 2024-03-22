// Expose the type to C/C++
#[cxx::bridge]
pub mod ffi_packet {
    /// Packet that is sent from the aircraft to the ground station
    pub struct AircraftPacket {
        data: u8,
    }

    /// Packet that is sent from the ground station to the aircraft
    /// This packet is used to control the aircraft
    pub struct GroundStationPacket {
        pub throttle: u16, // 0 to 1024
        pub brake: u16,    // 0 to 1024
        // Servo values - Aileron/Flaps/Rudder/Elevator
        pub aileron_left: u16,  // 0 to 180
        pub aileron_right: u16, // 0 to 180
        pub rudder: u16,        // 0 to 180
        pub elevator: u16,      // 0 to 180
        // Special
        pub button: u16, // Code that will activate a special action | Active: Debug, GPS, Autopilot, etc
        pub connected: bool,
    }
}
