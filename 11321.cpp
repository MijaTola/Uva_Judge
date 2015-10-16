#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool sorted(int a, int b){
	if(a%m != b%m) return	a%m < b%m;
	else{
		if(abs(a)%2== 0 && abs(b)%2==0) return a<b;
		else if(abs(a)%2!=0 && abs(b)%2!=0) return a>b;
		else if(abs(a)%2!=0) return true;
		else return false;
	}
}

int main(){
	ios:: sync_with_stdio(false); cin.tie(0);
	while(cin >> n >>  m){
		cout << n << " " << m <<endl;
		if(n == 0 && m == 0) break;
		int x;
		vector<int> list;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			list.push_back(x);
		}
		sort(list.begin(),list.end(),sorted);	
		for (int i = 0; i < list.size(); ++i) cout << list[i] <<endl;	
	}
	return 0;
}
