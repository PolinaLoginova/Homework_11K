#include<iostream>
using namespace std;
// как я поняла, их лучше объявять глобальными переменными
int n; // кол-во вершин
int m; // кол-во ребер

int* findHamiltonianCycle(int** array1, int* circle)
{
 for (int i=0; i<n; i++)
     circle[i] = i;
 // это я создала масиив (вместо той непонятной очереди, ибо хочу) и заполнила его вершинами, ибо могу
int start = 0; // "указатель" на начало массива
int end = n;  // "указатель" на конец массива 
 for (int k = 0; k <= n*(n-1); k++)
 {
     if (array1[start][ start + 1] == 1) 
        {  
            end = start;  
            start++; // тут нужно подвинуть массив на один элемент,поставив первый элемент в конец, по идее, так оно должно работать 
        }
     else 
     {   
         int i=2;
         while (array1[start][ i] != 1 && array1[start+1][ i+1])
             i++;
         for (int j=0; j<((i-start-1)/2); j++)
         {
             swap(circle[start+1+j], circle[i-j]); // меняю местами пары элементов, в итоге этот кусочек как бы разворачивается
         }
     }
       // в итоге у меня массив оказывается отсортирован в порядке Гамильтонова цикла   
 }
 
 for (int i = 0; i<n; i++)
 {
     cout << circle[i] << " ";
 }
 
return circle; // на будущее, а так можно было и не возвращать ничего, на самом то деле
};

int main()
{
cout << "Write numder of verchin" << endl; // я не помню как вершина по английски
cin >> n;
cout << "Write numder of edges" << endl; 
cin >> m;
// создаю двумерный динамический массив под таблицу
int **array1 = new int*[n];
 for (int i=0; i<n; i++)
     array1[i] = new int[n];
// заполним матрицу смежности с клавиатуры
 for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
         cout << "If verchina " << i << " cmegna c vernoj " << j << " write 1, if not - write 0" << endl;/* что бы удобнее было вводить, это можно закомментить и вводить просто по строчкам через пробел*/
         cin >> array1[i][j];
     }
 }
 //визиулизируем получившуюся матрицу
 for (int i=0; i<n; i++)
 {
     for (int j=0; j<n; j++)
     {
         cout << array1[i][j];
    }
    cout << endl;
 }
// теперь у вас есть матрица, поздравляю! 
// создаю заготовку под "очередь"
int **circle = new int*[n];
 for (int i=0; i<n; i++)
     circle[i] = new int[n];
findHamiltonianCycle(array1, *circle);
return 0;
}
