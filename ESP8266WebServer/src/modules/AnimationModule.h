#pragma once
#include <main.h>
#include <ArduinoJson.h>
#include <modules/ClientProcessingModule.h>

#define MOUSE_MOVE_ANIMATION 0x01

typedef struct AnimationTag{
    JsonDocument parsed;
    uint8_t *data;
} AnimationData;

class AnimationModule
{
private:
    ClientProcessing cpr;
    void MouseMoveAnimation();
public:
    void AnimationSetup(JsonDocument *parsed, uint8_t *data);
};

