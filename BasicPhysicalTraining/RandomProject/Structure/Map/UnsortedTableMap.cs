using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Structure.Map
{
    public class Entry
    {
        public int key;
        public int value;

        public Entry() { }
        public Entry(int key, int value) { this.key = key; this.value = value; }
    }

    public class UnsortedTableMap
    {
        private List<Entry> table = new();

        private int FindIndex(int k)
        {
            for(int i=0; i<table.Count; i++)
            {
                if (table[i].key.Equals(k))
                    return i;
            }
            return -1;
        }

        public int Size()
        {
            return table.Count;
        }

        public int? Get(int key)
        {
            int index = FindIndex(key);
            if (index == -1)
            {
                return null;
            }
            return table[index].value;
        }

        public int Put(int key, int value)
        {
            int index = FindIndex(key);
            if(index == -1)
            {
                table.Add(new Entry(key, value));
                return 1;
            }
            else
            {
                return 0;
            }
        }

        public int Remove(int key)
        {
            int index = FindIndex(key);
            if (index == -1)
                return 0;
            if (index != Size() - 1)
                table[index] = table[Size() - 1];
            table.RemoveAt(index);
            return index;
        }
    }
}
