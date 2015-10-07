#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, t;
	cin >> t;
	for (int p = 0; p < t; ++p)
	{
	cin >> n; 	
	vector<int> v;
	int maxdif = 1;
	v.push_back(0);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;	
		int dif = x - v[i-1];
		if(dif > maxdif)
			maxdif = dif;
		v.push_back(x);
	}
	int aux = maxdif;
	for (int i = 1; i <  v.size(); ++i)
	{
		if(v[i] - v[i-1] > maxdif)
		{
			aux++;
			break;
		}	
		if(v[i] - v[i-1] == maxdif)
			maxdif--;
	}
	cout <<"Case "<< p+1 <<": "<<aux<< endl;
}		
}