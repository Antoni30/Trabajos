#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu(){
    int opc;
    cout<<"1.-Generar Lista"<<endl;
    cout<<"2.-Ordenar Decrecinte"<<endl;
    cout<<"3.-Ordenar Creciente"<<endl;
    cout<<"4.-Busqueda"<<endl;
    cout<<"0.-Salir"<<endl;
    cin>>opc;
    return opc;
}

#endif // MENU_H_INCLUDED
