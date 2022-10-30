using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class ArrayService
    {
        Random random = new();
        public void Start()
        {
            //AverageArray();
            NotSameArray();
        }

        public void AverageArray()
        {
            int[] array = new int[10];
            double sum = 0;

            for(int i=0; i<array.Length; i++)
            {
                array[i] = random.Next(1, 11);
                Console.WriteLine("array[{0}] : {1}",i, array[i]);
                sum += array[i];
            }

            Console.WriteLine("array 평균 : {0}", sum / array.Length);
        }

        public void NotSameArray()
        {
            Console.Write("몇 개 배열을 선언하시겠습니까?(1~100) : ");
            int num = int.Parse(Console.ReadLine()!);
            int[] array = null!;

            if(num > 0 || num < 101)
            {
                array = new int[num];
            }

            for(int i=0; i < array.Length; i++)
            {
                array[i] = random.Next(1, 101);
            }
        }
    }
}
