#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int dp[500][30];//dinero y tiendas disponibles
int v[30][30];
int n,m,t;
int pp[30];
int solve(int remainder, int pos);
int main(){

	cin >> t;

	for (int i = 0; i < t; ++i)
	 {
	 	cin >> n >>m;

	 	for (int i = 0; i < m; ++i)
	 	{
	 		int x;
	 		cin>>pp[i];
	 		for (int j = 0; j < pp[i]; ++j)
	 		{
	 			
	 	 		cin >> v[i][j];
	 			
	 		}
	 	}
	 	memset(dp,-1,sizeof  dp);
	 	int ans=solve(n,0);
	 	if(ans!=INT_MAX)
	 	cout << n-ans << endl;
	 else cout<<"no solution"<<endl;
	 } 
}

int solve(int remainder, int pos){
	if(pos==m) {
		return remainder;
	}
	if(dp[remainder][pos]!=-1)return dp[remainder][pos];
	int ans=INT_MAX;
	for (int i = 0; i < pp[pos]; ++i)
	{
		if(remainder - v[pos][i] >= 0) {
			ans = min(ans,solve(remainder-v[pos][i],pos+1));
		}
	}
	dp[remainder][pos]=ans;
	return ans;
}