#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
int m,n;
ios::sync_with_stdio(false); cin.tie(0);
while(cin >> n >> m && n != 0 && m != 0){
	int money = 0;
	int k = 0;
	int l = 0;
	vector<int> heads;
	vector<int> knights;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		heads.push_back(x);
	}
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		knights.push_back(x);
	}
	sort(heads.begin(),heads.end());
	sort(knights.begin(),knights.end());

	while(k < n && l < m){
		while(heads[k] > knights[l] && l < m) l++;
		if(l == m) break;
		money+= knights[l];
		k++;
		l++;
	}
	if(k == n) cout << money << endl;
	else cout << "Loowater is doomed!" << endl;
}
}
