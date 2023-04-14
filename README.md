# STM32H743_OV2640
Development board for testing cube.AI technology on stm32h743 chip.<br>
Machine learning in embedded systems has become a reality, with the
first tools for neural network firmware development already being made
available for ARM microcontroller developers. This board the use of
one of such tools, namely the STM X-Cube-AI, on mainstream ARM Cortex-M
microcontrollers, analyzing their performance, and comparing support and
performance of other two common supervised ML algorithms, namely Support
Vector Machines (SVM) and k-Nearest Neighbours (k-NN). Results on three
datasets show that X-Cube-AI provides quite constant good performance even
with the limitations of the embedded platform. The workflow is well integrated
with mainstream desktop tools, such as Tensorflow and Keras.<br>
<br>
The core is a ready-made board on the stm32h743 microcontroller (https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M) purchased on ali.
The board has an OV2640 camera (DCMI), an ILI9341 display (spi) for cube.AI testing.
The following elements have been added to extend functionality:<br>
- INMP441 microphone via I2S interface <br>
- input for connecting an optical encoder on a chip LS7366R-S (spi)<br>
- input for connecting an optical encoder on the hardware timer TIM1<br>
- two buttons <br>
- UART output on uart1 <br>
- RS-232 output (MAX3232) on uart3<br>
- memory chip (qspi) on the board MCUDEV_DEVEBOX_H7XX_M<br>
- connector for connecting i2c devices <br>
 <br>
 <br>
Плата разработчика для тестирования технологии cube.AI на чипе stm32h743.<br>
Машинное обучение во встроенных системах стало реальностью уже созданы первые инструменты для разработки
и прошивки нейронной сети микроконтроллер ARM. Эта плата позволяет использовать
один из таких инструментов, а именно STM X-Cube-AI, на основной платформе ARM Cortex-M.
микроконтроллеров, анализируя их производительность и сравнивая поддержку и
производительность двух других распространенных алгоритмов контролируемого машинного обучения, а именно поддержки
метода опорных векторов (SVM) и метод k-ближайших соседей (k-NN). Результаты по трем
наборам данных показывают, что X-Cube-AI обеспечивает постоянную хорошую производительность даже
с ограничениями встроенной платформы. Рабочий процесс хорошо интегрирован
с основными настольными инструментами, такими как Tensorflow и Keras.<br>
В репозитарии представлено несколько примеров которые показывают использование cube.AI на микроконтроллере STM32H.
<br>
В качестве ядра используется готовая плата на микроконтроллере stm32h743 (https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M) купленная на ali.
На плате смонтирована камера OV2640 (DCMI), дисплей ILI9341 (spi) для тестирования cube.AI.
Для расширения функционала добавлены следующие элементы:<br>
- микрофон INMP441 по интрефейсу I2S <br>
- вход для подключения оптического энкодера на чипе LS7366R-S (spi)<br>
- вход для подключения оптического энкодера на аппаратном таймере TIM1<br>
- две кнопки <br>
- выход UART на на uart1 <br>
- выход RS-232 (MAX3232) на uart3<br>
- чип памяти (qspi) на плате MCUDEV_DEVEBOX_H7XX_M<br>
- разъем для подключения i2c устройств <br>
<br>
Внешний вид платы ver 1.0: <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/view01.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/view02.png" width="480" /> <br>
Фото собранной платы ver 1.0: <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/real01.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/Board/real02.jpg" width="480" /> <br>
<br>
