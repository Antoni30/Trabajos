#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "ListaTemplates.h"
#include "menu.h"

using namespace std;
int main()
{
    srand(time(NULL));
    Lista<char,string> lista;
    int opc;
    int num;
    char letra,lb;
    do{
        system("cls");
        opc=menu();
        switch(opc)
        {
        case 1:
            system("cls");
            for(int i=0;i<100;i++)
            {
                letra=(char) 33 + rand () % (127 - 33);
                lista.addFinal(letra);
            }
            cout<<"Lista Creada"<<endl;
            lista.mostrarLista();
            system("pause");
            break;
        case 2:
            lista.Burbuja();
            lista.mostrarLista();
            cout<<"Lista ordenada"<<endl;
            system("pause");
            break;
        case 3:
            lista.Radix();
            lista.mostrarLista();
            cout<<"Lista ordenada"<<endl;
            system("pause");
            break;
        case 4:
            cout<<"Ingrese Letra a buscar"<<endl;
            cin>>lb;
            lista.Binaria(lb);

            system("pause");
            break;
        case 0:
            break;
        default:
            cout<<"Opc Incorrencta"<<endl;
        }
    }while(opc!=0);
    return 0;
}
