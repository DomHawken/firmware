#pragma once

#include "Component.h"

class Triangle final : public Component
{
public:
    explicit Triangle(bool shouldBeFilled = false) : filled(shouldBeFilled)
    {
        setName("triangle");
    }

    void paint(Graphics &g) override
    {
        g.setColour(ElectraColours::rgb565NumericGreen);

        if (filled) {
            g.fillTriangle(
                0,
                0,
                getWidth() - 1,
                0,
                getWidth() / 2,
                getHeight() - 1);
        } else {
            g.drawTriangle(
                0,
                getHeight() - 1,
                getWidth() - 1,
                getHeight() - 1,
                getWidth() / 2,
                0);
        }
    }

    void onTouchDown(const TouchEvent &touchEvent) override
    {
        logMessage("callback: triangle");
    }

private:
    bool filled;
};
