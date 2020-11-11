#ifndef MANEJOARCHIVOS_H_INCLUDED
#define MANEJOARCHIVOS_H_INCLUDED
#include "FuncionesPrograma.h"
struct CuentaCliente{
    int numCuenta;
    string nombre;
    string apellido;
    string ci_ruc;
    string telefono;
};
struct Producto
{
    string codigoIdentificador;
    string nombreProducto;
    int cantidad;
    float precio;
};
void escribirArchivoUsuario(int numCuenta, string nombre, string apellido, string ci_ruc, string telefono)//permite llevar el archivo de usuarios
{
    ofstream archivo;
    archivo.open("DatosUsuario.csv",ios::out|ios::app);
    if(archivo.fail())
    {
        cout<<"El Archivo no existente o no se pudo crear"<<endl;
    }
    else{
        archivo<<numCuenta<<";"<<nombre<<";"<<apellido<<";"<<ci_ruc<<";"<<telefono<<endl;
    }
    archivo.close();
}
void escribirArchivoProducto(int codigoIdentificador, string nombreProducto,int cantidad , float precio)//permite llevar el archivo de productos
{
    ofstream archivo;
    archivo.open("Productos.csv",ios::out | ios::app);
    if(archivo.fail())
    {
        cout<<"El Archivo no existente o no se pudo crear"<<endl;
    }
    else{
        archivo<<codigoIdentificador<<";"<<pasarMayusculas(nombreProducto)<<";"<<cantidad<<";"<<precio<<endl;
    }
    archivo.close();
}
void llenarArregloProductos(Producto producto[],int tam)//llena un arreglo que nos servira para realizar las operacacion que realizaremos en un futuro
{
    ifstream archivo;
    string aux,aux2;
    archivo.open("Productos.csv",ios::in);
    if(archivo.fail()){
        cout<<"Archivo no encontrado"<<endl;
    }
    else{
        for(int i=0;i<tam;i++){
            getline(archivo,producto[i].codigoIdentificador,';');
            getline(archivo,producto[i].nombreProducto,';');
            getline(archivo,aux2,';');
            getline(archivo,aux,'\n');
            producto[i].precio=atof(aux.c_str());
            producto[i].cantidad=atoi(aux2.c_str());
        }
    }
    archivo.close();
}
void llenarArregloUsuarios(CuentaCliente cuentasClientes[], int tam)//llena un arreglo que nos servira para realizar las operacacion que realizaremos en un futuro
{
    ifstream archivo;
    string aux;
    archivo.open("DatosUsuario.csv",ios::in);
    if(archivo.fail()){
        cout<<"Archivo no encontrado"<<endl;
    }
    else{
        for(int i=0;i<tam;i++){
            getline(archivo,aux,';');
            getline(archivo,cuentasClientes[i].nombre,';');
            getline(archivo,cuentasClientes[i].apellido,';');
            getline(archivo,cuentasClientes[i].ci_ruc,';');
            getline(archivo,cuentasClientes[i].telefono,'\n');
            cuentasClientes[i].numCuenta=atoi(aux.c_str());
        }
    }
}
void mostrarUsuarios(CuentaCliente cuentasClientes[], int tam)//muestre por pantalla los datos
{
    int aux=3;
    gotoxy(2,1);
    cout<<"ID    Nombre         Apellido           CI/RUC         Telefono"<<endl;
    for(int i=0;i<tam;i++)
    {
        gotoxy(2,aux);
        cout<<cuentasClientes[i].numCuenta<<"    \t"<<cuentasClientes[i].nombre<<"     \t"<<cuentasClientes[i].apellido<<"    \t"<<cuentasClientes[i].ci_ruc<<"    \t"<<cuentasClientes[i].telefono<<endl;
        aux++;
    }
}
void mostrarProductos(Producto productos[],int tam)//muestre por pantalla los datos
{
    int aux=3;
    gotoxy(2,1);
    cout<<"ID       Nombre Producto            Cantida         Precio"<<endl;
    for(int i=0;i<tam;i++){
        gotoxy(2,aux);
        cout<<productos[i].codigoIdentificador<<"\t"<<productos[i].nombreProducto<<"\t\t\t"<<productos[i].cantidad<<" uds. \t"<<"$"<<productos[i].precio<<endl;
        aux++;
    }
}
void guardarProductosComprados(Producto p,int cantidad)//Crea un archivo y escribe los productos comprados
{
    ofstream archivo;
    archivo.open("ProductosComprados.csv",ios::out| ios::app);
    if(archivo.fail()){
        cout<<"Error al crear la Factura"<<endl;
    }
    else{
        archivo<<p.codigoIdentificador<<";"<<pasarMayusculas(p.nombreProducto)<<";"<<cantidad<<";"<<p.precio<<endl;
    }
    archivo.close();
}
void llenarArregloProductosComprados(Producto producto[],int tam)//llena un arreglo que nos servira para realizar las operacacion que realizaremos en un futuro
{
    ifstream archivo;
    string aux,aux2;
    archivo.open("ProductosComprados.csv",ios::in);
    if(archivo.fail()){
        cout<<"Archivo no encontrado"<<endl;
    }
    else{
        for(int i=0;i<tam;i++){
            getline(archivo,producto[i].codigoIdentificador,';');
            getline(archivo,producto[i].nombreProducto,';');
            getline(archivo,aux2,';');
            getline(archivo,aux,'\n');
            producto[i].precio=atof(aux.c_str());
            producto[i].cantidad=atoi(aux2.c_str());
        }
    }
    archivo.close();
}
float totalPago(Producto p[],int tam)//realiza la suma de todos los productos comprados
{
    float acum;
    for(int i=0;i<tam;i++)
    {
        acum=(p[i].precio*p[i].cantidad)+acum;
    }
    return acum;
}
void facturar(Producto p[],int tam,CuentaCliente c)//llena un archivo con los productos comprados y con el total a pagar  si el usuario se encuntra registrado en el sistema
{
    ofstream archivo;
    archivo.open("Factura.csv",ios::out);
    if(archivo.fail()){
        cout<<"No se puedo Crear el archivo"<<endl;
    }
    else{
        archivo<<"                         Factura"<<endl;
        archivo<<"Nombre: "<<c.nombre<<" "<<c.apellido<<"               Cedula/Ruc: "<<c.ci_ruc<<endl;
        archivo<<"Telefono: "<<c.telefono<<"                  Universidad de las Fuerzas Armadas ESPE"<<endl;
        archivo<<"Producto                             Cantidad                                Precio"<<endl;
        archivo<<"-----------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<tam;i++)
        {
            archivo<<p[i].nombreProducto<<"\t\t\t\t"<<p[i].cantidad<<"\t\t\t\t\t"<<p[i].precio<<endl;
        }
        archivo<<"                                                                       Total:\t"<<totalPago(p,tam)<<endl;
    }
    archivo.close();
}
void facturarC(Producto p[],int tam)//llena un archivo con los productos comprados y con el total a pagar si el usuario no se encuentra registrado
{
    ofstream archivo;
    archivo.open("Factura.csv",ios::out);
    if(archivo.fail()){
        cout<<"No se puedo Crear el archivo"<<endl;
    }
    else{
        archivo<<"                         Factura"<<endl;
        archivo<<"Nombre: Cosumidor Final                              Cedula/Ruc:0000000000"<<endl;
        archivo<<"Telefono:0000000000                Universidad de las Fuerzas Armadas ESPE"<<endl;
        archivo<<"Producto                             Cantidad                                Precio"<<endl;
        archivo<<"-----------------------------------------------------------------------------------"<<endl;
        for(int i=0;i<tam;i++)
        {
            archivo<<p[i].nombreProducto<<"\t\t\t\t"<<p[i].cantidad<<"\t\t\t\t\t"<<p[i].precio<<endl;
        }
        archivo<<"                                                                       Total:\t"<<totalPago(p,tam)<<endl;
    }
    archivo.close();
}
#endif // MANEJOARCHIVOS_H_INCLUDED
