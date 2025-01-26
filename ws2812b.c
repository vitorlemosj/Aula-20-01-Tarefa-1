#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"
#include "features/keyPad4x4.c"
#include "features/PIO.c"
#include "features/desenho.c"
#include "features/funcoes.c"
#include "features/New Piskel.c"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 10

// teclado
const uint column[4] = {5, 4, 3, 2};
const uint line[4] = {9, 8, 7, 6};

int main()
{
    // Iniciar teclado
    pico_keypad_init(column, line);

    // Inicializa entradas e saídas.
    stdio_init_all();
    waitUSB();
    menu();

    // Inicializa matriz de LEDs NeoPixel.
    npInit(LED_PIN);
    npClear();

    while (true)
    {
        char tecla = pico_keypad_get_key();
        if (tecla)
        {
            printf("Tecla pressionada: %c\n", tecla);

            switch (tecla)
            {
            case '1':

                break;

            case '2':

                break;

            case '3':

                break;

            case '4':

                break;

            case '5':

                break;

            case '6':
            //OBS: A função convert troca as cores durante a conversão
                for (int i = 0; i < 10; i++)
                {
                 convert(raining[i], 1e3);
                }
                desenhaMatriz(desliga, 0, 0.8);
                break;

                break;

            case '7':

                break;

            case '8':

                desenhaMatriz(matrizK, 2000, 0.8);
                desenhaMatriz(matrizE, 2000, 0.8);
                desenhaMatriz(matrizN, 2000, 0.8);
                desenhaMatriz(matrizJ, 2000, 0.8);
                desenhaMatriz(matrizI, 2000, 0.8);
                desenhaMatriz(desliga, 2000, 0.8);

                break;

            case '9':

                break;

            case 'A':

                break;

            case 'B':

                break;

            case 'C':

                break;

            case 'D':

                break;

            case '#':

                break;

            case '*':

                printf("HABILITANDO O MODO GRAVAÇÃO");
                reset_usb_boot(0, 0);
                break;

            default:
                printf("Tecla não configurada\n");
            }
        }
        sleep_ms(100);
    }
}