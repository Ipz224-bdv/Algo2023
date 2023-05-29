using System;

class Program
{
    static int[] CountingSort(int[] array, int maxValue)
    {
        var count = new int[maxValue + 1];
        for (var i = 0; i < array.Length; i++)
        {
            count[array[i]]++;
        }

        var index = 0;
        for (var i = 0; i < count.Length; i++)
        {
            for (var j = 0; j < count[i]; j++)
            {
                array[index] = i;
                index++;
            }
        }

        return array;
    }

    static int[] GenerateRandomArray(int arraySize, int minValue, int maxValue)
    {
        var random = new Random();
        var randomArray = new int[arraySize];
        for (var i = 0; i < randomArray.Length; i++)
        {
            randomArray[i] = random.Next(minValue, maxValue);
        }

        return randomArray;
    }

    static void Main(string[] args)
    {
        var arr = GenerateRandomArray(10, 0, 9);
        Console.WriteLine("Input data: {0}", string.Join(", ", arr));
        Console.WriteLine("Sorted array: {0}", string.Join(", ", CountingSort(arr, 9)));
        Console.ReadLine();
    }
}
