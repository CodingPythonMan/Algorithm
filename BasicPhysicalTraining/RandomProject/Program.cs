using RandomProject.Services;

//RandomService randomService = new();
//ArrayService arrayService = new();
//DimensionalService dimenService = new();
AlgorithmService algorithmService = new();

//randomService.Start();
//arrayService.Start();
//dimenService.Start();
/*int N1 = 28;
int N2 = 734;
int N3 = 1990;
int N4 = 1000;

int result1 = algorithmService.solution(N1);
int result2 = algorithmService.solution(N2);
int result3 = algorithmService.solution(N3);
int result4 = algorithmService.solution(N4);
Console.WriteLine(result1);
Console.WriteLine(result2);
Console.WriteLine(result3);
Console.WriteLine(result4);W*/

int[] music = new int[] { 10, 9, 4, 5, 12 };
algorithmService.solution(music);