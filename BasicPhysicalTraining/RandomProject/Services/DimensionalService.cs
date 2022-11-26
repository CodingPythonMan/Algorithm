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

            int zeroCount = 0;
            for(int i=0; i<array.GetLength(0); i++)
            {
                for(int j=0; j<array.GetLength(1); j++)
                {
                    if(zeroCount >= 6)
                    {
                        array[i, j] = random.Next(1, 11);
                    }
                    zeroCount++;
                }
            }

            shuffle(array);

            for (int i = 0; i < array.GetLength(0); i++)
            {
                for (int j = 0; j < array.GetLength(1); j++)
                {
                    Console.Write("{0} ", array[i, j]);
                }
                Console.WriteLine();
            }
        }

        public void shuffle(int[,] deck)
        {
            for (int i = 0; i < 16; i++)
            {
                int rand = random.Next(0, 4);
                int rand2 = random.Next(0, 4);
                int rand3 = random.Next(0, 4);
                int rand4 = random.Next(0, 4);

                int temp = deck[rand,rand2];
                deck[rand, rand2] = deck[rand3, rand4];
                deck[rand3, rand4] = temp;
            }
        }
    }
}
