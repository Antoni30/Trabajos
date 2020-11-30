using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TrabajoP6
{
    public class Arbol//creamos la clase arbol
    {
        class Nodo
        {
            public int info;
            public Nodo izq, der;
        }
        Nodo raiz;

        public Arbol()//Creamos el constructor
        {
            raiz = null;//no existe ningun valor y nos sirve para determinar si podemos ingresar valores o no
        }

        public void Insertar(int info)//funcion para incertar en el arbol
        {
            Nodo nuevo;
            nuevo = new Nodo();//creamos el nuevo nodo
            nuevo.info = info;//agregamos el dato al nodo
            nuevo.izq = null;//ponemos las nuevas hojas izquierda en null para que puedean ingresar otros valores
            nuevo.der = null;//ponemos las nuevas hojas derecha en null para que puedean ingresar otros valores
            if (raiz == null)//si no existe un nodo lo crea y es la raiz del arbol
                raiz = nuevo;
            else
            {
                Nodo anterior = null, reco;
                reco = raiz;
                while (reco != null)//vamos comparando y ordenando nuestro arbol
                {
                    anterior = reco;//mientras vamos recorriendo guardamos el anterior para que los datos no se pierdan
                    if (info < reco.info)//si  el data es menor  que el anteriro guarda en la hoja izquierda 
                        reco = reco.izq;
                    else//caso contrario lo guarda enla hoja derecha
                        reco = reco.der;
                }
                if (info < anterior.info)
                    anterior.izq = nuevo;
                else
                    anterior.der = nuevo;
            }
        }
        private void ImprimirPost(Nodo reco)//imprimimos
        {
            if (reco != null) //hasta que no encuentre un nodo vacio no para de imprimir
            {
                ImprimirPost(reco.izq);//imprime lo que tenga en la hoja izquierda
                ImprimirPost(reco.der);//imprime lo que tiene en la hoja derecha
                Console.Write((char)reco.info + " ");//nos devuelve un numero que es el codigo ascii de una letra y lo trasformamos 
            }
        }
        public void ImprimirPost()
        {
            ImprimirPost(raiz);//imprime la raiz
            Console.WriteLine();//salto de linea
        }
    }
    class Program
    {
       static void Main(string[] args)
       {
            string palabras,p;
            Console.WriteLine("Ingrese Palabras que va ingresar al arbol");
            palabras = Console.ReadLine();//recibimos por teclado las palabras
            string[] arreglo = palabras.ToLower().Split(" ");//dividimos las palabras para realizar el numero de casos
            for(int i = 0; i < arreglo.Length; i++)//recorre todo el arreglo de palabras
            {
                Arbol arbol = new Arbol();//Inicializamos el arbol
                for (int j = 0; j < arreglo[i].Length; j++)
                {
                    p = arreglo[i].Substring(j);//agregamos un caracter para hacer la trasformacion de char  a codigo ascci 
                    arbol.Insertar(Encoding.ASCII.GetBytes(p)[0]);// trasformamos el char a int respectivo del codigo ascci  y luego insertamos
                }
                arbol.ImprimirPost();//impriminos caso por caso 
            }
             
        }
    }
}
