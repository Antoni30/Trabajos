using System;

namespace Programa2P
{
    class Program
    {
        protected static int origRow;
        protected static int origCol;
       static int drawWave(int frecuencia,int amplitud)//Dibuja ondas dependiendo de la frecuencia que ingrese en la funcion
        {
            int a = 3;
            Console.ForegroundColor = ConsoleColor.Yellow;
            for (int o = 0; o < frecuencia; o++)
            {
                for (int i = 0; i <= amplitud; i++)
                {
                    position(25, a);
                    for (int j = 0; j < i; j++)
                    {
                        Console.Write(i);
                    }
                    a++;
                    Console.Write("\n");
                }
                for (int i = amplitud - 1; i > 0; i--)
                {
                    position(25, a);
                    for (int j = 0; j < i; j++)
                    {
                        
                        Console.Write(i);
                    }
                    a++;
                    Console.Write("\n");
                }
                Console.Write("\n");
            }
            return a;
        }
        protected static void WriteAt(string s, int x, int y)//Se coloca en un punto en especifico de la consola y dibuja un caracter
        {
            try
            {
                Console.SetCursorPosition(origCol + x, origRow + y);
                Console.Write(s);
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.Clear();
                Console.WriteLine(e.Message);
            }
        }
        protected static void position(int x, int y)//Nos coloca en una posicion de la consola y desde ese punto podemos escribir 
        {
            try
            {
                Console.SetCursorPosition(origCol + x, origRow + y);
            }
            catch (ArgumentOutOfRangeException e)
            {
                Console.Clear();
                Console.WriteLine(e.Message);
            }
        }
        static void margin()//Crea un margen donde se desarrollara la mayoria del programa 
        {
            Console.ForegroundColor = ConsoleColor.Red;
           
            for (int i = 0; i < 50; i++)
            {
                for (int j = 0; j < 20; j++)
                {
                    if (i == 0 || j == 0 || j == 19 || i == 49)
                    {
                        WriteAt("=", i, j);
                    }
                    Console.WriteLine("\n");
                }
            }
        }
        static void wavemargin(int tam)//Crea un margen en especifico donde se dibujara la onda 
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            for (int i = 0; i < 50; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    if (i == 0 || j == 0 || j == tam-1 || i == 49)
                    {
                        WriteAt("=", i, j);
                    }
                    Console.WriteLine("\n");
                }
            }
        }
        static void Main(string[] args)
        {
            origRow = Console.CursorTop;
            origCol = Console.CursorLeft;
            int amplitud, frecuencia;
            int marginWave;
            int nCasos,cont=0;
            bool validacion1=true,validacion2=true,validacion3=true;
            do
            {
                margin();
                position(1, 1);
                Console.ForegroundColor = ConsoleColor.White;
                Console.BackgroundColor = ConsoleColor.Blue;
                Console.WriteLine("         Ingrese los numero de casos:           ");
                position(1, 2);
                Console.BackgroundColor = ConsoleColor.Black;
                nCasos =int.Parse(Console.ReadLine());//Ingresamos Datos de  los numero de casos que vamos a dibujar en la onda
                if (nCasos > 0)
                {
                    validacion1 = false;
                    while (cont != nCasos)
                    {
                        do
                        {
                            Console.Clear();
                            margin();
                            position(1, 1);
                            Console.ForegroundColor = ConsoleColor.White;
                            Console.BackgroundColor = ConsoleColor.Blue;
                            Console.WriteLine("                  Ingrese Amplitud:             ");
                            position(1, 2);
                            Console.BackgroundColor = ConsoleColor.Black;
                            amplitud = int.Parse(Console.ReadLine());//Ingresamos  datos de Amplitud
                            if (amplitud > 0)
                            {
                                validacion2 = false;
                                do
                                {
                                    Console.Clear();
                                    margin();
                                    position(1, 1);
                                    Console.ForegroundColor = ConsoleColor.White;
                                    Console.BackgroundColor = ConsoleColor.Blue;
                                    Console.WriteLine("            Ingrese Frecuencia:                 ");
                                    position(1, 2);
                                    Console.BackgroundColor = ConsoleColor.Black;
                                    frecuencia = int.Parse(Console.ReadLine());//Ingresamos datos de Frecuencia
                                    if (frecuencia > 0)
                                    {
                                        validacion3 = false;
                                        Console.Clear();
                                        position(1, 1);
                                        Console.ForegroundColor = ConsoleColor.DarkRed;
                                        Console.BackgroundColor = ConsoleColor.White;
                                        Console.WriteLine("Grafico N: " + (cont + 1));
                                        position(1, 2);
                                        Console.ForegroundColor = ConsoleColor.DarkRed;
                                        Console.BackgroundColor = ConsoleColor.White;
                                        Console.WriteLine("Amplitud:" + amplitud + "   Frecuencia: " + frecuencia);
                                        Console.BackgroundColor = ConsoleColor.Black;
                                        marginWave = drawWave(frecuencia, amplitud) + 2;
                                        Console.BackgroundColor = ConsoleColor.Black;
                                        wavemargin(marginWave);//Dibujamos el margen donde se dibujara la onda y dibujamos la Onda
                                        Console.BackgroundColor = ConsoleColor.Black;
                                        Console.ReadKey();
                                        cont++;
                                    }

                                } while (validacion3); //Validamos si son numeros positivos
                            }

                        } while (validacion2);//Validamos si son numeros positivos
                    }
                }
                else
                {
                    Console.Clear();
                    position(60, 1);
                    Console.WriteLine("------------------------------------");
                    position(60, 2);
                    Console.WriteLine("|Recuerde ingresar numeros positivos|");
                    position(60, 3);
                    Console.WriteLine("-------------------------------------");
                }
            }while (validacion1);//Validamos  si son numeros positivos
            Console.ReadKey();
            Console.Clear();
        }
    }
}
