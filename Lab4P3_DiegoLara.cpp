#include <iostream>
#include<cstdlib>
#include<ctime>
#include <locale>
#include<cstring>
#include <string>
using namespace std;
int generarNumRandom(int minimo, int maximo) { // metodo para generar numeros al azar del 1 al 99 y del 97 al 122
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
	matriz = new char* [filas];
	for (int i = 0; i < filas; i++)
	{
		matriz[i] = new char[columnas];
	}
}
void llenarMatriz(char**& matriz, int filas, int columnas) {
	reservarMatriz(matriz, filas, columnas);
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			matriz[i][j] = char(generarNumRandom(97, 26));
		}
	}
}
void imprimirMatriz(char**& matriz, int filas, int columnas) {
	llenarMatriz(matriz, filas, columnas);
	for (int i = 0; i < filas; i++)
	{
		cout << "[ ";
		for (int j = 0; j < columnas; j++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << " ]" << endl;
	}
}
void buscarPalabra(char**& matriz, int filas, int columnas, string palabraBuscada) {
	bool fraseEncontrada = false;
	for (int i = 0; i < filas; i++)
	{
		string temporal = "";
		for (int j = 0; j < columnas; j++)
		{
			temporal += matriz[i][j];
		}
	}
	if (fraseEncontrada)
	{
		cout << "La palabra " << palabraBuscada << " SI se encuentra en la sopa de letras" << endl;
	}
	else {
		cout << "La palabra " << palabraBuscada << " NO se encuentra en la sopa de letras" << endl;
	}
}
void ejercicio_2() {
	int fila = 0;
	int columna = 0;
	string palabraBuscada = "";
	char** matriz = nullptr;
	cout << "Ingrese el numero de filas: "; cin >> fila;
	cout << endl;
	while (fila < 4) {
		cout << "Ingrese un numero de filas mayor o igual que 4: "; cin >> fila;
		cout << endl;
	}
	cout << "Ingrese el numero de columnas: "; cin >> columna;
	cout << endl;
	while (columna < 4) {
		cout << "Ingrese un numero de filas mayor o igual que 4: "; cin >> fila;
		cout << endl;
	}
	imprimirMatriz(matriz, fila, columna);
	cout << endl;
	cout << "Ingrese la palabra a buscar en la sopa de letras: "; cin >> palabraBuscada;
	cout << endl;
	
	
	buscarPalabra(matriz, fila, columna, palabraBuscada);
	cout << endl;
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