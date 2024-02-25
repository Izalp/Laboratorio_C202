#include <iostream> //Biblioteca

using namespace std;

int main() //Declarando as variaveis
{
	int m; //quantidade de bits a serem processados
	int n; //n�mero de repeti��es de cada bit
	int i; // contador para o For
	int contador = 0; // contador para ver quantas vezes vai entrar no while
	int bits[100]; // vetor para armazenar os bits

	cin >> m >> n; //lendo o n�mero de bits e o n�mero de repeti��es

	//For para ler o vetor:
	for(i = 0; i < m; i++) //Se o contador i for menor que a quantidade de bits
	{
		cin >> bits[i]; //Entrar� no for/loop e ir� fazer a leitura dos bits e armazen�-los no vetor
	}
	
	//For para mostrar o vetor como sa�da:
	for(i = 0; i < m; i++) //Se o contador i for menor que a quantidade de bits
	{
		while (contador != n) //Repentindo cada valor armazenado no vetor
		{
			cout << bits[i] << " "; // mostrando o resultado/os bits repetidos 
			contador++; // somando +1 ao contador 
		}
		
		contador = 0; // zerando o contador para compar�-lo na condi��o do while para fazer a repeti��o dos bits
	}

	return 0; // Finalizando o c�digo
}
