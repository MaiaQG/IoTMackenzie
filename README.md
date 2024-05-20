
Trabalho de Monitoramento da qualidade da água IoT - UNIVERSIDADE PRESBITERIANA MACKENZIE

A água é o elemento mais importante para maioria das dos processos humanos relacionados ao dia a dia, utilizamos a água não só para hidratação, como também para agricultura, limpeza e diversos processos profissionais como produção de alguns tipos de medicamento na biomedicina. A ideia deste projeto é desenvolver um sistema de monitoramento da água, onde temos 3 parâmetros principais, PH, temperatura e umidade.
	A Agência Nacional de Águas e Saneamento Básico (ANA) monitora a qualidade das águas superficiais e subterrâneas do país, e eles tem os dados fornecidos por órgãos estaduais gestores desses recursos hídricos, e por meio destes dados eles conseguem ajudar a fornecer melhor qualidade nos recursos que utilizam água, principalmente para o abastecimento público. 
	Então este projeto será feito para ajudar na medição de PH, temperatura e umidade em águas superficiais, ajudando a fornecer melhor qualidade nos recursos e definindo se a água está dentro dos parâmetros para agricultura e fornecimento de recurso público.


Objetivo principal é medir o PH, a temperatura da água e a umidade do solo enviar essa informação para um servidor MQTT conforme abaixo :
1- Conectar a rede WiFi e ao Servidor MQTT
2- Medir as informações dos sensores
3- Publica as informações dos sensores online em um tópico MQTT
4- Conseguimos buscar a informação para qualquer aplicação utilizando MQTT explorer com as validações corretas.
5- Caso a conexão MQTT seja perdida, ele se reconecta automaticamente.
6- Caso deseje atualizar os dados da tabela, basta selecionar o botão que ele faz a consulta dos últimos dados da tabela.

Materiais utilizados : 
1- Protoboard
2- Jumers
3- nodeMCU
4- Arduino
5- Sensor de PH e temperatura
6- Sensor de umidade
Diagrama: 
![image](https://github.com/MaiaQG/IoTMackenzie/assets/78659159/763a2595-f508-4863-bd0b-c47bf0cf0741)
