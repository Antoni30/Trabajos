#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include<iostream>
using namespace std;
struct Tarjeta{
    double cupo;
    int tipoMovimento;
    double monto;
    double saldo;
}movimiento[20];
int menu(){
    int opc;
    cout<<"1.-Consumo"<<endl;
    cout<<"2.-Pago de Cuota"<<endl;
    cout<<"3.-Imprimir todos los movimientos"<<endl;
    cout<<"0.-Salir"<<endl;
    cin>>opc;
    return opc;
}


#endif // FUNCIONES_H_INCLUDED
