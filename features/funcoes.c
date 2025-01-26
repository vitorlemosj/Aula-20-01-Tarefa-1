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