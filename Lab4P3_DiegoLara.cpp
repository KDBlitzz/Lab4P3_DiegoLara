#include <iostream>
#include<cstdlib>
#include<ctime>
#include <locale>
using namespace std;
int generarNumRandom(int minimo, int maximo) { // metodo para generar numeros al azar del 1 al 99
	int random;
	random = 0;
	random = minimo + (rand() % maximo);
	return random;
}
void reservarMatrizEntero(int**& matriz, int tamano) {
	matriz = new int* [tamano];
	for (int i = 0; i < tamano; i++)
	{
		matriz[i] = new int[tamano];
	}
}
void llenarMatrizEnteros(int**& matriz, int tamano) {
	reservarMatrizEntero(matriz, tamano);
	for (int i = 0; i < tamano; i++)
	{
		for (int j = 0; j < tamano; j++)
		{
			matriz[i][j] = generarNumRandom(1, 99);
		}
	}
	for (int i = 0; i < tamano; i++)
	{
		cout << "[ ";
		for (int j = 0; j < tamano; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << " ]" << endl;
	}
}
int calcularInversaMatematica(int**& matriz, int tamano) {
	int sumaDiagonal = 0;
	for (int i = 0; i < tamano; i++)
	{
		for (int j = 0; j < tamano; j++)
		{
			if (i == j)
			{
				sumaDiagonal += matriz[i][j];
			}
			if (j == (tamano - 1) - i)
			{
				sumaDiagonal += matriz[i][j];
			}
		}
	}
	return sumaDiagonal;
}
void ejercicio_1() {
	int** matriz = nullptr;
	int tamano = 0;
	int totalSumaDiagonal = 0;
	cout << "Ingrese n: "; cin >> tamano;
	cout << endl;

	while (tamano <= 2) {
		cout << "Debe ser un valor de n mayor o igual a 3: "; cin >> tamano;
		cout << endl;
	}
	llenarMatrizEnteros(matriz, tamano);
	totalSumaDiagonal = calcularInversaMatematica(matriz, tamano);
	cout << "La suma de la diagonal regular y la inversa es: " << totalSumaDiagonal << endl;

	for (int i = 0; i < tamano; i++)
	{
		delete[] matriz[i];
	}
	delete matriz;
}
void reservarMatriz(char**& matriz, int filas, int columnas) {

}
void llenarMatriz(char**& matriz, int filas, int columnas) {

}
void imprimirMatriz(char**& matriz, int filas, int columnas) {

}
void ejercicio_2() {
	int fila = 0;
	int columna = 0;
}
void menu() {
	bool menu = true;
	int option = 0;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Suma diagonalizada matemáticamente inversa" << endl;
		cout << "Ejercicio Práctico 2 – Sopa de letras" << endl;
		cout << "3. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			ejercicio_2();
			break;
		case 3:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	srand(time(NULL));
	menu();
}