# espectrometro-esperto


Esse é o projeto de construção de um espectrômetro.
Vou tentar usar isso para me organizar melhor e reunir as informações.

## Getting Started

O código do arquivo .ino é responsável por gerar o clock e fazer a leitura analógica do ILX-554B. A montagem utilizada foi quase identica ao do datasheet do sensor, o transistor no pino 1 não é absolutamente necessário.


#### OBS: Condicione o sinal de saida para 0-3V para ler os valores analógicos e faça a conversão lógica dos sinais clock para 5V.
#### OBS2: O código usa os dois cores do ESP32, mas com poucas modificações é possível utilizar com microcontroladores de um core.

## Material necessário:
 - Grade de difração
 - Sensor CCD ILX-554B
 - ESP32 DEV KIT funcionando na Arduino IDE
 
## Testes

O sensor é MUITO sensivel então coloque algumas fitas na frente do sensor, diminua a luz a luz ambiente e faça um teste tampando uma parte do sensor com o dedo para verificar o funcionamento básico.


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


