#include<iostream>
#include<fstream>
using namespace std;

//Structs predefinidos
struct Pieza {
	char simbolo; // Define qué tipo de pieza es y su caracter
	int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
	int cantidad_piezas; //primera línea del archivo
	Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};

//Funciones para cada pieza:
void ReyDeTon(char (&matriz)[8][8], int PosX, int PosY){  //Listo
	/*****
	* void ReyDeTon
	******
	* Resumen Función
	* Se encarga de marcar las 8 posibles posiciones a las que puede moverse el rey de Ton
	* Las marca sólo si no está marcada como que otra pieza pueda ponerse ahí
	* Si se cumple la condición, la marca como una 'o'
	* Además, marca la casilla en la que se encuentra porque es una posición válida para evitar el jaque
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
	//Además debe marcar su propia posicion en caso de que nada lo moleste ahí
	if(matriz[PosY][PosX] != 'M'){
		matriz[PosY][PosX] = 'o';
	}
			
}
void ReyDeSeba(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){ //Listo
	/*****
	* void ReyDeSeba
	******
	* Resumen Función
	* Se encarga de marcar las 8 posibles posiciones a las que puede moverse el rey de Sebastián
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//rey: 8 posibles posiciones
	if(PosY-1 >= 0 and (matrizTablero[PosY-1][PosX] == '_' or matrizTablero[PosY-1][PosX] == 'o')){
		matriz[PosY-1][PosX] = 'M';
	} //1 arriba
	if(PosX+1 <= 7 and PosY-1 >= 0 and (matrizTablero[PosY-1][PosX+1] == '_' or matrizTablero[PosY-1][PosX+1] == 'o')){
		matriz[PosY-1][PosX+1] = 'M';
	}//2 diagonal superior derecha
	if(PosX+1 <= 7 and ( matrizTablero[PosY][PosX+1] == '_' or matrizTablero[PosY][PosX+1] == 'o')){
		matriz[PosY][PosX+1] = 'M';
	} //3 derecha
	if(PosX+1 <= 7 and PosY+1 <= 7 and (matrizTablero[PosY+1][PosX+1] =='_' or matrizTablero[PosY+1][PosX+1] =='o')){
		matriz[PosY+1][PosX+1] = 'M';
	}//4 diagonal inferior derecha
	if(PosY+1 <= 7 and (matrizTablero[PosY+1][PosX] == '_' or matrizTablero[PosY+1][PosX] == 'o')){
		matriz[PosY+1][PosX] = 'M';
	} //5 abajo
	if(PosX-1 >= 0 and PosY+1 <= 7 and( matrizTablero[PosY+1][PosX-1] == '_' or matrizTablero[PosY+1][PosX-1] == 'o')){
		matriz[PosY+1][PosX-1] = 'M';
	}//6 diagonal inferior izquiera
	if(PosX-1 <= 7 and (matrizTablero[PosY][PosX-1] == '_' or matrizTablero[PosY][PosX-1] == 'o')){
		matriz[PosY][PosX-1] = 'M';
	} //7 izquierda
	if(PosX-1 >= 0 and PosY-1 >= 0 and (matriz[PosY-1][PosX-1] =='_' or matriz[PosY-1][PosX-1] =='o')){
		matriz[PosY-1][PosX-1] = 'M';
	}//8 diagonal superior izquiera
}
void Peon(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){ //Listo
	/*****
	* void Peon
	******
	* Resumen Función
	* Se encarga de marcar las 2 posibles posiciones a las que pueden moverse los peones
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//2 posiciones:
	//1. diagonal superior derecha
	if(PosX+1 <= 7 and PosY-1 >= 0 and (matrizTablero[PosY-1][PosX+1] =='_' or matrizTablero[PosY-1][PosX+1] == 'o') ){
		matriz[PosY-1][PosX+1] = 'M';
	}
	//2 diagonal superior izqierda
	if(PosX-1 >= 0 and PosY-1 >= 0 and (matrizTablero[PosY-1][PosX-1] == '_' or matrizTablero[PosY-1][PosX-1] =='o')){
		matriz[PosY-1][PosX-1] = 'M';
	}
}
void Alfil(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){ //Listo
	/*****
	* void Alfil
	******
	* Resumen Función
	* Se encarga de marcar los 4 sentidos a las que pueden moverse los alfiles
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//4 sentidos: D. Sup. izquierda, D. Sup. derecha, D. Inf. izquierda, D. Inf. derecha
	//1. D. Sup. izquierda
	for(int n = 1; n<=7;n++){
		if(PosX-n>=0 and PosY-n>=0){
			if(matrizTablero[PosY-n][PosX-n] == '_' or matrizTablero[PosY-n][PosX-n] =='o'){
				matriz[PosY-n][PosX-n] = 'M';
			}else{
				break;
			}
		}
	}
	//2 D. Sup. derecha
	for(int n = 1; n<=7;n++){
		if(PosX+n<=7 and PosY-n>=0){
			if(matrizTablero[PosY-n][PosX+n] == '_' or matrizTablero[PosY-n][PosX+n] =='o'){
				matriz[PosY-n][PosX+n] = 'M';
			}else{
				break;
			}
			
		}
	}
	//3 D. Inf. izquierda
	for(int n = 1; n<=7;n++){
		if(PosX-n>=0 and PosY+n<=7){
			if(matrizTablero[PosY+n][PosX-n] == '_' or matrizTablero[PosY+n][PosX-n] =='o'){
				matriz[PosY+n][PosX-n] = 'M';
			}else{
				break;
			}
				
		}
	}
	//4 D. Inf. derecha
	for(int n = 1; n<=7;n++){
		if(PosX+n<=7 and PosY+n<=7){
			if(matrizTablero[PosY+n][PosX+n] == '_' or matrizTablero[PosY+n][PosX+n] =='o'){
				matriz[PosY+n][PosX+n] = 'M';
			}else{
				break;
			}
		}
	}
}
void Caballo(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){  //Listo
	/*****
	* void Caballo
	******
	* Resumen Función
	* Se encarga de marcar las 8 posibles posiciones a las que pueden moverse los caballos
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//8 posibles posiciones:
	//1
	if(PosX+1 <= 7 and PosY-2 >= 0 and (matrizTablero[PosY-2][PosX+1] == '_' or matrizTablero[PosY-2][PosX+1] == 'o')){
		matriz[PosY-2][PosX+1] = 'M';
	}
	//2
	if(PosX+2 <= 7 and PosY-1 >= 0 and (matrizTablero[PosY-1][PosX+2] == '_' or matrizTablero[PosY-1][PosX+2] == 'o')){
		matriz[PosY-1][PosX+2] = 'M';
	}
	//3
	if(PosX+2 <= 7 and PosY+1 <= 7 and(matrizTablero[PosY+1][PosX+2] == '_' or matrizTablero[PosY+1][PosX+2] == 'o')){
		matriz[PosY+1][PosX+2] = 'M';
	}
	//4
	if(PosX+1 <= 7 and PosY+2 <= 7 and (matrizTablero[PosY+2][PosX+1] =='_' or matrizTablero[PosY+2][PosX+1] == 'o')){
		matriz[PosY+2][PosX+1] = 'M';
	}
	//5
	if(PosX-1 >= 0 and PosY+2 <= 7 and(matrizTablero[PosY+2][PosX-1] == '_' or matrizTablero[PosY+2][PosX-1] == 'o')){
		matriz[PosY+2][PosX-1] = 'M';
	}
	//6
	if(PosX-2 >= 0 and PosY+1 <= 7 and (matrizTablero[PosY+1][PosX-2] == '_' or matrizTablero[PosY+1][PosX-2] == 'o')){
		matriz[PosY+1][PosX-2] = 'M';
	}
	//7
	if(PosX-2 >= 0 and PosY-1 >= 0 and (matrizTablero[PosY-1][PosX-2] =='_' or matrizTablero[PosY-1][PosX-2] == 'o')){
		matriz[PosY-1][PosX-2] = 'M';
	}
	//8
	if(PosX-1 >= 0 and PosY-2 >= 0 and (matrizTablero[PosY-2][PosX-1] == '_' or matrizTablero[PosY-2][PosX-1] == 'o')){
		matriz[PosY-2][PosX-1] = 'M';
	}
}
void Torre(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){ //Listo
	/*****
	* void Torre
	******
	* Resumen Función
	* Se encarga de marcar las 2 direcciones en las que pueden moverse las torres
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	//2 direcciones: Horizontal y vertical
	//2 sentidos: positivo y negativo
	
	//Horizontal positivo (1.1) 

	for(int n = 1; n<9; n++){
		if(PosX+n < 8){ 
			if(matrizTablero[PosY][PosX+n] == '_' or matrizTablero[PosY][PosX+n] =='o'){
				matriz[PosY][PosX+n] = 'M';
			} else{
				break;
			}
		}
	}
	//Horizontal negativo (1.2)
	for(int n = 1; n<9; n++){
		if(PosX-n >= 0){ 
			if(matrizTablero[PosY][PosX-n] == '_' or matrizTablero[PosY][PosX-n] =='o'){
				matriz[PosY][PosX-n] = 'M';
			}else{
				break;
			}
		}
	}
	
	//Vertical positivo (2.1)
	for(int n = 1; n<9; n++){
		if(PosY+n < 8){ 
			if(matrizTablero[PosY+n][PosX] == '_' or matrizTablero[PosY+n][PosX] =='o'){
				matriz[PosY+n][PosX] = 'M';
			}else{
				break;
			}
		}
	}
	//Vertical positivo (2.1)
	for(int n = 1; n<9; n++){
		if(PosY-n >=0){
			if(matrizTablero[PosY-n][PosX] == '_' or matrizTablero[PosY-n][PosX] =='o'){
				matriz[PosY-n][PosX] = 'M';
			} else{
				break;
			}
			
		}
	}
	//Se vuelve a dejar la posicion de la torre libre
	matriz[PosY][PosX] = '_';

}
void Reina(char (&matriz)[8][8], int PosX, int PosY, char (&matrizTablero)[8][8]){ //Este esta pendiente todavia
	/*****
	* void Reina
	******
	* Resumen Función
	* Se encarga de marcar las posibles direcciones de la reina, que son la suma de las direccione sdel alfil y la torre. 
	* Por eso llama a esas funciones con los parametros de la reina. 
	* Marcará las casillas que correspondan con una 'M'
	******
	* Input:
	* char (&matriz)[8][8]:La matriz por referencia para marcar las posiciones
	* int PosX: coordenada X de la pieza
	* int PosY: coordenada Y de la pieza
	* char (&matrizTablero)[8][8]: Matriz de referencia para evitar la superposición de las piezas
	******
	* Returns:
	* No hay retorno pues es un void
	* Pero al recibir una matriz por referencia la va modificando
	*****/
	Alfil(matriz, PosX, PosY, matrizTablero);
	Torre(matriz, PosX, PosY, matrizTablero);

}
//Función principal
bool tableroEnJaqueMate(Tablero &tablero){
	/*****
	* bool tableroEnJaqueMate
	******
	* Resumen Función
	* Lo primero que hace es crear un arreglo bidimensional nuevo que simulará el tablero y donde se marcarán 
	* todas las casillas a las que las diferentes piezas puedan moverse. 
	* Luego recorre el struct tablero que se obtuvo por referencia desde el main para ir revisando pieza por pieza
	* Para cada pieza, llamará a la función que corresponda y les pasará las coordenas y la matriz bidimensional como parámetros
	* Luego de hacerlo con todas las piezas, buscará en la matriz si queda alguna posición a la que el Rey de Ton se pueda mover
	* sin generar un jaque. También es válido quedarse donde está si así evita el Jaque
	******
	* Input:
	* Tablero &tablero
	* Este es el struc generado en main() con la información de la cantidad de piezas, y las co
	* .......
	******
	* Returns:
	* Retorna el valor booleano de Flag, que será false si existe alguna posición segura para el Rey, y true si es que no la hay
	*****/
	bool Flag = true;
	//Se crea la matriz de 8x8 y se llena con '-' en todas las csillas.
	char matriz[8][8]; //[filas] [columnas] || [y][x]
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			matriz[j][i] = '_';
		}
	}
	//En esta mtariz se pondrán todas las piezas para revisar qué movimientos pueden realizar las piezas en general
	char matrizTablero[8][8]; //[filas] [columnas] || [y][x]
	for(int j = 0; j<8; j++){
		for(int i = 0; i<8; i++){
			matrizTablero[j][i] = '_';
		}
	}
	for(int i = 0; i<tablero.cantidad_piezas; i++){
		if(tablero.piezas_tablero[i].simbolo != 'X'){
			matrizTablero[tablero.piezas_tablero[i].y][tablero.piezas_tablero[i].x] = tablero.piezas_tablero[i].simbolo;
		}

	}
	
	
	//Aquí la lógica para marcar las casillas donde las piezas se pueden mover. 
	for(int i = 0; i<tablero.cantidad_piezas; i++){
		//[filas] [columnas] || [y][x]
		int PosX = tablero.piezas_tablero[i].x;
		int PosY = tablero.piezas_tablero[i].y;
		
		//Aquí se llama a la función correspondiente por cada pieza
		
		if(tablero.piezas_tablero[i].simbolo == 'K'){//Rey de Seba
			ReyDeSeba(matriz, PosX, PosY, matrizTablero);
		}else if(tablero.piezas_tablero[i].simbolo == 'R'){//Reina de Seba
			Reina(matriz, PosX, PosY, matrizTablero);
		}else if(tablero.piezas_tablero[i].simbolo == 'P'){//Peon de Seba
			Peon(matriz, PosX, PosY, matrizTablero);
		}else if(tablero.piezas_tablero[i].simbolo == 'A'){//Alfil de seba
			Alfil(matriz, PosX, PosY, matrizTablero);
		}else if(tablero.piezas_tablero[i].simbolo == 'C'){//Caballo de Seba
			Caballo(matriz, PosX, PosY, matrizTablero);
		}else if(tablero.piezas_tablero[i].simbolo == 'T'){//Torre de Seba
			Torre(matriz, PosX, PosY, matrizTablero);
		}
		
	}
	for(int i =0; i<tablero.cantidad_piezas; i++){
		int PosX = tablero.piezas_tablero[i].x;
		int PosY = tablero.piezas_tablero[i].y;
		if(tablero.piezas_tablero[i].simbolo == 'X'){ //Rey de Ton
			ReyDeTon(matriz, PosX, PosY);
		}
	}
	for(int y = 0; y<8; y++){
		for(int x = 0; x<8; x++){
			cout<<matrizTablero[y][x];
			}
		cout<<"\n";
		}
		
	
	cout<<"\n\n";
	//Acá se revisa si es jaque o no
	//Y por ahora tambíen imprimer la matriz completa	
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
//IDEA: Si logr eliminar la pieza que el rey se coma de la lista de piezas, podria vlver a llamr a la funcion booleana desde si misma. No se, quizas
int main(){
	/*****
	* int main()
	******
	* Resumen Función
	* En esta función se abre el archivo y se extrae la información necesaria.
	* Lo pirmero es crear todas las variables que vayan a ser necesarias, al igual que la apertura del archivo
	* Luego se extrae la información importante: La cantidad de piezas y las posiciones de cada una.
	* Esto se almacena el la variable del struct Tablero llamada "situacion"
	* Luego esta se pasa a la función TableroEnJaqueMate para que ejecute su lógica.
	* Por último se imprime si hay jaque según el retorno de la función y se cierra el archivo.
	******
	* Input:
	* No tiene inputs pues es la función main()
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
