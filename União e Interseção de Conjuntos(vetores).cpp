#include <iostream>
using namespace std;

int busca(int conjunto_procura[],int chave, int tamanho);
int inter(int conjunto_inter[], int conjuntoA[], int conjuntoB[], int cont_Inter, int tam);
int uniao(int conjunto_uniao[], int conjuntoA[], int conjuntoB[], int cont_Uniao, int tam);
void inserir_valores( int conjuntoA[], int conjuntoB[], int tam);

main() {
	setlocale(LC_ALL, "Portuguese");

	int tam;

	cout << "Informe o tamanho dos vetores (conjuntos): ";
	cin >> tam;


	int conjuntoA[tam];
	int conjuntoB[tam];

	int conjunto_inter[tam];
	int conjunto_uniao[tam*2];

	inserir_valores(conjuntoA, conjuntoB, tam);

	int cont_Uniao = uniao(conjunto_uniao, conjuntoA, conjuntoB, 0, tam);
	int cont_Inter = inter(conjunto_inter, conjuntoA, conjuntoB, 0, tam);

	cout << "\n\nConjunto Interseção:\n";

	for(int i = 0; i < cont_Inter; i++) {
		cout << conjunto_inter[i] << '\n';
	}

	cout << "\n\nConjunto União\n";

	for(int i = 0; i < cont_Uniao; i++) {
		cout << conjunto_uniao[i] << '\n';
	}
}

void inserir_valores( int conjuntoA[], int conjuntoB[], int tam) {

	cout << "\n\nInsira os valores para o conjunto A:\n";

	for(int i = 0; i<tam; i++) {
		cin >> conjuntoA[i];
	}

	cout << "\n\nInsira valores para o conjunto B:\n";

	for(int i = 0; i<tam; i++) {
		cin >> conjuntoB[i];
	}
}

int busca(int conjunto_procura[],int chave, int tamanho) {

	for(int i = 0; i<tamanho; i++) {

		if(conjunto_procura[i] == chave) {
			return 0;
		}
	}

	return -1;
}

int inter(int conjunto_inter[], int conjuntoA[], int conjuntoB[], int cont_Inter, int tam) {

	for(int i = 0; i<tam; i++) {

		if( busca(conjuntoA, conjuntoB[i],tam) == 0) {

			conjunto_inter[cont_Inter] = conjuntoB[i];
			cont_Inter++;
		}
	}

	return cont_Inter;
}

int uniao(int conjunto_uniao[], int conjuntoA[], int conjuntoB[], int cont_Uniao, int tam) {

	for(int i = 0; i<tam; i++) {
		conjunto_uniao[i] = conjuntoA[i];
	}

	cont_Uniao = tam;

	for(int i = 0; i<tam; i++) {
		if(  busca(conjunto_uniao, conjuntoB[i],tam) == -1 ) {
			conjunto_uniao[cont_Uniao] = conjuntoB[i];
			cont_Uniao++;
		}
	}

	return cont_Uniao;
}
