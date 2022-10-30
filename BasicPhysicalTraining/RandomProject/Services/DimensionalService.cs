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
            fourfour();
        }

        public void fourfour()
        {
            int[,] array = new int[4, 4];
            for(int i=0; i<array.Length; i++)
            {
                for(int j=0; j < array.Length; j++)
                {
                    Console.WriteLine("{0}, {1}", i, j);
                    array[i, j] = random.Next(1, 11);
                    Console.Write("{0} ", array[i ,j]);
                }
                Console.WriteLine();
            }
        }
    }
}
