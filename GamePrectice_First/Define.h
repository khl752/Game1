#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define ScreenCollisionTest(x,y) (((x) < 0 && (x) > SCREEN_WIDTH) && ((y) < 0 && (y) > SCREEN_HEIGHT))
