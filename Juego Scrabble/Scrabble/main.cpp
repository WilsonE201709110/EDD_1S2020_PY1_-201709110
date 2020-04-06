#include "matrizD.h" //archivo cavecera

#include <iostream>
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#include<fstream> //PARA ABRIR ARCHIVO
#include <ctype.h>
#include <stdlib.h> //para generar numeros aleatorios
#include <fstream> //MANEJO DE ARCHIVOS
#include <sstream> //pasar de string a int
#include <sstream> //convertir int a string 

#define LETRA_A 65
#define LETRA_B 66
#define LETRA_C 67
#define LETRA_D 68
#define LETRA_E 69
#define LETRA_F 70
#define LETRA_G 71
#define LETRA_H 72
#define UNO 49
#define DOS 50
#define TRES 51
#define NUEVE 57

using namespace std;



void OcultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //recuperar el identificador de la consola

    CONSOLE_CURSOR_INFO cci; //Estructura
    cci.dwSize = 2;//puede tomar de valores de 1 a 100
    cci.bVisible = FALSE;//falso o verdadero(se mostrara o no)

    SetConsoleCursorInfo(hCon, &cci); //para controlar el cursor  , por referencia
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------
//----CLASE O ESTRUCTURA*--ARBOL-----------------
struct NodoDeArbol{
	int dato;
	string nombre;
	NodoDeArbol *der;
	NodoDeArbol *izq;
	NodoDeArbol *padre;
	
}; NodoDeArbol *arbol = NULL;

class DatosDeEntrada{
	int Ancho;
	int Longitud;
public:
	void setAncho(int _Ancho){
		Ancho = _Ancho;
	}
	
	void setLongitud(int _Longitud){
		Longitud = _Longitud;
	}
	
	int getAncho(){
		return Ancho;
	}
	
	int getLongitud(){
		return Longitud;
	}
	
};

