# Algorithm
- Heap 구현<br>
Heap Order 구현했으므로 Add 한 첫 부분부터 잘 배열된게 보임<br>
![image](https://user-images.githubusercontent.com/27558778/198823806-d24565e8-42f0-4cb3-9d76-a6c48afb1a6d.png)
```
static void Main()
{
    // array based complete binary tree 형태로, min, size, add, remove 메소드 구현
    Heap heap = new Heap();
    heap.Add(5);
    heap.Add(2);
    heap.Add(4);
    heap.Add(8);
    heap.Add(10);
    heap.Add(9);
    heap.Add(3);
    heap.Add(13);
    heap.Add(7);
    heap.Print();

    Console.WriteLine("=========Remove ===========");
    heap.Remove();
    heap.Print();

    Console.WriteLine("=========Remove ===========");
    heap.Remove();
    heap.Print();

    Console.WriteLine("=========Min ===========");
    Console.WriteLine(heap.Min());
}
```
- Map 구현 <br>
