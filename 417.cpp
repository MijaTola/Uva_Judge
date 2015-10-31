#include <iostream>
#include <map>
#include <cstring>
using namespace std;
#define MAX 83682

map<string,int> combinations;
string store[MAX];
int main(){	
	ios::sync_with_stdio(false); cin.tie(0);
	int index = 1;
	for(int i=0;i<26;i++){
		char curr = (i+'a');
		string currStr = "";
		currStr = curr;
		combinations[currStr] = index;
		store[index++] = currStr;
	}
	int lowerRange = 1;
	int upperRange = 26;
	while(index < MAX) {
		for(int j=lowerRange;j<=upperRange;j++){
			string currStr = store[j];
			int nextIndex = currStr[currStr.length()-1]-'a'+1;
			for(int i=nextIndex;i<26;i++){
				char curr = (i+'a');
				string newStr = currStr + curr;
				combinations[newStr] = index;
				store[index++] = newStr;
			}
		}
		lowerRange = upperRange + 1;
		upperRange = index-1;
	}
	string x;
	while(cin >> x){
		cout << combinations[x] << endl;
	}
	return 0;
}