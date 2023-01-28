using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services
{
    public class RecursiveService
    {
        public void Start()
        {
            ReversePrint("abcd");
        }

        public void ReversePrint(string str)
        {
            if(str.Length > 0)
            {
                ReversePrint(str.Substring(1, str.Length - 1));
                Console.Write(str[0]);
            }
        }
    }
}
