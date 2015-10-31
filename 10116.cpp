#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#define MAX 65
int m,n,s,amove;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
string maze[MAX];
char choice;
int dist[MAX][MAX];
bool dfs_value[MAX][MAX];
bool sw;
int count;
void dfs(int a,int b){
	int c,d;
	sw = false;
	while(a >= 0 && b >= 0 && a < m && b < n && !dfs_value[a][b]){
		count++;
		dist[a][b] += count;
		dfs_value[a][b] = true;
	switch(maze[a][b]){
		case 'N':
			amove = 0;
			break;
		case 'S':
			amove = 2;
			break;
		case 'E':
			amove = 1;
			break;
		case 'W':
			amove = 3;
			break;
	}
		c = a + dy[amove];
		d = b + dx[amove];
		if(dfs_value[c][d]){
			sw = true; 
			break;
		}else if(c >= 0 && d >= 0 && c < m && d < n){
			a = c; b = d;
		}
	}	
	if(sw){
		int value = dist[c][d]-1;
		int loop = dist[a][b] - value;
		cout << value <<" step(s) before a loop of " << loop << " step(s)"<<endl;
	} else cout << dist[a][b]<<" step(s) to exit"<<endl;
}
int main(){
	while(cin >> m >> n >> s && m!=0 && n != 0 && s != 0){
	count = 0;
	memset(dfs_value,false,sizeof dfs_value);
	memset(dist,0,sizeof dist);
	cin.ignore();
	for (int i = 0; i < m; ++i)
	{
		string p;
		getline(cin,p);	
		maze[i] = p;
	}

	dfs(0,s-1);
	}
	return 0;
}	