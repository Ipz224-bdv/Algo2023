using System;
using System.Collections;
using System.Collections.Generic;

namespace AlgoTempLab4
{
    public class doubleNode<T>
    {
        public T Data;
        public doubleNode<T> Previous;
        public doubleNode<T> Next;

        public doubleNode(T Data)
        {
            this.Data = Data;
        }
    }
    public class DoubleLinkedList<T>
    {
        doubleNode<T> head;
        doubleNode<T> tail;
        public int count { get; private set; }

        public void Add(T data)
        {
            doubleNode<T> node = new doubleNode<T>(data);

            if (head == null)
                head = node;
            else
            {
                tail.Next = node;
                node.Previous = tail;
            }
            tail = node;
            count++;
        }

        public void AddFirst(T data)
        {
            doubleNode<T> node = new doubleNode<T>(data);
            doubleNode<T> temp = head;
            node.Next = temp;
            head = node;

            if (count == 0)
                tail = head;
            else
                temp.Previous = node;


            count++;
        }

        public bool Remove(T data)
        {
            doubleNode<T> current = head;

            while (current != null)
            {
                if (current.Data.Equals(data))
                {
                    break;
                }
                current = current.Next;
            }
            if (current != null)
            {
                if (current.Next != null)
                {
                    current.Next.Previous = current.Previous;
                }
                else
                {
                    tail = current.Previous;
                }

                if (current.Previous != null)
                {
                    current.Previous.Next = current.Next;
                }
                else
                {
                    head = current.Next;
                }
                count--;
                return true;
            }
            return false;
        }
        public void Destroy()
        {
            head = null;
            tail = null;
            count = 0;
        }
        public void Show()
        {
            doubleNode<T> current = head;

            for (int i = 1; i <= count; i++)
            {
                Console.WriteLine($"{i}. {current.Data}");
                current = current.Next;
            }
        }
    }
    class task_2
    {
        static void Main(string[] args)
        {
            DoubleLinkedList<int> list = new DoubleLinkedList<int>();
            list.Add(1);
            list.Add(3);
            list.Add(12);
            list.Add(7);
            list.Add(17);
            list.AddFirst(99);
            list.Add(15);
            list.Add(18);
            list.Remove(7);
            list.Show();
            list.Destroy();
            list.Show();
        }
    }
}