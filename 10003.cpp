#include <iostream>
#include <cstring>
using namespace std;
int n,l;
int A[55], dp[55][55];
int cut(int left, int right){
	if(left + 1 == right) return 0;
	if(dp[left][right] != -1) return dp[left][right];
	int ans = 1000000;
	for (int i = left+1; i < right; ++i)
	{
		ans = min(ans,cut(left,i)+cut(i,right)+(A[right]-A[left]));
	}
	return dp[left][right] = ans;	
}

int main (){
	ios::sync_with_stdio(false); cin.tie(0);
	while(cin >> l && l!=0){
		cin >> n;
		memset(dp,-1,sizeof dp);
		for (int i = 1; i <= n; ++i) cin >> A[i];
		A[n + 1] = l;
		A[0] = 0;
		cout <<"The minimum cutting is " <<cut(0,n+1)<<"." <<endl;
	}
	return 0;
}