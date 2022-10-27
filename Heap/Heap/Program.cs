using System.Numerics;
using System;
using System.Collections.Generic;
using System.Collections;

namespace Heap
{
    public class Heap
    {
        List<int> list = new List<int>();

        public void Add(int value)
        {
            list.Add(value);
            int last = list.Count - 1;

            // Heap Order 구현
            while (list[last] < list[last / 2])
            {
                int temp = list[last];
                list[last] = list[last / 2];
                list[last / 2] = temp;
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
                int child1 = index * 2 + 1;
                int child2 = index * 2 + 2;

                if(child1 < child2)
                {

                }

                // 자식 비교
                if (list[child1] > list[child2])
                {
                    // 작은 자식이 부모와 비교
                    if (list[index * 2 + 2] < list[index])
                    {
                        int temp = list[index*2 + 2];
                        list[index* 2] = list[last*2 + 1];
                        list[last*2+1] = temp;
                    }
                }

                int temp = list[last];
                list[last] = list[last / 2];
                list[last / 2] = temp;
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