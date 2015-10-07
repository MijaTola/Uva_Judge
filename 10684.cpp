#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n != 0){
		int sum = 0;
		int ans = 0;
		while(n--){
			int c;
			cin >> c;
			sum += c;
			ans = max(ans,sum);
			if(sum < 0) sum = 0;
		}
		if(ans==0) cout << "Losing streak."<< endl;
		else cout << "The maximum winning streak is " <<ans<<"."<<endl;
	}
	return 0;
}