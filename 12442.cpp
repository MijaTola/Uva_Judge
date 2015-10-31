#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define MAX 50000
typedef vector<int> vi;

int dfs_num[MAX];
int sum;
int adjacentList[MAX];
void dfs(int u){
		int v = adjacentList[u];
		if(dfs_num[v] == -1)
			dfs(v);
		else{
			sum++;
		}
}
int main(){
	int t,n;
	memset(dfs_num,-1,sizeof dfs_num);
	cin >> n;
	for (int i = 0; i < n; ++i){
		int x,y;
		cin >> x >> y;
		adjacentList[x] = y;
	}
	sum = 0;
	for (int i = 1; i <= n; ++i){
		dfs_num[i] = 0;
		dfs(i);
	}
	cout <<"Case "<<": " <<sum;
	return 0;
}