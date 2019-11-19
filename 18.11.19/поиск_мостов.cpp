//поиск вершины, содержащей 3 моста
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int const n = 10; // chislo vershin v grafe
int timer, tin[n], fup[n];
bool used[n];
int mx[n][n] = {
	{	0, 1, 1, 0, 0, 0, 1, 0, 0, 0 },
{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
{1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
{0, 0, 0, 0, 0, 0, 0, 1, 1, 0} };

vector <int> dfs (int v, vector <int> &result, int p = -1) // poisk v glubinu
{
	//vector <int> result;
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < n; ++i)
	{
		if (mx[v][i] == 1)
		{
			int to = i;
			if (to == p) continue;
			if (used[to]) fup[v] = std::min(fup[v], tin[to]);
			else
			{
				dfs(to, result, v);
				fup[v] = std::min(fup[v], fup[to]);
				if (fup[to] > tin[v]) {
					result.push_back(v);
					result.push_back(to);
					std::cout << "мосты: (" << v << " , " << to << ")\n";
				}
			}
		}
		
	}
	return result;
}

vector <int>  find_bridges() // poisk mostov
{
	vector <int> result;
	timer = 0;
	for (int i = 0; i < n; ++i)
	{
		used[i] = false;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])  result = dfs(i, result);
	}
	vector <int> result_new;
	for (int i = 0; i < result.size(); i = i + 2) {
		if (i == 0) {
			result_new.push_back(result[i]);
			result_new.push_back(result[i + 1]);
		}
		else {
			if (result[i] != result[0] || result[i + 1] != result[1]) {
				result_new.push_back(result[i]);
				result_new.push_back(result[i + 1]);
			}
		}
	}
	return result_new;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector <int> result;
	result = find_bridges();
	
	cout << endl << endl << "Изгнание неугодных ";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	vector <int> kurlik;
	
	for (int i = 0; i < result.size(); i++) {
		int count = 0;
		for (int j = 0; j < result.size(); j++) {
			if (result[i] == result[j])
				count++;
		}
		if (count == 3)
			kurlik.push_back(result[i]);
	}

	
	kurlik.erase(unique (kurlik.begin(), kurlik.end()), kurlik.end());

	cout << endl << "На этом все ";

	for (int i = 0; i < kurlik.size(); i++) {
		cout << kurlik[i] << " ";
	}
	return 0;
}
