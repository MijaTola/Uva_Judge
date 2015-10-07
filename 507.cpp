#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll b,r;
	cin >> b;
	int k = 1;
	while(b--){
		cin >> r;
		int n = r-1;
		int p = -1;
		int q = -1;
		ll ansmax = INT_MIN;
		ll sum = 0;
		int aux = 0;
		for (int i = 0; i < n; ++i)
		{
			int c;
			cin >> c;
			sum += c;
			if(sum < 0){
				sum = 0;
				aux = i + 1; 
			}
			if(ansmax < sum){
				ansmax = sum;
				p = aux;
				q = i;
			}else if(ansmax == sum){
				if(q-p < i - aux || (q-p==i-aux && p>aux)){
					p = aux;
					q = i;
				}
			}
		}
		if(ansmax == 0) cout << "Route "<<k<<" has no nice parts" << endl;
		else cout << "The nicest part of route "<< k <<" is between stops " <<p+1<< " and " <<q+2 <<endl;
		k++;
	}
	return 0;
}