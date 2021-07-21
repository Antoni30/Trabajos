#ifndef LISTATEMPLATES_H_INCLUDED
#define LISTATEMPLATES_H_INCLUDED
#include "NodoTemplates.h"
#include <iostream>
#include<cmath>
#include<vector>
#include <cstring>
using namespace std;
template<class TipoClase,class TipoClase2>
class Lista{
	public:
	   void addFinal(TipoClase dato);
	   void mostrarLista();
	   TipoClase getDato(int i);
	   void setDato(int pos,TipoClase newDato);
	   int length();
	   void Binaria(TipoClase);
       void Burbuja();
       void Radix();
	private:
	    Nodo<TipoClase>*lista = NULL;
};
template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2>::addFinal(TipoClase dato)
{
   	Nodo<TipoClase> *nuevo_nodo = new Nodo<TipoClase>();
   	nuevo_nodo->setDato(dato);
   	Nodo<TipoClase> *aux1=lista;
   	Nodo<TipoClase> *aux2;
   	while(aux1!=NULL)
   	{
       aux2=aux1;
       aux1=aux1->getSiguiente();
   	}
   	if(lista == aux1)
   	{
       	lista = nuevo_nodo;
   	}
   	else{
    	aux2->setSiguiente(nuevo_nodo);
   }
   nuevo_nodo->setSiguiente(aux1);
}
template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2>::mostrarLista()
{
   	Nodo<TipoClase> *actual = new Nodo<TipoClase>();
   	int i = 1;
   	actual = lista;
   	while(actual != NULL)
   	{
       cout<<actual->getDato()<<endl;
       actual=actual->getSiguiente();
       i++;
   	}
   	delete actual;
}
template<class TipoClase,class TipoClase2>
int Lista<TipoClase,TipoClase2>::length(){
	Nodo<TipoClase> *aux1;
	int i = 0;
	aux1 = lista;
	while(aux1 != NULL){
		aux1 = aux1->getSiguiente();
		i++;
	}
	return i;
}
template<class TipoClase,class TipoClase2>
TipoClase Lista<TipoClase,TipoClase2>::getDato(int i){
    TipoClase dato;
    dato=TipoClase();
    int position=0;
    Nodo<TipoClase> *aux ;
    Nodo<TipoClase> *datoL;
    aux=lista;
    if(i<=length()&& i>0)
    {
        while((aux!=NULL)&& (position!=i))
        {
            datoL=aux;
            aux=aux->getSiguiente();
            position++;
        }
        dato=datoL->getDato();
        return dato;
    }
    else{
        cout<<"Dato no encontrado"<<endl;
        return dato;
    }
}
template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2>::setDato(int pos,TipoClase newDato){
    int position=0;
    Nodo<TipoClase> *aux ;
    Nodo<TipoClase> *datoL;
    aux=lista;
    if(pos<=length()&& pos>0)
    {
        while((aux!=NULL)&& (position!=pos))
        {
            datoL=aux;
            aux=aux->getSiguiente();
            position++;
        }
        datoL->setDato(newDato);
    }
    else{
        cout<<"Dato no encontrado"<<endl;
    }
}
 template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2>::Burbuja(){
    TipoClase aux1;
    for(int i=1;i<=length();i++){
    	for(int j=1;j<=length()-1;j++){
    		if(getDato(j)<=getDato(j+1)){
    			aux1= getDato(j);
    			setDato(j,getDato(j+1));
    			setDato(j+1,aux1);
			}
		}
	}
}
template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2>::Radix(){
    vector< vector <TipoClase> > Vec;
    Vec.resize(100);
    int temp,m=1;
    for(int i=0;i<98;i++){
        for(int j=0;j<length();j++){
            temp=(int)(getDato(j+1)/pow(10,i))%10;
            Vec[temp].push_back(getDato(j+1));
        }
        for(int k=0;k<100;k++){
            for(int l=0;l<Vec[k].size();l++){
                setDato(m,Vec[k][l]);
                m++;
            }
            Vec[k].clear();
        }
        m=1;
    }
}
template<class TipoClase,class TipoClase2>
void Lista<TipoClase,TipoClase2> :: Binaria(TipoClase palabra){
	int centro, izquierda, derecha;
	/*bool ban = false;
	izquierda = 1;
	derecha = length();
	string cadenaA,cadenaB;
	TipoClase cadena1,cadena2;
	cadena1=nombre;
	cadenaA=nombre;
	while(izquierda <= derecha && ban == false){
		centro = (izquierda + derecha)/2;
		cadena2=getDato(centro);
		cadenaB=cadena2;
		if(strcmp(cadenaA.c_str(),cadenaB.c_str())==0){
			ban = true;
            if(ban == true){
		cout << "\n\tLa persona buscada es: " << endl;
		cout << "\n\tLetra: " << getDato(centro)<<endl;
        }
		}else if(strcmp(cadenaB.c_str(),cadenaA.c_str())<0){
			izquierda = centro + 1;
		}else{
			derecha = centro - 1;
		}
	}	if(ban== false){
		cout << "\n\tInformacion no encontrada en la lista de letras." << endl;
	}*/
	izquierda = 0;
	derecha= length();
	centro= (izquierda+derecha)/2;
	while(izquierda<=derecha){
        if(getDato(centro) < palabra){
            izquierda=centro+1;
        }
        else if(getDato(centro)== palabra){
            cout<<" Se encontro la posicion ";
            cout<<centro<<endl;
            break;
        }
        else{
            derecha=centro-1;
        }
        centro=(izquierda+derecha)/2;
	}
	if(izquierda>derecha){
        cout<<palabra<<" no se encontro"<<endl;;
	}
}
#endif // LISTATEMPLATES_H_INCLUDED
