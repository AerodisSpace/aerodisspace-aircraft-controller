#pragma once
#include <Bluepad32.h>
#include "../generated/gamepad.rs.h"

// GAMEPAD HANDLES
extern ControllerPtr GAMEPAD_PTR;
extern GamepadState GAMEPAD_STATE;

void gamepadSetup();
void gamepadLoop();
void gamepadOnConnect();
void gamepadOnDisconnect();
// =================================

// CONTROLLER HANDLES
// This class will handle all the controller logic
// Will get the gamepad state and send to aircraft via radio on loop function for this class
class Controller
{
public:
    void setup();
    void loop();

    
}
// =================================