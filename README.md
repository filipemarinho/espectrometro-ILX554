# espectrometro-esperto

Esse é o projeto  de um espectrômetro optico.

Vou tentar usar isso para me organizar melhor e reunir as informações.

Eis o que devo fazer:
-Phase Lock com a rotação do espelho n/
-Ler a voltagem de um fotosensor que está associada com o deslocamento angular do espelho
-Calcular o comprimento de onda para a voltagem lida

<p>
  Phase Lock:
Vou usar um sensor de infravermelho pronto para gerar um sinal de sincronização.
Frequencia de rotação: ~500Hz
Número de faces no espelho: 4
Leitura: + de 2kHz 
<p>

O que fazer com esse sinal? IC comparador para gerar pulsos vs. digitalizar

<p>

Leitura da voltagem:
Fazer com o ADC do arduino ou do ESP? ou o ESP controlando o arduino?
Modo de leitura intermitente, mais rápidez para coleta de dados.
Python tem alguma vantagem? aparentemente não
Taxa de leitura: 14kHz
Tenho ~80us para cada leitura
<p>


<p>

Fotosensor:
<p>

Calculo
