#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

//-----------NODO ORTOGONAL-----------------------
struct nodoOrtogonal{
	char dato;
	int x,y;
	nodoOrtogonal* arriba;
	nodoOrtogonal* abajo;
	nodoOrtogonal* izquierda;
	nodoOrtogonal* derecha;
	
	nodoOrtogonal(char dato, int x, int y){ //CONSTRUCTOR
		this->dato = dato;
		this->x = x;
		this->y = y;
		arriba=NULL;
		abajo=NULL;
		izquierda =NULL;
		derecha=NULL;
		
	}
	
};

struct listaVertical{
	nodoOrtogonal* primero;
	nodoOrtogonal* ultimo;
	
	listaVertical() //Constructor
	{
		primero = NULL;
		ultimo = NULL;
	}
	
	void insertarNodoLV(nodoOrtogonal* inserta)
	{
		if(vacio())
		{
			primero = ultimo = inserta;
		}
		else
		{
			if(inserta->y < primero->y)
			{
				insertarFrente(inserta);			
			}
			else if(inserta->y > ultimo->y)
			{
				insertarFinal(inserta);
			}
			else
			{
				insertarMedio(inserta);
			}
			
		}
	}
	
	bool vacio()
	{
		if(primero==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void insertarFrente(nodoOrtogonal* inserta)
	{
		primero->arriba = inserta;
		inserta->abajo = primero;
		primero = primero->arriba;
	}
	
	void insertarFinal(nodoOrtogonal* inserta)
	{
		ultimo->abajo = inserta;
		inserta->arriba = ultimo;
		ultimo=ultimo->abajo;
	}
	
	void insertarMedio(nodoOrtogonal* inserta)
	{
		nodoOrtogonal* temporal1;
		nodoOrtogonal* temporal2;
		temporal1= primero;
		
		while(temporal1->y < inserta->y)
		{
			temporal1= temporal1->abajo;
		}
		temporal2= temporal1->arriba;
		
		temporal2->abajo = inserta;
		temporal1->arriba = inserta;
		inserta->abajo = temporal1;
		inserta->arriba = temporal2;
		
	}
	
	void reaamplazar(nodoOrtogonal* inserta){
			bool encontrado= false;
			if(!vacio()){
			nodoOrtogonal* temporal;
			temporal = primero;
			while(temporal!=NULL&&!encontrado)
			{
				if(temporal->y == inserta->y)
				{
					//cout<<"V->"<<temporal->dato<<"->"<<inserta->dato<<"\n";
					temporal->dato = inserta->dato;
					//cout<<"V->"<<temporal->dato<<"\n";
				 	encontrado = true;
				 } 
				//cout<<"y="<<temporal->y<<endl;
				temporal = temporal->abajo;
			}
		}
	}
	
	void recorrer()
	{
		if(!vacio()){
			nodoOrtogonal* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
				cout<<"y="<<temporal->y<<endl;
				temporal = temporal->abajo;
			}
		}
		
	}
	
	
};

//Lista horizontal
struct listaHorizontal{
	nodoOrtogonal* primero;
	nodoOrtogonal* ultimo;
	
	listaHorizontal() //Constructor
	{
		primero = NULL;
		ultimo = NULL;
	}
	
	void insertarNodoLH(nodoOrtogonal* inserta)
	{
		if(vacio())
		{
			primero = ultimo = inserta;
		}
		else
		{
			if(inserta->x < primero->x)
			{
				insertarFrente(inserta);			
			}
			else if(inserta->x > ultimo->x)
			{
				insertarFinal(inserta);
			}
			else
			{
				insertarMedio(inserta);
			}
			
		}
	}
	
