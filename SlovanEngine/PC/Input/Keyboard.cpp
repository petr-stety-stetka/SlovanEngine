#include "Keyboard.h"

bool Keyboard::keyPressed[512];
bool Keyboard::keyRepeated[512];
bool Keyboard::keyReleased[512];

bool Keyboard::isPressed(int keyCode) {
    if (keyPressed[keyCode]) {
        keyPressed[keyCode] = false;
        return true;
    }
    else
        return false;
}

bool Keyboard::isRepeated(int keyCode) {
    return keyRepeated[keyCode];
}

bool Keyboard::isReleased(int keyCode) {
    if (keyReleased[keyCode]) {
        keyReleased[keyCode] = false;
        return true;
    }
    else
        return false;
}

void Keyboard::setKeyState(int keyCode, int state) {
#if defined(PC)
    if (state == GLFW_PRESS) {
        keyPressed[keyCode] = true;
        keyRepeated[keyCode] = true;
    }
    else if (state == GLFW_RELEASE) {
        keyRepeated[keyCode] = false;
        keyReleased[keyCode] = true;
    }
#endif
}