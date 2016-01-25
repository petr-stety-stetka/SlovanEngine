#include "Mouse.h"

bool Mouse::buttonPressed[8];
bool Mouse::buttonRepeated[8];
bool Mouse::buttonReleased[8];
float Mouse::XCursorPosition;
float Mouse::YCursorPosition;
float Mouse::XScrollWheel;
float Mouse::YScrollWheel;

bool Mouse::isPressed(int buttonCode) {
    if (buttonPressed[buttonCode]) {
        buttonPressed[buttonCode] = false;
        return true;
    }
    else
        return false;
}


bool Mouse::isRepeated(int buttonCode) {
    return buttonRepeated[buttonCode];
}

bool Mouse::isReleased(int buttonCode) {
    if (buttonReleased[buttonCode]) {
        buttonReleased[buttonCode] = false;
        return true;
    }
    else
        return false;
}

void Mouse::setButtonState(int buttonCode, int state) {
#if defined(PC)
    if (state == GLFW_PRESS) {
        buttonPressed[buttonCode] = true;
        buttonRepeated[buttonCode] = true;
    }
    else if (state == GLFW_RELEASE) {
        buttonRepeated[buttonCode] = false;
        buttonReleased[buttonCode] = true;
    }
#endif
}


void Mouse::setCursorPosition(float x, float y) {
    XCursorPosition = x;
    YCursorPosition = y;
}


void Mouse::setScrollWheel(float x, float y) {
    XScrollWheel += x;
    YScrollWheel += y;
}

float Mouse::getXCursorPosition() {
    return XCursorPosition;
}

float Mouse::getYCursorPosition() {
    return YCursorPosition;
}


float Mouse::getXScrollWheel() {
    float x(XScrollWheel);
    XScrollWheel = 0;
    return x;
}

float Mouse::getYScrollWheel() {
    float y(YScrollWheel);
    YScrollWheel = 0;
    return y;
}