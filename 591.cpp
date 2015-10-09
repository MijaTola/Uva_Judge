#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	int c = 1;
	while(cin >> n && n != 0){
		int piles[60];
		int sum = 0,x;
		for (int i = 0; i < n; ++i)
		{
			cin >> piles[i];
			sum += piles[i];
		}
	
		int t = sum/n;
		int ans = 0;
		for (int i = 0; i < n; ++i){
			if(piles[i] > t)
				ans+=piles[i] - t;
		}
		cout << "Set #" <<c << endl;
		cout <<"The minimum number of moves is " <<ans<<"." << endl;
		cout << endl;
		c++;
	}
		return 0;
}