#pragma once

#include "../../Core/GL/GLHeader.h"

#define MOUSE_BUTTON_1         0
#define MOUSE_BUTTON_2         1
#define MOUSE_BUTTON_3         2
#define MOUSE_BUTTON_4         3
#define MOUSE_BUTTON_5         4
#define MOUSE_BUTTON_6         5
#define MOUSE_BUTTON_7         6
#define MOUSE_BUTTON_8         7
#define MOUSE_BUTTON_LAST      MOUSE_BUTTON_8
#define MOUSE_BUTTON_LEFT      MOUSE_BUTTON_1
#define MOUSE_BUTTON_RIGHT     MOUSE_BUTTON_2
#define MOUSE_BUTTON_MIDDLE    MOUSE_BUTTON_3

class Mouse {
private:
    static bool buttonPressed[8];
    static bool buttonRepeated[8];
    static bool buttonReleased[8];
    static float XCursorPosition;
    static float YCursorPosition;
    static float XScrollWheel;
    static float YScrollWheel;
public:
    /**
     * Return true if is button pressed (down).
     */
    static bool isPressed(int buttonCode);

    /**
     * Return true if is button repeated (hold).
     */
    static bool isRepeated(int buttonCode);

    /**
     * Return true if is button released (up).
     */
    static bool isReleased(int buttonCode);

    /**
     * Get X position of cursor mouse.
     */
    static float getXCursorPosition();

    /**
     * Get Y position of cursor mouse.
     */
    static float getYCursorPosition();

    /**
     * Get X scroll wheel offset.
     */
    static float getXScrollWheel();

    /**
     * Get X position of cursor mouse.
     */
    static float getYScrollWheel();

    /**
     * Set state of mouse button. You don't use this function!
     */
    void setButtonState(int buttonCode, int state);

    /**
     * Set X and Y position of cursor mouse. You don't use this function!
     */
    void setCursorPosition(float x, float y);

    /**
     * Set X and Y offset of scroll wheel. You don't use this function!
     */
    void setScrollWheel(float x, float y);
};