Софт для CubeMX IDE <br>
В последние годы различные приложения, такие как распознование лиц, речь, изображения или распознавание почерка,
обработка естественного языка и автоматическая медицинская диагностика, продемонстрировали выдающуюся эффективность,
применяя методы глубокого обучения (DL). Для дальнейшего повышения производительности приложений и добавления дополнительных
функций в настоящее время изучаются сложные глубокие нейронные сети (DNN). Однако это приводит к все более высоким
вычислительным требованиям к конечным устройствам. Чтобы удовлетворить эти требования, производители интегральных микросхем
сосредоточились на увеличении количества доступных ядер, рабочих частотах обработчиков и систем памяти, а также на
специализированных аппаратных решениях. В последнее время специализированные аппаратные ускорители (нейроускорители) в
сочетании с системами памяти с высокой пропускной способностью являются предпочтительной архитектурой для таких задач.
Помимо этих основных приложений, новый класс систем пытается воспользоваться алгоритмами DNN для решения различных задач.
Эти приложения поступают из области интеллектуальных датчиков и устройств. В отличие от основных применений, они имеют
более низкую сложность, но в то же время требуют очень низкого энергопотребления, поскольку большинство этих систем должны
работать на автономном питании в течение длительного времени. Некоторые из этих приложений могут быть даже реализованы на
недорогих микроконтроллерах с низким энергопотреблением, такими как те, которые построены на ядрах Arm Cortex-M.<br>
STMicroElectronics является еще одним из производителей, который внес важный вклад в рынок для поддержки вычислений AI Edge
в качестве новой парадигмы для IoT.Его усилия были направлены на запуск нейронных сетей на микроконтроллерах общего назначения
STM32, что значительно влияет на производительность разработчиков системы Edge AI -системы за счет сокращения времени
развертывания приложений. В этом случае основное внимание уделяется не на аппаратных ускорителях, а на обширном программном
инструментарии, предназначенном для портировании DNN моделей для стандартных микроконтроллеров STM32 с высокой производительностью
для ядра процессора ARM Cortex-M4 и M7.<br>
<br>
Плата развивается, и некоторый софт перестает подходить, по этому проверяйте соответсвие софта и железа.<br>
<br>
Соединение перефирии:<br>
<b>Hardware 1.0 </b><br>
Configuration	stm32h_cam <br>
STM32CubeMX 	6.3.0 <br>
Date	08/29/2022  <br>
MCU	STM32H743VITx <br>
<br>
<br>
PERIPHERALS	MODES	FUNCTIONS	PINS <br>
DCMI	Slave 8 bits External Synchro	DCMI_D0	PC6 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D1	PC7 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D2	PC8 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D3	PE1 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D4	PE4 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D5	PD3 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D6	PE5 <br>
DCMI	Slave 8 bits External Synchro	DCMI_D7	PE6 <br>
DCMI	Slave 8 bits External Synchro	DCMI_HSYNC	PA4 <br>
DCMI	Slave 8 bits External Synchro	DCMI_PIXCLK	PA6 <br>
DCMI	Slave 8 bits External Synchro	DCMI_VSYNC	PB7 <br>
DEBUG	Trace Asynchronous Sw	DEBUG_JTMS-SWDIO	PA13 (JTMS/SWDIO) <br>
DEBUG	Trace Asynchronous Sw	DEBUG_JTCK-SWCLK	PA14 (JTCK/SWCLK) <br>
DEBUG	Trace Asynchronous Sw	DEBUG_JTDO-SWO	PB3 (JTDO/TRACESWO)
I2C1	I2C	I2C1_SCL	PB8 <br>
I2C1	I2C	I2C1_SDA	PB9 <br>
I2C3	I2C	I2C3_SCL	PA8 <br>
I2C3	I2C	I2C3_SDA	PC9 <br>
I2S1	Full-Duplex Master	I2S1_CK	PA5 <br>
I2S1	Full-Duplex Master	I2S1_SDO	PA7 <br>
I2S1	Full-Duplex Master	I2S1_WS	PA15 (JTDI) <br>
I2S1	Full-Duplex Master	I2S1_SDI	PB4 (NJTRST) <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_BK1_IO0	PD11 <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_BK1_IO1	PD12 <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_BK1_IO2	PE2 <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_BK1_IO3	PD13 <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_BK1_NCS	PB6 <br>
QUADSPI	Bank1 with Quad SPI Lines	QUADSPI_CLK	PB2 <br>
RCC	Crystal/Ceramic Resonator	RCC_OSC_IN	PH0-OSC_IN (PH0) <br>
RCC	Crystal/Ceramic Resonator	RCC_OSC_OUT	PH1-OSC_OUT (PH1) <br>
RCC	Crystal/Ceramic Resonator	RCC_OSC32_IN	PC14-OSC32_IN (OSC32_IN) <br>
RCC	Crystal/Ceramic Resonator	RCC_OSC32_OUT	PC15-OSC32_OUT (OSC32_OUT) <br>
SPI2	Full-Duplex Master	SPI2_MISO	PC2_C <br>
SPI2	Full-Duplex Master	SPI2_MOSI	PC1 <br>
SPI2	Full-Duplex Master	SPI2_SCK	PB13 <br>
SYS	SysTick	SYS_VS_Systick	VP_SYS_VS_Systick <br>
TIM1	Encoder Mode	TIM1_CH1	PE9 <br>
TIM1	Encoder Mode	TIM1_CH2	PE11 <br>
TIM2	Internal Clock	TIM2_VS_ClockSourceINT	VP_TIM2_VS_ClockSourceINT <br>
TIM2	PWM Input on CH1	TIM2_CH1	PA0 <br>
USART1	Asynchronous	USART1_RX	PB15 <br>
USART1	Asynchronous	USART1_TX	PB14 <br>
USART3	Asynchronous	USART3_RX	PB11 <br>
USART3	Asynchronous	USART3_TX	PB10 <br>
<br>
<br>

