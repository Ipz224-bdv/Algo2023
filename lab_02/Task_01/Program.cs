using System;
using System.Text;

namespace Lab_01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;

            uint a = 1664525;
            uint c = 1013904223;
            ulong m = 4294967296;
            ulong x = (ulong)DateTime.Now.Ticks;
            int K = 20000;
            int[] frequency = new int[150];

            long[] arr = new long[K];

            // Генерування послідовності випадкових чисел
            for (int i = 0; i < K; i++)
            {
                x = (a * x + c) % m;
                arr[i] = (long)(x % 150);
                frequency[arr[i]]++;
                Console.WriteLine($"{i}  {arr[i]}");
            }

            // Статистична ймовірність
            double statisticProbability = 1.0 / K;

            double[] probability = new double[150];

            for (int i = 0; i < 150; i++)
            {
                probability[i] = frequency[i] / (double)K;
                Console.WriteLine($"{probability[i]}");
            }

            double mean = 0;
            double variance = 0;

            for (int i = 0; i < 150; i++)
            {
                mean += i * probability[i];
            }

            for (int i = 0; i < 150; i++)
            {
                variance += (i - mean) * (i - mean) * probability[i];
            }

            // Output

            Console.WriteLine("Mean: {0}", mean);
            Console.WriteLine("Variance: {0}", variance);
            Console.WriteLine("Statistical Probability: {0}", statisticProbability);
            Console.WriteLine("Standard Deviation: {0}", Math.Sqrt(variance));
        }
    }
}
