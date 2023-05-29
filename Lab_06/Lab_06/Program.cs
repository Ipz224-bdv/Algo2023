using System;

class Program
{
    static int[] FillArray(int[] arr, int n)
    {
        Random random = new Random();
        for (int i = 0; i < n; i++)
        {
            arr[i] = random.Next(-5, 5);
        }
        arr[0] = 0;

        return arr;
    }

    static void PrintArray(int[] arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 10 == 0)
            {
                Console.WriteLine();
            }
            Console.Write("{0,4}", arr[i]);
        }
    }

    static int Parent(int i)
    {
        return i / 2;
    }

    static void Swap(ref int a, ref int b)
    {
        int t = a;
        a = b;
        b = t;
    }

    static void Heap(int[] arr, int n)
    {
        for (int i = n - 1; i > 1; i--)
        {
            if (arr[i] < arr[Parent(i)])
            {
                Swap(ref arr[i], ref arr[Parent(i)]);
            }
        }
    }

    static int[] Sorting(int[] arr, int[] secondArray, int n)
    {
        int count = n;
        for (int i = 0; i < count - 1; i++)
        {
            Heap(arr, n);
            secondArray[i] = arr[1];
            Swap(ref arr[1], ref arr[n - 1]);
            n--;
        }

        return secondArray;
    }

    static void Main(string[] args)
    {
        Random random = new Random();
        int n = int.Parse(Console.ReadLine());
        int[] arr = new int[n + 1];
        int[] secondArr = new int[n];

        FillArray(arr, n + 1);

        PrintArray(arr, n + 1);

        Sorting(arr, secondArr, n + 1);
        Console.WriteLine();
        PrintArray(secondArr, n);

        Console.ReadLine();
    }
}
