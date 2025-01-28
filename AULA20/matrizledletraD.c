case '1':
    {
        // Matriz para a letra 'D' (cada número representa um LED aceso ou apagado)
        int letraD[5][5] = {
            {1, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 1, 0, 0}
        };

        // Animação: Mostra a letra D piscando.
        for (int i = 0; i < 10; i++) // 10 ciclos de animação
        {
            // Se for um número ímpar, acende a letra, senão apaga
            float intensidade = (i % 2 == 0) ? 0.5 : 0.0; // Alterna entre aceso (0.5) e apagado (0)

            // Desenha a letra 'D' na matriz de LEDs
            for (int y = 0; y < 5; y++)
            {
                for (int x = 0; x < 5; x++)
                {
                    // Se a posição da letra 'D' for 1, acende o LED
                    if (letraD[y][x] == 1)
                    {
                        int index = getIndex(x, y);
                        npSetLED(index, 0, intensidade, 0);  // Usa verde (0, intensidade, 0)
                    }
                    else
                    {
                        int index = getIndex(x, y);
                        npSetLED(index, 0, 0, 0);  // Apaga o LED
                    }
                }
            }

            npWrite();  // Atualiza a matriz de LEDs
            sleep_ms(500); // Intervalo de 500ms entre cada ciclo
        }
    }
    break;