	bool vacio()
	{
		if(primero==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void insertarFrente(nodoOrtogonal* inserta)
	{
		primero->izquierda = inserta;
		inserta->derecha = primero;
		primero = primero->izquierda;
	}
	
	void insertarFinal(nodoOrtogonal* inserta)
	{
		ultimo->derecha = inserta;
		inserta->izquierda = ultimo;
		ultimo=ultimo->derecha;
	}
	
	void insertarMedio(nodoOrtogonal* inserta)
	{
		nodoOrtogonal* temporal1;
		nodoOrtogonal* temporal2;
		temporal1= primero;
		
		while(temporal1->x < inserta->x)
		{
			temporal1= temporal1->derecha;
		}
		temporal2= temporal1->izquierda;
		
		temporal2->derecha = inserta;
		temporal1->izquierda = inserta;
		inserta->derecha = temporal1;
		inserta->izquierda = temporal2;
		
	}
	
	void recorrer()
	{
		if(!vacio()){
			nodoOrtogonal* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
			cout<<"X="<<temporal->x<<endl;
			
				temporal = temporal->derecha;
			}
		}
		
	}
	
	void reaamplazar(nodoOrtogonal* inserta){
			bool encontrado= false;
			if(!vacio()){
			nodoOrtogonal* temporal;
			temporal = primero;
			while(temporal!=NULL&&!encontrado)
			{
				if(temporal->x == inserta->x)
				{
					//cout<<"\nF->"<<temporal->dato<<"->"<<inserta->dato<<"\n";
					inserta->dato = inserta->dato;
				 	//cout<<"\nF->"<<temporal->dato<<"\n";
					 encontrado = true;
				 } 
				//cout<<"y="<<temporal->y<<endl;
				temporal = temporal->abajo;
			}
		}
	}
		
}; 



//-----NODO CABECERA--------------
struct nodoCabecera{
	int x;
	
	nodoCabecera* siguiente;
	nodoCabecera* anterior;
	
	listaVertical* columna;
	
	nodoCabecera(int x)
	{
		this->x = x;
		columna = new listaVertical();
		siguiente=NULL;
		anterior =NULL;
	}
	
	
	
};

//---cabeceras-----
struct cabeceras
{
	nodoCabecera* primero;
	nodoCabecera* ultimo;
	
	cabeceras() //Constructor
	{
		primero = NULL;
		ultimo = NULL;
	}
	
	void insertarNodo(nodoCabecera* inserta)
	{
		if(vacio())
		{
			primero = ultimo = inserta;
		}
		else
		{
			if(inserta->x < primero->x)
			{
				insertarFrente(inserta);			
			}
			else if(inserta->x > ultimo->x)
			{
				insertarFinal(inserta);
			}
			else
			{
				insertarMedio(inserta);
			}
			
		}
	}
	
	bool vacio()
	{
		if(primero==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void insertarFrente(nodoCabecera* inserta)
	{
		primero->anterior = inserta;
		inserta->siguiente = primero;
		primero = primero->anterior;
	}
	
	void insertarFinal(nodoCabecera* inserta)
	{
		ultimo->siguiente = inserta;
		inserta->anterior = ultimo;
		ultimo=ultimo->siguiente;
	}
	
	void insertarMedio(nodoCabecera* inserta)
	{
		nodoCabecera* temporal1;
		nodoCabecera* temporal2;
		temporal1= primero;
		
		while(temporal1->x < inserta->x)
		{
			temporal1= temporal1->siguiente;
		}
		temporal2= temporal1->anterior;
	
		temporal2->siguiente = inserta;
		temporal1->anterior = inserta;
		inserta->siguiente = temporal1;
		inserta->anterior = temporal2;
		
	}
	
	void recorrer()
	{
		if(!vacio()){
			nodoCabecera* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
				//grapivph = "nodo"+temporal->x; //"nodo" + temporal->x + "[label=\"" + temporal->x + "\"];\n";
				//nodoGrapivph = "[shape=box, [label=\""+temporal->x;
				//cabeceraGrapivph += grapivph+nodoGrapivph+"\"]\n";
				cout<<"x="<<temporal->x<<endl;
				temporal = temporal->siguiente;
			}
			//return cabeceraGrapivph;
		}
	//	return cabeceraGrapivph="";
	}
	
	bool existe(int x)
	{
		if(vacio())
		{
			//cout<<"no existe lista vacia"<<endl;
			return false;
		}
		else
		{
			nodoCabecera* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
				if(temporal->x == x){
					//cout<<"existe"<<endl;
					return true;
				}
				else if(temporal->siguiente==NULL)
				{
					//cout<<"nose encontro"<<endl;
					return false;
				}
				
				temporal=temporal->siguiente;
			}	
			
		}
	}
	
