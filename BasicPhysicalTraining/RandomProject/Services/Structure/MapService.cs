using RandomProject.Structure.Map;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Services.Structure
{
    public class MapService
    {
        public void Start()
        {
            ChainHashMap chainHashMap = new ChainHashMap();
            chainHashMap.Put(1, 3);
            chainHashMap.Put(2, 3);
            chainHashMap.Put(3, 3);
            chainHashMap.Put(4, 3);

            Console.WriteLine(chainHashMap.Contains(3));
            Console.WriteLine(chainHashMap.Contains(6));
        }
    }
}
