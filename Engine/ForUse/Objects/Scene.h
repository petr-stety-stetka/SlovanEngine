#pragma once

class Scene
{
protected:

public:
    /** Function for rendering 2D graphics */
    virtual void draw2D() = 0;

    /** Function for rendering 3D graphics */
    virtual void draw3D() = 0;

    /** Function for processing input events */
    virtual void input() = 0;

    /** Function for update game states and physics */
    virtual void update() = 0;
};