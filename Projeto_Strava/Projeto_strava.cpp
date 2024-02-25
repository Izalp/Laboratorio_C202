#include<iostream>
#include<cmath> // biblioteca para fazer a formula de Haversine
#include<iomanip> // biblioteca de precis�o de casas decimais

using namespace std;

struct dados // struct para as variaveis
{
	double latitude; // latitude
	double longitude; // longitude
	double elevacao; // elevacao
	int hora; // hora
	int minuto; // minuto
	int segundo; // segundo
};
int main()
{
	dados inf[2000]; //informa��es
	int i = 0;// contador
	int b = 0;// contador
	int raio = 6371; // raio da terra
	int tempo[4000]; // tempo
	int tempo_total = 0; // tempo total decorrido
	int tempo_hora; // tempo convertido para horas
	int hora; // horas
	int minuto; // minutos
	int segundo; // segundos
	double velocidade; // velocidade
	double velocidade_media; // velocidade m�dia
	double vmax = -1000; // velocidade maxima
	double gelevacao = 0; // ganho da eleva��o
	double pelevacao = 0; // perda da eleva��o
	double maioralt = -10000; // maior altitude
	double menoralt = 10000; // menor altitude
	double pi; // valor de pi
	double quantidade = 0; // quantidade de latitudes e longitudes
	double total1, total2; // parti��es da f�rmula de Haversine
	double diferencalat[4000]; // diferen�a entre latitudes
	double diferencalong[4000]; // diferen�a entre longitudes
	double distancia[4000]; // distancia de percurso
	double distancia_total = 0; // distancia total percorrida

	//Lendo a latitude, longitude, elevacao, hora, minuto e segundo
	cin >> inf[i].latitude >> inf[i].longitude >> inf[i].elevacao >> inf[i].hora >> inf[i].minuto >> inf[i].segundo;

	// Enquanto a latitude, longitude, elevacao, hora, minuto e segundo forem diferentes de -1, entrar� no loop do while
	// Caso forem iguais a -1, sa�ra do loop
	while(inf[i].latitude != -1 && inf[i].longitude != -1 && inf[i].elevacao != -1 && inf[i].hora != -1 && inf[i].minuto != -1 && inf[i].segundo != -1)
	{
		pi = 4.0 * atan(1.0); // calculando valor de pi

		inf[i].latitude = inf[i].latitude * (pi / 180); // calculando distancia da latitude
		inf[i].longitude = inf[i].longitude * (pi / 180); // calculando distancia da longitude

		i++; // contagem de repeti��o do loop
		quantidade++; // contando quantidade de latitudes e longitudes

		//Lendo novamente latitude, longitude, elevacao, hora, minuto e segundo
		cin >> inf[i].latitude >> inf[i].longitude >> inf[i].elevacao >> inf[i].hora >> inf[i].minuto >> inf[i].segundo;
	}

	quantidade = quantidade - 1;// desconsiderando a entrada de -1

	//Calculando a f�rmula de Haversine em parti��es
	for(i = quantidade; i >= 1; i--)
	{
		diferencalat[b] = (inf[i].latitude - inf[i - 1].latitude); // calculando diferen�a entre latitudes
		diferencalong[b] = (inf[i].longitude - inf[i - 1].longitude); // calculando diferenca entre longitudes

		//calculando parti��es da f�rmula de Haversine
		total1 = sin(diferencalat[b] / 2) * sin(diferencalat[b] / 2) + cos(inf[i].latitude) * cos(inf[i - 1].latitude) * sin(diferencalong[b] / 2) * sin(diferencalong[b] / 2);
		total2 = 2 * atan2(sqrt(total1), sqrt(1 - total1));

		//Calculando distancia de percurso
		distancia[b] = raio * total2;

		//Calculando a dist�ncia total percorrida
		distancia_total = distancia_total + distancia[b];

		b++; // contagem de repeti��o do loop
	}

	b = 0; //zerando o contador b

	//calculando tempo de cada entrada (hora+minuto+segundo) para depois somar os tempos, assim encontraremos o tempo total decorrido
	for(i = quantidade; i >= 1; i--)
	{
		//calculando os tempos de cada entrada:
		//Achando a diferen�a entre a hora1 e hora2 e depois convertendo para segundos
		//Achando a diferen�a entre a minuto1 e minuto2 e depois convertendo para segundos
		//Achando a diferen�a entre a segundo1 e segundo2
		//somar ambas as diferen�as convertidas em segundos
		tempo[b] = ((inf[i].hora - inf[i - 1].hora) * 3600) + ((inf[i].minuto - inf[i - 1].minuto) * 60) + (inf[i].segundo - inf[i - 1].segundo);

		// somando os tempos de cada entrada
		tempo_total = tempo_total + tempo[b];

		b++; // contagem de repeti��o do loop
	}

	//Arrumando o tempo total para apresentar no cout:
	//Se o tempo total convertido em segundos n�o for maior, menor ou igual a 1
	//o formato do tempo no cout ficar� assim --> 0:0:tempo_total(que j� est� convertido em segundos)
	if (!(tempo_total / 3600 < 1 || tempo_total / 3600 >= 1))
	{
		hora = 0;
		minuto = 0;
		segundo = tempo_total;
	}
	//Se o tempo total desconvertido para segundos for menor que 1
	//Dividindo o tempo total em 60 para converter para minutos
	//Se o resto da divis�o de convers�o for maior que zero
	//Os segundos � o restante da divis�o de convers�o para minutos
	//Caso o resto da divis�o de convers�o for menor ou igual a zero, os segundos ser� igual a zero
	//o formato do tempo no cout ficar� assim --> 0:(tempo_total em formato de minutos):(resto do tempo_total - segundos)
	else if (tempo_total / 3600 < 1)
	{
		hora = 0;
		minuto = tempo_total / 60;

		if (tempo_total % 60 > 0)
		{
			segundo = tempo_total % 60;
		}
		else if(tempo_total % 60 <= 0)
		{
			segundo = 0;
		}
	}
	//Se o tempo total desconvertido para segundos for maior ou igual a 1
	//Converte o tempo_total que tava em segundos para horas
	/*/Se o resto da convers�o for maior que zero, vai armazenar as horas numa variavel auxiliar "tempo_hora"
	//Na variavel auxiliar vai ser armazenada a diferen�a entre o tempo_total com a hora convertida em horas sendo convertida para segundos)
	//Converte o tempo_hora para minutos
	//Se o resto da divis�o de convers�o do tempo_hora para minutos for maior que zero
	//Os segundos ser�o o resto da divis�o de convers�o do tempo_hora para minutos
	//Se o resto da divis�o de convers�o do tempo_hora para minutos for menor ou igual a zero, os segundos ser� igual a zero /*/
	/*/Se o resto da convers�o for menor ou igual a zero,os minutos e segundos ser�o iguais a zero /*/
	else if (tempo_total / 3600 >= 1)
	{
		hora = tempo_total / 3600;

		if (tempo_total % 3600 > 0)
		{
			tempo_hora = (tempo_total - (hora * 3600));
			minuto = tempo_hora / 60;

			if (tempo_hora % 60 > 0)
			{
				segundo = tempo_hora % 60;
			}
			else if (tempo_hora % 60 > 0)
			{
				segundo = 0;
			}
		}
		else if (tempo_total % 3600 <= 0)
		{
			minuto = 0;
			segundo = 0;
		}
	}

	b = 0; //zerando o contador b

	//calculando a velocidade de cada entrada
	// e comparando com o valor atribuido para a velocidade maxima (vmax) para achar a maior velocidade
	for(i = quantidade; i >= 1; i--)
	{
		velocidade = (distancia[b] * 1000 / tempo[b]) * 3.6; // convertendo de m/s para km/h

		if (velocidade > vmax)
		{
			vmax = velocidade;
		}

		b++; // contagem de repeti��o do loop
	}

	//calculando a velocidade media e convertendo de m/s para km/h
	velocidade_media = (distancia_total * 1000 / tempo_total) * 3.6;

	b = 0; //zerando o contador b

	//Comparando se a diferen�a de duas altitudes � maior que zero, se sim, calculando o ganho de eleva��o
	//Comparando se a diferen�a de duas altitudes � menor que zero, se sim, calculando a perda de eleva��o
	for(i = quantidade; i >= 1; i--)
	{
		if((inf[i].elevacao - inf[i - 1].elevacao) > 0)
		{
			gelevacao = gelevacao + (inf[i].elevacao - inf[i - 1].elevacao);
		}

		else if((inf[i].elevacao - inf[i - 1].elevacao) < 0)
		{
			pelevacao = pelevacao + (inf[i].elevacao - inf[i - 1].elevacao);
		}

		b++; // contagem de repeti��o do loop
	}

	//Verificando qual altitude � maior e a menor
	//Se a eleva��o for maior que o valor atribuido ao maioralt (maior altitude), a eleva��o passa ser a maior
	//Se a eleva��o for menor que o valor atribuido ao menorralt (menor altitude), a eleva��o passa ser a menor
	while(inf[i].elevacao != -1)
	{
		if(inf[i].elevacao > maioralt)
		{
			maioralt = inf[i].elevacao;
		}
		else if(inf[i].elevacao < menoralt)
		{
			menoralt = inf[i].elevacao;
		}

		i++; // contagem de repeti��o do loop
	}

	//Mostrando o resultado/sa�da com duas casas decimais:
	cout << fixed << setprecision(2);
	cout << "Distancia total: " << distancia_total << " km" << endl;
	cout << "Tempo total decorrido: " << hora << ":" << minuto << ":" << segundo << endl;
	cout << "Velocidade maxima: " << vmax << " km/h" << endl;
	cout << "Velocidade media: " << velocidade_media << " km/h" << endl;
	cout << "Ganho de elevacao: " << gelevacao << " m" << endl;
	cout << "Perda de elevacao: " << pelevacao << " m" << endl;
	cout << "Maior altitude: " << maioralt << " m" << endl;
	cout << "Menor altitude: " << menoralt << " m" << endl;

	//Finalizando o c�digo
	return 0;
}
