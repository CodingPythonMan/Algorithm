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
            List<int> list = new List<int>();

            while(list.Count < 10)
            {
                int num = random.Next(0, 16);
                if (!list.Contains(num))
                {
                    list.Add(num);

                    int row = num / 4;
                    int col = num % 4;
                    array[row, col] = random.Next(1, 11);
                }
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
    }
}
