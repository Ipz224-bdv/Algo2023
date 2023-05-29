using System;
using System.Runtime.InteropServices;

class Program
{
    [DllImport("kernel32.dll")]
    private static extern bool SetConsoleCP(int codePage);

    [DllImport("kernel32.dll")]
    private static extern bool SetConsoleOutputCP(int codePage);

    delegate void PrintFunc(ref int data);

    class Node
    {
        public int value;
        public Node next;
        public Node prev;
    }

    class MyList
    {
        public Node head;
        public Node tail;
        public int size;
    }

    static MyList CreateList()
    {
        MyList list = new MyList();
        list.size = 0;
        list.head = list.tail = null;
        return list;
    }

    static bool IsEmptyList(MyList list)
    {
        return (list.head == null || list.tail == null);
    }

    static void DeleteList(MyList list)
    {
        Node head = list.head;
        Node next = null;

        while (head != null)
        {
            next = head.next;
            Marshal.FreeHGlobal((IntPtr)head);
            head = next;
        }

        list.head = list.tail = null;
        list = null;
    }

    static int PushFront(MyList list, ref int data)
    {
        Node node = (Node)Marshal.AllocHGlobal(Marshal.SizeOf(typeof(Node)));
        if (node == null)
            return -1;

        node.value = data;
        node.next = list.head;
        node.prev = null;

        if (!IsEmptyList(list))
            list.head.prev = node;
        else
            list.tail = node;

        list.head = node;
        list.size++;

        return 0;
    }

    static int PopFront(MyList list, ref int data)
    {
        if (IsEmptyList(list))
            return -2;

        Node node = list.head;
        list.head = list.head.next;

        if (!IsEmptyList(list))
            list.head.prev = null;
        else
            list.tail = null;

        data = node.value;
        list.size--;

        Marshal.FreeHGlobal((IntPtr)node);
        return 0;
    }

    static int PushBack(MyList list, ref int data)
    {
        Node node = (Node)Marshal.AllocHGlobal(Marshal.SizeOf(typeof(Node)));
        if (node == null)
            return -3;

        node.value = data;
        node.next = null;
        node.prev = list.tail;

        if (!IsEmptyList(list))
            list.tail.next = node;
        else
            list.head = node;

        list.tail = node;
        list.size++;

        return 0;
    }

    static int PopBack(MyList list, ref int data)
    {
        if (IsEmptyList(list))
            return -4;

        Node node = list.tail;
        list.tail = list.tail.prev;

        if (!IsEmptyList(list))
            list.tail.next = null;
        else
            list.head = null;

        data = node.value;
        list.size--;

        Marshal.FreeHGlobal((IntPtr)node);
        return 0;
    }

    static Node GetNode(MyList list, int index)
    {
        if (index >= list.size)
            return null;

        Node node;
        int i;

        if (index < list.size / 2)
        {
            i = 0;
            node = list.head;
            while (node != null && i < index)
            {
                node = node.next;
                i++;
            }
        }
        else
        {
            i = list.size - 1;
            node = list.tail;
            while (node != null && i > index)
            {
                node = node.prev;
                i--;
            }
        }

        return node;
    }

    static void PrintList(MyList list, PrintFunc func)
    {
        Node node = list.head;

        if (IsEmptyList(list))
            return;

        while (node != null)
        {
            func(ref node.value);
            node = node.next;
        }
    }

    static int DeleteNode(MyList list, int index, ref int data)
    {
        if (index < 0 || index >= list.size)
            return -1;

        Node node = GetNode(list, index);

        if (node == null)
            return -2;

        if (node == list.head)
            return PopFront(list, ref data);

        if (node == list.tail)
            return PopBack(list, ref data);

        node.prev.next = node.next;
        node.next.prev = node.prev;

        data = node.value;
        list.size--;

        Marshal.FreeHGlobal((IntPtr)node);
        return 0;
    }

    static void PrintValue(ref int data)
    {
        Console.Write(data + " ");
    }

    static void Main()
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        MyList list = CreateList();
        int action = -1;

        while (action != 0)
        {
            Console.WriteLine("1. Додати елемент у початок списку");
            Console.WriteLine("2. Додати елемент у кінець списку");
            Console.WriteLine("3. Видалити елемент з початку списку");
            Console.WriteLine("4. Видалити елемент з кінця списку");
            Console.WriteLine("5. Видалити елемент за індексом");
            Console.WriteLine("6. Вивести список на екран");
            Console.WriteLine("0. Вихід");
            Console.Write("Введіть номер дії: ");
            action = int.Parse(Console.ReadLine());

            switch (action)
            {
                case 1:
                    {
                        Console.Write("Введіть значення: ");
                        int data = int.Parse(Console.ReadLine());
                        PushFront(list, ref data);
                        Console.WriteLine("Елемент успішно додано!");
                        break;
                    }
                case 2:
                    {
                        Console.Write("Введіть значення: ");
                        int data = int.Parse(Console.ReadLine());
                        PushBack(list, ref data);
                        Console.WriteLine("Елемент успішно додано!");
                        break;
                    }
                case 3:
                    {
                        int data = 0;
                        int res = PopFront(list, ref data);
                        if (res == 0)
                            Console.WriteLine("Видалено елемент зі значенням " + data);
                        else
                            Console.WriteLine("Список порожній!");
                        break;
                    }
                case 4:
                    {
                        int data = 0;
                        int res = PopBack(list, ref data);
                        if (res == 0)
                            Console.WriteLine("Видалено елемент зі значенням " + data);
                        else
                            Console.WriteLine("Список порожній!");
                        break;
                    }
                case 5:
                    {
                        Console.Write("Введіть номер позиції для видалення: ");
                        int index = int.Parse(Console.ReadLine());
                        Console.Write("Введіть значення: ");
                        int data = int.Parse(Console.ReadLine());
                        if (DeleteNode(list, index, ref data) == 0)
                            Console.WriteLine("Елемент успішно вставлено!");
                        else
                            Console.WriteLine("Помилка вставки елемента!");
                        break;
                    }
                case 6:
                    {
                        Console.WriteLine("Список:");
                        PrintList(list, PrintValue);
                        Console.WriteLine();
                        break;
                    }
                case 0:
                    {
                        break;
                    }
                default:
                    {
                        Console.WriteLine("Некоректний ввід! Введіть число від 0 до 5");
                        break;
                    }
            }
        }

        DeleteList(list);
    }
}
