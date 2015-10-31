#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX 200
int m,n,amove,s;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
string maze[MAX];
char choice;
bool dfs_value[MAX][MAX];
bool sw;
void dfs(int a,int b){
	int sum = 0;
	for (int i = 0; i < s; ++i){
		cin >> choice;
		switch(choice){
			case 'D':	
			amove++;
			if(amove > 3) amove = 0;
				break;
			case 'E':
			amove--;
			if(amove < 0) amove = 3;
			 	break;
			case 'F':
				int c = a + dy[amove];
				int d = b + dx[amove];
				//cout << c << " " << d << endl;
				if(c >= 0 && c < m && d >= 0 && d < n){
					if(maze[c][d] != '#'){
					if(maze[c][d] == '*' && !dfs_value[c][d]){
						dfs_value[c][d] = true;
						sum++;
					}
					a = c;
					b = d;
				}
				}
				break;
		}
	}
	cout << sum << endl;
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	string x;
	while(cin >> m >> n >> s && m!=0 && n != 0 && s != 0){
	cin.ignore();
	int f,g;
	memset(dfs_value,false,sizeof dfs_value);
	for (int i = 0; i < m; ++i)
	{
		string p;
		getline(cin,p);
		maze[i] = p;
		for (int j = 0; j < p.size(); ++j)
		{
			if(p[j] == 'N'){f = i; g = j; amove = 0;}
			if(p[j] == 'S'){f = i; g = j; amove = 2;}
			if(p[j] == 'L'){f = i; g = j; amove = 1;}
			if(p[j] == 'O'){f = i; g = j; amove = 3;}
		}
	}
	dfs(f,g);
	}
	return 0;
}	