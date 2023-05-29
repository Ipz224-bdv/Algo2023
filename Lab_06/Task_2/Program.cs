using System;

class Program
{
    static int[] SortingArray(int[] arr, int n)
    {
        int step = n / 2;
        while (step > 0)
        {
            for (int i = 0; i < (n - step); i++)
            {
                int j = i;
                while (j >= 0 && arr[j] > arr[j + step])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + step];
                    arr[j + step] = temp;
                    j--;
                }
            }
            step = step / 2;
        }
        return arr;
    }

    static int GetNumberOfValues()
    {
        int input = 0;
        Console.Write("Enter the number of values: ");
        input = int.Parse(Console.ReadLine());
        return input;
    }

    static int[] FillArray(int[] arr, int n)
    {
        Random random = new Random();
        for (int i = 0; i < n; i++)
        {
            if (i % 10 == 0)
            {
                Console.WriteLine();
            }
            arr[i] = random.Next(-5, 5);
            Console.Write("{0,6}", arr[i]);
        }
        Console.WriteLine();
        return arr;
    }

    static int[] PrintArray(int[] arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 10 == 0)
            {
                Console.WriteLine();
            }
            Console.Write("{0,6}", arr[i]);
        }
        Console.WriteLine();
        return arr;
    }

    static double AverageTime(double[] timeArr, int k)
    {
        double average = 0;
        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += timeArr[i];
        }

        average = sum / k;
        return average;
    }

    static double[] PrintTime(double[] timeArr, int k)
    {
        for (int i = 0; i < k; i++)
        {
            if (i % 10 == 0)
            {
                Console.WriteLine();
            }
            Console.Write("|{0}| ", timeArr[i]);
        }
        return timeArr;
    }

    static void Main(string[] args)
    {
        int k = 0;
        int rows = int.Parse(Console.ReadLine());
        double[] timeArr = new double[rows];
        int j = 0;
        int q = 0;
        while (j < rows)
        {
            int n = 0;
            Random random = new Random();

            n = GetNumberOfValues();
            q = n;
            int[] arr = new int[n];

            FillArray(arr, n);

            DateTime start = DateTime.Now;
            SortingArray(arr, n);
            DateTime finish = DateTime.Now;
            PrintArray(arr, n);

            timeArr[k] = (finish - start).TotalMilliseconds / 1000.0;

            Console.WriteLine("\n{0}\n\n", timeArr[k]);

            k++;
            j++;

            arr = null;
        }
        PrintTime(timeArr, k);

        Console.WriteLine("\nAverage value: {0}", AverageTime(timeArr, k));
    }
}
