#ifndef NODOTEMPLATES_H_INCLUDED
#define NODOTEMPLATES_H_INCLUDED
template<class Dato>
class Nodo{
private:
    Nodo* siguiente;
    Dato dato;
public:
    Nodo* getSiguiente()
    {
        return siguiente;
    }
    void setSiguiente(Nodo* sig)
    {
        siguiente=sig;
    }
    Dato getDato();
    void setDato(Dato);
};
template<class Dato>
Dato Nodo<Dato>::getDato(){
    return dato;
}
template<class Dato>
void Nodo<Dato>::setDato(Dato date){
    dato=date;
}
#endif // NODOTEMPLATES_H_INCLUDED
