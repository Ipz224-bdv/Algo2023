using System;

public delegate double Func(double function);

namespace ConsoleAppALGOR
{
    public class Tabulator
    {
        public static void Tabulate(int a, int b, int h, Func func)
        {
            for (int i = a; i <= b; i += h)
            {
                double y = func(i);

                if (y > 500) return;

                Console.WriteLine($"f({i}) = {y:F2}");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int a = 0, b = 50, h = 1;
            int menu;
            bool flag = true;

            Console.WriteLine("Виберіть функцію:");
            Console.WriteLine("1) f(n) = n;");
            Console.WriteLine("2) f(n) = log(n);");
            Console.WriteLine("3) f(n) = n * log(n);");
            Console.WriteLine("4) f(n) = n^2;");
            Console.WriteLine("5) f(n) = 2^n;");
            Console.WriteLine("6) f(n) = n!;");

            do
            {
                flag = int.TryParse(Console.ReadLine(), out menu);

                if (!flag || menu > 6 || menu < 1)
                    Console.WriteLine("Помилка!");

            } while (!flag || menu > 6 || menu < 1);

            switch (menu)
            {
                case 1:
                    Tabulator.Tabulate(a, b, h, (x) => x);
                    break;

                case 2:
                    Tabulator.Tabulate(a, b, h, (x) => Math.Log(x));
                    break;

                case 3:
                    Tabulator.Tabulate(a, b, h, (x) => x * Math.Log(x));
                    break;

                case 4:
                    Tabulator.Tabulate(a, b, h, (x) => Math.Pow(x, 2));
                    break;

                case 5:
                    Tabulator.Tabulate(a, b, h, (x) => Math.Pow(2, x));
                    break;

                case 6:
                    Tabulator.Tabulate(a, b, h, (x) =>
                    {
                        double factorial = 1;
                        for (double i = x; i > 0; i--)
                            factorial *= i;
                        return factorial;
                    });
                    break;
            }
        }
    }
}
