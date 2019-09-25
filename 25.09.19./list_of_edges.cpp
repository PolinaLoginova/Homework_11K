#include <iostream>

using namespace std;

// как я поняла, их лучше объявять глобальными переменными
int n; // кол-во вершин
int m; // кол-во ребер

int main()
{
cout << "Write numder of verchin" << endl; // я не помню как вершина по английски
cin >> n;
cout << "Write numder of edges" << endl; 
cin >> m;

int *array1 = new int[m];
int *array2 = new int[m];

for (int i=0; i<m; i++)
{
cout << "Write pair of verchin, who have a edge between them" << endl;
cin >> array1[i];
cin >> array2[i];
}

cout << endl;
cout << n << ", " << m << endl; // выводит кол-во вершин и ребер

for (int i=0; i<m; i++) // выводит пары вершин
{
cout << array1[i] << ", " << array2[i] << endl;
}

return 0;
}
