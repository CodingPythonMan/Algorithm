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

            if (num < 0 || num > 100)
            {
                return;
            }

            int[] deck = new int[100];
            for(int i=0; i<deck.Length; i++)
            {
                deck[i] = i;
            }

            shuffle(deck);

            for(int i=0; i < num; i++)
            {
                Console.WriteLine("array[{0}] : {1}", i, deck[i]);
            }
        }

        public void shuffle(int[] deck)
        {
            for(int i=0; i<deck.Length; i++)
            {
                int rand = random.Next(0, 100);
                int rand2 = random.Next(0, 100);

                int temp = deck[rand];
                deck[rand] = deck[rand2];
                deck[rand2] = temp;
            }
        }
    }
}
