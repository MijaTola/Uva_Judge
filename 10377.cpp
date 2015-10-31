#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#define MAX 65
int m,n,amove;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
char direction[4] = {'N','E','S','W'};
string maze[MAX];
char choice;
bool dfs_value[MAX][MAX];
bool sw;
void dfs(int a,int b){
	amove = 0;
	while(cin >> choice && choice != 'Q'){
		switch(choice){
			case 'R':	
			amove++;
			if(amove > 3) amove = 0;
				break;
			case 'L':
			amove--;
			if(amove < 0) amove = 3;
			 	break;
			case 'F':
				int c = a + dy[amove];
				int d = b + dx[amove];
				if(maze[c][d] != '*'){
					maze[c][d] = 'f';	
					a = c;
					b = d;
				}
				break;
		}
	}
	cout <<a+1<<" "<<b+1<<" "<<direction[amove] << endl;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
	string x;
	cin >> m >> n;
	cin.ignore();
	for (int i = 0; i < m; ++i)
	{
		string p;
		getline(cin,p);
		maze[i] = p;
	}
	int f,g;
		cin >> f >> g;
		f--;
		g--;
	dfs(f,g);
	if(t)cout << endl;
	}
	return 0;
}	