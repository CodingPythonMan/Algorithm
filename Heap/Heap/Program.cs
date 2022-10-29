using System.Numerics;
using System;
using System.Collections.Generic;
using System.Collections;

namespace Heap
{
    public class Heap
    {
        List<int> list = new List<int>();

        public int left(int i) { return 2 * i + 1; }
        public int right(int i) { return 2 * i + 2; }
        public bool hasLeft(int i) { return left(i) < list.Count; }
        public bool hasRight(int i) { return right(i) < list.Count; }
        public void swap(int i, int j) 
        {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }  

        public void Add(int value)
        {
            list.Add(value);
            int last = list.Count - 1;

            // Heap Order 구현
            while (list[last] < list[last / 2])
            {
                swap(last, last / 2);
            }
        }

        public int Min()
        {
            return list.First();    
        }

        public int Size()
        {
            return list.Count;
        }

        public void Remove()
        {
            int last = list.Count - 1;
            list[0] = list[last];
            list.RemoveAt(last);

            // Heap Order 구현
            int index = 0;
            while(index < list.Count)
            {
                
            }
        }

        public void Print()
        {
            foreach(int value in list)
            {
                Console.WriteLine(value);
            }
        }
    }

    class Program
    {
        static void Main()
        {
            // array based complete binary tree 형태로, min, size, add, remove 메소드 구현
            Heap heap = new Heap();
            heap.Add(5);
            heap.Add(2);
            heap.Add(4);
            heap.Add(8);
            heap.Add(10);
            heap.Add(9);
            heap.Add(3);
            heap.Add(13);
            heap.Add(7);
            heap.Print();

            Console.WriteLine("=========Remove ===========");
            heap.Remove();
            heap.Print();

            Console.WriteLine("=========Remove ===========");
            heap.Remove();
            heap.Print();

            Console.WriteLine("=========Min ===========");
            Console.WriteLine(heap.Min());
        }
    }
}