	/*void reaamplazar(nodoCabecera* inserta, char letra){
			bool encontrado= false;
			if(!vacio()){
			nodoCabecera* temporal;
			temporal = primero;
			while(temporal!=NULL&&!encontrado)
			{
				if(temporal->x == x)
				{
					temporal-> = letra;
				 	encontrado = true;
				 } 
				//cout<<"y="<<temporal->y<<endl;
				temporal = temporal->abajo;
			}
		}
	}*/
	
	
	//METODO BUSCAR
	nodoCabecera* busqueda(int x)
	{
		if(existe(x))
		{
			nodoCabecera* temporal;
			temporal = primero;
			while(temporal->x!=x)
			{
				
				temporal = temporal->siguiente;
			}
			//cout<<"retornando"<<endl;
			return temporal;
			
		}
		else
		{
			//cout<<"no esiste"<<endl;
			return(new nodoCabecera(-1));
		
		}
	}
	
};


/*------------nodo lateral--------*/
struct nodoLateral{
	int y;
	
	nodoLateral* siguiente;
	nodoLateral* anterior;
	
	listaHorizontal* fila;
	
	nodoLateral(int y)
	{
		this->y = y;
		fila = new listaHorizontal();
		siguiente=NULL;
		anterior =NULL;
	}
	
	
	
};

//laterales--------
struct laterales
{
	nodoLateral* primero;
	nodoLateral* ultimo;
	

	laterales() //Constructor
	{
		primero = NULL;
		ultimo = NULL;
	}
	
	void insertarNodo(nodoLateral* inserta)
	{
		if(vacio())
		{
			primero = ultimo = inserta;
		}
		else
		{
			if(inserta->y < primero->y)
			{
				insertarFrente(inserta);			
			}
			else if(inserta->y > ultimo->y)
			{
				insertarFinal(inserta);
			}
			else
			{
				insertarMedio(inserta);
			}
			
		}
	}
	
	bool vacio()
	{
		if(primero==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void insertarFrente(nodoLateral* inserta)
	{
		primero->anterior = inserta;
		inserta->siguiente = primero;
		primero = primero->anterior;
	}
	
	void insertarFinal(nodoLateral* inserta)
	{
		ultimo->siguiente = inserta;
		inserta->anterior = ultimo;
		ultimo=ultimo->siguiente;
	}
	
	void insertarMedio(nodoLateral* inserta)
	{
		nodoLateral* temporal1;
		nodoLateral* temporal2;
		temporal1= primero;
		
		while(temporal1->y < inserta->y)
		{
			temporal1= temporal1->siguiente;
		}
		temporal2= temporal1->anterior;
		
		temporal2->siguiente = inserta;
		temporal1->anterior = inserta;
		inserta->siguiente = temporal1;
		inserta->anterior = temporal2;
		
	}
	
	void recorrer()
	{
		if(!vacio()){
			nodoLateral* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
				//grapivph = "nodo"+temporal->y; //"nodo" + temporal->x + "[label=\"" + temporal->x + "\"];\n";
				//nodoGrapivph = "[shape=box, [label=\""+temporal->y;
				//cabeceraGrapivph += grapivph+nodoGrapivph+"\"]\n";
				
				cout<<"y="<<temporal->y<<endl;
				temporal = temporal->siguiente;
			}
			//return cabeceraGrapivph;
		}
		//return cabeceraGrapivph="";
	}
	
	bool existe(int y)
	{
		if(vacio())
		{
			//cout<<"no existe lista vacia"<<endl;
			return false;
		}
		else
		{
			nodoLateral* temporal;
			temporal = primero;
			while(temporal!=NULL)
			{
				if(temporal->y == y){
					//cout<<"existe"<<endl;
					return true;
				}
				else if(temporal->siguiente==NULL)
				{
					//cout<<"nose encontro"<<endl;
					return false;
				}
				temporal=temporal->siguiente;
			}	
			
		}
	}
	
	/*void reaamplazar(nodoLateral* insertar){
			bool encontrado= false;
			if(!vacio()){
			nodoLateral* temporal;
			temporal = primero;
			while(temporal!=NULL&&!encontrado)
			{
				if(temporal->y == insertar->y)
				{
					tempora = letra;
				 	encontrado = true;
				 } 
				//cout<<"y="<<temporal->y<<endl;
				temporal = temporal->abajo;
			}
		}
	}
*/
	//METODO BUSCAR
	nodoLateral* busqueda(int y)
	{
		if(existe(y))
		{
			nodoLateral* temporal;
			temporal = primero;
			while(temporal->y!=y)
			{
				temporal = temporal->siguiente;
			}
			//cout<<"retornando"<<endl;
			return temporal;
			
		}
		else
		{
			//cout<<"no esiste"<<endl;
			return(new nodoLateral(-1));
		}
	}
	
};

//matrizortognal
struct matrizOrtogonal
{
		cabeceras* c;
		laterales* l;
		//string matrizGrapivph;
		
		
		string m1;
		string m2;
		string nodConj;
		string nod;
		string rank1;
		string rank2;
		string conecciones;
		string final;
		
