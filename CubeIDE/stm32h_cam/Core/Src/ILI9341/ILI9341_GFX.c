#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"

/* imprecise small delay */
__STATIC_INLINE void DelayUs(volatile uint32_t us)
{
	us *= (SystemCoreClock / 1000000);
	while (us--);
}

void ILI9341_DrawHollowCircle(uint16_t X, uint16_t Y, uint16_t radius, uint16_t color)
{
	int x = radius-1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y)
	{
		ILI9341_DrawPixel(X + x, Y + y, color);
		ILI9341_DrawPixel(X + y, Y + x, color);
		ILI9341_DrawPixel(X - y, Y + x, color);
		ILI9341_DrawPixel(X - x, Y + y, color);
		ILI9341_DrawPixel(X - x, Y - y, color);
		ILI9341_DrawPixel(X - y, Y - x, color);
		ILI9341_DrawPixel(X + y, Y - x, color);
		ILI9341_DrawPixel(X + x, Y - y, color);

		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}

		if (err > 0)
		{
			x--;
			dx += 2;
			err += (-radius << 1) + dx;
		}
	}
}

void ILI9341_DrawFilledCircle(uint16_t X, uint16_t Y, uint16_t radius, uint16_t color)
{

	int x = radius;
	int y = 0;
	int xChange = 1 - (radius << 1);
	int yChange = 0;
	int radiusError = 0;

	while (x >= y)
	{
		for (int i = X - x; i <= X + x; i++)
		{
			ILI9341_DrawPixel(i, Y + y,color);
			ILI9341_DrawPixel(i, Y - y,color);
		}

		for (int i = X - y; i <= X + y; i++)
		{
			ILI9341_DrawPixel(i, Y + x,color);
			ILI9341_DrawPixel(i, Y - x,color);
		}

		y++;
		radiusError += yChange;
		yChange += 2;

		if (((radiusError << 1) + xChange) > 0)
		{
			x--;
			radiusError += xChange;
			xChange += 2;
		}
	}
}

void ILI9341_DrawHollowRectangleCoord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t color)
{
	uint16_t xLen = 0;
	uint16_t yLen = 0;
	uint8_t negX = 0;
	uint8_t negY = 0;
	float negCalc = 0;

	negCalc = X1 - X0;
	if(negCalc < 0) negX = 1;
	negCalc = 0;

	negCalc = Y1 - Y0;
	if(negCalc < 0) negY = 1;

	//DRAW HORIZONTAL!
	if(!negX)
	{
		xLen = X1 - X0;
	}
	else
	{
		xLen = X0 - X1;
	}
	ILI9341_DrawHLine(X0, Y0, xLen, color);
	ILI9341_DrawHLine(X0, Y1, xLen, color);

	//DRAW VERTICAL!
	if(!negY)
	{
		yLen = Y1 - Y0;
	}
	else
	{
		yLen = Y0 - Y1;
	}

	ILI9341_DrawVLine(X0, Y0, yLen, color);
	ILI9341_DrawVLine(X1, Y0, yLen, color);

	if((xLen > 0)||(yLen > 0))
	{
		ILI9341_DrawPixel(X1, Y1, color);
	}
}

void ILI9341_DrawFilledRectangleCoord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t color)
{
	uint16_t xLen = 0;
	uint16_t yLen = 0;
	uint8_t negX = 0;
	uint8_t negY = 0;
	int32_t negCalc = 0;
	uint16_t X0True = 0;
	uint16_t Y0True = 0;

	negCalc = X1 - X0;
	if(negCalc < 0) negX = 1;
	negCalc = 0;

	negCalc = Y1 - Y0;
	if(negCalc < 0) negY = 1;

	if(!negX)
	{
		xLen = X1 - X0;
		X0True = X0;
	}
	else
	{
		xLen = X0 - X1;
		X0True = X1;
	}

	if(!negY)
	{
		yLen = Y1 - Y0;
		Y0True = Y0;
	}
	else
	{
		yLen = Y0 - Y1;
		Y0True = Y1;
	}

	ILI9341_DrawRectangle(X0True, Y0True, xLen, yLen, color);
}

void ILI9341_DrawChar(char ch, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor)
{
	if ((ch < 31) || (ch > 127)) return;

	uint8_t fOffset, fWidth, fHeight, fBPL;
	uint8_t *tempChar;

	fOffset = font[0];
	fWidth = font[1];
	fHeight = font[2];
	fBPL = font[3];

	tempChar = (uint8_t*)&font[((ch - 0x20) * fOffset) + 4]; /* Current Character = Meta + (Character Index * Offset) */

	/* Clear background first */
	ILI9341_DrawRectangle(X, Y, fWidth, fHeight, bgcolor);

	for (int j=0; j < fHeight; j++)
	{
		for (int i=0; i < fWidth; i++)
		{
			uint8_t z =  tempChar[fBPL * i + ((j & 0xF8) >> 3) + 1]; /* (j & 0xF8) >> 3, increase one by 8-bits */
			uint8_t b = 1 << (j & 0x07);
			if (( z & b ) != 0x00)
			{
				ILI9341_DrawPixel(X+i, Y+j, color);
			}
		}
	}
}

