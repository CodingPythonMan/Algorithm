using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class DimensionalService
    {
        Random random = new();
        public void Start()
        {
            //setRandomArray();
            setZeroToSix();
        }

        public void setRandomArray()
        {
            int[,] array = new int[4, 4];
            for (int i = 0; i < array.GetLength(0); i++)
            {
                for (int j = 0; j < array.GetLength(1); j++)
                {
                    array[i, j] = random.Next(1, 11);
                    Console.Write("{0} ", array[i, j]);
                }
                Console.WriteLine();
            }
        }

        public void setZeroToSix()
        {
            int[,] array = new int[4, 4];
            int[] deck = new int[16];

            for (int i = 0; i < deck.Length; i++)
            {
                deck[i] = i;
            }

            shuffle(deck);

            for (int i = 0; i < array.GetLength(0); i++)
            {
                for (int j = 0; j < array.GetLength(1); j++)
                {
                    array[i, j] = random.Next(1, 11);
                }
            }

            for (int i = 0; i <deck.Length; i++)
            {
                array[deck[i]] = 0;
            }

            for (int i = 0; i < array.GetLength(0); i++)
            {
                for (int j = 0; j < array.GetLength(1); j++)
                {
                    Console.Write("{0} ", array[i, j]);
                }
                Console.WriteLine();
            }
        }

        public void shuffle(int[] deck)
        {
            for (int i = 0; i < deck.Length; i++)
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