		matrizOrtogonal()
		{
			c = new cabeceras();
			l = new laterales();
			m1= "Matriz ";
			m2 = "Matriz ";
			nod = "\nnode [shape=box];\n";
			rank1 = "{rank = same; \"Matriz\";";
			conecciones = "\n";
			final = "\n }";
		}
		
		void insertarNodo(int x,int y, char insertar)
		{
			nodoOrtogonal * insercion;
			insercion = new nodoOrtogonal(insertar,x,y);
			if(c->existe(x)==false)
			{
				c->insertarNodo(new nodoCabecera(x));
				
			}
			if(l->existe(y)==false)
			{
				l->insertarNodo(new nodoLateral(y));
			}
			nodoCabecera* CTemporal;
			nodoLateral* LTemporal;
			
			
			CTemporal=c->busqueda(x);
			LTemporal=l->busqueda(y);
			
			
			CTemporal->columna->insertarNodoLV(insercion);
			LTemporal->fila->insertarNodoLH(insercion);
			//cout<<"inserto "<<insertar<<"en "<<x<<" , "<<y<<endl;
			
			
		}
		
		void reemplazar(char letra, int x, int y){
			nodoOrtogonal * insercion;
			insercion = new nodoOrtogonal(letra,x,y);
			
			nodoCabecera* CTemporal;
			nodoLateral* LTemporal;
			
			CTemporal=c->busqueda(x);
			LTemporal=l->busqueda(y);
			
			CTemporal->columna->reaamplazar(insercion);
			LTemporal->fila->reaamplazar(insercion);
		}
		
		string getm1(){
			return m1;
		}
		
		string getm2(){
			return m2;
		}
		string getnodConj(){
			return nodConj;
		}
		
		string getnod(){
			return nod;
		}
		
		string getrank1(){
			return rank1;
		}
		
		string getrank2(){
			return rank2;
		}
		string getConecciones(){
			return conecciones;
		}
		string getFinal(){
			return final;
		}
		
