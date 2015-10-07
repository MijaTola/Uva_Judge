#include <iostream>
#include <cstring>
using namespace std;

int dp[10100];
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int m,n,t;

	while(cin >> m >> n >> t){
		memset(dp,-1,sizeof dp);
		dp[t] = 0; //base case
		for (int i = t; i >= 0; --i)
		{
			if(dp[i] == -1) continue;
			if(i - m >= 0)
				if(dp[i-m] < dp[i]+1)
					dp[i - m] = dp[i]+1;
			if(i - n >= 0)
				if(dp[i-n] < dp[i]+1)
					dp[i-n] = dp[i] +1;
		}

		if(dp[0] > 0) cout << dp[0] << endl;
		else{
			for (int i = 1; i <= t; ++i)
			{
				if(dp[i] >= 0) {cout << dp[i] <<" " << i << endl; break;}
			}
		}
	}

	return 0;
}

