#include <iostream>
#include <algorithm>
#include <math.h> 
#include <cstring>
using namespace std;

#define MAX 10500
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int dp[MAX];
	memset(dp,4,sizeof dp);
	for (int i = 1; i < 101; ++i)
	{
		dp[i*i] = 1;
	}
	dp[0] = 0;
	for (int i = 1; i < MAX; ++i)
	{ 
		if(dp[i] == 1) continue;
		for (int j = 1; j <= i; ++j)
		{
			if(dp[i] > dp[i-j]+ dp[j])
				dp[i] = dp[i-j] + dp[j];	
		}
	}
	int t,n;
	cin >> t;	
	while(t--){
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}