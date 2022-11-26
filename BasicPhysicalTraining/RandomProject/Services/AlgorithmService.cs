using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class AlgorithmService
    {
        /* 자릿수 합 문제
         * 
         * public int solution(int N)
        {
            // N 은 1이상 5만 이하
            int n = N;
            int NdigitSum = digitSum(N);

            while(true)
            {
                n++;
                if(NdigitSum == digitSum(n))
                {
                    break;
                }
            }

            return n;
        }

        public int digitSum(int N)
        {
            int result = 0;
            int a = N;
            while (true)
            {
                if (a == 0)
                {
                    break;
                }
                else
                {
                    result += (a % 10);
                }
                a /= 10;
            }

            return result;
        }*/

        public int solution(int[] music)
        {
            int result = 0;

            HashSet<int> blackSet = new() {2,4,6,9,11 };
            HashSet<int> whiteSet = new() {1,3,5,7,8,10,12 };

            // 검은색...인지 흰색인지?


            for(int i=0; i<music.Length; i++)
            {
                                
            }

            return result;
        }
    }
}
