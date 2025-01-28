<h1 align="center">
  <br>
    <img width="400px" src="https://github.com/Kenjibercysec/Aula-20-01-Tarefa-1/blob/main/src/logo.png">
  <br>
  Microcontroladores – GPIO - Parte 2
  <br>
</h1>
<div align="center">

</div>

<div align="center"> 
  
Esta atividade tem como objetivo usar o Raspberry Pi Pico W para controlar uma matriz de LEDs 5x5, criando animações que são ativadas por um teclado matricial 4x4. O projeto envolve programação
em C, integração com o SDK do Raspberry Pi Pico e o simulador Wokwi. 
</div>

<details open="open">
<summary>Sumário</summary>
  
- [Requisitos](#requisitos)
- [Componentes Utilizados](#componentes-utilizados)
- [Objetivos](#objetivos)
- [Comandos Utilizados no Teclado](#comandos-utilizados-no-teclado)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como Executar](#como-executar)
  - [Pré-requisitos](#pré-requisitos)
  - [Passos para Execução](#passos-para-execução)
- [Testes Realizados](#testes-realizados)
- [Vídeo Demonstração](#vídeo-demonstração)
- [Autores](#autores-do-subgrupo-3)

</details>

## Requisitos

O projeto deve cumprir os seguintes requisitos:

1. **Teclado Matricial 4x4**: As teclas de 0 a 9 devem acionar animações. As teclas A, B, C, D e # devem ter funções específicas.
2. **Matriz de LEDs 5x5 (WS2812)**: Deve ser capaz de exibir animações com diferentes cores e intensidades.
3. **FPS (Frames por segundo)**: Definido pela equipe, com um mínimo de 5 frames por animação.
4. **Ação com Teclas Específicas**:
    - Tecla `A`: Desliga todos os LEDs.
    - Tecla `B`: Liga os LEDs na cor azul (100% intensidade).
    - Tecla `C`: Liga os LEDs na cor vermelha (80% intensidade).
    - Tecla `D`: Liga os LEDs na cor verde (50% intensidade).
    - Tecla `#`: Liga os LEDs na cor branca (20% intensidade).
    - Tecla `*`: Habilita o modo de gravação (Reboot).
5. **Animações**: Deve ser gerado um conjunto de animações, cada uma com pelo menos 5 frames.

## Componentes Utilizados

1. **Raspberry Pi Pico W**: Microcontrolador para controle do sistema.
2. **Teclado Matricial 4x4**: Interface para entrada de comandos.
3. **Matriz de LEDs WS2812 (5x5)**: Exibição de animações.
4. **VS Code**: Ambiente de desenvolvimento para código em linguagem C.
5. **Simulador Wokwi**: Para simulação do circuito.

## Estrutura do Código

- **ws2812b.c**: Código responsável pela configuração e controle da matriz de LEDs.
- **keyPad4x4.c**: Funções para leitura e controle do teclado matricial.
- **PIO.c**: Biblioteca para controle do PIO (Programmable Input/Output) do Raspberry Pi Pico W.
- **desenho.c**: Funções para definição das animações a serem exibidas na matriz de LEDs.
- **funcoes.c**: Funções auxiliares para controle do sistema.
- **New Piskel.c**: Arquivo com animações exportadas do Piskel.

## Autores

<table>
  <tr>
    <td align="center"><img src="https://avatars.githubusercontent.com/u/98486996?v=4" width="100px;" alt=""/><br /><sub><b> Naila Suele </b></sub></a></td>
    <td align="center"><img src="https://avatars.githubusercontent.com/u/139288116?v=4" width="100px;" alt=""/><br /><sub><b> Leonardo Romão </b></sub></a></td>
    <td align="center"><img src="https://avatars.githubusercontent.com/u/105324711?v=4" width="100px;" alt=""/><br /><sub><b> Silas Kenji </b></sub></a></td>
    <td align="center"><img src="https://avatars.githubusercontent.com/u/191928515?v=4" width="100px;" alt=""/><br /><sub><b> Arthur Kleber </b></sub></a></td>
  </tr>
</table>

