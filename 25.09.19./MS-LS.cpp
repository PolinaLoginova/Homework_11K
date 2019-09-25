#include <iostream>
using namespace std;
int n;
int m;

int* MS_LE(int **array, int *array1, int *array2)
{
//создаю переменную-счетчик 
    int count = 0;
    
//переделываю матрицу в список
for (int i=0; i<n; i++)
 {
     for (int j=0; j<i; j++)
     {
         if(array[i][j] == 1)
         {
             array1[count] = i;
             array2[count] = j;
             count++;
         }
     }
 }



return array1;
return array2;
};

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

// создаю заготовку под возвращаемыу массивы со списком ребер
int *array1 = new int[m];
int *array2 = new int[m];

MS_LE(array, array1, array2);

for (int i=0; i<m; i++) // выводит пары вершин
{
cout << array1[i] << ", " << array2[i] << endl;
}


return 0;
}