		void llenar(int x,int y)
		{
			stringstream cadenam1;
			stringstream cadenam2;
			stringstream cadenanodConj;
			stringstream cadenarank1;
			stringstream cadenarank2;
			stringstream cadenaconecciones;
			stringstream cadena;
		
			string arribas[50];
			string abajos[50];
			string anterior;
			string actual;
			
			
			bool ultimX = false;
			bool ultimY = false;
			
			int o=1;
			char k='l';
			for(int i=1;i<=y;i++)
			{
				/*cadenarank2<<"{rank = same; y"<<i<<"; ";
				    //->>*/
				for(int j=1;j<=x;j++){
				/*	//cout<<i<<"ddd"<<j<<endl;
					
					cadenanodConj<<" \""<<o<<"\"; ";
							//->>
					cadenarank2<< " \""<<o<<"\";"; 	
					cadena.str("");			//->>
					cadena<< "\""<<o<<"\""; 	
					actual = cadena.str();           //->>
					
					if(j==x)ultimX = true;
					if(i==y)ultimY = true;
					if(j==1 && i==1){
						anterior = actual;
						arribas[j]=actual;
					}
					else if(j>1 && i==1 && !ultimX && !ultimY){
						arribas[j]=actual;
						cadenaconecciones <<actual<<"->"<<anterior<<";\n";
						//conecciones += cadena.str(); //->>
						cadenaconecciones << anterior<<"->"<<actual<<";\n";
						//conecciones += cadena.str(); //->>
						anterior = actual;
					}
					else if(j>1 && i==1 && ultimX && !ultimY ){
						arribas[j]=actual;
					
						cadenaconecciones << actual<<"->"<<anterior<<";\n";
						//conecciones += cadena.str(); //->>
						cadenaconecciones << anterior<<"->"<<actual<<";\n";
						//conecciones += cadena.str(); //->>
						ultimX = false;
					}
					else if(j==1 && i>1 && !ultimX && !ultimY) {
						anterior = actual;
						cadenaconecciones << actual<<"->"<<arribas[j]<<";\n";
						//conecciones +=  cadena.str();//->>
						cadenaconecciones <<  arribas[j]<<"->"<<actual<<";\n";
						//conecciones += cadena.str();//->>
						arribas[j]=actual;
					}
					else if(j>1 && i>1 && !ultimX){
						cadenaconecciones << actual<<"->"<<arribas[j]<<";\n";
						//conecciones +=  cadena.str();//->>
						cadenaconecciones << arribas[j]+"->"+actual+";\n";
						//conecciones +=  cadena.str();//->>
						cadenaconecciones << actual<<"->"<<anterior<<";\n";
						//conecciones += cadena.str(); //->>
						cadenaconecciones << anterior<<"->"<<actual<<";\n"; 
						//conecciones += cadena.str();//->>
						anterior = actual;
						arribas[j]=actual;
					}
					else if(j>1 && i>1 && ultimX && !ultimY)
					{
						cadenaconecciones <<actual<<"->"<<arribas[j]<<";\n"; 
						//conecciones += cadena.str(); //->>
						cadenaconecciones << arribas[j]<<"->"<<actual<<";\n";
						//conecciones += cadena.str(); //->>
						cadenaconecciones <<  actual<<"->"<<anterior<<";\n";
						//conecciones += cadena.str(); //->>
						cadenaconecciones << anterior<<"->"<<actual<<";\n";
						//conecciones += cadena.str();//->>
						arribas[j]=actual;
						ultimX = false;
					}
					else if(j==1 && i>1 && !ultimX && ultimY)
					{
						anterior = actual;
						cadenaconecciones << actual<<"->"<<arribas[j]<<";\n";
						//conecciones+= cadena.str();//->>
						cadenaconecciones << arribas[j]<<"->"<<actual<<";\n";
						//conecciones += cadena.str();//->>
						//arribas[i]=actual;
						ultimY = false;
					}
					else if(j>1 && i>1 && ultimX && ultimY){
						cadenaconecciones << actual<<"->"<<arribas[j]<<";\n"; 
						//conecciones += cadena.str();//->>
						cadenaconecciones << arribas[j]<<"->"<<actual<<";\n";
						
						cadenaconecciones << actual<<"->"<<anterior<<";\n"; 
						//conecciones += cadena.str();//->>
						cadenaconecciones << anterior<<"->"<<actual<<";\n";
						//conecciones += cadena.str(); //->>
						//arribas[i]=actual;
						ultimX = false;
						ultimY = false;
					}
					**/
					insertarNodo(j,i,'-');
					/*
					if(j==x){
						cadenarank2<<"}\n";				//->>	
					}
					k=o;*/	
					o++;
					
					
				}
				/*	cadenam1<<" -> y"<<i;
					//m1+=cadenam1.str(); 
					cadenam2<<" -> x"<<i;
					//m2+= cadenam2.str();  //->>
					cadenarank1<< " x"<<i<<";";
					        //->> */
			}
			
			/*m1+=cadenam1.str()+";\n"; 
			m2+=cadenam2.str()+";\n";                   //->>
			nodConj += cadenanodConj.str()+"}\n";	
			rank1 += cadenarank1.str()+"}\n";
			rank2 += cadenarank2.str();
			conecciones += cadenaconecciones.str();//->>*/
		}
		
};
