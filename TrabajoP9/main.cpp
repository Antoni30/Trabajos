#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include "funciones.h"
using namespace std;
int main(){
    int opc;
    Tarjeta miTarjeta;
    miTarjeta.cupo=1000;
    int posMovimiento=0;
    do{
        system("cls");
        opc=menu();
        double consumo,pago;
        switch(opc)
        {
        case 1:
            system("cls");
                cout<<"Ingrese cuanto Quiere consumir"<<endl;
                cin>>consumo;
                miTarjeta.tipoMovimento=0;
                if(miTarjeta.cupo>0)
                {
                    miTarjeta.saldo=miTarjeta.cupo;
                    miTarjeta.monto=consumo;
                    miTarjeta.cupo=miTarjeta.saldo-consumo;
                    movimiento[posMovimiento]=miTarjeta;
                    posMovimiento++;
                }
                    else{
                        cout<<"Saldo Insuficiente"<<endl;
                        system("pause");
                    }
                miTarjeta.tipoMovimento=0;
            break;


        case 2:
            system("cls");
                cout<<"Ingrese cuanto Quiere Pagar"<<endl;
                cin>>pago;
                if(miTarjeta.cupo+pago<1000)
                {
                    miTarjeta.tipoMovimento=1;
                    miTarjeta.saldo=miTarjeta.cupo;
                    miTarjeta.monto=pago;
                    miTarjeta.cupo=miTarjeta.saldo+pago;
                    movimiento[posMovimiento]=miTarjeta;
                    movimiento[posMovimiento]=miTarjeta;
                    posMovimiento++;
                }
                else{
                    cout<<"El pago exede el cupo disponible"<<endl;
                    system("pause");
                }

            break;
        case 3:
            system("cls");
                cout<<"Tabla de Movimientos"<<endl;
                cout<<"No.Movimientos\tTipo de Movimiento\tMonto\tSaldo"<<endl;
                cout<<"0\t0\t1000\t1000"<<endl;
                for(int i=0;i<posMovimiento;i++){

                    cout<<i+1<<"\t"<<movimiento[i].tipoMovimento<<"\t"<<movimiento[i].monto<<"\t"<<movimiento[i].cupo<<endl;
                }
                system("pause");
            break;
        case 0:
            break;
        default:
            cout<<"Opcion incorrecta"<<endl;
            break;
        }
    }while(opc!=0);
    system("pause");
    return 0;
}
