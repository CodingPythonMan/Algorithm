using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Random.Services
{
    public class RandomService
    {
        public void Start()
        {
            UpAndDown();
        }

        void UpAndDown()
        {
            int goal = Random.Next(0, 100);
        
            while(true)
            {
                Console.WriteLine("숫자를 입력하세요 (0 ~ 100) : ");
                int num = int.Parse(Console.ReadLine()!);

                if(num < 0 || num > 100)
                {
                    Console.WriteLine("범위에 벗어난 숫자입니다.");
                }

                
            }
        }
    }
}
