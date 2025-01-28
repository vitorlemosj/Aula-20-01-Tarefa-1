#include <stdio.h>
#include <stdlib.h>


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

void menu()
{
    printf("\t## Acionamento de animações na matriz de LED 5x5 pelo Teclado 4x4 ##\n");
    printf("Possui os seguintes comandos:\n");
    printf("1 - Aperte A para desligar os LEDs\n");
    printf("2 - Aperte B para ligar os LEDs na cor Azul em 100%%\n");
    printf("3 - Aperte C para ligar os LEDs na cor Vermelha em 80%%\n");
    printf("4 - Aperte D para ligar os LEDs na cor Verde em 50%%\n");
    printf("5 - Aperte * Modo de gravação\n");
    printf("6 - Aperte # para ligar os LEDs na cor Branca em 20%%\n");
    printf("7 - Aperte 1 ...\n");
    printf("8 - Aperte 2 para Animação de Naila\n");
    printf("9 - Aperte 3 ...\n");
    printf("10 - Aperte 4 ...\n");
    printf("11 - Aperte 5 para Animação de Arthur\n");
    printf("12 - Aperte 6 para Animação de Leonardo: Matrix Reload (poor quality)\n");
    printf("13 - Aperte 7 ...\n");
    printf("14 - Aperte 8 para Animação de Kenji\n");
    printf("15 - Aperte 5 ...\n");
    printf("Obs: É necessário segurar a brevemente para o comando ser registrado\n");
}