using System;

namespace Programa3P
{
    class Program
    {
        protected static int origRow;
        protected static int origCol;
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
        static bool vocal(char c)//Devuelve un verdadero si es vocal y si no un falso 
        {
            switch (c)
            {
                case 'a':
                    return true;
                case 'e': 
                    return true;
                case 'i':
                    return true;
                case 'o':
                    return true;
                case 'u':
                    return true;
                case 'A':
                    return true;
                case 'E':
                    return true;
                case 'I':
                    return true;
                case 'O':
                    return true;
                case 'U':
                    return true;
                default:
                    return false;
            }
        }
        static void Main(string[] args)
        {
            origRow = Console.CursorTop;
            origCol = Console.CursorLeft;
            String frase = string.Empty;
            int tam;
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            position(25, 0);
            Console.WriteLine("-------------------------------------------------------");
            position(25, 1);
            Console.WriteLine("|               Ingrese una Frase                     |");
            position(25, 2);
            Console.WriteLine("-------------------------------------------------------");
            position(25, 4);
            Console.BackgroundColor = ConsoleColor.Black;
            Console.WriteLine("->");
            position(27, 4);
            Console.ForegroundColor = ConsoleColor.Yellow;
            frase = Console.ReadLine();//Ingresamos una frase 
            String []arreglo= frase.Trim().Split(" ");//Borramos los espacios en branco del inicio y del final,dividimos la frase y guardamos en un arreglo de strings
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            position(25, 6);
            Console.WriteLine("|                       PIG-LATIN                     |");
            Console.BackgroundColor = ConsoleColor.Black;
            position(45, 8);
            Console.ForegroundColor = ConsoleColor.Cyan;
            for (int i = 0; i < arreglo.Length; i++)//Recorremos nuestro arreglo de string
            {
                if (vocal(arreglo[i][0]))//Vamos comparando si existe una vocal o una consonante en la palabra
                {
                    Console.Write (arreglo[i] + "ay ");// Si es vocal colocamos al final de la palabra ay
                }
                else
                {
                    tam = arreglo[i].Length;
                    Console.Write(arreglo[i].Substring(1)+arreglo[i][0]+"ay ");//Si es consonante cortamos la primera letra y lo colocamos al final y aumentamos ay
                }
            }
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            position(25, 10);
            Console.WriteLine("|                                                     |");
            Console.BackgroundColor = ConsoleColor.Black;

        }
    }
}
