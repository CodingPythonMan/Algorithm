using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class RandomService
    {
        Random random = new();

        public void Start()
        {
            //UpAndDown();
            Gugudan();
        }

        void UpAndDown()
        {
            int goal = random.Next(0, 101);

            while(true)
            {
                Console.Write("숫자를 입력하세요 (0 ~ 100) : ");
                int num = int.Parse(Console.ReadLine()!);

                if(num < 0 || num > 100)
                {
                    Console.WriteLine("범위에 벗어난 숫자입니다.");
                }

                if(goal > num)
                {
                    Console.WriteLine("Up");
                }
                else if(goal < num)
                {
                    Console.WriteLine("Down");
                }
                else
                {
                    Console.WriteLine("정답입니다.");
                    break;
                }
            }
        }
        
        void Gugudan()
        {
            int dan = random.Next(2, 10);
            int d = random.Next(2, 10);

            for(int i=0; i<3; i++)
            {

            }
        }
    }
}
