#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>	
using namespace std;

int tape,tracks,trackLists[30];
bool ver[30];
vector<int> ans;
vector<int> aux;
int mini;
void solved(int space);
void verify(int dif);
int main(){

	while(cin >> tape >> tracks){
		aux.clear();
		ans.clear();
		mini = 30;
	for (int i = 0; i < tracks; ++i)
	{
		cin >> trackLists[i];
	}
	memset(ver,false,sizeof  ver);
	solved(tape);
	int c = 0;
	int sum = 0;
	while(c < ans.size()){
 		cout << ans[c] << " ";
		sum += ans[c];
		c++;
	}
	cout << "sum:" << sum << endl;
}
return 0;
}

void solved(int space){
	int dif = 0;
	if(space < 0){
		aux.pop_back();
		return;
	}
	for (int i = 0; i < tracks; ++i)
	{
		if(space == 1 || space == 0){
			verify(space);
			if(!aux.empty()) aux.pop_back();
			return;
		}
		if(!ver[i]){
		ver[i] = true;
		aux.push_back(trackLists[i]);
		solved(space - trackLists[i]);
		int dif = space - trackLists[i];
		ver[i] = false;
		}
	}
	verify(dif);
	if(!aux.empty()) aux.pop_back();
}
void verify(int dif){
	if(dif < mini){
		mini = dif;
		ans = aux;
	}else if(dif == mini){
	if(aux.size() > ans.size())	aux = aux;
	aux.clear();
	}
}
