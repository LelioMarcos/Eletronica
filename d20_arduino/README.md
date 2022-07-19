# D20 Arduino
Nosso projeto envolve criar um dado de 20 lados usando o Arduino UNO e uma matriz de leds 8x8.


## Materiais usados:

### Arduino UNO

### Display MAX7219

### Buzzer Passivo
Com o buzzer, também é usado um resistor de 10ohms. Essa resistência controla o volume do som que sai no buzzer, já que esse volume é diretamente proporcional a corrente que chega no buzzer.

Va = 5v, R = 10ohms 
I = Va/R = 5 / 10 = 0.5A

## Circuito no Tinkercad
![Imagem do circuito no Tinkercad](imagens/d20_circuito.jpg)

## Código
![Código do arduino](codigo/sketch_jul12a.ino)

## Vídeo
https://youtu.be/zMl9nvj6ZbU

##Material de apoio
-Utilizamos o simulador LED MATRIX SIMULATOR - https://xantorohara.github.io/led-matrix-editor/ para desenhar os números e utilizamos parte do código disponibilizado como apoio.
-Também usamos a biblioteca externa LedControl - https://www.arduino.cc/reference/en/libraries/ledcontrol/
