#include <iostream>

using namespace std;

int main()
{
	int n; // numero de repeti�oes 
	int auxiliar; // variavel auxiliar na leitura de dados 
	int soma; // soma dos numeros
	int i; // contador
	
	// lendo o numero de repeti�oes
	cin >> n;
	
	// atribuindo valor na variavel soma pra nao pegar lixo de memoria
	soma = 0;
	
	// i come�a com zero, se o i for menor que n, vai somar +1 no i e realizar o comando de baixo
	// a leitura do n vai ser guardada na variavel auxiliar 
	// a soma � o valores de numeros armazenados na variavel auxiliar
	for (i=0; i < n; i++)
	{
		cin >> auxiliar; 
		soma = soma + auxiliar;
	}
		cout << "soma = " << soma << endl;
	
	return 0;
	
}