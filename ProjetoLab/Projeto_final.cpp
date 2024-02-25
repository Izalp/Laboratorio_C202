#include<iostream>
#include<iomanip> //Biblioteca de precisao de casas decimais
#include<fstream> //Biblioteca para arquivo

using namespace std;

int main() //Declarando as vari�veis:
{
	ifstream arq; // vari�vel para fazer a leitura do arquivo
	int processo[5]; // vetor para armazenar os valores de processo
	int tempo[5]; // vetor para armazenar os valores de tempo
	int priorid[5]; //vetor para armazenar os valores de prioridade
	int n; // v�riavel representando a quantidade de vezes para entrar no loop
	int aux; // vari�vel auxiliar para a mudan�a de posi��o da prioridade, processo e tempo
	int j; // contador para o for de mudan�a de posi��o
	int i = 0; // contador1 com valor zero atribuido
	int posicao; // contador para auxiliar na mudan�a de posi��o;
	int temp = 0; // variavel auxiliar para guardar os valores de tempo
	double espera = 0; // variavel auxiliar para armazenar os tempos de espera
	double media; // variavel para fazer a media dos tempos de espera

	//abrindo o arquivo para fazer a leitura dos dados:
	arq.open("prioridade.txt", ifstream::in);

	//While para fazer a leitura de mais de um valor:
	while(!arq.eof()) //Enquanto n�o chega no final do arquivo
	{
		//Fazendo a leitura dos valores de processo, tempo e prioridade:
		arq >> processo[i] >> tempo[i] >> priorid[i];

		i++; //sendo atribuido +1 ao contador toda vez que passar pelo loop
	}

	// A quantidade de dados dos vetores a serem lidos ser� o mesmo valor da quantidade de vezes que o contador somar ao passar pelo loop
	n = i;

	// For para a mudan�a de posi��es:

	for (i = 0; i < n; i++) //For vai entrar em loop 5 vezes
	{
		posicao = i; // o valor da posi��o iniciar� com 0

		for (j = i + 1; j < n; j++)
			//Se o valor da posicao 0 do vetor for maior que o valor da posi��o 1 do vetor
			if(priorid[posicao] > priorid[j])
				posicao = j; //A posi��o passar� a ter o valor do contador j

		//Alterando as posi��es do vetor prioridade para ordem crescente:

		//Trocando as posi��es dos valores do vetor prioridade com ajuda de uma variavel auxiliar
		aux = priorid[i];
		priorid[i] = priorid[posicao];
		priorid[posicao] = aux;

		//Trocando as posi��es dos valores do vetor tempo com ajuda de uma variavel auxiliar
		aux = tempo[i];
		tempo[i] = tempo[posicao];
		tempo[posicao] = aux;

		//Trocando as posi��es dos valores do vetor processo com ajuda de uma variavel auxiliar
		aux = processo[i];
		processo[i] = processo[posicao];
		processo[posicao] = aux;
	}

	//For para apresentar a ordem da CPU conforme a prioridade
	for(posicao = 0; posicao < n; posicao++)
	{
		//mostrando o processo por ordem de prioridade
		cout << "P" << processo[posicao];

		//armazenando o valor de tempo de acordo com a posi��o numa vari�vel auxiliar
		temp = tempo[posicao];

		for(i = 0; i < temp; i++) //acresentando/mostrando "-" de acordo com o valor de tempo
			cout << "-";
	}
	cout << endl << endl;

	//Somando os tempos anteriores de cada posi��o para achar o tempo de espera
	for (i = 0; i < n; i++)
	{
		if(i > 0) // se o contador for maior q zero
			for(j = 0; j < i; j++)
				espera = espera + tempo[j]; //somando os tempos anteriores
	}

	media = espera / n; //fazendo a m�dia do tempo de espera dos processos

	//Apresentando o tempo medio de espera em ms (precisao de 1 casa decimal)
	cout << fixed << setprecision(1);
	cout << "Tempo medio de espera: " << media << " ms" << endl;

	arq.close(); //Fechando o arquivo

	return 0;
}
