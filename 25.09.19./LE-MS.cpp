#include <iostream>
using namespace std;
int n;
int m;
int** change_grom_lE_to_MS( int *array1, int *array2, int **array)
{
// заполним  новую матрицу смежности нулями
 for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
          array[i][j] = 0;
     }
 }
 
 for (int i=0; i<m; i++) 
 {
     int a;
     int b;
     a = array1[i];
     b = array2[i];
     array[a][b] = 1;
     array[b][a] = 1;
 }
return array; 
}; 

int main() 
{
cout << "Write numder of verchin" << endl; // я не помню как вершина по английски
cin >> n;
cout << "Write numder of edges" << endl; 
cin >> m;

int *array1 = new int[m];
int *array2 = new int[m];

//создаю и заполняю список ребер
for (int i=0; i<m; i++)
{
cout << "Write pair of verchin, who have a edge between them" << endl;
cin >> array1[i];
cin >> array2[i];
}

// создаю заготовку под возвращаемую таблицу
int **array = new int*[n];
 for (int i=0; i<n; i++)
     array[i] = new int[n];
 
change_grom_lE_to_MS(array1, array2, array); // запускаю смену списка на матрицу

for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
         cout << array[i][j];
    }
    cout << endl;
 }
return 0;
}
