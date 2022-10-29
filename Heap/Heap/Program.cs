using System.Numerics;
using System;
using System.Collections.Generic;
using System.Collections;

namespace Heap
{
    public class Heap
    {
        List<int> list = new List<int>();

        public int Left(int i) { return 2 * i + 1; }
        public int Right(int i) { return 2 * i + 2; }
        public int Parent(int i) { return i / 2; }
        public int Last() { return list.Count - 1; }
        public bool HasLeft(int i) { return Left(i) < list.Count; }
        public bool HasRight(int i) { return Right(i) < list.Count; }
        public void Swap(int i, int j) 
        {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }  

        public void Add(int value)
        {
            list.Add(value);

            // Heap Order 구현
            int index = Last();
            while(Parent(index) > 0)
            {
                if (list[Parent(index)] > list[index])
                {
                    Swap(Parent(index), index);
                    index = Parent(index);
                }
                else
                {
                    break;
                }
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
            int last = Last();
            list[0] = list[last];
            list.RemoveAt(last);

            // Heap Order 구현
            int index = 0;
            while(HasLeft(index))
            {
                int lessChild = 0;
                if (list[index] > list[Left(index)])
                {
                    lessChild = Left(index);
                }

                if (HasRight(index) && (list[Left(index)] > list[Right(index)]))
                {
                    lessChild = Right(index);
                }

                if(lessChild != 0)
                {
                    Swap(index, lessChild);
                    index = lessChild;
                }
                else
                {
                    break;
                }
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