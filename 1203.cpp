#include <iostream>
#include <queue>
#include <map>
using namespace std;
	
string Reg;
map<int, int> Register;
struct compare
{
	bool operator() (const pair<int, int> a, const pair<int,int> b){
		if(a.second == b.second) return a.first > b.first;
		else return a.second > b.second;
	}
};
int main(){
	int id;
	int f;
	int limit;
	priority_queue<pair<int,int>, vector<pair<int,int> >, compare > frequece;
	while(cin >> Reg && Reg != "#" ){
		cin >> id >> f;
		Register[id] = f;
		frequece.push(make_pair(id,f));
	}
	cin >> limit;
	int c = 0;
	while(c < limit){
			pair<int, int> toShow = frequece.top();
			frequece.pop();
			cout << toShow.first << endl;
			toShow.second += Register[toShow.first];
			frequece.push(toShow);
			c++;
	}
}	

