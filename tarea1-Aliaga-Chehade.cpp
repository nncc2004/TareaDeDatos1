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
	cout<<"\n";
	//Se crea la matriz de 8x8 y se llena con "v" (de vacío). Luego se imprime con forma matricial
	char matriz[8][8];
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			matriz[j][i] = '_';
		}
	}
	
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			cout<<matriz[j][i];
		}
		cout<<"\n";
	}
	for(int i = 0; i<cantPiezas; i++){
		matriz[tablero.piezas_tablero[i].x][tablero.piezas_tablero[i].y] = tablero.piezas_tablero[i].simbolo;
		//Aquí en vez de poner la pieza, debería separar en condicionales por tipo de pieza y aprovechar sus términos x,y
		//para poder definir sus futuras jugadas y marcar esos lugares con una X
	}
	
	cout<<"\n";
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			cout<<matriz[j][i];
		}
		cout<<"\n";
	}
	//Hasta aquí todo lo que está en la función es para demostrar el funcionamiento de la matriz del tablero
	//y para ver cómo recorrer las piezas y sus ubicaciones. Funciona de pana 
	
	//Aquí debería empezar a recorrer las piezas y sergún qué pieza es y su ubicación marcar sus posibles movimientos con "x"
	// en una matriz como la de la línea 24. Se haría de manera similar al for que está en la línea 42. Notar que la pieza no debe 
	//incluírse en la matriz de las posiciones usadas porque el rey sí podría moverse a donde haya una pieza mientras no esté en jaque.
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


