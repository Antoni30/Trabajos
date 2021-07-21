using System;

namespace TrabajoP8
{
	class Program
    {
		public const int INF = 99999;//constante de infinitos 
		public static void imprimir(int[,] distance, int verticesCount)
		{

			for (int i = 0; i < verticesCount; ++i)//vamos recorriendo  la matriz en i
			{
				for (int j = 0; j < verticesCount; ++j)//vamos recorriendo la matriz en j
				{
					if (distance[i, j] == INF)//si ecuentra que es inf imprime la palabra inf representando infinito
                    {
						Console.Write("INF".PadLeft(7));
					}
					else
                    {
						Console.Write(distance[i, j].ToString().PadLeft(7));
					}
				}
				Console.WriteLine();
			}
		}
		public static int[,] floydWarshall(int[,] graph, int verticesCount)//Resuelve la matriz y nos devuelve una matriz solucion
		{
			int[,] distance = new int[verticesCount, verticesCount];//creamos otra matriz para guardar la solucion

			for (int i = 0; i < verticesCount; ++i)
            {
				for (int j = 0; j < verticesCount; ++j)
                {
					distance[i, j] = graph[i, j];//guardamos la matriz en la matriz nueva
				}	
			}
			for (int k = 0; k < verticesCount; ++k)
			{
				for (int i = 0; i < verticesCount; ++i)
				{
					for (int j = 0; j < verticesCount; ++j)
					{
						if (distance[i, k] + distance[k, j] < distance[i, j])
                        {
							distance[i, j] = distance[i, k] + distance[k, j];
						}
						
					}
				}
			}

			return distance;
		}
		public static void mostrarOperaciones(int[,] graph, int verticesCount)//mostramos las operaciones que se realizo en la matriz
        {
			int[,] distance = new int[verticesCount, verticesCount];//creamos otra matriz para guardar la solucion

			for (int i = 0; i < verticesCount; ++i)
			{
				for (int j = 0; j < verticesCount; ++j)
				{
					distance[i, j] = graph[i, j];//guardamos la matriz en la matriz nueva
				}
			}
			for (int k = 0; k < verticesCount; ++k)
			{
				for (int i = 0; i < verticesCount; ++i)
				{
					for (int j = 0; j < verticesCount; ++j)
					{
						if (distance[i, k] + distance[k, j] < distance[i, j])
						{
							distance[i, j] = distance[i, k] + distance[k, j];
							Console.WriteLine();
							imprimir(distance, 6);
						}

					}
				}
			}
		}
		static void Main(string[] args)
        {
			int[,] graphSolution;
			string s;
			int[,] graph = {
							{0 , 3 , 5 , 1 , INF , INF},
							{3 , 0 , INF , INF , 9 ,INF},
							{5 , INF , 0 , 7 , 7 ,1},
							{1 , INF , 7 , 0 , INF , 4},
							{INF , 9 , 7 , INF , 0 , INF},
							{INF , INF , 1 , 4 , INF ,0},
												};
			Console.WriteLine("Desea mostrar las operaciones que se realizo\n Escriba s(Si)    Cualquier letra(No):");
			s = Console.ReadLine();
            if (s == "s")
            {
				Console.WriteLine("Operaciones de matriz");
				mostrarOperaciones(graph, 6);
				Console.WriteLine("-------------------------------");
			}
			graphSolution = floydWarshall(graph, 6);
			Console.WriteLine("Matriz Original");
			imprimir(graph, 6);
			Console.WriteLine();
			Console.WriteLine("Matriz Solucion:");
			Console.WriteLine("Distancias más cortas entre cada par de vértices:");
			imprimir(graphSolution, 6);
		}
	}
}
