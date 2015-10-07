#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> myVector;
vector<int> sum;
vector<int> query;
int c;
void fill(int n);
void Sums(int n);
void Answer(int n);

int main(){
 c = 0;
 int n,p;
 p = 1;
 do{cin >> n;
	if(n != 0){
	fill(n);
	Sums(n); 
	cout << "Case "<< p << ":" << "\n";
	Answer(n);
	p++;
	}
 }while(n != 0);
 }

void fill(int n){
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
			
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		query.push_back(x);
	}
}
void Sums(int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			sum.push_back(myVector[i] + myVector[j]);
		}
	}
}
void Answer(int n){
 for (int i = 0; i < query.size(); ++i){
	int Answer = INT_MAX;
	int x = 0;
	for (int j = 0; j < sum.size(); ++j)
	{
		if(abs(sum[j] - query[i]) <  Answer){
			Answer = abs(sum[j] - query[i]);
			x = sum[j];
		}
	}
	cout << "Closest sum to "<< query[i] << " is " << x << ".\n";
 }
	myVector.clear();
	sum.clear();
	query.clear();
}