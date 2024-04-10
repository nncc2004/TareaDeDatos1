#include<iostream>
#include<fstream>
using namespace std;

//Structs predefinidos
struct Pieza {
	char simbolo; // Define qu� tipo de pieza es y su caracter
	int x, y; // Su posici�n dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
	int cantidad_piezas; //primera l�nea del archivo
	Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};

//Funciones para cada pieza:
void ReyDeTon(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void ReyDeTon
	******
	* Resumen Funci�n
	* Se encarga de marcar las 8 posibles posiciones a las que puede moverse el rey de Ton
	* Las marca s�lo si no est� marcada como que otra pieza pueda ponerse ah�
	* Si se cumple la condici�n, la marca como una 'o'
	* Adem�s, marca la casilla en la que se encuentra porque es una posici�n v�lida para evitar el jaque
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	 
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
	//Adem�s debe marcar su propia posicion en caso de que nada lo moleste ah�
	if(matriz[PosY][PosX] != 'M'){
		matriz[PosY][PosX] = 'o';
	}
			
}
void ReyDeSeba(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void ReyDeSeba
	******
	* Resumen Funci�n
	* Se encarga de marcar las 8 posibles posiciones a las que puede moverse el rey de Sebasti�n
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
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
}
void Reina(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void Reina
	******
	* Resumen Funci�n
	* Se encarga de marcar las 6 posibles direcciones en las que puede moverse la reina
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
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
}
void Peon(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void Peon
	******
	* Resumen Funci�n
	* Se encarga de marcar las 2 posibles posiciones a las que pueden moverse los peones
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//2 posiciones:
	//1. diagonal superior derecha
	if(PosX+1 <= 7 and PosY-1 >= 0 ){
		matriz[PosY-1][PosX+1] = 'M';
	}
	//2 diagonal superior izqierda
	if(PosX-1 >= 0 and PosY-1 >= 0){
		matriz[PosY-1][PosX-1] = 'M';
	}
}
void Alfil(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void Alfil
	******
	* Resumen Funci�n
	* Se encarga de marcar los 4 sentidos a las que pueden moverse los alfiles
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
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
}
void Caballo(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void Caballo
	******
	* Resumen Funci�n
	* Se encarga de marcar las 8 posibles posiciones a las que pueden moverse los caballos
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
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
}
void Torre(char (&matriz)[8][8], int PosX, int PosY){
	/*****
	* void Torre
	******
	* Resumen Funci�n
	* Se encarga de marcar las 2 direcciones en las que pueden moverse las torres
	* Marcar� las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//2 direcciones: Horizontal y vertical
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

//Funci�n principal
bool tableroEnJaqueMate(Tablero &tablero){
	/*****
	* bool tableroEnJaqueMate
	******
	* Resumen Funci�n
	* Lo primero que hace es crear un arreglo bidimensional nuevo que simular� el tablero y donde se marcar�n 
	* todas las casillas a las que las diferentes piezas puedan moverse. 
	* Luego recorre el struct tablero que se obtuvo por referencia desde el main para ir revisando pieza por pieza
	* Para cada pieza, llamar� a la funci�n que corresponda y les pasar� las coordenas y la matriz bidimensional como par�metros
	* Luego de hacerlo con todas las piezas, buscar� en la matriz si queda alguna posici�n a la que el Rey de Ton se pueda mover
	* sin generar un jaque. Tambi�n es v�lido quedarse donde est� si as� evita el Jaque
	******
	* Input:
	* Tablero &tablero
	* Este es el struc generado en main() con la informaci�n de la cantidad de piezas, y las co
	* .......
	******
	* Returns:
	* Retorna el valor booleano de Flag, que ser� false si existe alguna posici�n segura para el Rey, y true si es que no la hay
	*****/
	bool Flag = true;
	//Se crea la matriz de 8x8 y se llena con '-' en todas las csillas.
	char matriz[8][8]; //[filas] [columnas] || [y][x]
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			matriz[j][i] = '_';
		}
	}
	
	
	//Aqu� la l�gica para marcar las casillas donde las piezas se pueden mover. 
	for(int i = 0; i<tablero.cantidad_piezas; i++){
		//[filas] [columnas] || [y][x]
		int PosX = tablero.piezas_tablero[i].x;
		int PosY = tablero.piezas_tablero[i].y;
		
		//Aqu� se llama a la funci�n correspondiente por cada pieza
		if(tablero.piezas_tablero[i].simbolo == 'X'){ //Rey de Ton
			ReyDeTon(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'K'){//Rey de Seba
			ReyDeSeba(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'R'){//Reina de Seba
			Reina(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'P'){//Peon de Seba
			Peon(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'A'){//Alfil de seba
			Alfil(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'C'){//Caballo de Seba
			Caballo(matriz, PosX, PosY);
		}else if(tablero.piezas_tablero[i].simbolo == 'T'){//Torre de Seba
			Torre(matriz, PosX, PosY);
		}
		
	}
	//Ac� se revisa si es jaque o no
	//Y por ahora tamb�en imprimer la matriz completa	
	for(int y = 0; y<8; y++){
		for(int x = 0; x<8; x++){
			if(matriz[y][x] == 'o'){
				Flag = false;
			}
		}
	}
	return Flag;
}


int main(){
	/*****
	* int main()
	******
	* Resumen Funci�n
	* En esta funci�n se abre el archivo y se extrae la informaci�n necesaria.
	* Lo pirmero es crear todas las variables que vayan a ser necesarias, al igual que la apertura del archivo
	* Luego se extrae la informaci�n importante: La cantidad de piezas y las posiciones de cada una.
	* Esto se almacena el la variable del struct Tablero llamada "situacion"
	* Luego esta se pasa a la funci�n TableroEnJaqueMate para que ejecute su l�gica.
	* Por �ltimo se imprime si hay jaque seg�n el retorno de la funci�n y se cierra el archivo.
	******
	* Input:
	* No tiene inputs pues es la funci�n main()
	* .......
	******
	* Returns:
	* Tiene el return 0 de costumbre.
	*/
	
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
				situacion.piezas_tablero[posicionArreglo].simbolo = caracterActual;
				situacion.piezas_tablero[posicionArreglo].x = x;
				situacion.piezas_tablero[posicionArreglo].y =y;
				posicionArreglo++;
			}
		}
	}
	
	if(tableroEnJaqueMate(situacion)){
		cout<<"Si";
	}else{
		cout<<"No";
	}
	archivo.close();
	return 0;
}


