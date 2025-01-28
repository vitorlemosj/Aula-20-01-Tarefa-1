#include "matriz_led.pio.h"
#include <stdio.h>
#include <stdlib.h>

// número de LEDs
#define NUM_PIXELS 25

// imprimir valor binário
void imprimir_binario(int num)
{
    int i;
    for (i = 31; i >= 0; i--)
    {
        (num & (1 << i)) ? printf("1") : printf("0");
    }
    printf("\n");
}

// rotina para definição da intensidade de cores do led
uint32_t matrix_g(double b, double r, double g)
{
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

// rotina para acionar a matrix de leds - ws2812b
void desenho_pio_1(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)
{
    for (int16_t i = 0; i < NUM_PIXELS; i++)
    {
        valor_led = matrix_g(b = 0.0, r = 0.0, desenho[24 - i]);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
    imprimir_binario(valor_led);
}


void waitUSB() {
     printf("Aguardando a comunicação USB...\n");

    // Espera até que a comunicação USB esteja conectada
    while (!stdio_usb_connected())
    {
        // O dispositivo USB ainda não foi conectado
        sleep_ms(100); // Espera 100ms antes de checar novamente
    }

    // Quando a comunicação USB for detectada, a execução continua
    printf("Comunicação USB detectada!\n");
}

// Exibe uma mensagem informativa inicial no terminal
void menu()
{
    printf("\t## Acionamento de animações na matriz de LED 5x5 pelo Teclado 4x4 ##\n");
    printf("Possui os seguintes comandos:\n");
    printf("1 - Aperte A ...\n");
    printf("2 - Aperte B ...\n");
    printf("3 - Aperte C ...\n");
    printf("4 - Aperte D ...\n");
    printf("5 - Aperte * Modo de gravação\n");
    printf("6 - Aperte # ...\n");
    printf("7 - Aperte 2 ...\n");
    printf("8 - Aperte 3 ...\n");
    printf("9 - Aperte 4 ...\n");
    printf("10 - Aperte 5 ...\n");
    printf("6 - Aperte 6 para Animação Matrix Reload (poor quality)\n");
    printf("Obs: É necessário segurar a brevemente para o comando ser registrado\n");
}