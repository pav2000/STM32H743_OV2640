Пример 1 для CubeMX IDE <br>
Пакет X-CUBE-AI расширяет функциональные возможности среды STM32CubeMX, добавляя в нее автоматический генератор библиотеки
нейронной сети. Этот генератор преобразует файлы моделей предварительно обученных нейронных сетей, формируемые различными
фреймворками глубокого обучения (такими как Caffe, Keras, Lasagne, TensorFlow™ Lite и ConvNetJs), в оптимизированную по
скорости выполнения и объему памяти (ОЗУ и Flash) библиотеку. Сгенерированная библиотека автоматически интегрируется с
пользовательским приложением, в результате чего на выходе получается полностью настроенный проект, готовый к компиляции и
исполнению на микроконтроллере STM32.<br>
Пакет расширения X-CUBE-AI предназначен для создания проектов с поддержкой ИИ на базе микроконтроллеров STM32
с ядрами ARM® Cortex®-M.Текущая версия примера использует:<br>
- X-CUBE-AI версии 8.0.0; <br>
- клиентское API нейронной сети версии 1.2.0;<br>
- утилита командной строки версии 1.7.0.<br>
Предварительно обученная DL-модель Keras, используется в данном примере.<br>
<br>
Первый пример использования CUBE.AI. Используется нейросеть обученная на распозование кошка или собака.
Нейросеть имеет на входе картинку 96х96х3, где первые два числа ширина и выстота обрабатываемого изображения,
3 это RGB компоненты цвета.<br>
Для этого примера используется изображение 128х128 точек с камеры и из него берется верхний левый угол размером
96х96 пикселей.<br>
Кнопка SELECT - ставит процесс распознования на паузу. Кнопка ENTER показывает/выключает рамку на изображении которая
указывает область обработки нейросетью.<br>
Внизу экрана выводится какой класс определен нейросетью и в скобках вероятность по обоим классам (cat/dog).<br>
Внизу экрана показывается частота обновления экрана.<br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/CubeIDE/stm32h_cam_AI1/picture/ex11.jpg" width="360" /> <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/CubeIDE/stm32h_cam_AI1/picture/ex12.jpg" width="360" /> <br>
<img src="https://github.com/pav2000/STM32H743_OV2640/blob/main/CubeIDE/stm32h_cam_AI1/picture/ex13.jpg" width="360" /> <br>
<br>
<br>

