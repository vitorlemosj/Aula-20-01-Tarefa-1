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

// Para simular na placa troque o scanf no loop da main

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

char tecla;

// teclado
const uint column[4] = {5, 4, 3, 2};
const uint line[4] = {10, 9, 8, 6};

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
    desenhaMatriz(desliga, 0, 0.8);

    while (true)
    {
        tecla = pico_keypad_get_key(); // Comente esta linha para simular na placa
        // scanf("%c", &tecla); // para simular na placa
        if (tecla)
        {

            switch (tecla)
            {
            case '1':

                break;

            case '2':
                printf("Iniciando animação...\n");
                animaNome();
                break;
            case '3':

                break;

            case '4':

                break;

            case '5':
                // Animação Arthur
                for (int i = 0; i < 5; i++)
                {
                    desenhaMatriz(frame1[i], 2000, 0.5);
                }
                desenhaMatriz(desliga, 0, 0.8);
                break;

            case '6':
                // Animação
                //  OBS: A função convert troca as cores durante a conversão 16^8 >> 2^8 do arquivo exportado do https://www.piskelapp.com/
                for (int i = 0; i < 50; i++)
                {
                    convert(raining[i % 10], 1e3, 0.4);
                }
                desenhaMatriz(desliga, 0, 0.8);
                break;

                break;

            case '7':
                // Animação Gustavo Netto
               for (int i = 0; i < 4; i++)
                {
                    desenhaMatriz(matrizNet[i], 2000, 0.8);
                }
                
                break;

            case '8':
                // Animação Silas Kenji
               for (int i = 0; i < 5; i++)
                {
                    desenhaMatriz(matrizKen[i], 2000, 0.8);
                }

                break;

            case '9':

                break;

            case 'A':
            case 'a':
                printf("Desliga os LEDs\n");
                desenhaMatriz(desliga, 0, 0.8);
                break;

            case 'B':
            case 'b':
                printf("Liga os LEDs na cor Azul em 100%%\n");
                desenhaMatriz(azul, 2000, 1.0);
                break;

            case 'C':
            case 'c':
                printf("Liga os LEDs na cor Vermelha em 80%%\n");
                desenhaMatriz(vermelho, 2000, 0.8);
                break;

            case 'D':
            case 'd':
                printf("Liga os LEDs na cor Verde em 50%%\n");
                desenhaMatriz(verde, 2000, 0.5);
                break;

            case '#':
                printf("Liga os LEDs na cor Branca em 20%%\n");
                desenhaMatriz(branco, 2000, 0.2);
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