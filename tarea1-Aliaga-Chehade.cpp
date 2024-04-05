#include<iostream>
#include<fstream>

using namespace std;


struct Pieza {
 char simbolo; // Define qué tipo de pieza es y su caracter
 int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
 Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};

bool tableroEnJaqueMate(Tablero &tablero, int cantPiezas){
	cout<<"\n\n";
	for(int i = 0; i<cantPiezas; i++){
		cout<<tablero.piezas_tablero[i].simbolo<<": (";
		cout<<tablero.piezas_tablero[i].x<<","<<tablero.piezas_tablero[i].y<<")\n";
	}
	return true; //Por ahora, eso cambiarlo luego
}


int main(){
	ifstream archivo;
	string lineaActual;
	char caracterActual;
	archivo.open("tablero.txt", ios::in);
	int cantPiezas, posicionArreglo = 0;
	archivo>>cantPiezas;
	Tablero situacion;
	situacion.piezas_tablero = new Pieza[cantPiezas];
	
	
    
	
	for(int x = 0; x<8; x++){
		archivo>>lineaActual;
		for(int y = 0; y<8; y++){
			caracterActual = lineaActual[y];
			if(caracterActual != '.'){
				//cout<<caracterActual<<": ("<<x<<","<< y<<")\n";
				situacion.piezas_tablero[posicionArreglo].simbolo = caracterActual;
				situacion.piezas_tablero[posicionArreglo].x = x;
				situacion.piezas_tablero[posicionArreglo].y =y;
				posicionArreglo++;
			}
		}
	}
	/*
	cout<<"\n\n";
	for(int i = 0; i<cantPiezas; i++){
		cout<<situacion.piezas_tablero[i].simbolo<<": (";
		cout<<situacion.piezas_tablero[i].x<<","<<situacion.piezas_tablero[i].y<<")\n";
	}*/
	
	bool funcion = tableroEnJaqueMate(situacion, cantPiezas);	//en cero porque es un puntero y los espacios de memoria están juntos
	archivo.close();
	return 0;
}


