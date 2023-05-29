using System;
using System.Diagnostics;

class Task3
{
    class Node
    {
        public int data;
        public Node prev;
        public Node next;
    }

    static void Insert(ref Node head, int newData)
    {
        Node newNode = new Node();
        newNode.data = newData;
        newNode.prev = null;
        newNode.next = head;

        if (head != null)
        {
            head.prev = newNode;
        }

        head = newNode;
    }

    static void PrintList(Node node)
    {
        while (node != null)
        {
            Console.Write("{0} ", node.data);
            node = node.next;
        }

        Console.WriteLine();
    }

    static void InsertionSort(ref Node head)
    {
        Node current = head?.next;

        while (current != null)
        {
            int key = current.data;
            Node previous = current.prev;

            while (previous != null && previous.data > key)
            {
                previous.next.data = previous.data;
                previous = previous.prev;
            }

            if (previous == null)
            {
                head.data = key;
            }
            else
            {
                previous.next.data = key;
            }

            current = current.next;
        }
    }

    static void Main()
    {
        Node head = null;
        int size;

        Console.Write("Кількість елементів: ");
        size = int.Parse(Console.ReadLine());
        Random random = new Random();

        for (int i = 0; i < size; i++)
        {
            int data = random.Next(1, 101);
            Insert(ref head, data);
        }

        Console.WriteLine("Оригінальний список: ");
        PrintList(head);

        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();
        InsertionSort(ref head);
        stopwatch.Stop();

        Console.WriteLine("Відсортований список: ");
        PrintList(head);
        Console.WriteLine($"Час виконання сортування:  {stopwatch.Elapsed.TotalSeconds:F4} секунд");
    }
}