void ILI9341_DrawText(const char* str, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor)
{
	uint8_t charWidth;			/* Width of character */
	uint8_t fOffset = font[0];	/* Offset of character */
	uint8_t fWidth = font[1];	/* Width of font */

	while (*str)
	{
		ILI9341_DrawChar(*str, font, X, Y, color, bgcolor);

		/* Check character width and calculate proper position */
		uint8_t *tempChar = (uint8_t*)&font[((*str - 0x20) * fOffset) + 4];
		charWidth = tempChar[0];

		if(charWidth + 2 < fWidth)
		{
			/* If character width is smaller than font width */
			X += (charWidth + 2);
		}
		else
		{
			X += fWidth;
		}

		str++;
	}
}

// Вывод изображения с камеры на экран с разрешением 320х240 точек
// Проблема DMA больше 64кб не перекидывает, по этому кидаем частями
// Вход: буфер (frameBuffer) где лежит изображение и высота (hh) изображения в точках для вывода (можно обрезать картинку по вертикали)
#define DMA_H  80                       // сколько точек по вертикали кидается за один проход
#define MAX_H  ILI9341_SCREEN_HEIGHT    // высота экрана в точках
void ILI9341_render320x240(uint16_t *frameBuffer, uint16_t hh)
{
	uint8_t test = 0;
	uint8_t i=0;
	for(i=0;i<3;i++)
	{
	ILI9341_SetAddress(0, i*DMA_H, 320-1, 240-1);
	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, 0);
	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, 1);
	HAL_SPI_Transmit(HSPI_INSTANCE, &test, 1, 1);
	if ((i+1)*DMA_H>hh) {
		HAL_SPI_Transmit_DMA(HSPI_INSTANCE, (uint8_t*)frameBuffer+i*DMA_H*320*2, (hh-(i*DMA_H))*320*2);
		while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);
		break;}
	else { HAL_SPI_Transmit_DMA(HSPI_INSTANCE, (uint8_t*)frameBuffer+i*DMA_H*320*2, DMA_H*320*2);
	while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);}
	}
	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, 1);	//deselect//
}


extern DMA_HandleTypeDef hdma_spi2_tx;

void ILI9341_DrawImage(const uint8_t* image, uint8_t orientation)
{
	if(orientation == SCREEN_HORIZONTAL_1)
	{
		ILI9341_SetRotation(SCREEN_HORIZONTAL_1);
		ILI9341_SetAddress(0,0,ILI9341_SCREEN_WIDTH,ILI9341_SCREEN_HEIGHT);
	}
	else if(orientation == SCREEN_HORIZONTAL_2)
	{
		ILI9341_SetRotation(SCREEN_HORIZONTAL_2);
		ILI9341_SetAddress(0,0,ILI9341_SCREEN_WIDTH,ILI9341_SCREEN_HEIGHT);
	}
	else if(orientation == SCREEN_VERTICAL_2)
	{
		ILI9341_SetRotation(SCREEN_VERTICAL_2);
		ILI9341_SetAddress(0,0,ILI9341_SCREEN_HEIGHT,ILI9341_SCREEN_WIDTH);
	}
	else if(orientation == SCREEN_VERTICAL_1)
	{
		ILI9341_SetRotation(SCREEN_VERTICAL_1);
		ILI9341_SetAddress(0,0,ILI9341_SCREEN_HEIGHT,ILI9341_SCREEN_WIDTH);
	}

		HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);	//data
		HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);	//select
		int t1=HAL_GetTick();

			if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE, image, 65000)!= HAL_OK){
			ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);
			}
			// HAL_SPI_Transmit(HSPI_INSTANCE, buffer, len, 10);
			while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);

	//		__HAL_DMA_DISABLE(&hdma_spi2_tx);
	//		__HAL_DMA_ENABLE(&hdma_spi2_tx);
	//		__HAL_DMA_CLEAR_FLAG(&hdma_spi2_tx,DMA_FLAG_TCIF0_4 );



			if(HAL_SPI_Transmit_DMA(HSPI_INSTANCE, image+65000, 65000)!= HAL_OK){
			ILI9341_DrawText("ERROR", FONT3, 10, 20, BLACK, WHITE);
			}
//			// HAL_SPI_Transmit(HSPI_INSTANCE, buffer, len, 10);
			while(HAL_SPI_GetState(HSPI_INSTANCE) != HAL_SPI_STATE_READY);

		t1=HAL_GetTick()-t1;


		HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);	//deselect//

		char buf[32];
		sprintf(buf,"time=%d",t1);
		ILI9341_DrawText(buf, FONT3, 10, 10, BLACK, WHITE);


/*
	uint32_t counter = 0;
		for(uint32_t i = 0; i < ILI9341_SCREEN_WIDTH*ILI9341_SCREEN_HEIGHT*2/BURST_MAX_SIZE; i++)
	{
		ILI9341_WriteBuffer((uint8_t*)(image + counter), BURST_MAX_SIZE);
		counter += BURST_MAX_SIZE;

		// DMA Tx is too fast, It needs some delay
		DelayUs(1);
	}
*/

}
