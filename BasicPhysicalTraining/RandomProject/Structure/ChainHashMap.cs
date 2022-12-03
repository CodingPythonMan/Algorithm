using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Structure
{
    public class Entry
    {
        int key;
        int value;

        public Entry() { }
        public Entry(int key, int value) { this.key = key; this.value = value; }
    }

    public class ChainHashMap
    {
        List<Entry> table = new();

        void Get(int key)
        {
            // Get 을 할 때 key 로 구해올 수 있게 해야한다.

        }

        void Add(int key, int value)
        {
            table.Add(new Entry(key, value));
        }

        void Remove(int key)
        {

        }

        /*
        int Contains(int key)
        {

        }

        int Size()
        {

        }*/
    }
}
