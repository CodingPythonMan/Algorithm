using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace RandomProject.Structure.Map
{
    public class ChainHashMap
    {
        protected int n;
        protected int capacity;
        private long scale, shift;
        private int prime;

        UnsortedTableMap[] table = null!;

        public ChainHashMap(int cap, int p)
        {
            prime = p;
            capacity = cap;
            Random rand = new Random();
            scale = rand.Next(1, prime-1) + 1;
            shift = rand.Next(1, prime);
            CreateTable();
        }

        public ChainHashMap(int cap) : this(cap, 109345121) { }
        public ChainHashMap() : this(17){}

        public void CreateTable()
        {
            table = new UnsortedTableMap[capacity];
        }

        public int? Get(int key)
        {
            return EntryGet(Hash(key), key);
        }

        public int? EntryGet(int hash, int key)
        {
            UnsortedTableMap bucket = table[hash];
            if(bucket is null)
            {
                return null;
            }
            else
            {
                return bucket.Get(key);
            }
        }

        public int Put(int key, int value)
        {
            int answer = BucketPut(Hash(key), key, value);   
            if(n > capacity / 2)
            {
                Resize(2 * capacity - 1);
            }
            return answer;
        }

        public int BucketPut(int hash, int key, int value)
        {
            UnsortedTableMap bucket = table[hash];
            if(bucket == null)
            {
                table[key] = bucket = new UnsortedTableMap();
            }
            int oldSize = bucket.Size();
            int answer = bucket.Put(key, value);
            n += (bucket.Size() - oldSize);

            return answer;
        }

        public int Remove(int key)
        {
            return BucketRemove(Hash(key), key);
        }

        public int BucketRemove(int hash, int key)
        {
            UnsortedTableMap bucket = table[hash];
            if(bucket is null)
            {
                return 0;
            }
            int oldSize = bucket.Size();
            int answer = bucket.Remove(key);
            n -= (oldSize - bucket.Size());
            return answer;
        }

        public int Hash(int key)
        {
            int hash = (int)((Math.Abs(key.GetHashCode() * scale + shift) % prime) % capacity);
            return hash;
        }
   
        public bool Contains(int key)
        {
            if(Get(key) is null)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        public int Size() { return n; }

        private void Resize(int newCapacity)
        {
            capacity = newCapacity;
        }
    }
}
