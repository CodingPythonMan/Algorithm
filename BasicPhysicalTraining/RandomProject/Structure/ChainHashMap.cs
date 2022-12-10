using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Structure
{
    public class Entry
    {
        public int key;
        public int value;

        public Entry() { }
        public Entry(int key, int value) { this.key = key; this.value = value; }
    }

    public class ChainHashMap
    {
        protected int capacity;
        private long scale, shift;
        private int prime;

        List<List<Entry>> table = new();

        public ChainHashMap(int cap, int p)
        {
            prime = p;
            capacity = cap;
            Random rand = new Random();
            scale = rand.Next(1, prime-1) + 1;
            shift = rand.Next(1, prime);
        }
        public ChainHashMap(int cap) : this(cap, 109345121) { }
        public ChainHashMap() : this(17){}

        public int? Get(int key)
        {
            return EntryGet(Hash(key));
        }

        public int? EntryGet(int key)
        {
            Entry entry = table[key][key];
            if(entry == null)
            {
                return null;
            }
            else
            {
                return entry.value;
            }
        }

        public void Put(int key, int value)
        {
            //table.Add(new Entry(Hash(key), value));
            BucketPut(key, value);   
        }

        public void BucketPut(int key, int value)
        {
            List<Entry> bucket = table[Hash(key)];
            if(bucket == null)
            {
                table[key] = bucket = new List<Entry>();
            }
            int oldSize = bucket.Count;
            // key 가 중복되면 Overwrite 하는 방법...
            // 그건 기존에 배열에 값을 넣으면 Overwrite 가 
            // 됐었다... 
            
            bucket.Add(new Entry(key, value));
        }

        public void Remove(int key)
        {

        }

        public int Hash(int key)
        {
            int hash = (int)((Math.Abs(key.GetHashCode() * scale + shift) % prime) % capacity);
            return hash;
        }
   
        public bool Contains(int key)
        {

        }

        public int Size()
        {
            return table.Count;
        }
    }
}
