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
// создаю двумерный динамический массив под таблицу
 int **array = new int*[n];
 for (int i=0; i<n; i++)
     array[i] = new int[n];
    cout << endl;
 
 
 // заполним матрицу смежности с клавиатуры
 for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
         cout << "If verchina " << i << " cmegna c vernoj " << j << " write 1, if not - write 0" << endl;
         cin >> array[i][j];
     }
 }
 
 //визиулизируем получившуюся матрицу
 for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
         cout << array[i][j];
    }
 }
 
return 0;
} 
