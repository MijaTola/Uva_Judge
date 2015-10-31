#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vii;
int r,C,m,n,w;
int odd, even;
int field[100][100];
bool dfs_value[100][100];
int dx[2] = {1,-1};
void dfs(int a,int b){
	if(dfs_value[a][b]) return;
	dfs_value[a][b] = true;
	for (int i = 0; i < 2; ++i)
		for (int f = 0; f < 2; ++f){
		int c = a + dx[i]*m; int d = b + dx[f]*n;
			if(c >=0 && c < r && d >= 0 && d < C && field[c][d] != -1){
			field[c][d]++;
			dfs(c,d);
			}
			c = a + dx[i]*n; d = b + dx[f]*m;
			if(c >=0 && c < r && d >= 0 && d < C && field[c][d] != -1){
			field[c][d]++;
			dfs(c,d);
			}	
		}
} 
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	for (int k = 1; k <= t; ++k)
	{
	cin >> r >> C >> m >> n >> w;
	memset(field,0,sizeof field);
	memset(dfs_value,false, sizeof dfs_value);
	for (int i = 0; i < w; ++i)
	{
		int x,y;
		cin >> x >> y;
		field[x][y] = -1;
		dfs_value[x][y] = true;	
	}
	odd = even = 0;
	dfs(0,0);

	for (int i = 0; i < r; ++i)
		for (int f = 0; f < C; ++f){
		if(m==0 || n==0 || m == n)
			field[i][f]/=2;
		if((field[i][f] || (!i && !f))&& field[i][f]!=-1){
				 if(field[i][f] % 2 == 0) even++;
				 else odd++;
		}
	}
	cout <<"Case "<<k<<": " <<even << " " << odd << endl;
}
	return 0;
}

