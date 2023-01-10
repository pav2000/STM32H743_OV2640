# STM32H743_OV2640
Плата разработчика для отладки тестирования технологии cube.AI на чипе stm32h743.<br>
В качестве ядра используется готовая плата на микроконтроллере stm32h743 (https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M) купленная на ali.
На плате смонтирована камера OV2640 (DCMI), дисплей ILI9341 (spi) для тестирования cube.AI.
Для расширения функционала добавлен следующий функционал:<br>
- микрофон INMP441 по интрефейсу I2S <br>
- вход для подключения оптического энкодера на чипе LS7366R-S (spi)<br>
- вход для подключения оптического энкодера на аппаратном таймере TIM1<br>
- две кнопки <br>
- выход UART на на uart1 <br>
- выход RS-232 (MAX3232) на uart3<br>
- чип памяти (qspi) на плате MCUDEV_DEVEBOX_H7XX_M<br>
<br>
Внешний вид платы ver 1.0: <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/view01.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/view02.png" width="480" /> <br>
<br>
