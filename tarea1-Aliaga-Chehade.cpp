#include<iostream>
#include<fstream>

using namespace std;


struct Pieza {
	char simbolo; // Define qué tipo de pieza es y su caracter
	int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
	int cantidad_piezas;
	Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};

bool tableroEnJaqueMate(Tablero &tablero){
	bool Flag = true;
	//Se crea la matriz de 8x8 y se llena con "v" (de vacío). Luego se imprime con forma matricial
	char matriz[8][8]; //[filas] [columnas] || [y][x]
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			matriz[j][i] = '_';
		}
	}
	
	//Aquí la lógica para marcar las casillas donde las piezas se pueden mover. 
	for(int i = 0; i<tablero.cantidad_piezas; i++){
		//[filas] [columnas] || [y][x]
		int PosX = tablero.piezas_tablero[i].x;
		int PosY = tablero.piezas_tablero[i].y;
		//matriz[PosY][PosX] = tablero.piezas_tablero[i].simbolo;
		
		if(tablero.piezas_tablero[i].simbolo == 'X'){ //Rey de Ton
			//rey: 8 posibles posiciones
			//1 arriba
			if(PosY-1 >= 0 and matriz[PosY-1][PosX] != 'M'){
				matriz[PosY-1][PosX] = 'o';
			} 
			//2 diagonal superior derecha
			if(PosX+1 <= 7 and PosY-1 >= 0 and matriz[PosY-1][PosX+1] != 'M'){
				matriz[PosY-1][PosX+1] = 'o';
			}
			//3 derecha
			if(PosX+1 <= 7 and matriz[PosY][PosX+1] != 'M'){
				matriz[PosY][PosX+1] = 'o';
			} 
			//4 diagonal inferior derecha
			if(PosX+1 <= 7 and PosY+1 <= 7 and matriz[PosY+1][PosX+1] != 'M'){
				matriz[PosY+1][PosX+1] = 'o';
			}
			//5 abajo
			if(PosY+1 <= 7 and matriz[PosY+1][PosX] != 'M'){
				matriz[PosY+1][PosX] = 'o';
			} 
			//6 diagonal inferior izquiera
			if(PosX-1 >= 0 and PosY+1 <= 7 and matriz[PosY+1][PosX-1] != 'M'){
				matriz[PosY+1][PosX-1] = 'o';
			}
			//7 izquierda
			if(PosX-1 <= 7 and matriz[PosY][PosX-1] != 'M'){
				matriz[PosY][PosX-1] = 'o';
			} 
			//8 diagonal superior izquiera
			if(PosX-1 >= 0 and PosY-1 >= 0 and matriz[PosY-1][PosX-1] != 'M'){
				matriz[PosY-1][PosX-1] = 'o';
			}
			//Además debe marcar su propia posicion en caso de que nada lo moleste ahí
			if(matriz[PosY][PosX] != 'M'){
				matriz[PosY][PosX] = 'o';
			}
			
		}else if(tablero.piezas_tablero[i].simbolo == 'K'){//Rey de Seba
			//rey: 8 posibles posiciones
			if(PosY-1 >= 0){
				matriz[PosY-1][PosX] = 'M';
			} //1 arriba
			if(PosX+1 <= 7 and PosY-1 >= 0 ){
				matriz[PosY-1][PosX+1] = 'M';
			}//2 diagonal superior derecha
			if(PosX+1 <= 7 ){
				matriz[PosY][PosX+1] = 'M';
			} //3 derecha
			if(PosX+1 <= 7 and PosY+1 <= 7){
				matriz[PosY+1][PosX+1] = 'M';
			}//4 diagonal inferior derecha
			if(PosY+1 <= 7){
				matriz[PosY+1][PosX] = 'M';
			} //5 abajo
			if(PosX-1 >= 0 and PosY+1 <= 7){
				matriz[PosY+1][PosX-1] = 'M';
			}//6 diagonal inferior izquiera
			if(PosX-1 <= 7){
				matriz[PosY][PosX-1] = 'M';
			} //7 izquierda
			if(PosX-1 >= 0 and PosY-1 >= 0){
				matriz[PosY-1][PosX-1] = 'M';
			}//8 diagonal superior izquiera
			
		}else if(tablero.piezas_tablero[i].simbolo == 'R'){//Reina de Seba
			//6 sentidos: vertical, horizontal y las cuatro diagonales.
			//Es la suma de los movimientos de la torre y el alfil.
			//1. D. Sup. izquierda
			for(int n = 1; n<=7;n++){
				if(PosX-n>=0 and PosY-n>=0){
					matriz[PosY-n][PosX-n] = 'M';
				}
			}
			//2 D. Sup. derecha
			for(int n = 1; n<=7;n++){
				if(PosX+n<=7 and PosY-n>=0){
					matriz[PosY-n][PosX+n] = 'M';
				}
			}
			//3 D. Inf. izquierda
			for(int n = 1; n<=7;n++){
				if(PosX-n>=0 and PosY+n<=7){
					matriz[PosY+n][PosX-n] = 'M';
				}
			}
			//4 D. Inf. derecha
			for(int n = 1; n<=7;n++){
				if(PosX+n<=7 and PosY+n<=7){
					matriz[PosY+n][PosX+n] = 'M';
				}
			}
			//5 Horizontal 
			for(int n = 0; n<8; n++){
				if(n != PosX){  //Esto es para evitar marcar el espacio que esta ocupando pq el rey si se puede mover ahi
					matriz[PosY][n] = 'M';
				}
			}
			//6 Vertical
			for(int n = 0; n<8; n++){
				if(n != PosY){  //Esto es para evitar marcar el espacio que esta ocupando pq el rey si se puede mover ahi
					matriz[n][PosX] = 'M';
				}
			}
	
		}else if(tablero.piezas_tablero[i].simbolo == 'P'){//Peon de Seba
			//2 posiciones:
			//1. diagonal superior derecha
			if(PosX+1 <= 7 and PosY-1 >= 0 ){
				matriz[PosY-1][PosX+1] = 'M';
			}
			//2 diagonal superior izqierda
			if(PosX-1 >= 0 and PosY-1 >= 0){
				matriz[PosY-1][PosX-1] = 'M';
			}
		}else if(tablero.piezas_tablero[i].simbolo == 'A'){//Alfil de seba
			//4 sentidos: D. Sup. izquierda, D. Sup. derecha, D. Inf. izquierda, D. Inf. derecha
			//1. D. Sup. izquierda
			for(int n = 1; n<=7;n++){
				if(PosX-n>=0 and PosY-n>=0){
					matriz[PosY-n][PosX-n] = 'M';
				}
			}
			//2 D. Sup. derecha
			for(int n = 1; n<=7;n++){
				if(PosX+n<=7 and PosY-n>=0){
					matriz[PosY-n][PosX+n] = 'M';
				}
			}
			//3 D. Inf. izquierda
			for(int n = 1; n<=7;n++){
				if(PosX-n>=0 and PosY+n<=7){
					matriz[PosY+n][PosX-n] = 'M';
				}
			}
			//4 D. Inf. derecha
			for(int n = 1; n<=7;n++){
				if(PosX+n<=7 and PosY+n<=7){
					matriz[PosY+n][PosX+n] = 'M';
				}
			}
		}else if(tablero.piezas_tablero[i].simbolo == 'C'){//Caballo de Seba
			//8 posibles posiciones:
			//1
			if(PosX+1 <= 7 and PosY-2 >= 0 ){
				matriz[PosY-2][PosX+1] = 'M';
			}
			//2
			if(PosX+2 <= 7 and PosY-1 >= 0 ){
				matriz[PosY-1][PosX+2] = 'M';
			}
			//3
			if(PosX+2 <= 7 and PosY+1 <= 7 ){
				matriz[PosY+1][PosX+2] = 'M';
			}
			//4
			if(PosX+1 <= 7 and PosY+2 <= 7 ){
				matriz[PosY+2][PosX+1] = 'M';
			}
			//5
			if(PosX-1 >= 0 and PosY+2 <= 7 ){
				matriz[PosY+2][PosX-1] = 'M';
			}
			//6
			if(PosX-2 >= 0 and PosY+1 <= 7 ){
				matriz[PosY+1][PosX-2] = 'M';
			}
			//7
			if(PosX-2 >= 0 and PosY-1 >= 0 ){
				matriz[PosY-1][PosX-2] = 'M';
			}
			//8
			if(PosX-1 >= 0 and PosY-2 >= 0 ){
				matriz[PosY-2][PosX-1] = 'M';
			}
		}else if(tablero.piezas_tablero[i].simbolo == 'T'){//Torre de Seba
			//2 sentidos: Horizontal y vertical
			//Horizontal (1)
			for(int n = 0; n<8; n++){
				if(n != PosX){  //Esto es para evitar marcar el espacio que esta ocupando pq el rey si se puede mover ahi
					matriz[PosY][n] = 'M';
				}
			}
			//Vertical (2)
			for(int n = 0; n<8; n++){
				if(n != PosY){  //Esto es para evitar marcar el espacio que esta ocupando pq el rey si se puede mover ahi
					matriz[n][PosX] = 'M';
				}
			}
		}
		
	}	
	cout<<"\n";
	for(int y = 0; y<8; y++){
		for(int x = 0; x<8; x++){
			cout<<matriz[y][x];
			if(matriz[y][x] == 'o'){
				Flag = false;
			}
		}
		cout<<"\n";
	}
	return Flag;
	
}


int main(){
	ifstream archivo;
	string lineaActual;
	char caracterActual;
	archivo.open("tablero.txt", ios::in);
	int posicionArreglo = 0;
	
	Tablero situacion;
	archivo>>situacion.cantidad_piezas;
	situacion.piezas_tablero = new Pieza[situacion.cantidad_piezas];    
	
	for(int y = 0; y<8; y++){
		archivo>>lineaActual;
		for(int x = 0; x<8; x++){
			caracterActual = lineaActual[x];
			if(caracterActual != '.'){
				//cout<<caracterActual<<": ("<<x<<","<< y<<")\n";
				situacion.piezas_tablero[posicionArreglo].simbolo = caracterActual;
				situacion.piezas_tablero[posicionArreglo].x = x;
				situacion.piezas_tablero[posicionArreglo].y =y;
				posicionArreglo++;
			}
		}
	}
	cout<<tableroEnJaqueMate(situacion);
	archivo.close();
	return 0;
}


