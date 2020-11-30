using System;


namespace ProgramaP7
{
    class Program
    {
        static void Main(string[] args)
        {
            int numDatos,cont=0;
            string datosR;
            string[] datosN = new string[100];
            Console.WriteLine("Ingrese el numero de datos a tratar");
            datosR = Console.ReadLine();//pedimos datos
            numDatos = int.Parse(datosR);//trasformamos el string en int para usarlo 
            Console.WriteLine("Ingrese los datos separados con un espacio: ");
            for (int i = 0; i < numDatos; i++)
            {
                datosN[i] = Console.ReadLine();//vamos guardado los datos en el arreglo
            }
            Console.WriteLine(" ");
            Console.WriteLine("Puntos criticos");
            for (int j = 0; j < numDatos; j++)
            {
                if(datosN[j].Length==1 && int.Parse(datosN[j].Substring(0))!=0)//vamos comparando las lineas y viendo si tiene cortes y a estos los denominamos puntos criticos a demas que no sean igual a 0
                {
                    cont++;
                    Console.WriteLine(cont);//imprimimos los numeros 
                }
            }
            Console.ReadKey();
        }
    }
}
