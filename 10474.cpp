#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, q;
	vector<int> v;
	int c = 0;
	while(cin >> n >> q && n != 0 || q != 0){
	v.clear();
	c++;
	for (int i = 0; i < n; ++i)
	{	int x;
		cin >> x; 
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << "CASE# "<<c<<":"<<endl;
	for (int i = 0; i < q; ++i)
	{
		int t;
		cin >> t;
		int b = n;
		int a = -1;
		int bus = t;
		while(b-a>1){
 			int mid = (a+b)>>1;
 			if(v[mid]>=bus)b=mid;
 			else a=mid;
 		}	
 		if(b!=n&&v[b]==t)cout<<t<<" found at "<<b+1<<endl;
			else cout<<t<<" not found"<<endl;
	}
	}
}