#ifndef ILI9341_GFX_H
#define ILI9341_GFX_H

#include "stdbool.h"
#include "stm32h7xx_hal.h"
#include "fonts.h"

#define HORIZONTAL_IMAGE	0
#define VERTICAL_IMAGE		1

void ILI9341_DrawHollowCircle(uint16_t X, uint16_t Y, uint16_t radius, uint16_t color);
void ILI9341_DrawFilledCircle(uint16_t X, uint16_t Y, uint16_t radius, uint16_t color);
void ILI9341_DrawHollowRectangleCoord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t color);
void ILI9341_DrawFilledRectangleCoord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t color);
void ILI9341_DrawChar(char ch, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor);
void ILI9341_DrawText(const char* str, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor);
void ILI9341_DrawImage(const uint8_t* image, uint8_t orientation);
void ILI9341_render160x160(uint16_t *frameBuffer,int16_t x,int16_t y,int16_t w,int16_t h);
#endif
