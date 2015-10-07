#include <iostream>
#include <cstring>	
using namespace std;
int dp[110][110];
int x;
int ways(int n,int k){
	unsigned c = 0;
	if(k == 1) return 1;
	if(dp[n][k] != -1)
		return dp[n][k];
	for (int i = 0; i <= n; ++i)
	{
		dp[n-i][k -1] = ways(n-i,k-1);
		c += dp[n - i][k-1];
	}
	return c%1000000;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k;
	while(cin >> n >> k && n != 0 && k != 0){
	memset(dp,-1,sizeof dp);
	cout << ways(n,k) << endl;
	}
	return 0;
}