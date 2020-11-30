using System;
using System.Text;

namespace Programa5P
{
   
    class Program
    {
        public static int[]lista(string conteodigito)//Funcion para contar los numeros repetido
        {
            int[] arreglo = new int[10];
            int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0, cont8 = 0, cont9 = 0, cont0 = 0;
            for(int i = 0; i < conteodigito.Length; i++)//recorre el string y va contando cuatos caracteres iguales existe
            {
                if (conteodigito[i] == '1')//compara si  el digito es 1 
                {
                    cont1++;
                }
                else if (conteodigito[i] == '2')//compara si  el digito es 2
                {
                    cont2++;
                }
                else if (conteodigito[i] == '3')//compara si  el digito es 3
                {
                    cont3++;
                }
                else if (conteodigito[i] == '4')//compara si  el digito es 4
                {
                    cont4++;
                }
                else if (conteodigito[i] == '5')//compara si  el digito es 5
                {
                    cont5++;
                }
                else if (conteodigito[i] == '6')//compara si  el digito es 6
                {
                    cont6++;
                }
                else if (conteodigito[i] == '7')//compara si  el digito es 7
                {
                    cont7++;
                }
                else if (conteodigito[i] == '8')//compara si  el digito es 8
                {
                    cont8++;
                }
                else if (conteodigito[i] == '9')//compara si  el digito es 9
                {
                    cont9++;
                }
                else if (conteodigito[i] == '0')//compara si  el digito es 0
                {
                    cont0++;
                }

            }
            arreglo[0] = cont0;//Guardamos
            arreglo[1] = cont1;// los
            arreglo[2] = cont2;//valores
            arreglo[3] = cont3;//que
            arreglo[4] = cont4;// se 
            arreglo[5] = cont5;//encuentran 
            arreglo[6] = cont6;//repetidos
            arreglo[7] = cont7;//en 
            arreglo[8] = cont8;// mi
            arreglo[9] = cont9;//arreglo  de decimas los cuales me serviran para contar el ciclo
            return arreglo;//devolvemos un arreglo que posee el numero de repeticiones de cada numero
        }
        static void Main(string[] args)
        {
            string numeros, numeros2, numeros3, cicloR, cicloR2 ,cicloR3, comparo, comparo2, comparo3, concatenacion="", concatenacion2 = "", concatenacion3 = "", gb, gb2, gb3, inicio, inicio2, inicio3;
            int numerador=0,denominador=0, numerador2 = 0, denominador2 = 0, numerador3 = 0, denominador3 = 0,cont =0, cont2 = 0, cont3 = 0;
            int[] l;
            int[] l2;
            int[] l3;
            decimal resultado, resultado2, resultado3;
            Console.WriteLine("Ingrese dos numeros: ");//Pedimos el numero y lo separamos por espacio
            numeros = Console.ReadLine();//pedimos los numeros por consola
            numeros2 = Console.ReadLine();//pedimos los numeros por consola
            numeros3 = Console.ReadLine();//pedimos los numeros por consola
            string[] fraccion = numeros.Split(" ");//dividimos y guardamos en un arreglo
            string[] fraccion2 = numeros2.Split(" ");//dividimos y guardamos en un arreglo
            string[] fraccion3 = numeros3.Split(" ");//dividimos y guardamos en un arreglo
            try
            {
                //haces la trasformacion para hacer los calculos
                numerador = int.Parse(fraccion[0]);//convertimos en it el primer termino y lo guardamos en el numerador
                denominador = int.Parse(fraccion[1]);//convertimos en it el primer termino y lo guardamos en el denominador
                numerador2 = int.Parse(fraccion2[0]);//convertimos en it el primer termino y lo guardamos en el numerador
                denominador2 = int.Parse(fraccion2[1]);//convertimos en it el primer termino y lo guardamos en el denominador
                numerador3 = int.Parse(fraccion3[0]);//convertimos en it el primer termino y lo guardamos en el numerador
                denominador3 = int.Parse(fraccion3[1]);//convertimos en it el primer termino y lo guardamos en el denominador
            }
            catch(Exception Ex)//Si da Error
            {
                Console.WriteLine("No ingreso Numeros");//si no ingresa un numero se cierra el programa
            }
            resultado = decimal.Divide(numerador,denominador);//realizamos la operacion con un funcion que nos sirve para sacar las maximas decimas de nuestra divicion 
            resultado2 = decimal.Divide(numerador2, denominador2);//realizamos la operacion con un funcion que nos sirve para sacar las maximas decimas de nuestra divicion 
            resultado3 = decimal.Divide(numerador3, denominador3);//realizamos la operacion con un funcion que nos sirve para sacar las maximas decimas de nuestra divicion 
            cicloR = resultado.ToString();//convertimos el resutado en string
            cicloR2 = resultado2.ToString();//convertimos el resutado en string
            cicloR3 = resultado3.ToString();//convertimos el resutado en string
            if (cicloR.Length > 1)
            {
                string[] resultR = cicloR.Split(".");//guardamos y dividimos  por . para que podamos trabajar con las decimas
                comparo = resultR[1];//guardamos la parde decimal en string para usar la funcion de contar y saber cual es el ciclo
                concatenacion = comparo[0].ToString();//guardo el primer valor de decima
                l = lista(comparo);
                for (int i = 0; i < l.Length; i++)//contamos mos numeros repetidos
                {
                    if (l[i] > 2)//si existe nuemeros > a 2 en el arreglo significa que tenemos numeros repetidos y contamos  
                    {
                        cont++;//contador sube mas 1
                    }
                }
                inicio = comparo.Substring(0, 1);//divido el string en los 2 primeros dos terminos para realizar la comparacion 
                if (cont > 0)//si no existe un 0 constante realizamos el proceso 
                {
                    gb = comparo.Substring(0, cont);//los terminios antes de terminar el ciclo 
                    while (inicio != gb.Substring(gb.Length - 1))//vamos comparando el inicio y el final de ciclo para ver si cumple que es ciclico
                    {
                        if (cont > comparo.Length)//si contador es mayot a arreglo de decimas para el while
                        {
                            break;//cuando encuentre la igualdad salga 
                        }
                        else
                        {
                            cont++;
                            gb = comparo.Substring(0, cont);//si no cumple la condicion vamos aumentando hasta que los 2 primeros digitos sean iguales 
                        }
                    }
                    if (cont == 15)//imprimimos depentiendo el caso de repeticiones que se dan
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador + "/" + denominador);
                        Console.WriteLine(resultR[0] + "." + "(" + gb + ")");
                        Console.WriteLine((cont + 6) + "= number of digits in repeating cycle");
                    }
                    else if (cont == 18)// si los primeros 50 decimas no son iguales 
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador + "/" + denominador);
                        Console.WriteLine(resultR[0] + "." + "(" + gb + "...)");
                        Console.WriteLine("99" + "= number of digits in repeating cycle");
                    }
                    else
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador + "/" + denominador);
                        Console.WriteLine(resultR[0] + "." + "(" + gb + ")");
                        Console.WriteLine(cont + "= number of digits in repeating cycle");
                    }
                }
                else//si el nuemero a repetir es 0
                {
                    //mostramos todo los datos obtenidos
                    Console.WriteLine(numerador + "/" + denominador);
                    Console.WriteLine(resultado + "(0)");
                    Console.WriteLine("1" + "= number of digits in repeating cycle");
                }
            }
            else
            {
                //mostramos todo los datos obtenidos
                Console.WriteLine(numerador + "/" + denominador);
                Console.WriteLine(resultado + ".(0)");
                Console.WriteLine("1" + "= number of digits in repeating cycle");
            }
            if (cicloR2.Length > 1)
            {
                string[] resultR2 = cicloR2.Split(".");//guardamos y dividimos  por . para que podamos trabajar con las decimas
                comparo2 = resultR2[1];//guardamos la parde decimal en string para usar la funcion de contar y saber cual es el ciclo
                concatenacion2 = comparo2[0].ToString();//guardo el primer valor de decima
                l2 = lista(comparo2);
                for (int i = 0; i < l2.Length; i++)//contamos mos numeros repetidos
                {
                    if (l2[i] > 2)//si existe nuemeros > a 2 en el arreglo significa que tenemos numeros repetidos y contamos  
                    {
                        cont2++;//contador sube mas 1
                    }
                }
                inicio2 = comparo2.Substring(0, 1);//divido el string en los 2 primeros dos terminos para realizar la comparacion 
                if (cont2 > 0)//si no existe un 0 constante realizamos el proceso 
                {
                    gb2 = comparo2.Substring(0, cont2);//los terminios antes de terminar el ciclo 
                    while (inicio2 != gb2.Substring(gb2.Length - 1))//vamos comparando el inicio y el final de ciclo para ver si cumple que es ciclico
                    {
                        if (cont2 > comparo2.Length)//si contador es mayot a arreglo de decimas para el while
                        {
                            break;//cuando encuentre la igualdad salga 
                        }
                        else
                        {
                            cont2++;
                            gb2 = comparo2.Substring(0, cont2);//si no cumple la condicion vamos aumentando hasta que los 2 primeros digitos sean iguales 
                        }
                    }
                    if (cont2 == 15)//imprimimos depentiendo el caso de repeticiones que se dan
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador2 + "/" + denominador2);
                        Console.WriteLine(resultR2[0] + "." + "(" + gb2 + ")");
                        Console.WriteLine((cont2 + 6) + "= number of digits in repeating cycle");
                    }
                    else if (cont2 == 18)// si los primeros 50 decimas no son iguales 
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador2 + "/" + denominador2);
                        Console.WriteLine(resultR2[0] + "." + "(" + gb2 + "...)");
                        Console.WriteLine("99" + "= number of digits in repeating cycle");
                    }
                    else
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador2 + "/" + denominador2);
                        Console.WriteLine(resultR2[0] + "." + "(" + gb2 + ")");
                        Console.WriteLine(cont2 + "= number of digits in repeating cycle");
                    }
                }
                else//si el nuemero a repetir es 0
                {
                    //mostramos todo los datos obtenidos
                    Console.WriteLine(numerador2 + "/" + denominador2);
                    Console.WriteLine(resultado2 + "(0)");
                    Console.WriteLine("1" + "= number of digits in repeating cycle");
                }
            }
            else
            {
                //mostramos todo los datos obtenidos
                Console.WriteLine(numerador2 + "/" + denominador2);
                Console.WriteLine(resultado2 + ".(0)");
                Console.WriteLine("1" + "= number of digits in repeating cycle");
            }
            if (cicloR3.Length > 1)
            {
                string[] resultR3 = cicloR3.Split(".");//guardamos y dividimos  por . para que podamos trabajar con las decimas
                comparo3 = resultR3[1];//guardamos la parde decimal en string para usar la funcion de contar y saber cual es el ciclo
                concatenacion3 = comparo3[0].ToString();//guardo el primer valor de decima
                l3 = lista(comparo3);
                for (int i = 0; i < l3.Length; i++)//contamos mos numeros repetidos
                {
                    if (l3[i] > 2)//si existe nuemeros > a 2 en el arreglo significa que tenemos numeros repetidos y contamos  
                    {
                        cont3++;//contador sube mas 1
                    }
                }
                inicio3 = comparo3.Substring(0, 1);//divido el string en los 2 primeros dos terminos para realizar la comparacion 
                if (cont3 > 0)//si no existe un 0 constante realizamos el proceso 
                {
                    gb3 = comparo3.Substring(0, cont3);//los terminios antes de terminar el ciclo 
                    while (inicio3 != gb3.Substring(gb3.Length - 1))//vamos comparando el inicio y el final de ciclo para ver si cumple que es ciclico
                    {
                        if (cont3 > comparo3.Length)//si contador es mayot a arreglo de decimas para el while
                        {
                            break;//cuando encuentre la igualdad salga 
                        }
                        else
                        {
                            cont3++;
                            gb3 = comparo3.Substring(0, cont3);//si no cumple la condicion vamos aumentando hasta que los 2 primeros digitos sean iguales 
                        }
                    }
                    if (cont3 == 15)//imprimimos depentiendo el caso de repeticiones que se dan
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador3 + "/" + denominador3);
                        Console.WriteLine(resultR3[0] + "." + "(" + gb3 + ")");
                        Console.WriteLine((cont3 + 6) + "= number of digits in repeating cycle");
                    }
                    else if (cont3 == 18)// si los primeros 50 decimas no son iguales 
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador3 + "/" + denominador3);
                        Console.WriteLine(resultR3[0] + "." + "(" + gb3 + "...)");
                        Console.WriteLine("99" + "= number of digits in repeating cycle");
                    }
                    else
                    {
                        //mostramos todo los datos obtenidos
                        Console.WriteLine(numerador3 + "/" + denominador3);
                        Console.WriteLine(resultR3[0] + "." + "(" + gb3 + ")");
                        Console.WriteLine(cont3 + "= number of digits in repeating cycle");
                    }
                }
                else//si el nuemero a repetir es 0
                {
                    //mostramos todo los datos obtenidos
                    Console.WriteLine(numerador3 + "/" + denominador3);
                    Console.WriteLine(resultado3 + "(0)");
                    Console.WriteLine("1" + "= number of digits in repeating cycle");
                }
            }
            else
            {
                //mostramos todo los datos obtenidos
                Console.WriteLine(numerador3 + "/" + denominador3);
                Console.WriteLine(resultado3 + ".(0)");
                Console.WriteLine("1" + "= number of digits in repeating cycle");
            }
            Console.ReadKey();//espera una tecla para cerrar el programa
        }
    }
}
