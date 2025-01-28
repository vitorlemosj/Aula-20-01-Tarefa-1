#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"
#include "matriz_led.pio.h"
// Adicionar desenho
#include "desenho/matrixReload.c"
#include "desenho/drawing.c"

#define NUM_PIXELS 25
#define LED_PIN 10 // pino de saída do led (Na placa é 7 no wokwi é 10)

struct pixel_t
{
  uint8_t G, R, B;
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t;

// Declaração do buffer de pixels que formam a matriz.
npLED_t leds[NUM_PIXELS];

PIO np_pio;
uint sm;

void npInit(uint pin)
{

  uint offset = pio_add_program(pio0, &pio_matrix_program);
  np_pio = pio0;

  sm = pio_claim_unused_sm(np_pio, false);
  if (sm < 0)
  {
    np_pio = pio1;
    sm = pio_claim_unused_sm(np_pio, true);
  }

  pio_matrix_program_init(np_pio, sm, offset, pin);

  for (uint i = 0; i < NUM_PIXELS; ++i)
  {
    leds[i].R = 0;
    leds[i].G = 0;
    leds[i].B = 0;
  }
}

void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b)
{
  leds[index].R = r;
  leds[index].G = g;
  leds[index].B = b;
}

void npClear()
{
  for (uint i = 0; i < NUM_PIXELS; ++i)
    npSetLED(i, 0, 0, 0);
}

void bootsel()
{
  reset_usb_boot(0, 0);
}

uint8_t coluna[4] = {5, 4, 3, 2};
uint8_t linha[4] = {9, 8, 7, 6};

char teclas[4][4] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

void inicializar_teclado()
{
  for (int i = 0; i < 4; i++)
  {
    gpio_init(linha[i]);
    gpio_set_dir(linha[i], GPIO_OUT);
    gpio_put(linha[i], 1);

    gpio_init(coluna[i]);
    gpio_set_dir(coluna[i], GPIO_IN);
    gpio_pull_up(coluna[i]);
  }
}

char ler_teclado(uint8_t *colunas, uint8_t *linhas)
{
  for (int i = 0; i < 4; i++)
  {
    gpio_put(linhas[i], 0);
    for (int j = 0; j < 4; j++)
    {
      if (!gpio_get(colunas[j]))
      {
        gpio_put(linhas[i], 1);
        return teclas[i][j];
      }
    }
    gpio_put(linhas[i], 1);
  }
  return 0;
}

// MATRIZ DE LEDS
uint matrix_rgb(float r, float g, float b)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

void npWrite()
{
  for (uint i = 0; i < NUM_PIXELS; ++i)
  {
    pio_sm_put_blocking(np_pio, sm, leds[i].G);
    pio_sm_put_blocking(np_pio, sm, leds[i].R);
    pio_sm_put_blocking(np_pio, sm, leds[i].B);
  }
  sleep_us(100);
}

// Função para converter a posição do matriz para uma posição do vetor.
int getIndex(int x, int y)
{
  // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
  // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
  if (y % 2 == 0)
  {
    return 24 - (y * 5 + x); // Linha par (esquerda para direita).
  }
  else
  {
    return 24 - (y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
  }
}

void desenhaMatriz(int matriz[5][5][3], int tempo_ms, float intensidade)
{
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      npSetLED(posicao, (matriz[coluna][linha][0] * intensidade), (matriz[coluna][linha][1] * intensidade), (matriz[coluna][linha][2] * intensidade));
    }
  }
  npWrite();
  sleep_ms(tempo_ms);
  npClear();
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)
{
  for (int16_t i = 0; i < NUM_PIXELS; i++)
  {
    valor_led = matrix_rgb(desenho[i] * r, desenho[i] * g, desenho[i] * b);
    pio_sm_put_blocking(pio, sm, valor_led);
  }
}



double apagar_leds[25] = {0.0, 0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0, 0.0,
                          0.0, 0.0, 0.0, 0.0, 0.0};

double desenho1_1[25] = {0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3};

double desenho1_2[25] = {0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0};

double desenho1_3[25] = {0.3, 0.3, 0.0, 0.0, 0.3,
                         0.3, 0.0, 0.0, 0.0, 0.3,
                         0.0, 0.0, 0.0, 0.0, 0.0,
                         0.3, 0.0, 0.0, 0.0, 0.3,
                         0.3, 0.3, 0.0, 0.0, 0.3};