NodoDeArbol *crearNodoDeArbol(int n,string s,NodoDeArbol *padre){
	NodoDeArbol *nuevo_nodo = new NodoDeArbol();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->nombre = s;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

void insertarNodoEnArbol(NodoDeArbol *&arbol,int n,string s,NodoDeArbol *padre){
	if(arbol==NULL){ //Si el arbol esta vacio
		NodoDeArbol *nuevo_nodo = crearNodoDeArbol(n,s,padre);
		arbol = nuevo_nodo;
	}
	else{ //Si el arbol tiene un nodo o mas
		if(arbol->dato==n){
			cout<<"ya Existete :("<<endl;
			Sleep(1200);
		}
		else{
			int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
			if(n<valorRaiz){ //Si el elemento es menor ala raiz lo insetamos en el lado izquierdo
				insertarNodoEnArbol(arbol->izq,n,s,arbol);
			}
			else{ //si el elemnto es mayor ala raiz insertar en el lado izquierdo
				insertarNodoEnArbol(arbol->der, n,s,arbol);
			}	
		}
	}
}


bool busquedaEnArbol(NodoDeArbol *arbol, int n,string s){
	if(arbol == NULL){ // si el arbol esta vacio
		return false;
	}
	else if(arbol->dato==n&&arbol->nombre==s){ //si el nodo es igual al elemento
		return true;
	}
	else if(n < arbol->dato){
		return busquedaEnArbol(arbol->izq,n,s);
	}
	else{
		return busquedaEnArbol(arbol->der,n,s);
	}
}

void mostrarArbol(NodoDeArbol *arbol,int n){
	if(arbol==NULL){  //si el arbo, esta vacio
		return;
	}
	else{
		mostrarArbol(arbol->der, n+1);
		for(int i=0;i<n;i++){
			cout<<"   ";
		}
		cout<<"Nombre: "<<arbol->nombre<<" - Contrasena: "<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,n+1);
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------LISTA Circular DOBLEMENTE ENLAZADA----> CONTRENDA EN DICCIONARIO

struct nodo_LCDE_D{
	string palabra;
	nodo_LCDE_D* siguiente;
	nodo_LCDE_D* atras;
}*primero, *ultimo;

//insertar un nodo
void insertarNodo_LCDE_D(string palabra){
	nodo_LCDE_D* nuevo = new nodo_LCDE_D();
	nuevo->palabra = palabra;

	if(primero==NULL){
		primero = nuevo;              // p->[]
		ultimo = nuevo;               // u->[]
		primero->siguiente = primero; //  s->[]->s
		primero->atras = ultimo;      // a->[]->a
	}else{
		ultimo->siguiente = nuevo;
		nuevo->atras = ultimo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
}

//MOSTRAR palabras
void desplegarListaPU(){
	nodo_LCDE_D* actual = new nodo_LCDE_D();
	actual = primero;
	if(primero!=NULL){
		do{
			cout << "\n " << actual->palabra;
			actual = actual->siguiente;
		}while(actual!=primero);

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

bool buscarNodoDiccionario(string palabra){
	nodo_LCDE_D* actual = new nodo_LCDE_D();
	actual = primero;
	bool encontrado = false;
	if(primero!=NULL){
		do{

			if(actual->palabra==palabra){
				//cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
				
				return encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=primero && encontrado != true);

		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	return encontrado = false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------LISTA Circular DOBLEMENTE ENLAZADA----> Jugadores

struct nodo_LCDE_J{
	string nombre;
	int puntaje;
	nodo_LCDE_J* siguiente;
	nodo_LCDE_J* atras;
} *primeroJ, *ultimoJ;// *scrobPrimero,*scrobUltimo;


// isertar
void isertarNodoJugador(int _puntaje, string _nombre){
	nodo_LCDE_J* nuevo = new nodo_LCDE_J();
	nodo_LCDE_J* nuevoAux = new nodo_LCDE_J();
	nuevoAux = primeroJ;
	
	bool esta= false;
	
	if(primeroJ!=NULL){
		while(!esta&&nuevoAux!=ultimoJ){
			if(nuevoAux->nombre==_nombre) esta = true;
			nuevoAux= nuevoAux->siguiente;
		}
	}
	if(!esta){
		nuevo->nombre = _nombre;
		nuevo->puntaje = _puntaje;
	
		if(primeroJ==NULL){
			primeroJ = nuevo;
			ultimoJ = nuevo;
			primeroJ->siguiente = primeroJ;
			primeroJ->atras = ultimoJ;
		}
		else
		{
			ultimoJ->siguiente = nuevo;
			nuevo->atras = ultimoJ;
			nuevo->siguiente = primeroJ;
			ultimoJ = nuevo;
			primeroJ->atras = ultimoJ;
		}	
	}
	
}
	

void PuntajeJugador(string nombre, int _puntos){ 
	nodo_LCDE_J* actual = new nodo_LCDE_J();
	actual = primeroJ;
	bool encontrado = false;
	//int nodoBuscado = 0;
	
	if(primeroJ!=NULL){
		do{

			if(actual->nombre==nombre){
				actual->puntaje+=_puntos;
				encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=primeroJ && encontrado != true);

		if(!encontrado){
			cout << "\n Jugador no Encontrado\n\n";
		}

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

string mostrarScrobBoar(){
	nodo_LCDE_J* actual = new nodo_LCDE_J();
	actual = primeroJ;
	nodo_LCDE_J* actualAux = new nodo_LCDE_J();
	actualAux = primeroJ->siguiente;
	string reporte;
	stringstream cadena;
	
	reporte = "digraph G{\n";
	
	if(primeroJ!=NULL){
		do{
			cadena<<actual->puntaje;
			reporte += actual->nombre+"[shape=box, label=\""+actual->nombre+": "+cadena.str()+"\"];\n";
			reporte += actual->nombre+"->"+actualAux->nombre+";\n";
			
			actual = actualAux;
			actualAux= actualAux->siguiente;
			
		}while(actualAux==primeroJ);

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	
	reporte += "}\n";
	Sleep(5000);
}

void mostrarpuntajedejugador(string nombre){
	nodo_LCDE_J* actual = new nodo_LCDE_J();
	actual = primeroJ;
	bool encontrado = false;
	
	if(primeroJ!=NULL){
		do{

			if(actual->nombre==nombre){
				actual->puntaje;
				cout<<actual->nombre<<"->"<<actual->puntaje<<";"<<endl;
				encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=NULL && encontrado != true);

		if(!encontrado){
			cout << "\n Jugador no Encontrado\n\n";
		}

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	Sleep(5000);
}

int buscarPuntajeJugador(string nombre){
	nodo_LCDE_J* actual = new nodo_LCDE_J();
	actual = primeroJ;
	bool encontrado = false;
	//int nodoBuscado = 0;
	
	if(primeroJ!=NULL){
		do{

			if(actual->nombre==nombre){
				//cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado\n\n";
				return actual->puntaje;
				encontrado = true;
			}

			actual = actual->siguiente;
		}while(actual!=primeroJ && encontrado != true);

		if(!encontrado){
			cout << "\n Jugador no Encontrado\n\n";
		}

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	return 0;
}

string mostrarScrobBoarJugadores(){
	nodo_LCDE_J* actual = new nodo_LCDE_J();
	actual = primeroJ;
	nodo_LCDE_J* actualAux = new nodo_LCDE_J();
	actualAux = primeroJ->siguiente;
	string reporte;
	stringstream cadena;
	
	reporte = "digraph G{\n";
	
	if(primeroJ!=NULL){
		do{
			cadena<<actual->puntaje;
			reporte += actual->nombre+"[shape=box, label=\""+actual->nombre+": "+cadena.str()+"\"];\n";
			reporte += actual->nombre+"->"+actualAux->nombre+";\n";
			
			actual = actualAux;
			actualAux= actualAux->siguiente;
			
		}while(actualAux==ultimoJ);

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	
	reporte += "}\n";
	return reporte;
	Sleep(5000);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------LISTA DOBLEMENTE ENLAZADA----> Fichas jugador 1

struct nodo_LDE_F1{
	int puntos;
	char letra;
	nodo_LDE_F1* siguiete;
	nodo_LDE_F1* atras;
} *primeroF1, *ultimoF1;

int puntosF1;
char letraF1;
void setPuntosF1(int _punto){
	 puntosF1 = _punto; 
}
int getPuntosF1(){  
	return puntosF1;
}
void setLetraF1(char _letra){
	 letraF1 = _letra; 
}
int getLetraF1(){  
	return letraF1;
}

//insertar 
void isertarNodoFicha(char ficha, int punteo){
	nodo_LDE_F1* nuevo = new nodo_LDE_F1();
	nuevo->letra = ficha;
	nuevo->puntos = punteo;
	
	if(primeroF1==NULL){
		primeroF1 = nuevo;
		ultimoF1 = nuevo;
		primeroF1->siguiete = NULL;
		primeroF1->atras = NULL;
	}
	else{
		ultimoF1->siguiete = nuevo;
		nuevo->atras = ultimoF1;
		ultimoF1 = nuevo;
		nuevo->siguiete = NULL;
		primeroF1->atras = primeroF1;
	}
}

void desplegarLista_Fichas1(){
	nodo_LDE_F1* actual = new nodo_LDE_F1();
	actual = primeroF1;
	if(primeroF1!=NULL){
		cout<< "    ---------------------------- \n";		
		while(actual!=NULL){
			cout<< "  \t  ¦ " << actual->letra<<" ¦\n";
			actual = actual->siguiete;
		}
		cout<< "    ---------------------------- \n";	
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

void eliminarNodoF1(char letra){  //eliminarNodoF1(char letra)
	nodo_LDE_F1* actual = new nodo_LDE_F1();
	actual = primeroF1;
	nodo_LDE_F1* anterior = new nodo_LDE_F1();
	anterior = NULL;
	bool encontrado = false;
	if(primeroF1!=NULL){

		while(actual!=NULL && encontrado!=true){

			if(actual->letra == letra){
				setPuntosF1(actual->puntos);
				
				if(actual==primeroF1){
					primeroF1 = primeroF1->siguiete;
					primeroF1->atras = NULL;
					
				}else if(actual==ultimoF1){
					anterior->siguiete = NULL;
					ultimoF1 = anterior;
				}else{
					anterior->siguiete = actual->siguiete;
					actual->siguiete->atras = anterior;
				}

				//cout << "\n Nodo Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiete;
		}

		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}

	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}




int ObtenerPunto(char letra){
	nodo_LDE_F1* actual = new nodo_LDE_F1();
	actual = primeroF1;
	nodo_LDE_F1* anterior = new nodo_LDE_F1();
	anterior = NULL;
	bool encontrado = false;
	if(primeroF1!=NULL){

		while(actual!=NULL && encontrado!=true){

			if(actual->letra == letra){
				//cout << "\n Nodo con el dato ( " << nodoBuscado << " ) Encontrado";
				return actual->puntos;
				

				//cout << "\n Nodo Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiete;
		}

		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}

	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	return 0;
}
//----------------LISTA DOBLEMENTE ENLAZADA----> Fichas jugador 2

struct nodo_LDE_F2{
	int puntos;
	char letra;
	nodo_LDE_F2* siguiete;
	nodo_LDE_F2* atras;
} *primeroF2, *ultimoF2;

int puntosF2;
void setPuntosF2(int _punto){
	 puntosF2 = _punto; 
}
int getPuntosF2(){
	return puntosF2;
}

//insertar 
void isertarNodoFichaJugador2(char ficha, int punteo){
	nodo_LDE_F2* nuevo = new nodo_LDE_F2();
	nuevo->letra = ficha;
	nuevo->puntos = punteo;
	
	if(primeroF2==NULL){
		primeroF2 = nuevo;
		ultimoF2 = nuevo;
		primeroF2->siguiete = NULL;
		primeroF2->atras = NULL;
	}
	else{
		ultimoF2->siguiete = nuevo;
		nuevo->atras = ultimoF2;
		ultimoF2 = nuevo;
		nuevo->siguiete = NULL;
		primeroF2->atras = primeroF2;
	}
}

void desplegarLista_Fichas2(){
	nodo_LDE_F2* actual = new nodo_LDE_F2();
	actual = primeroF2;
	if(primeroF2!=NULL){
		cout<< "    ---------------------------- \n";	
		while(actual!=NULL){
			
			cout<< "  \t  ¦ " << actual->letra<<" ¦\n";
			
			actual = actual->siguiete;
		}
		cout<< "    --------------------------- \n";
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}


void eliminarNodoF2(char letra){
	nodo_LDE_F2* actual = new nodo_LDE_F2();
	actual = primeroF2;
	nodo_LDE_F2* anterior = new nodo_LDE_F2();
	anterior = NULL;
	bool encontrado = false;
	if(primeroF2!=NULL){

		while(actual!=NULL && encontrado!=true){

			if(actual->letra == letra){
				setPuntosF2(actual->puntos);
				
				if(actual==primeroF2){
					primeroF2 = primeroF2->siguiete;
					primeroF2->atras = NULL;
					
				}else if(actual==ultimoF2){
					anterior->siguiete = NULL;
					ultimoF2 = anterior;
				}else{
					anterior->siguiete = actual->siguiete;
					actual->siguiete->atras = anterior;
				}

				//cout << "\n Nodo Eliminado";
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiete;
		}

		if(!encontrado){
			cout << "\n Nodo no Encontrado\n\n";
		}

	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------COLA---> AQUI ESTAN LoS NUMEROS ALEATORIO

struct nodo_cola{
	int puntos;
	char letra;
	nodo_cola* siguienteC;
} *primero_cola, *ultimo_cola;

int _punteo;
char _letra;
void setPunteo(int puntos){
	_punteo = puntos;	
} 
void setLetra(char letra){
	_letra = letra;	
} 
int getPuntos(){    
	return _punteo;
} 
char getLetra(){
	return _letra;	
} 


void insertarNodoCola(int _puntos,char _letra){
	nodo_cola* nuevoCola = new nodo_cola();
	nuevoCola->puntos = _puntos;
	nuevoCola->letra = _letra;
	
	
	if(primero_cola==NULL){
		primero_cola = nuevoCola;
		primero_cola->siguienteC = NULL;
		ultimo_cola = primero_cola;
	}
	else{
		ultimo_cola->siguienteC = nuevoCola;
		nuevoCola->siguienteC = NULL;
		ultimo_cola = nuevoCola;
	}
	
}

 void eliminarNodoCola(){ 
	nodo_cola* actual = new nodo_cola();
	actual = primero_cola;
	
	
	if(primero_cola!=NULL){
		if(actual== primero_cola){
			primero_cola = primero_cola->siguienteC;
			setPunteo(actual->puntos);
			setLetra(actual->letra);
		}
	}else{
		cout<<endl<<" Se paso el dato "<< endl <<endl;
	}
}

//*ESTOS METODOS SIRVEN PARA AGREGAR LOS DATOS DE LA LISTA DE FICHAS DE A LA COLA
//FICHA JUGADOR 1
void vaciarF1(int n){  //eliminarNodoF1(char letra)
	nodo_LDE_F1* actual = new nodo_LDE_F1();
	actual = primeroF1;
	nodo_LDE_F1* anterior = new nodo_LDE_F1();
	anterior = NULL;
	int Numero_de_Fichas = 0;
	if(primeroF1!=NULL){

		while(actual!=NULL&& Numero_de_Fichas<n){
			insertarNodoCola(actual->puntos,actual->letra);
				if(actual->siguiete==NULL){
					primeroF1 = NULL;
					ultimoF1 = NULL;
				}
				else if(actual==primeroF1){
					primeroF1 = primeroF1->siguiete;
					primeroF1->atras = NULL;
					
				}else if(actual==ultimoF1){
					anterior->siguiete = NULL;
					ultimoF1 = anterior;
				}else{
					anterior->siguiete = actual->siguiete;
					actual->siguiete->atras = anterior;
				}
			Numero_de_Fichas++;	
			anterior = actual;
			actual = actual->siguiete;
		}
	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

//FIcha de jugador 2
void vaciarF2(int n){
	nodo_LDE_F2* actual = new nodo_LDE_F2();
	actual = primeroF2;
	nodo_LDE_F2* anterior = new nodo_LDE_F2();
	anterior = NULL;
	int Numero_de_Fichas = 0;
	if(primeroF2!=NULL){

		while(actual!=NULL && Numero_de_Fichas < n){
				insertarNodoCola(actual->puntos,actual->letra);
				if(actual->siguiete==NULL){
					primeroF2 = NULL;
					ultimoF2 = NULL;
				}
				else if(actual==primeroF2){
					primeroF2 = primeroF2->siguiete;
					primeroF2->atras = NULL;
					
				}else if(actual==ultimoF2){
					anterior->siguiete = NULL;
					ultimoF2 = anterior;
				}else{
					anterior->siguiete = actual->siguiete;
					actual->siguiete->atras = anterior;
				}
				 Numero_de_Fichas++;
			anterior = actual;
			actual = actual->siguiete;
		}

	}else{
		cout << "\n La listas se encuentra Vacia\n\n";
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
///----------LISTA SIMPLE ENLAZADA PARA SCROBBOAR De cada jugador

struct nodo_LSE{
	string nombre;
	int punto;
	nodo_LSE* siguiente;
}*primeroLSE, *ultimoLSE;

void agregarJugador(){
	
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//-----------METODOS DE MENU JUEGO-------------
void menu_Juego();
void iniJuego();
void usuarios(); 
void lectura();
void optenedorDeDatosDeLectura(string);
void reportes();


//VARIABLES DE ARCHIVO
int dimension;
int casillasDobles[50][2], filas=0, columnas=0;
int casillasTriples[50][2], filast=0, columnast=0;
string diccionario;
//string casillasDobles;
//string casillasTriples;

void setDimension(int);
//void setCasillaDoble(string);
//void setCasillaTriple(string);
void setCasillaDoble(int);
void setCasillaTriple(int);
void setDiccionario(string);

string extraer(string);
int getDimension();
//string getCasillaDoble();
//string getCasillaTriple();
string getDiccionario();

//metodo opara generar las letras al asar
void generadorDeLetras(int);

///----------------------------------------------------
//-----------------------------------------------------
///----------------------------------------------------
///REPORTES O GRAFICAS
void reporteCola(char,int,int);
void reporteDiccionario(string,string,bool);
void reporteArbol(string,string,string);
void reportepreOrden(string);
void reporteinOrden(string);
void reportepostOrden(string);
void reporteMatriz(string);
void reporteScrob(string);

void graficar(int);

//Cola
void mostrarCola();
//DICCIONARIO
void mostrarDiccionario();
//Arbol
//Funcionpara mostrar el arbol comlpeto
void mostrarArbol(NodoDeArbol*);
//REcorrido en profundidad - PreOrden
void preOrdenArbol(NodoDeArbol*);

//REcorrido en profundidad - InOrden
void InOrdenArbol(NodoDeArbol*);

//REcorrido en profundidad - PostOrden
void PostOrdenArbol(NodoDeArbol*);

//codigo de matriz
string llenarMatriz(matrizOrtogonal*,nodoOrtogonal*);
char indice(matrizOrtogonal*,nodoOrtogonal*,int, int);
char caso1(matrizOrtogonal*, nodoOrtogonal*, int , int ); //   <---
char caso2(matrizOrtogonal*, nodoOrtogonal*, int , int ); //  ||++
char caso3(matrizOrtogonal*, nodoOrtogonal*, int , int ); // //^^^^
char caso4(matrizOrtogonal*, nodoOrtogonal*, int , int ); // //^^^^
char caso5(matrizOrtogonal*, nodoOrtogonal*, int , int ); // //^^^^
int n;
int indiceY();
void setindiceY(int);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    OcultarCursor();
    int num;
    cout<<"\nIngresa tus fichas porfavor $_$!: "; cin>>num;
	generadorDeLetras(num);
	
    bool salir=FALSE;
    char teclaOpcion;
    do{
        system("cls");
        cout<<"\t\tSCRABBLE++\n\n"<<endl;
        cout<<"\tA. Lectura de Archivo\n"<<endl;
        cout<<"\t B. Juego*\n"<<endl;
        cout<<"\t  C. Reportes\n"<<endl;
        cout<<"\t   D. Salir\n"<<endl;

        teclaOpcion=getch();

        switch(teclaOpcion){
            case LETRA_A:
                lectura();
                break;
            case LETRA_B:
                cout<<"\t\t\testas en el juego"<<endl;
                menu_Juego();
                break;
            case LETRA_C:
                cout<<"\t\t\testas en reportes"<<endl;
                reportes();
                break;
            case LETRA_D:
                salir=TRUE;
                cout<<"\n\tGRASIAS POR JUGAR :)"<<endl;
                Sleep(500);
                break;
            default:
                cout<<"\tINGRESA UNA OPCION VALIDA (-_-)!!"<<endl<<endl;
                Sleep(850);
                break;
        }
        //Sleep(100);
    }while(!salir);

    getch();
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu_Juego(){
	OcultarCursor();
	//matrizOrtogonal* matriz = new matrizOrtogonal();
	
    bool salir=FALSE;
    char teclaOpcion;
    int id; 
    string nombre;
    string texto;
    char letra;
    
    do{
        system("cls");
        cout<<"\t\tSCRABBLE++\n\n"<<endl;
        cout<<"\tA. Jugar \n"<<endl;
        cout<<"\t B. Usuarios*\n"<<endl;
        cout<<"\t  C. Busca Usuario\n"<<endl;
		cout<<"\t   D. Atras\n"<<endl;
		 
        teclaOpcion=getch();

        switch(teclaOpcion){
            case LETRA_A:
                cout<<"\t\tMATRIZ DEL JUEGO"<<endl;
                iniJuego();
              
                
                break;
            case LETRA_B:
                usuarios();
                break;
            case LETRA_C:cout<<"\ndigite el nombre de usuario: "<<endl;
					cin>>nombre;
					cout<<"\ndigite id de usuario: "<<endl;
					cin>>id;
					if( busquedaEnArbol(arbol,id,nombre)== true){
						cout<<"\nEl usuario "<<nombre<<" con id "<<id<<" Encontrado"<<endl;
					}
					else{
						cout<<"\nEl usuario no existe\n"<<endl;
					}
					cout<<"\n";
                	Sleep(1200);
                break;
            case LETRA_D:
            	salir=TRUE;
            default:
                cout<<"\tINGRESA UNA OPCION VALIDA (-_-)!!"<<endl<<endl;
                Sleep(900);
                break;
        }
    }while(!salir);

}

void usuarios(){
	OcultarCursor();
	string nombre;
    int contrasena;
        system("cls");
        cout<<"\t\tSCRABBLE++\n\n"<<endl;
        cout<<"\tNombre de Usuario: "; cin>>nombre;
        cout<<"\tIngresa tu Contraseña de [1,..,50]: "; cin>>contrasena;
        
        insertarNodoEnArbol(arbol,contrasena,nombre,NULL);
        cout<<"USUARIO REGISTRADO"<<endl;
        Sleep(1000);
}


//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------
//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------
//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------
void iniJuego(){
	//-----------------CREACION DE LA MATRIZ --------------------------------
	matrizOrtogonal* matriz = new matrizOrtogonal();
	nodoOrtogonal* nodo;
	 		
	matriz->llenar(getDimension(),getDimension());
	//----------------------------------------------------------------------
	
	string nombre1;	
	string nombre2;	
	int contrasena;
	
	bool jugador1 = false;
	bool jugador2 = false;
	bool continuar = true;
	
	char teclaOpcion;
	
	do{
		if(!jugador1){
			cout<<"\tjugador 1"<<endl;
			cout<<"\nNOMBRE DE JUGADOR: "; cin>>nombre1;
			cout<<"\nINGRESA CONTRASEÑA: "; cin>>contrasena; 
			if(busquedaEnArbol(arbol,contrasena,nombre1)){
			isertarNodoJugador(0, nombre1); 
			jugador1 = true;
			}
		}
			
		cout<<"\t\nA) Continuar #OK";
		cout<<"\t\t\nB) Regresar #KO";
		teclaOpcion = getch();
		
		system("cls");
		
		switch(teclaOpcion)
		{
			if(jugador1 && jugador2){
				continuar = false;
			}
			case LETRA_B:
				continuar = false;
				break;
		}
		
		if(!jugador2){
			cout<<"\tjugador 2"<<endl;
			cout<<"\nNOMBRE DE JUGADOR: "; cin>>nombre2;
			cout<<"\nINGRESA CONTRASEÑA: "; cin>>contrasena; 
			if(busquedaEnArbol(arbol,contrasena,nombre2)){
			isertarNodoJugador(0, nombre2);
			jugador2 = true;
			}
		}
		
	}while(continuar);
	
	system("cls");
	if(jugador1 && jugador2){
		int numero_de_letra;
		cout<<"Ingrese el numero de fichas a Jugar\nPorfa :) ->: "; cin>>numero_de_letra;
		for(int i=0;i < numero_de_letra;i++){
			eliminarNodoCola();
			isertarNodoFicha(getLetra(),getPuntos());
			eliminarNodoCola();
			isertarNodoFichaJugador2(getLetra(),getPuntos());
		}
	//----------------------------TURNOS--------------------------
	bool turno = true;
	int alazar;
	bool finalizar = false;
	cout<<"Elige un numero = [1 , 2 ,3 ,4 ,5 ,6]"<<endl;
	cout<<"\t----> "; cin>>alazar;
	
	if(alazar!=1&&alazar!=3&&alazar!=4){
		turno = true;	
	}
	else{
		turno = false;
	}
	
//**-------------------------------------------------------	
	char opcion; char opcionDeUno;
	//variables de 
	char letra;
	int Postx,Posty;
	char letras[100][100];
	char temporal[10];
	stringstream format;
	stringstream palabaConcatenada;
	string palabra;
	int s=0;
	
	int xp, yp; bool prim =true;
	int xu, yu;
	
	reporteMatriz(llenarMatriz(matriz,nodo));      //---------------------------------------------------------------------------------------------------------------------------------------------------------
	graficar(7);
	//***ABRIR IMAGEN
	try{
		string comando;
					
		comando="matriz.png";
		
		system(comando.c_str());
		
		cout<<"Reporte Diccionario";
		system("pause");
		}catch(std::exception& e){
		cout<<"Reporte Graficado. \n";
	}
	//--------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------
	do{
		prim = true;
		if(turno){		//--------------------------------------------------------------------------------------------------------
			system("cls");
			cout<<"\t\tScrabble"<<endl<<endl;
			cout<<"\t\t\t  "<<nombre1<<"___Puntaje "<<buscarPuntajeJugador(nombre1)<<endl;
			cout<<"\nfichas1"<<endl;
			desplegarLista_Fichas1();
			
			cout<<"  1) Colocar Ficha"<<endl;
			cout<<"   2) TerminarTurno"<<endl;
			cout<<"    3) Cambiar Fichas"<<endl;
			cout<<"     9) Salir"<<endl;
			cout<<"\n[Opcion]:  "; 
			opcion = getch();
			
			switch(opcion){
				case UNO:
					do{
						system("cls");
						cout<<"\t\t:3 Scrabble :)"<<endl<<endl;		//MENU PARA COLOCAR UNA FICHA
						cout<<"\n[Letra]: "; cin>>letra;
						cout<<"\n[Pocision_X]: "; cin>>Postx;
						cout<<"\n[pocision_Y]: "; cin>>Posty;
						if(prim){									//SEGUARDAN LOS PRIMEROS DATOS
							xp=Postx; yp=Posty;	
							prim= false;
						}
						letras[Postx][Posty] = letra;				//SE GUARDA EN LA MATRIZ
						temporal[s] = letra; 
								
						cout<<"\nfichas1"<<endl;                    //MENUR
						desplegarLista_Fichas1();
			
						cout<<"  1) Colocar otra Ficha"<<endl;
						cout<<"   2) Validar"<<endl;
						cout<<"\n[Opcion]:  "; 
						
						opcionDeUno = getch();						//OPCION SEGUNDA
						
						switch(opcionDeUno){						//OPCIONES MENU 2 
							case UNO:		
								s++;
								opcionDeUno = 1;
								break;
							case DOS:
								xu = Postx; yu = Posty;         
								for(int i = yp; i <=yu;i++){
									for(int j = xp; j <= xu; j++){
										palabaConcatenada<<letras[j][i];						
									}
								}					
								palabra=palabaConcatenada.str();
								
								if(buscarNodoDiccionario(palabra)){		//agregar a a mi matriz
									palabaConcatenada.str("");
									for(int i = yp; i <=yu;i++){
										for(int j = xp; j <= xu; j++){
											if(letras[j][i]!=NULL){
												matriz->reemplazar(letras[j][i],j,i);
												for(int k=0;k<50;k++){
													if(casillasDobles[k][0]!=NULL){
														if(casillasDobles[k][0] == j&&casillasDobles[k][1] == i) PuntajeJugador(nombre1, getPuntosF1()*2);	
													}
													if(casillasTriples[k][0]!=NULL)
													{
														if(casillasTriples[k][0] == j&&casillasTriples[k][1] == i) PuntajeJugador(nombre1, getPuntosF1()*3);
													}
												}
											}							
										}
									}		
									Sleep(200);
									
									for(int k = 0;k<10;k++){			//eliminar de la lista		y sumar el pnteo correspondiente
										if(temporal[k]!=NULL){
											eliminarNodoF1(temporal[k]);
											PuntajeJugador(nombre1, getPuntosF1());
										}
									}
									
									for(int k = 0;k<10;k++){			//borrar datos jiji		
										if(temporal[k]!=NULL){
											temporal[k]=' ';
										}
										s=0;
									}
								}
								
								//-----------------------------------------------
								reporteMatriz(llenarMatriz(matriz,nodo));      //---------------------------------------------------------------------------------------------------------------------------------------------------------
								graficar(7);
								
								try{
									string comandoCerrar;	
						
									comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
									system(comandoCerrar.c_str());
									cout<<"reporte Cerrado";
					
								}catch(std::exception& e){
									cout<<"Reporte GRaficado. \n";
								}
                		 			Sleep(1500);
									turno = false;
									opcionDeUno = 2;
									break;
									
								}
								try{
									string comando;
					
									comando="matriz.png";
		
									system(comando.c_str());
		
								cout<<"Reporte Diccionario";
								system("pause");
								}catch(std::exception& e){
									cout<<"Reporte Graficado. \n";
								}
						
					}while(opcionDeUno!=2);
					
					break;
					
				case DOS:
					turno = false;
					break;
					
				case TRES:
					vaciarF1(numero_de_letra);
						for(int i=0;i < numero_de_letra;i++){
							eliminarNodoCola();
							isertarNodoFicha(getLetra(),getPuntos());
						}
					cout<<"\nTu turno a terminado :)"<<endl;
					Sleep(1000);
					turno = false;
					break;
					
				case NUEVE:
					finalizar = true;
					break;
						
				default:
					cout<<"\nSolo una opcion de las que estan (-_-)!!";
					break;	
			}
		}
		//JUGADOR DOS
		else if(!turno)
		{
			system("cls");
			cout<<"\t\tScrabble"<<endl<<endl;
			cout<<"\t\t\t  "<<nombre2<<"___Puntaje "<<buscarPuntajeJugador(nombre2)<<endl;
			cout<<"\nfichas2"<<endl;
			desplegarLista_Fichas2();
			
			cout<<"  1) Colocar Ficha"<<endl;
			cout<<"   2) TerminarTurno"<<endl;
			cout<<"    3) Cambiar Fichas"<<endl;
			cout<<"     9) Salir"<<endl;
			cout<<"\n[Opcion]:  "; 
			opcion = getch();
			
			switch(opcion){
					case UNO:
						do{
						system("cls");
						cout<<"\t\t:3 Scrabble :)"<<endl<<endl;
						cout<<"\n[Letra]: "; cin>>letra;
						cout<<"\n[Pocision_X]: "; cin>>Postx;
						cout<<"\n[pocision_Y]: "; cin>>Posty;
						if(prim){
							xp=Postx; yp=Posty;	
							prim= false;
						}
						letras[Postx][Posty] = letra;
						temporal[s] = letra; 
								
						cout<<"\nfichas2"<<endl;
						desplegarLista_Fichas1();
			
						cout<<"  1) Colocar otra Ficha"<<endl;
						cout<<"   2) Validar"<<endl;
						cout<<"\n[Opcion]:  "; 
						
						opcionDeUno = getch();
						
						switch(opcionDeUno){
							case UNO:		
								s++;
								opcionDeUno = 1;
								break;
							case DOS:
								xu = Postx; yu = Posty;
								for(int i = yp; i <=yu;i++){
										for(int j = xp; j <= xu; j++){
											palabaConcatenada<<letras[j][i];							
										}
								}					
								palabra=palabaConcatenada.str();
								
								if(buscarNodoDiccionario(palabra)){
									palabaConcatenada.str("");
									for(int i = yp; i <=yu;i++){
										for(int j = xp; j <= xu; j++){
											if(letras[j][i]!=NULL){
												matriz->reemplazar(letras[j][i],j,i);
												for(int k=0;k<50;k++){
													if(casillasDobles[k][0]!=NULL){
														if(casillasDobles[k][0] == j&&casillasDobles[k][1] == i) PuntajeJugador(nombre1, getPuntosF1()*2);	
													}
													if(casillasTriples[k][0]!=NULL)
													{
														if(casillasTriples[k][0] == j&&casillasTriples[k][1] == i) PuntajeJugador(nombre1, getPuntosF1()*3);
													}
												}
											}
											
										   //reporteMatriz(llenarMatriz(matriz,nodo));								
										}
									}		
									Sleep(2000);
									
									for(int k = 0;k<10;k++){
										if(temporal[k]!=NULL){
											eliminarNodoF2(temporal[k]);
											PuntajeJugador(nombre2, getPuntosF2());
										}
									}
									
									for(int k = 0;k<10;k++){			//borrar datos jiji		
										if(temporal[k]!=NULL){
										temporal[k]=' ';
									}
									s=0;
									}
								}
								reporteMatriz(llenarMatriz(matriz,nodo));      //---------------------------------------------------------------------------------------------------------------------------------------------------------
								graficar(7);
									try{
							string comandoCerrar;	
						
							comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
							system(comandoCerrar.c_str());
		
							cout<<"reporte Cerrado";
					
							}catch(std::exception& e){
								cout<<"Reporte GRaficado. \n";
							}
                 			Sleep(1500);
							turno = true;
							opcionDeUno = 2;
							break;
						}
								try{
									string comando;
					
									comando="matriz.png";
		
									system(comando.c_str());
		
								cout<<"Reporte Diccionario";
								system("pause");
								}catch(std::exception& e){
									cout<<"Reporte Graficado. \n";
								}
						
					}while(opcionDeUno!=2);
					
						break;
					case DOS:
						turno = true;
						break;
					case TRES:                  /////////	Vaciar ------------
						vaciarF2(numero_de_letra);
						for(int i=0;i < numero_de_letra;i++){
							eliminarNodoCola();
							isertarNodoFichaJugador2(getLetra(),getPuntos());
						}
						cout<<"\nTu turno a terminado :)"<<endl;
						Sleep(1000);
						turno = true;
						break;
					case NUEVE:
						
						finalizar = true;
						break;
					default:
					cout<<"\nSolo una opcion de las que estan (-_-)!!";
					break;	
			}
			
		}
	}while(!finalizar);		
	
/*	if(finalizar){
		insertarNodoScoreBoard(buscarPuntajeJugador(nombre1));
		insertarNodoScoreBoard(buscarPuntajeJugador(nombre2));
	}*/
	
	}
	/*cout<<" JUGAR1 :)\n";
	mostrarpuntajedejugador(nombre1);
	cout<<" JUGAR2 :)\n";
	mostrarpuntajedejugador(nombre2);
	cout<<"SALISTE DEL JUEGO GRASIAS POR JUGAR :)";*/
	getch();
}



//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------
//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------
//-------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++----------------

void reportes(){
	OcultarCursor();  //OCULTAR EL CURSOR

    bool salir=false; //VARIBLE PARA SALIR
    char teclaOpcion; //VARIABLE DONDE SE GUARDARA LA TECLA PRESIONADA
    int id;  
    string nombre;
    do{
        system("cls");
        cout<<"\t\tSCRABBLE++\n\n"<<endl;
        cout<<"\tA. Diccionario \n"<<endl;
        cout<<"\t B. Cola de fichas*\n"<<endl;
        cout<<"\t  C. Arbol\n"<<endl;
		cout<<"\t   D. Arbol - preOrden\n"<<endl;
		cout<<"\t    E. Arbol - inOrden\n"<<endl;
		cout<<"\t     F. Arbol - postOrden\n"<<endl;
		cout<<"\t      G. Scrob Boar\n"<<endl; 
		cout<<"\t       H. Atras\n"<<endl;
		 
        teclaOpcion=getch();
        switch(teclaOpcion){
            case LETRA_A:
                 mostrarDiccionario();
                 try{
					string comando;
					
					comando="Diccionario.png";
		
					system(comando.c_str());
		
					cout<<"Reporte Diccionario";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
                break;
            case LETRA_B:
                mostrarCola();
                try{
					string comando;
					
					comando="Cola.png";
		
					system(comando.c_str());
		
					cout<<"Reporte Cola";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
                getch();
                break;
            case LETRA_C:
            	mostrarArbol(arbol,0);
            	Sleep(3700);
                break;
            case LETRA_D:
            	preOrdenArbol(arbol);
            	reportepreOrden("F");
            	graficar(4);
            	
            	try{
					string comando;
					
					comando="preOrden.png";
		
					system(comando.c_str());
		
					cout<<"Reporte PreOrden";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
            	break;
            case LETRA_E:
            	InOrdenArbol(arbol);
            	reporteinOrden("F");
            	graficar(5);
            		try{
					string comando;
					
					comando="inOrden.png";
		
					system(comando.c_str());
		
					cout<<"Reporte PreOrden";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
            	break;
			case LETRA_F:
            	PostOrdenArbol(arbol);
            	reportepostOrden("F");
            	graficar(6);
            		try{
					string comando;
					
					comando="postOrden.png";
		
					system(comando.c_str());
		
					cout<<"Reporte PreOrden";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
            	break;
			case LETRA_G:
				reporteScrob(mostrarScrobBoar());
				graficar(8);
            		try{
					string comando;
					
					comando="scrobBoar.png";
		
					system(comando.c_str());
		
					cout<<"Reporte PreOrden";
					system("pause");
				}catch(std::exception& e){
						cout<<"Reporte Graficado. \n";
				}
				try{
					string comandoCerrar;	
						
					comandoCerrar="taskkill /IM Microsoft.Photos.exe /F";
		
					system(comandoCerrar.c_str());
		
					cout<<"reporte Cerrado";
					
				}catch(std::exception& e){
						cout<<"Reporte GRaficado. \n";
				}
                 Sleep(1500);
            	
				break;		
			case LETRA_H:
				salir = true;
				break;
            default:
                cout<<"\tINGRESA UNA OPCION VALIDA (-_-)!!"<<endl<<endl;
                Sleep(900);
                break;
        }
    }while(!salir);
}

void lectura(){
    ifstream archivo;
    string texto;
	string  nombreDeArchivo;
	string textoEscanear;
	
	system("cls");
	cout<<"\t\tSCRABBLE++\n\n"<<endl;
	
	cout<<"\tNOTA...el archivo debe de estar en el escritorio y debe ser de extension JSON\n"<<endl;
	
	cout<<"\tNombre de Archivo: "; cin>>nombreDeArchivo;
	cout<<"\n\t"<<endl;
	
	
    archivo.open("Entrada.JSON",ios::in); //ABRIMOS EL ARCHIVO EN MODO LECTURA

    if(archivo.fail()){
        cout<<"nose pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //MIENTRAS NO SEA EL FINAL DEL ARCHIVO
        getline(archivo,texto);
        //cout<<texto<<endl;
        textoEscanear += texto+"\n";
    }
	//cout<<"\nWILSON"<<endl;
	cout<<textoEscanear<<endl;
	optenedorDeDatosDeLectura(textoEscanear);
	//cout<<"\n\n\n\n"<<endl;


	//cout<<"->"<<getDimension()<<endl;
	//cout<<filas<<", c-> "<<columnas<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<=columnas;j++){
			//cout<<"X->"<<casillasDobles[i][j]<<endl;
		}
	}
	
	//out<<"Tripleas"<<endl;
	//cout<<filast<<", c-> "<<columnast<<endl;
	for(int i=0;i<filast;i++){
		for(int j=0;j<=columnast;j++){
			//cout<<casillasTriples[i][j]<<endl;
		}
	}

    archivo.close(); //CERRAMOS EL ARCHIVO
    //Sleep(10000);
    getch();
}

void optenedorDeDatosDeLectura(string archivo){
	
	string cadena = "";
	bool aceptar = false;
	bool dimension = false;
	bool casillas = false;
	bool doble = false;
	bool triple = false;
	bool x = false;
	bool y = false;
	bool diccio = false;
	bool palabra = false;
	int estado=0;
	char caracter;
	int mandar;
	
	for(int i = 0; i < archivo.length();i++ ){
		
		caracter= archivo[i];
		
		if(cadena=="dimension"){
			dimension = true;
			estado = 1;
			cadena ="";
		}
		else if(cadena=="casillas"){
			casillas = true;
			estado = 1;
			cadena ="";
		}
		else if(cadena=="diccionario"){
			diccio = true;
			casillas = false;
			doble = false;
			triple = false;
			estado = 1;
			cadena ="";
		}
		else if(cadena =="dobles"){
			doble = true;
			triple = false;
			estado = 1;
			cadena ="";	
		}
		else if(cadena=="triples"){
			doble = false;
			triple = true;
			estado = 1;
			cadena ="";	
		}
		else if(cadena =="x"){
			x = true;
			y= false;
			estado = 1;
			cadena ="";
		}
		else if(cadena=="y"){
			x = false;
			y= true;
			estado = 1;
			cadena ="";
			
		}
		else if(cadena =="palabra"){
			palabra = true;
			estado = 1;
			cadena ="";
		}
		//cout<<"\n"<<cadena<<endl;
		switch(estado){
			case 0:
				switch(caracter){
					case '\n':
					case '\t':
					case ' ':
					case '\r':
						estado = 0;	
						break;
					case '"':
						estado = 1;
						cadena = "";
						break;
					case ':':
						estado =2;
						cadena = "";
						break;
					default:
						estado=0;
						cadena = "";
						break; 
					
				}
				
				break;
			case 1:
				if(caracter != '\"'){
					cadena+=caracter;
					estado = 1;
				}
				else{
					estado = 0;
					cadena = "";
				}
				break;
			case 2:
				if(caracter!=','&&caracter!='\n'&&caracter!='{'&&caracter!='['&&caracter!='}'){
					
					cadena+=caracter;
					estado = 2;
				}else{
					if(dimension){
						aceptar=true;
					}
					else if(casillas&&doble&&x){
						aceptar=true;
					}
					else if(casillas&&doble&&y){
						aceptar=true;
					}
					else if(casillas&&triple&&x){
						aceptar=true;
					}
					else if(casillas&&triple&&y){
						aceptar=true;
					}
					else if(diccio&&palabra){
						aceptar=true;
					}
					
					estado = 0;
				}
				break;
			
		}
		if(dimension&&aceptar){
			stringstream geek(cadena);
			mandar;
			geek>>mandar;
			setDimension(mandar);
			dimension = false;
			aceptar = false;
			cadena = "";
		}
		else if(casillas&&doble&&x&&aceptar){
			stringstream geek(cadena);
			mandar;
			geek>>mandar;
			columnas=0;
			setCasillaDoble(mandar);
			//setCasillaDoble("x->"+cadena);
			x = false;
			aceptar= false;
			cadena = "";
		}
		else if(casillas&&doble&&y&&aceptar){
			stringstream geek(cadena);
			mandar;
			geek>>mandar;
			columnas=1;
			setCasillaDoble(mandar);
			//setCasillaDoble("y->"+cadena);
			filas++; 
			y = false;
			aceptar=false;
			cadena = "";
		}
		else if(casillas&&triple&&x&&aceptar){
			stringstream geek(cadena);
			mandar;
			geek>>mandar;
			columnast=0;
			setCasillaTriple(mandar);
			//setCasillaTriple("x->"+cadena);
			x = false;
			aceptar= false;
			cadena = "";
		}
		else if(casillas&&triple&&y&&aceptar){
			stringstream geek(cadena);
			mandar;
			geek>>mandar;
			columnast=1;
			setCasillaTriple(mandar);
			//setCasillaTriple("y->"+cadena);
			filast++; 
			y = false;
			aceptar=false;
			cadena = "";
		}
		else if(diccio&&palabra&&aceptar){
			setDiccionario(extraer(cadena));
			insertarNodo_LCDE_D(extraer(cadena));
			palabra = false;
			aceptar = false;
			cadena = "";
		}
		//cout<<"\n"<<cadena<<endl;
		
	}
	
}

string extraer(string cadena){
	string palabra ="" ;
	char caracter;
	int estado=0;
	for(int i =0; i <cadena.length();i++){
		caracter = cadena[i];
		switch(estado){
			case 0:
				switch(caracter){
				case '"':
					estado = 1;
					break;
				}
				break;
			case 1:
				if(caracter!='\"'){
					palabra += caracter;
					estado = 1;
				}
				else return palabra;
				break;
		}
	}
	return palabra;
} 

void setDimension(int _dimension){
	dimension = _dimension;
}
void setCasillaDoble(int _doble){
	casillasDobles[filas][columnas]= _doble;
}

void setCasillaTriple(int _triple){
	casillasTriples[filast][columnast]=_triple;
}

/*void setCasillaDoble(string _doble){
	casillasDobles+= _doble+" , ";
}

void setCasillaTriple(string _triple){
	casillasTriples+=_triple+" , ";
}
*/
void setDiccionario(string _palabra){
	diccionario += _palabra +" , ";
}

int getDimension(){
	return dimension;
}
/*string getCasillaDoble(){
	return casillasDobles;
}
string getCasillaTriple(){
	return casillasTriples;
}*/
string getDiccionario(){
	return diccionario;
}


//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void generadorDeLetras(int _i){
		int total = 1;	
		
		int numeroASCII ;
		
		// 1 punto
		int A = 12, E = 12;
		int O = 9;
		int I = 6, S =6;
		int N =5, R=5, U=5; 
		int L=4, T=4;
		// 2 puntos
		int D= 5; 
		int G= 2;
		// 3 puntos
		int C = 4; 
		int B= 2, M=2, P=2;
		// 4 puntos
		int H =2 ; 
		int F =1, V=1 , Y=1; 
		// 5 puntos
		int Q=1;
		// 8 puntos
		int J = 1,  X=1; //Ñ = 1,
		// 10 puntos
		int Z = 1;
		
			
		srand(_i);
		numeroASCII= 64+rand()%25;
		
		
		while(total<95){
			//numeroASCII = numeroASCII + _i;	
		//	cout<<numeroASCII<<endl;
			
		/*	if(A<0&& B<0&& C<0&& D<0&& E<0&& F<0&& G<0&& H<0&& I<0&& J<0&& K<0&& ){
				numeroASCII = numeroASCII+1;
				
			}*/
			
			if(numeroASCII==65 && A > 0){
				insertarNodoCola(1,'a');
				A--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==66&&B>0){
				insertarNodoCola(3,'b');
				B--;
				numeroASCII += 3;	
				total++;
			}
			else if(numeroASCII==67&&C>0){
				insertarNodoCola(3,'c');
				C--;
				numeroASCII += 3;	
				total++;	
			}
			else if(numeroASCII==68&&D>0){
				insertarNodoCola(2,'d');
				D--;
				numeroASCII += 2;	
				total++;
			}
			else if(numeroASCII==69&&E>0){
				insertarNodoCola(12,'e');
				E--;
				numeroASCII += 2;	
				total++;
			}
			else if(numeroASCII==70&&F>0){
				insertarNodoCola(4,'f');
				F--;
				numeroASCII += 4;	
				total++;
			}
			else if(numeroASCII==71&&G>0){
				insertarNodoCola(2,'g');
				G--;
				numeroASCII += 2;	
				total++;
			}
			else if(numeroASCII==72&&H>0){
				insertarNodoCola(4,'h');
				H--;
				numeroASCII += 4;	
				total++;
			}
			else if(numeroASCII==73&&I>0){
				insertarNodoCola(1,'i');
				I--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==74&&J>0){
				insertarNodoCola(8,'j');
				J--;
				numeroASCII += 8;	
				total++;
			}
			else if(numeroASCII==76&&L>0){
				insertarNodoCola(1,'l');
				L--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==77&&M>0){
				insertarNodoCola(3,'m');
				M--;
				numeroASCII += 3;	
				total++;
			}
			else if(numeroASCII==78&&N>0){
				insertarNodoCola(1,'n');
				N--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==79&&O>0){
				insertarNodoCola(1,'o');
				O--;
				numeroASCII += 1;	
				total++;
			}else if(numeroASCII==80&&P>0){
				insertarNodoCola(3,'p');
				P--;
				numeroASCII += 3;	
				total++;
			}
			else if(numeroASCII==81&&Q>0){
				insertarNodoCola(5,'q');
				Q--;
				numeroASCII += 5;	
				total++;
			}
			else if(numeroASCII==82&&R>0){
				insertarNodoCola(1,'r');
				R--;
				numeroASCII += 1;	
				total++;
			}else if(numeroASCII==83&&S>0){
				insertarNodoCola(1,'s');
				S--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==84&&T>0){
				insertarNodoCola(1,'t');
				T--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==85&&U>0){
				insertarNodoCola(1,'u');
				U--;
				numeroASCII += 1;	
				total++;
			}
			else if(numeroASCII==86&&V>0){
				insertarNodoCola(4,'v');
				V--;
				numeroASCII += 4;	
				total++;
			}
			else if(numeroASCII==88&&X>0){
				insertarNodoCola(8,'x');
				X--;
				numeroASCII += 8;	
				total++;
			}
			else if(numeroASCII==89&&Y>0){
				insertarNodoCola(4,'y');
				Y--;
				numeroASCII += 4;	
				total++;
			}
			else if(numeroASCII==90&&Z>0){
				insertarNodoCola(10,'z');
				Z--;
				numeroASCII -= 10;	
				total++;
			}else if(numeroASCII>90){
				numeroASCII=65;
				
			}
			else if(numeroASCII<65){
				numeroASCII = 65;
			}
			else{
				if(E>1&&E<12){
					numeroASCII = 69;
				}
				else{
					numeroASCII = numeroASCII+1;
				}	
			}	
		}
}

//---------------------------------------------------------------------
//---------------------------------------------------------------------   REPORTES
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------   REPORTES
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------   REPORTES
//---------------------------------------------------------------------
//mostrar cola
void mostrarCola(){
	string texto;
	int n = 1; 
	
	nodo_cola* aux = new nodo_cola();
	aux = primero_cola;
	
	
	if(primero_cola!=NULL){
		while(aux!=NULL){
			reporteCola(aux->letra,aux->puntos,n);
			aux = aux->siguienteC;
			n++;
			texto="";
		}
	}
	else{
		cout<<"LA lista esta vacia"<<endl;
	}
	reporteCola('s',0,0);
	
	graficar(1);

}

//Diccionario
void mostrarDiccionario(){
	nodo_LCDE_D* actual = new nodo_LCDE_D();                           //mi lista doble circular enlasada 
	nodo_LCDE_D* actual2 = new nodo_LCDE_D();
	
	actual = primero;
	actual2 = actual->siguiente;
	
	if(primero!=NULL){
		do{
			reporteDiccionario(actual->palabra,actual2->palabra, true); //aqui llamo a mi metodo para escribir en el archivo
			
			actual = actual->siguiente;
			actual2 = actual->siguiente;
			
		}while(actual!=primero);                                       //recorro la lista asta que actual llege otravez a primero

	}else{
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
	
	reporteDiccionario(actual->palabra,actual2->palabra, false);      //cuando dermine le paso false para que me coloque }\n 
	
	
	graficar(2);                                                     //llamo a gaficar
}

string t="", d="";
//ARBOL
//Funcionpara mostrar el arbol comlpeto


//REcorrido en profundidad - PreOrden
void  preOrdenArbol(NodoDeArbol *arbol){
	if(arbol==NULL){ //si el arbol esta vacio
		return;
	}
	else{
		reportepreOrden(arbol->nombre);
		preOrdenArbol(arbol->izq);
		preOrdenArbol(arbol->der);
	}
}

//REcorrido en profundidad - InOrden
void InOrdenArbol(NodoDeArbol *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		InOrdenArbol(arbol->izq);
		reporteinOrden(arbol->nombre);
		InOrdenArbol(arbol->der);
	}
}

//REcorrido en profundidad - PostOrden
void PostOrdenArbol(NodoDeArbol *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		PostOrdenArbol(arbol->izq);
		PostOrdenArbol(arbol->der);
		reportepostOrden(arbol->nombre);
	}
}



//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//MEtodo GRaficar
void graficar(int g){  //variable que indica en numero de grafica 
	system("cls");
	string comando;
	try{
		if(g==1){
			comando="dot -Tpng Cola.txt -o Cola.png";
		}
		else if(g==2){
			comando="dot -Tpng Diccionario.txt -o Diccionario.png";  //comando es la variable del commando a ejecutar en el cmd
		}
		else if(g==3){
			comando="dot -Tpng Arbol.txt -o Arbol.png";
		}
		else if(g==4){
			comando="dot -Tpng preOrden.txt -o preOrden.png";
		}
		else if(g==5){
			comando="dot -Tpng inOrden.txt -o inOrden.png";
		}
		else if(g==6){
			comando="dot -Tpng postOrden.txt -o postOrden.png";
		}
		else if(g==7){
			comando="dot -Tpng matriz.txt -o matriz.png";
		}
		else if(g==8){
			comando="dot -Tpng scrobBoar.txt -o scrobBoar.png";
		}
		system(comando.c_str());                                    //este metodo abre el cmd y ejecuta el comando que le damos
		
		cout<<"reporte GRAFICA ya esta lista";
		system("pause");
	}catch(std::exception& e){
		cout<<"Reporte GRaficado. \n";
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------


void reporteCola(char c, int i, int n){
	ofstream archivo;
	

    archivo.open("Cola.txt",ios::app);//ABRIENDO EL ARCHIVO EN MODO AÑADIEMDO
	
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
	
	if(n!=0){
		archivo<<"nodo"<<n<<"[shape=box, label=\""<<c<<"x"<<i<<"pts\"];"<<endl;
	}
	else{
		archivo<<"}"<<endl;
	}
	
    archivo.close(); //cerramos el archivo
}

void reporteDiccionario(string s,string n,bool ok){
	ofstream archivo;								//esta variable pertenece ala libreria #include <fstream>
	
	archivo.open("Diccionario.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	if(ok){
		archivo<<s<<"[shape=box, label=\""<<s<<"\"];"<<endl;  //si biene el primero seria hola[shape=box,lable="hola"]; \n y se agraga al documento
		archivo<<s<<"->"<<n<<";"<<endl;;                      //aqui seria hola->mundo;
		archivo<<n<<"->"<<s<<";"<<endl;;				      //aqui seria mundo->hola;
	}
	else{
		archivo<<"}"<<endl;                                   //de ultimo se cierra
	}
	
	archivo.close(); //se cierra el archivo
}

void reporteArbol(string s, string n,string p){
	ofstream archivo;
	
	archivo.open("Arbol.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	//if(apuntadorS==primero)
	if(s!="F"&&s!="W"){
		archivo<<p<<"[label=\""<<p<<"\"];"<<endl;
		archivo<<s<<"[label=\""<<s<<"\"];"<<endl;
		archivo<<n<<"[label=\""<<n<<"\"];"<<endl;
		archivo<<p<<"->"<<n<<";"<<endl;
		archivo<<p<<"->"<<s<<";"<<endl;
	}
	else if(s=="F"){
		archivo<<"}"<<endl;
	}
	
	
	archivo.close();
}

void reportepreOrden(string s){
	ofstream archivo;
	
	archivo.open("preOrden.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	//archivo.open("preOrden.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	//if(apuntadorS==primero)
	if(s!="F"&&s!="A"){
		archivo<<s<<"[shape=box, label=\""<<s<<"\"];"<<endl;
	}
	/*else if(s=="A"){
		archivo<<"digraph G{"<<endl;
	
	}*/
	else{
		archivo<<"}"<<endl;
	}
	
	archivo.close();
}
void reporteinOrden(string s){
	ofstream archivo;
	
	archivo.open("inOrden.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	//archivo.open("inOrden.txt",ios::out); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	//if(apuntadorS==primero)
	if(s!="F"&&s!="A"){
		archivo<<s<<"[shape=box, label=\""<<s<<"\"];"<<endl;
	}
	/*else if(s=="A"){
		archivo<<"digraph G{"<<endl;
	}*/
	else{
		archivo<<"}"<<endl;
	}
	
	archivo.close();
}
void reportepostOrden(string s){
	ofstream archivo;
	
	archivo.open("postOrden.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	//archivo.open("postOrden.txt",ios::out); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	//if(apuntadorS==primero)
	if(s!="F"&&s!="A"){
		archivo<<s<<"[shape=box, label=\""<<s<<"\"];"<<endl;
	}
	/*else if(s=="A"){
		archivo<<"digraph G{"<<endl;
	}*/
	else{
		archivo<<"}"<<endl;
	}
	
	archivo.close();
}

void reporteScrob(string texto){ //  
	ofstream archivo;
	
	//archivo.open("matriz.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	archivo.open("scrobBoar.txt",ios::out); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
		archivo<<texto<<endl;
	
	
	archivo.close();
}


void reporteMatriz(string texto){ // 
	ofstream archivo;
	
	//archivo.open("matriz.txt",ios::app); //ABRIENDO ARCHIVO EN MODO AÑADIMIENTO
	archivo.open("matriz.txt",ios::out); 
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
		archivo<<texto<<endl;
	
	
	archivo.close();
}

//Lenado de matriz
string llenarMatriz(matrizOrtogonal* matriz,nodoOrtogonal* nodo){
	string textoG;
	
	
	stringstream cadenam1;
	stringstream cadenam2;
	stringstream cadenanodConj;
	stringstream cadenarank1;
	stringstream cadenarank2;
	stringstream cadenaconecciones;
	stringstream cadena;
	
	string principal;
	string m1;
	string m2;
	string nodConj;
	string nod;
	string rank1;
	string rank2;
	string conecciones;
	string final;
		
	principal = "digraph asde91{\n ranksep=.75; size=\"9.5,9.5\";\n { \n node[shape=plaintext, fontsize=21];\n";

	m1 = "Matriz ";
	m2 = "Matriz ";
	nod = "\nnode [shape=box];\n";
	rank1 = "{rank = same; \"Matriz\";";
	conecciones = "\n";
	final = "\n }";	
		
	string arribas[50];
	string abajos[50];
	string anterior = "-";
	string actual;
				
	bool ultimX = false;
	bool ultimY = false;
	
	char letra;
	char letraDirec;

	
	//matriz->reemplazar(letter,xp,yp);
	
	int o=1;
	
	for(int i = 1;i <= getDimension(); i++ ){
		cadenarank2<<"{rank = same; y"<<i<<"; ";
		
		for(int j = 1; j<= getDimension(); j++ ){
			
			letra =indice(matriz,nodo, j,i);
			if(letra!='-'){
				cadenanodConj<<" \""<<letra<<"\"; ";
				cadenarank2<< " \""<<letra<<"\";";
				cadena.str("");			
				cadena<< "\""<<letra<<"\""; 	
				actual = cadena.str();
				
				
				if(j==getDimension())ultimX = true;
				if(i==getDimension())ultimY = true;
				if(j==1 && i==1){
					anterior = actual;
					arribas[j] = actual;
				}
				else if(j>1 && i==1 && !ultimX && !ultimY){
					letraDirec = caso1(matriz,nodo,j,i);
					if(letraDirec != '-'){
						//arribas[j]=actual;
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						anterior = actual;
					}
										
				}
				else if(j>1 && i==1 && ultimX && !ultimY ){
					letraDirec = caso1(matriz,nodo,j,i);
					if(letraDirec != '-'){
						//arribas[j]=actual;
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						anterior = actual;
					}
						ultimX = false;
				}
				else if(j==1 && i>1 && !ultimX && !ultimY)
				{
					letraDirec = caso2(matriz,nodo,j,i);
					if(letraDirec != '-')
					{
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
					}
				}
				else if(j>1 && i>1 && !ultimX && !ultimY){
					letraDirec = caso3(matriz,nodo,j,i);
					if(letraDirec != '-')
					{
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
					}
					letraDirec = caso4(matriz,nodo,j,i);
					if(letraDirec != '-')
					{
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
					}
				}
				else if(j>1 && i>1 && ultimX && !ultimY)
					{
						letraDirec = caso3(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
						letraDirec = caso4(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
					
						ultimX = false;
					}
					else if(j==1 && i>1 && !ultimX && ultimY)
					{
						letraDirec = caso2(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
						cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
						cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
					}
					else if(j>1 && i>1 && !ultimX && ultimY){
						letraDirec = caso3(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
						letraDirec = caso4(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
						ultimY = false;
					}
					else if(j>1 && i>1 && ultimX && ultimY){
						letraDirec = caso3(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
						letraDirec = caso4(matriz,nodo,j,i);
						if(letraDirec != '-')
						{
							cadenaconecciones <<actual<<"->"<<"\""<< letraDirec<<"\";\n";
							cadenaconecciones <<"\""<<letraDirec<<"\"->"<<actual<<";\n";
						}
					
						
						ultimX = false;
						ultimY = false;
					}
			}
			else{
				o++;
				//cadenarank2<< " \"^_^\";";
				cadenarank2<< " \"-"<<o<<"-\";";
			}
					if(j==getDimension()){
						cadenarank2<<"}\n";				//->>	
					}
					//k=o;	
		}
		cadenam1<<" -> y"<<i;
		cadenam2<<" -> x"<<i;
		cadenarank1<<" x"<<i<<";";
	}
	m1 += cadenam1.str()+";\n";
	m2 += cadenam2.str()+";\n";
	nodConj += cadenanodConj.str()+"}\n";
	rank1 += cadenarank1.str()+"}\n";
	rank2 += cadenarank2.str();
	conecciones += cadenaconecciones.str();
	
	textoG +=principal;
	textoG += m1;
	textoG += m2;
	textoG += nodConj;
	textoG += nod;
	textoG += rank1;
	textoG += rank2;
	textoG += conecciones;
	textoG += final;
	
	return textoG;
}

char indice(matrizOrtogonal* matriz, nodoOrtogonal* nodo, int x, int y){
	
	char letra;
	nodo = matriz->c->busqueda(x)->columna->primero;
	for(int i = 1; i<= getDimension();i++){
			if(y==i){
				break;
			}
			nodo = nodo->abajo;
	}
	return letra = nodo->dato;
}

char caso1(matrizOrtogonal* matriz, nodoOrtogonal* nodo, int x, int y){
	char letra;
	nodo = matriz->c->busqueda(x)->columna->primero;
	for(int i = x; i>= 1;i--){
			if(y==i){
				break;
			}
			nodo = nodo->izquierda;
			if(nodo->dato!='-'){
				return letra = nodo->dato;
			}
	}
	if(nodo->dato!='-'){
		return letra = nodo->dato;
	}	
	return letra = '-';
}

char caso2(matrizOrtogonal* matriz, nodoOrtogonal* nodo, int x, int y){
	char letra;
	nodo = matriz->l->busqueda(y)->fila->primero;
	
	for(int i = y; i>= 1;i--){
			if(x==i){
				break;
			}
			nodo = nodo->arriba;
			if(nodo->dato!='-'){
				return letra = nodo->dato;
			}
	}
	if(nodo->dato!='-'){
				return letra = nodo->dato;
	}
	return letra = '-';
}

char caso3(matrizOrtogonal* matriz, nodoOrtogonal* nodo, int x, int y)
{
	char letra;
	nodo = matriz->c->busqueda(x)->columna->primero->izquierda;
	/*for(int i = 1; i<(x-1);i++){
		nodo = nodo->abajo;
	}*/
	for(int i = 1; i<y;i++){
		nodo = nodo->abajo;
	}
	for(int i = (x-1); i> 1;i--){ //
			if(x==1){
				break;
			}
			if(nodo->dato!='-'){
				return letra = nodo->dato;
			}
			/*if((y-1)==i){
				break;
			}*/
			nodo = nodo->izquierda;
	}
	if(nodo->dato!='-'){
				return letra = nodo->dato;
	}
	return letra = '-';
}

char caso4(matrizOrtogonal* matriz, nodoOrtogonal* nodo, int x, int y)
{
	char letra;
	nodo = matriz->c->busqueda(x)->columna->primero;
	for(int i = 1; i<(y-1);i++){
		nodo = nodo->abajo;
	}
	for(int i = (y-1); i> 1;i--){
		if(y==1){
			break;
		}
		if(nodo->dato!='-'){
			return letra = nodo->dato;
		}
		
		nodo = nodo->arriba;
	}
	if(nodo->dato!='-'){
				return letra = nodo->dato;
			}
	return letra = '-';
}


