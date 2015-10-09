#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;

int dfs_num[26];
vi List[26];
int trees;
int acorn;
int count;
bool ver;
void dfs(int u){
	dfs_num[u] = 0;
	count++;
	for (int i = 0; i < List[u].size(); ++i)
	{
		int v = List[u][i];
		if(dfs_num[v] == -1)
			dfs(v);
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
	for (int i = 0; i < 30; ++i)
	{
		List[i].clear();
	}
	memset(dfs_num,-1,sizeof dfs_num);
	string x;
	while(cin >> x){
		if(x[0] == '*') break;
		int nod1 = x[1] - 65;
		int nod2 = x[3] - 65; 
		List[nod1].push_back(nod2); 
		List[nod2].push_back(nod1);
	}
	trees = 0;
	acorn = 0;
	count = 0;
	cin >> x;
	for (int i = 0; i < x.size(); ++i){
		if(x[i] == ',') continue;	
		ver = false;
		if(dfs_num[x[i]-65] == -1){
				count = 0;	
				dfs(x[i]-65);
			if(count == 1) acorn++;
			else if(count > 1) trees++;
		}
	}	
	cout << "There are "<< trees <<" tree(s) and " << acorn <<	" acorn(s)." << endl;
	}
	return 0;
}
