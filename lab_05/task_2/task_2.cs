using System;
using System.Diagnostics;

class Task2
{
    static void InsertionSort(int[] array)
    {
        int length = array.Length;
        for (int i = 1; i < length; i++)
        {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

    static void PrintArray(int[] array)
    {
        int length = array.Length;
        for (int i = 0; i < length; i++)
        {
            Console.Write(array[i] + " ");
        }
        Console.WriteLine();
    }

    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        int size;
        Console.Write("Введите количество элементов в массиве: ");
        size = int.Parse(Console.ReadLine());
        int[] array = new int[size];
        Console.WriteLine("Генерация случайных элементов для массива...");
        Random random = new Random();
        for (int i = 0; i < size; i++)
        {
            array[i] = random.Next(100);
        }
        Console.Write("Исходный массив: ");
        PrintArray(array);

        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        InsertionSort(array);
        stopwatch.Stop();

        Console.Write("Отсортированный массив: ");
        PrintArray(array);
        Console.WriteLine($"Время выполнения сортировки: {stopwatch.Elapsed.TotalSeconds:F4} секунд");
    }
}