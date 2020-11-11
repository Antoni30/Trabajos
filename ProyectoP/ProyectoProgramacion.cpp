/*
UNIVERSIDAD DE LAS FUERZA ARMADAS ESPE
NOMBRES:
NRC:
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include "FuncionesPrograma.h"
#include "ManejoArchivos.h"
#include "Validacion.h"
using namespace std;
string user="admin";
int main()
{
    CuentaCliente cc[numItemsArchivoU()];
    llenarArregloUsuarios(cc,numItemsArchivoU());
    Producto p[numItemsArchivoP()];
    Producto pCompra[50];
    string nombreProducto,usuario,clave,nombre,apellido,cedula,telefono;
    bool pregunta=true;
    float precio;
    char tecla;
    int cantidad=0,aux=numItemsArchivoP(),cantidadA,auxC;
    int id,opcF,opc2,opcM;
    margen();
    switch( menuPrincipal())
    {
        case 1:
            system("cls");
            margen();
            switch(menuPrograma()){
                case 1:
                    system("cls");

                        while(pregunta)
                        {
                            margenProducto();
                            llenarArregloProductos(p,numItemsArchivoP());
                            mostrarProductos(p,numItemsArchivoP());
                            margenCompra();
                            gotoxy(80,1);
                            cout<<"COMPRAR"<<endl;
                            gotoxy(66,2);
                            cout<<"Ingrese ID para comprar"<<endl;
                            gotoxy(66,3);
                            id=ingresarInt(&tecla);
                            if(id>numItemsArchivoP())
                            {
                                gotoxy(66,4);
                                cout<<"Id Fuera del Rango"<<endl;
                                system("pause>nul");
                                system("cls");
                            }
                            else{
                                gotoxy(66,4);
                                cout<<"Ingrese la cantidad a comprar"<<endl;
                                gotoxy(66,5);
                                cantidad=ingresarInt(&tecla);
                                if(cantidad>p[id].cantidad){
                                    gotoxy(66,6);
                                    cout<<"No existe la cantidad deseada"<<endl;
                                    system("pause>nul");
                                    system("cls");
                                }
                                else{
                                    p[id].cantidad=p[id].cantidad-cantidad;
                                    remove("Productos.csv");
                                    for(int j=0;j<aux;j++){
                                        nombreProducto=p[j].nombreProducto;
                                        precio=p[j].precio;
                                        cantidadA=p[j].cantidad;
                                        escribirArchivoProducto(j,nombreProducto,cantidadA,precio);
                                    }
                                    guardarProductosComprados(p[id],cantidad);
                                    gotoxy(66,6);
                                    cout<<"0:Facturar    1:Seguir Comprando"<<endl;
                                    gotoxy(66,7);
                                    opcF=ingresarInt(&tecla);
                                    if(opcF==0){
                                        llenarArregloProductosComprados(pCompra,numItemsArchivoPC());
                                        gotoxy(66,8);
                                        cout<<"1:Factura Cliente Registrado"<<endl;
                                        gotoxy(66,9);
                                        cout<<"2:Factura Consumidor final"<<endl;
                                        gotoxy(66,10);
                                        opc2=ingresarInt(&tecla);
                                        switch(opc2)
                                        {
                                            case 1:
                                                    gotoxy(66,11);
                                                    cout<<"Ingrese Id"<<endl;
                                                    gotoxy(66,12);
                                                    id=ingresarInt(&tecla);
                                                    if(id<numItemsArchivoU()){
                                                        facturar(pCompra,numItemsArchivoPC(),cc[id]);
                                                        system("txt2pdf.exe Factura.csv Factura.pdf -oao -pfs60 -pps43 -ptc0 -width3500 -height5000");
                                                    }
                                                    else{
                                                        gotoxy(66,13);
                                                        cout<<"Id no encontrado"<<endl;
                                                        remove("Factura.csv");
                                                    }
                                                    break;
                                            case 2:
                                                    facturarC(pCompra,numItemsArchivoPC());
                                                    system("txt2pdf.exe Factura.csv Factura.pdf -oao -pfs60 -pps43 -ptc0 -width3500 -height5000");
                                                    break;
                                            default:
                                                gotoxy(66,11);
                                                cout<<"Opcion no encontrada"<<endl;
                                        }
                                        llenarArregloProductosComprados(pCompra,numItemsArchivoPC());
                                        pregunta=false;
                                        remove("ProductosComprados.csv");
                                        system("pause>nul");
                                    }
                                }
                                system("cls");
                            }
                        }
                        break;
                case 2:
                        ingresoUsuarioMaestro(&usuario);
                        gotoxy(2,22);
                        cout<<"Ingresar Contrasenia"<<endl;
                        gotoxy(2,23);
                        clave=contrasenia();
                        margen();
                        if(usuario==user && igualesContrasenia(clave)==1)
                        {
                            system("cls");
                            margen();
                            gotoxy(2,1);
                            ingreso(&nombreProducto,&precio,&cantidad);
                            escribirArchivoProducto(numItemsArchivoP(),nombreProducto,cantidad,precio);
                        }
                        else{
                            gotoxy(2,24);
                            cout<<"Usuario o contrasenia incorrectos"<<endl;
                        }
                        break;
                case 3:
                        ingresoUsuarioMaestro(&usuario);
                        gotoxy(2,22);
                        cout<<"Ingresar Contrasenia"<<endl;
                        gotoxy(2,23);
                        clave=contrasenia();
                        margen();
                        if(usuario==user && igualesContrasenia(clave)==1)
                        {
                            llenarArregloProductos(p,numItemsArchivoP());
                            system("cls");
                            margen();
                            gotoxy(2,1);
                            cout<<"Ingrese ID del producto a modificar"<<endl;
                            gotoxy(2,2);
                            opcM=ingresarInt(&tecla);
                            if(opcM<=numItemsArchivoP()){
                                    gotoxy(2,3);
                                    cout<<"El producto elegido es: "<<p[opcM].nombreProducto<<endl;
                                    gotoxy(2,4);
                                    cout<<"¿Que Desea modificar?"<<endl;
                                    gotoxy(2,5);
                                    cout<<"1.-Nombre"<<endl;
                                    gotoxy(2,6);
                                    cout<<"2.-Precio"<<endl;
                                    gotoxy(2,7);
                                    cout<<"3.-Cantidad de producto exixtente"<<endl;
                                    gotoxy(2,8);
                                    switch(ingresarInt(&tecla)){
                                    case 1:
                                        gotoxy(2,9);
                                        cout<<"Ingrese nuevo nombre"<<endl;
                                        gotoxy(2,10);
                                        getline(cin,nombreProducto,'\n');
                                        p[opcM].nombreProducto=nombreProducto;
                                        remove("Productos.csv");
                                        break;
                                    case 2:
                                        gotoxy(2,9);
                                        cout<<"Ingrese nuevo Precio"<<endl;
                                        gotoxy(2,10);
                                        cin>>precio;
                                        p[opcM].precio=precio;
                                        remove("Productos.csv");
                                        break;
                                    case 3:
                                        gotoxy(2,9);
                                        cout<<"Ingrese nueva cantidad de producto, recuerde posee"<<p[opcM].cantidad<<"uds"<<endl;
                                        gotoxy(2,10);
                                        auxC=ingresarInt(&tecla);
                                        p[opcM].cantidad=p[opcM].cantidad+auxC;
                                        remove("Productos.csv");
                                        break;
                                    default:
                                        remove("Productos.csv");
                                        gotoxy(2,9);
                                        cout<<"Opcion no encontrada"<<endl;
                                    }
                                for(int j=0;j<aux;j++){
                                    nombreProducto=p[j].nombreProducto;
                                    precio=p[j].precio;
                                    cantidad=p[j].cantidad;
                                    escribirArchivoProducto(j,nombreProducto,cantidad,precio);
                                }
                            }
                        }
                        else{
                            gotoxy(2,24);
                            cout<<"Usuario o contrasenia incorrectos"<<endl;
                        }
                        break;
                case 4:
                        ingresoUsuarioMaestro(&usuario);
                        gotoxy(2,22);
                        cout<<"Ingresar Contrasenia"<<endl;
                        gotoxy(2,23);
                        clave=contrasenia();
                        margen();
                        if(usuario==user && igualesContrasenia(clave)==1)
                        {
                            system("cls");
                            margen();
                            gotoxy(2,1);
                            cout<<"Ingrese Nombre"<<endl;
                            fflush(stdin);
                            gotoxy(2,2);
                            getline(cin,nombre,'\n');
                            fflush(stdin);
                            gotoxy(2,3);
                            cout<<"Ingrese Apellido"<<endl;
                            fflush(stdin);
                            gotoxy(2,4);
                            getline(cin,apellido,'\n');
                            fflush(stdin);
                            gotoxy(2,5);
                            cout<<"Ingrese Telefono"<<endl;
                            fflush(stdin);
                            gotoxy(2,6);
                            getline(cin,telefono,'\n');
                            fflush(stdin);
                            gotoxy(2,7);
                            cout<<"Ingrese Cedula"<<endl;
                            fflush(stdin);
                            gotoxy(2,8);
                            getline(cin,cedula,'\n');
                            escribirArchivoUsuario(numItemsArchivoU(),nombre,apellido,cedula,telefono);
                            gotoxy(2,9);
                            cout<<"USUARIO CREADO CON EXITO"<<endl;
                            system("pause>nul");
                        }
                        else{
                            gotoxy(2,24);
                            cout<<"Usuario o contrasenia incorrectos"<<endl;
                        }
                        break;
                case 5:
                    system("cls");
                    margen();
                    mostrarUsuarios(cc,numItemsArchivoU());
                    system("pause>Nul");
                        break;
                case 6:
                        break;
                default:
                      cout<<"Opcion Incorrecta"<<endl;
                      cout<<"Recuerde opciones entre 1 y 6"<<endl;
            }
            break;
        case 2:cout<<"Integrantes:"<<endl;
            cout<<"Nombre1 \nNombre2 \nNombre3"<<endl;
            system("pause>Nul");
            break;
        case 3:system("cls");
            cout<<"Gracias por usar nuestro programa"<<endl;
            break;
        default:
            cout<<"Opcion no encontrada"<<endl;
            cout<<"Recuerde opciones entre 1 y 3"<<endl;
    }
    system("cls");
    margen();
    gotoxy(1,1);
    cout<<"Gracias por usar nuestro programa"<<endl;
    gotoxy(1,2);
    system("pause>nul");
    return 0;
}