double desenho1_4[25] = {0.3, 0.3, 0.3, 0.0, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.0,
                         0.3, 0.0, 0.3, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.0,
                         0.3, 0.3, 0.3, 0.0, 0.0};

double desenho1_5[25] = {0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.3, 0.0, 0.3};

double desenho1_6[25] = {0.0, 0.3, 0.0, 0.3, 0.0,
                         0.3, 0.0, 0.0, 0.0, 0.3,
                         0.0, 0.0, 0.0, 0.0, 0.0,
                         0.3, 0.0, 0.0, 0.0, 0.3,
                         0.0, 0.3, 0.0, 0.3, 0.0};

int main()
{
  PIO pio = pio0;
  bool frequenciaClock;
  uint16_t i;
  uint valor_led;
  float r = 0.0, b = 0.0, g = 0.0;

  frequenciaClock = set_sys_clock_khz(128000, false);
  stdio_init_all();
  inicializar_teclado();
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  waitUSB();

  printf("iniciando a transmissão PIO");
  if (frequenciaClock)
    printf("clock set to %ld\n", clock_get_hz(clk_sys));

  // configurações da PIO
  uint offset = pio_add_program(pio, &pio_matrix_program);
  uint sm = pio_claim_unused_sm(pio, true);
  pio_matrix_program_init(pio, sm, offset, LED_PIN);

  while (true)
  {

    char tecla = ler_teclado(coluna, linha);

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
      
      while (true) {
    for (int i = 0; i < 25; i++)
        {
          desenho_pio_1(blink[i % 5], valor_led, pio, sm, r, g, b);
          sleep_ms(1000);
        }
        desenho_pio(blink[5], valor_led, pio, sm, r, g, b);
        break;

        break;

      case '6':
        for (int i = 0; i < 25; i++)
        {
          desenho_pio_1(Raining[i % 5], valor_led, pio, sm, r, g, b);
          sleep_ms(200);
        }
        desenho_pio(Raining[5], valor_led, pio, sm, r, g, b);
        break;

        break;

      case '7':
      


        break;

      case 8:

        int matrizK[5][5][3] = {
            {{255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {255, 0, 0}},
            {{255, 0, 0}, {0, 0, 255}, {0, 0, 0}, {0, 0, 255}, {255, 0, 0}},
            {{255, 0, 0}, {0, 0, 0}, {0, 255, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}};

        desenhaMatriz(matrizK, 2000, 0.8);

        int matrizE[5][5][3] = {
            {{0, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 255, 0}},
            {{0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 0}},
            {{0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 0}},
            {{0, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 0}},
            {{0, 255, 0}, {0, 255, 0}, {0, 0, 0}, {0, 255, 0}, {0, 255, 0}}};

        desenhaMatriz(matrizE, 2000, 0.8);

        int matrizN[5][5][3] = {
            {{255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}}};

        desenhaMatriz(matrizN, 2000, 0.8);

        int matrizJ[5][5][3] = {
            {{0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}},
            {{0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}},
            {{0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}},
            {{0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}},
            {{0, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 255, 255}}};

        desenhaMatriz(matrizJ, 2000, 0.8);

        int matrizI[5][5][3] = {
            {{255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}},
            {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
            {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
            {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
            {{255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}, {255, 255, 0}}};

        desenhaMatriz(matrizI, 2000, 0.8);

        break;

      case '9':

        break;

      case 'A':

        npClear();
        r = 0;
        g = 0;
        b = 0;
        apagar_leds;
        break;

      case 'B':
        r = 0;
        g = 0;
        b = 1;
        break;

      case 'C':
        r = 0.8;
        g = 0;
        b = 0;
        break;

      case 'D':
        r = 0;
        g = 0.5;
        b = 0;
        break;

      case '#':
        r = 0.2;
        g = 0.2;
        b = 0.2;
        break;

      case '*':

        printf("HABILITANDO O MODO GRAVAÇÃO");
        bootsel();
        break;

      default:
        printf("Tecla não configurada\n");
      }
    }
    sleep_ms(200);
  }
}
}