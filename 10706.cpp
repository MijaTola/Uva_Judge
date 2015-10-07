#include <iostream>
#include <vector>
#include <math.h>
#include <climits>
#include <vector>
#include <sstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	long long k;
	cin >> t;
	vector<long long> sum;
	vector<long long> value;
	sum.push_back(0);
	value.push_back(0);
	for (int i = 1;sum[i-1] < INT_MAX; ++i)
	{
		value.push_back(0);
		sum.push_back(0);
		value[i] = value[i-1] +log10(i)+1;
		sum[i] = sum[i-1]+value[i];
	}	
	for (int i = 0; i < t; ++i)
	{
		cin >> k;
		int a = -1,b = sum.size();
		while(b - a > 1){
		int mid = (a+b)>>1;
		if(sum[mid] >= k) b = mid;
		else a = mid;
	}	
	long long x = k - sum[a];
	stringstream ss;
	string word = "";
	long long nd = log10(x);
	long long aux =nd+1;
	nd = pow(10,nd);	
	long long ii = 1;
	long long count = 1;
	while(count <=x+10){
		ss << ii;
		ii++;
		word = ss.str();
		count += log10(ii)+1;
	}
	cout << word.at(x-1)<<endl;
}
	return 0;
}

	