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
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Funcionalidades](#funcionalidades)
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
  <div align="center">
      <img width="800px" src="https://github.com/Kenjibercysec/Aula-20-01-Tarefa-1/blob/main/src/image.png" />
      <p>Fig 1. Projeto no simulador .</p>
   </div>
   
## Estrutura do Projeto

- **ws2812b.c**: Código responsável pela configuração e controle da matriz de LEDs.
- **keyPad4x4.c**: Funções para leitura e controle do teclado matricial.
- **PIO.c**: Biblioteca para controle do PIO (Programmable Input/Output) do Raspberry Pi Pico W.
- **desenho.c**: Funções para definição das animações a serem exibidas na matriz de LEDs.
- **funcoes.c**: Funções auxiliares para controle do sistema.
- **New Piskel.c**: Arquivo com animações exportadas do Piskel.

## Funcionalidades 

- **Tecla A**: Desliga todos os LEDs.
- **Tecla B**: Liga todos os LEDs na cor azul com 100% de luminosidade.
- **Tecla C**: Liga todos os LEDs na cor vermelha com 80% de luminosidade.
- **Tecla D**: Liga todos os LEDs na cor verde com 50% de luminosidade.
- **Tecla #**: Liga todos os LEDs na cor branca com 20% de luminosidade.
- **Tecla * (asterisco)**: Reinicia o Raspberry Pi Pico W para o modo de gravação.
- **Tecla 1** a **Tecla 4**: .
- **Tecla 2**: Inicia uma animação.
- **Tecla 5**: Inicia uma animação.
- **Tecla 6**: Inicia uma animação com efeito de transição de cores ("Matrix Reload").
- **Tecla 8**: Inicia uma animação.
- **Tecla 9**: Ação para animação não detalhada no código.
- **Teclado Matricial 4x4**: Captura as teclas pressionadas e executa as ações correspondentes.
- **Matriz de LEDs 5x5**: Controla os LEDs de acordo com a tecla pressionada.
- **Menu no Terminal**: Exibe instruções e opções de animação e controle de LEDs no terminal.

## Como Executar

### Pré-requisitos

1. **Git**: Certifique-se de ter o Git instalado no seu sistema. 
2. **VS Code**: Instale o Visual Studio Code, um editor de código recomendado para desenvolvimento com o Raspberry Pi Pico.
3. **Pico SDK**: Baixe e configure o SDK do Raspberry Pi Pico, conforme as instruções da documentação oficial.
4. **Simulador Wokwi**: Utilize o simulador de eletrônica Wokwi para simular o projeto, caso não tenha acesso à placa física.
5. **Conexão USB**: Certifique-se de que o Raspberry Pi Pico W esteja conectado via USB quando for testar o código.

### Passos para Execução

1. **Clonar o repositório**: Clone o repositório utilizando o comando Git no terminal:
   
   ```bash
   git clone https://github.com/Kenjibercysec/Aula-20-01-Tarefa-1.git
   ```
2. Abrir no VS Code: Abra a pasta clonada no VS Code e no terminal do VS Code, vá até a pasta do projeto.
4. Compilar o código.

## Testes Realizados
Alguns testes foram realizados para garantir o funcionamento correto do projeto:

1. **Tecla B, C e D.**  
   <div align="center">
      <img width="800px" src="https://github.com/Kenjibercysec/Aula-20-01-Tarefa-1/blob/main/src/tecla-b-c-d.gif" />
      <p>Fig 2. Tecla B, C e D .</p>
   </div>
2. **Tecla A e #.**  
   <div align="center">
      <img width="800px" src="https://github.com/Kenjibercysec/Aula-20-01-Tarefa-1/blob/main/src/tecla-A-%23.gif" />
      <p>Fig 3. Tecla A e # .</p>
   </div>

   
## Vídeo Demonstração

## Autores

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/nailasuely" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/98486996?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Naila Suele </b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/Ukobir" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/139288116?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Leonardo Romão </b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/Kenjibercysec" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/105324711?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Silas Kenji </b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/ArthurKleberAK" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/191928515?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Arthur Kleber </b></sub>
    </td>
    <td align="center">
      <a href="https://github.com/codedanilo" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/143664389?v=4" width="100px;" alt=""/>
      </a>
      <br /><sub><b> Danilo Silveira </b></sub>
    </td>
  </tr>
</table>

