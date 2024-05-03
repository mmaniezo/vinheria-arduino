# Projeto de Controle de Ambiente para Armazenamento de Vinhos
Este projeto utiliza um Arduino para monitorar e controlar as condições ambientais ideais para o armazenamento de vinhos. O Arduino é responsável por monitorar a temperatura, umidade e luminosidade, garantindo que as condições estejam dentro dos limites ideais para preservar a qualidade dos vinhos.

Componentes Utilizados
-Arduino Uno: Plataforma de prototipagem eletrônica.
-Sensor de Temperatura e Umidade DHT22: Utilizado para medir a temperatura e umidade ambiente.
-Sensor de Luminosidade (LDR): Utilizado para detectar os níveis de luminosidade no ambiente.
-Módulo de Display LCD I2C: Utilizado para exibir as informações de temperatura e umidade.
-LEDs e Buzzer: Utilizados para fornecer feedback visual e sonoro sobre as condições do ambiente.

Conexões
-O sensor de temperatura e umidade DHT22 está conectado ao pino digital 12 do Arduino.
-O sensor de luminosidade (LDR) está conectado ao pino analógico A0 do Arduino.
-O buzzer está conectado ao pino digital 10 do Arduino.
-Os LEDs estão conectados aos pinos digitais 2 (verde), 4 (vermelho) e 7 (amarelo) do Arduino.
-O display LCD I2C está conectado ao Arduino através da comunicação I2C.

Funcionamento
-O Arduino lê continuamente os valores dos sensores de temperatura, umidade e luminosidade. Com base nesses valores, ele controla os LEDs e o buzzer para fornecer feedback sobre as condições do ambiente de armazenamento de vinhos:

-Temperatura: Se a temperatura estiver acima de 15°C, o LED vermelho e o LED correspondente ao controle de temperatura são ligados, e o buzzer emite um som de alerta.
-Umidade: Se a umidade estiver acima de 80% ou abaixo de 60%, o LED correspondente ao controle de umidade é ligado, e o buzzer emite um som de alerta.
-Luminosidade: Se a luminosidade estiver abaixo de 500 (indicando baixa luminosidade), o LED verde é ligado. Se estiver entre 500 e 1000 (nível de alerta), o LED amarelo é ligado. Se estiver acima de 1000 (indicando alta luminosidade), o LED vermelho é ligado e o buzzer emite um som de alerta.
-Além disso, as informações de temperatura e umidade são exibidas no display LCD em tempo real.

Como Usar
-Monte o circuito conforme as conexões descritas acima.
-Carregue o código do Arduino fornecido neste repositório para o Arduino.
-Alimente o Arduino com uma fonte de energia adequada.
-Observe o feedback dos LEDs e do buzzer, bem como as leituras de temperatura e umidade no display LCD.
