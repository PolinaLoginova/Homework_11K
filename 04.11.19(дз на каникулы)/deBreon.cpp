// C++ implementation of 
// the above approach 
#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 

unordered_set<string> seen; 
vector<int> edges; 


void dfs(string node, int& k, string& A) 
{ 
	for (int i = 0; i < k; ++i) { 
		string str = node + A[i]; 
		if (seen.find(str) == seen.end()) { 
			seen.insert(str); 
			dfs(str.substr(1), k, A); 
			edges.push_back(i); 
		} 
	} 
} 

s 
string deBruijn(int n, int k, string A) 
{ 

 
	seen.clear(); 
	edges.clear(); 

	string startingNode = string(n - 1, A[0]); 
	dfs(startingNode, k, A); 

	string S; 


	int l = pow(k, n); 
	for (int i = 0; i < l; ++i) 
		S += A[edges[i]]; 
	S += startingNode; 

	return S; 
} 

 
int main() 
{ 
	int n, k; // длина слова и алфавита
	string A;
    
    cin >> n >> k;
    
    if(k == 1) A = "0";
    if(k == 2) A = "01";
    if(k == 3) A = "012";
    if(k == 4) A = "0123";
    if(k == 5) A = "01234";
    if(k == 6) A = "012345";
 
	cout << deBruijn(n, k, A); 

	return 0; 
} 
