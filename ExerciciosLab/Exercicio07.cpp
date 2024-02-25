#include <iostream> 
#include <cstring>
#include <ctype.h> // biblioteca para o isalpha

using namespace std;

int main()
{
	//Declarando as strings e contador
	char nome1[50]; 
	char nome2[50];
	int i;
	
	//Lendo as strings 
	cin >> nome1;
	cin >> nome2;

	//Se nome1 e nome2 forem iguais, ir� retornar o valor 0
	//For para ver cada valor de cada espa�o nas strings
	//Isalpha --> Se o valor na string nome1 ou nome2 for diferente de 0, � caracter
	//Passa para o cout e teria que mostrar esses caracteres no resultado
	if(strcmp(nome1, nome2) == 0)
	{
		for(i = 0; nome1[i] && nome2[i] != '\0'; i++)
		{
			if(isalpha(nome1[i]) != 0 && isalpha(nome2[i]) != 0)
				cout << nome1[i];
		}		
	}
	
	//Se nome1 e nome2 retornar um valor diferente de zero, n�o s�o iguais
	else
	{
		cout << "Nao sao iguais!" << endl;
	}

	return 0;
}