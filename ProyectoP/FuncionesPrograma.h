#ifndef FUNCIONESPROGRAMA_H_INCLUDED
#define FUNCIONESPROGRAMA_H_INCLUDED
#include<iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
string contra= "adminadmin2020";
void gotoxy(int x,int y)//Manejo de la  pantalla
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 string pasarMayusculas(string palabra)//trasforma toda las palabras en Mayusculas
 {
    string aux,aux2;
   for(int i=0;i<palabra.length();i++)
   {
       aux=toupper(palabra.at(i));
       aux2=aux2+aux;
   }
   return aux2;
}
 string contrasenia()//ingreso por teclado letras y las combierte en '*' y devuelve un string
{
    char tecla;
    string strContrasenia;
    int i=0;
    do{
        tecla=getch();
        if(i>0 && tecla == 8)
        {
            cout<<"\b \b";
            strContrasenia.at(--i)='\0';
        }
        else{
            cout<<"*";
            strContrasenia=strContrasenia+tecla;
            i++;
        }
    }while(tecla!=13);
    return strContrasenia;
}
void margen()//margen que se coloca en la mayoria del programa
{
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i==0||j==0||j==99||i==29)
            {
                gotoxy(j,i);
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
void margenProducto()//margen diseñado solo para mostrar los productos
{
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i==0||j==0||j==99||i==49)
            {
                gotoxy(j,i);
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
void margenCompra()//margen colocado en la esquina superior para realizar la compra
{
    for(int i=0;i<15;i++){
        gotoxy(65,i);
        cout<<"*";
    }
    for(int j=65;j<100;j++){
        gotoxy(j,14);
        cout<<"*";
    }
}
int menuPrincipal()//muerta mi menu de inicio
{
    int opc;
    gotoxy(35,1);
    cout<<"UNIVERSIDAD DE LAS FUERZA ARMADAS ESPE"<<endl;
    gotoxy(43,28);
    cout<<"2020-2020"<<endl;
    gotoxy(20,5);
    cout<<"1.-Menu Principal"<<endl;
    gotoxy(20,7);
    cout<<"2.-Nombre de Integrantes"<<endl;
    gotoxy(20,9);
    cout<<"3.-Salir del Programa"<<endl;
    gotoxy(20,11);
    cout<<"Ingresar Opcion:";
    cin>>opc;
    return opc;
}
int menuPrograma()//menu que posee las opciones de nuestro programa
{
    int opc;
    gotoxy(35,1);
    cout<<"Menu"<<endl;
    gotoxy(20,5);
    cout<<"1.-Venta de productos a Usuarios"<<endl;
     gotoxy(20,7);
    cout<<"2.-Aniadir Productos"<<endl;
     gotoxy(20,9);
    cout<<"3.-Modificar Producto"<<endl;
     gotoxy(20,11);
    cout<<"4.-Aniadir Usuario"<<endl;
     gotoxy(20,13);
    cout<<"5.-Visualisar Usuarios Registrados en el sistema"<<endl;
     gotoxy(20,15);
    cout<<"6.-Salir"<<endl;
     gotoxy(20,17);
    cout<<"Ingrese opcion: ";
    cin>>opc;
    return opc;
}
int numItemsArchivoU()//devuelve el numero de usuarios registrados en el archivo
{
    int lin=0;
    ifstream archivo;
    archivo.open("DatosUsuario.csv",ios::in);
    if(archivo.fail())
    {
        cout<<"ERROR: No existe el Archivo o no se puede leer"<<endl;
    }
    else{
        while(archivo.good())
        {
            if(archivo.get()=='\n')
            {
                lin++;
            }
        }
    }
    archivo.close();
    return lin;
}
int numItemsArchivoP()//devuelve el numero de productos guardados en el archivo
{
    int lin=0;
    ifstream archivo;
    archivo.open("Productos.csv",ios::in);
    if(archivo.fail())
    {
        cout<<"ERROR: No existe el Archivo o no se puede leer"<<endl;
    }
    else{
        while(archivo.good())
        {
            if(archivo.get()=='\n')
            {
                lin++;
            }
        }
    }
    archivo.close();
    return lin;
}
int numItemsArchivoPC()//devuelve el numero de productos comprados
{
    int lin=0;
    ifstream archivo;
    archivo.open("ProductosComprados.csv",ios::in);
    if(archivo.fail())
    {
        cout<<"ERROR: No existe el Archivo o no se puede leer"<<endl;
    }
    else{
        while(archivo.good())
        {
            if(archivo.get()=='\n')
            {
                lin++;
            }
        }
    }
    archivo.close();
    return lin;
}
void ingreso(string *nombreProducto,float *precio, int *cantidad)//menu para pedir datos producto
{
    cout<<"Ingrese Nombre del Producto"<<endl;
    fflush(stdin);
    gotoxy(2,2);
    getline(cin,*nombreProducto,'\n');
    fflush(stdin);
    gotoxy(2,3);
    cout<<"Ingrese Precio"<<endl;
    gotoxy(2,4);
    cin>>*precio;
    gotoxy(2,5);
    cout<<"Ingrese Cantidad de producto"<<endl;
    gotoxy(2,6);
    cin>>*cantidad;
}
void ingresoUsuarioMaestro(string *usuario)//Ingreso de Usuario maestro para realizar las modificaciones necesarias
{
    gotoxy(2,20);
    cout<<"Ingresar Usuario maestro para Realizar Cambios a la base de datos"<<endl;
    fflush(stdin);
    gotoxy(2,21);
    getline(cin,*usuario,'\n');
}
bool igualesContrasenia(string clave)//comprueba si el si la contraseña es correcta o no;
{
    int j=0;
    if(contra.length()==clave.length()-1)
    {
        for(int i=0;i<contra.length();i++)
        {
            if(clave.at(i)==contra.at(i))
            {
                j++;
            }
        }
    }
    if(j==contra.length()){
        return true;
    }
    else{
        return false;
    }
}
#endif // FUNCIONESPROGRAMA_H_INCLUDED
