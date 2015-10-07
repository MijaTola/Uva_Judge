#include <iostream>
#include <math.h>
#include <vector>
#include <climits>
using namespace std;
vector<int> pi;
vector<int> pj;
vector<int> px;
vector<int> py;
vector<int> ansi;
vector<int> ansj;
void fill(int m);
int solve(int m);
int main(){
	int m;
	while (cin >> m){
		pi.clear();
		pj.clear();
		px.clear();
		py.clear();
		ansi.clear();
		ansj.clear();
	fill(m);
	int c = solve(m);
	cout << c << endl;
}
}
void fill(int m){
	string input; 
	for (int i = 0; i < m; i++) { 
 			cin >> input; 
 			for (int y = 0, sz = input.size(); y < sz; y++) { 
 				if (input[y] == '1') 
 				{
 					pi.push_back(i);
 					pj.push_back(y);
 				}
 				else if (input[y] == '3') 
 				{
 					px.push_back(i);
 					py.push_back(y); 
 				}
 			} 
 		}
}
int solve(int m){
		int distance = -1; 
 		for (int i = 0, sz = pi.size(); i < sz; i++) { 
 			int max = -1; 
 			for (int y = 0, sz2 = py.size(); y < sz2; y++) { 
 				int a=(abs(pi[i] - px[y]));
				int b=(abs(pj[i]-py[y]));
				int manhattan = a + b;
 				if (max == -1) 
 					max = manhattan; 
 				else if (manhattan < max) 
 					max = manhattan; 
 			} 
 			if (distance == -1) 
 				distance = max; 
 			else if (max > distance) 
 				distance = max; 
 		} 
	return distance;
}