#include <iostream>
using namespace std;

int main ()
{
	int a; // meu numero de come�o
	int b; // meu numero final
	int i; // contador 
	int resultado; // variavel auxiliar que guarda  os numeros do meu contador 
	int comprimento; // quantidade de numeros at� dar 1
	int maior; // maior numero encontrado na minha quantidade de numeros

	// lendo o meu numero de come�o e o de final
	cin >> a >> b;

	// atribuindo valor a variavel maior para ela nao pegar lixo de memoria
	maior = 0;
	
	// se meu numero final for maior que o meu de come�o, ir� entrar no For
	// atribui i para resultado e zero para comprimento 
	// ai entra no while ( o resultado tem que ser diferente de 1 )
	// porque 1 � o numero que para o meu loop
	if (a < b)
	{
		for (i = a; i <= b; i++)
	{
		resultado = i;
		comprimento = 1;
		
		while (resultado != 1)
		{
			if (resultado % 2 == 0)
			{
				resultado = resultado/ 2;
			}
			
			else
				resultado = (3 * resultado) + 1;
            comprimento++;
		}

		if (comprimento > maior)
			maior = comprimento;
	}
	
	}
	
	// aqui sera para caso o meu numero de come�o seja maior que meu numero final
	// o que muda � o FOR, se a atribui��o de "a" � o contador, ent�o o contador tem
	// que ser maior ou igual a "b" e com isso haver� uma decrementa��o
		if (a > b)
	{
		for (i = a; i >= b; i--)
	{
		resultado = i;
		comprimento = 1;
		
		while (resultado != 1)
		{
			if (resultado % 2 == 0)
			{
				resultado = resultado/ 2;
			}
			
			else
				resultado = (3 * resultado) + 1;
            comprimento++;
		}

		if (comprimento > maior)
			maior = comprimento;
	}
	
	}
	cout << a << " " << b << " " << maior << endl;
	
	return 0;
}
