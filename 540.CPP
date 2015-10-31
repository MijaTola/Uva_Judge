#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main(){
ios::sync_with_stdio(false); cin.tie(0);	
int t;
int k = 1;
while(cin >> t && t != 0){
    cout << "Scenario #" << k++ << endl;
    map<int, int> team;
    for(int i=0; i<t; ++i){
    int invs;
    cin >> invs;
    	for(int j=0; j<invs; ++j){
        int inv;
        cin >> inv;
        team[inv] = i;
      	}
	}

    string command;
    int number;
    vector<queue<int> > formTeams(t);
    queue<int> list;
    vector<bool> visited(t,false);
    while(cin >> command && command != "STOP"){
    	if(command == "ENQUEUE"){
    		cin >> number;
    		int x = team[number];
    		formTeams[x].push(number);
    		if(!visited[x]){
    			list.push(x);
    			visited[x] = true;
    		}
    	}else{
    		int x = list.front();
    		number = formTeams[x].front();
    		formTeams[x].pop();
    		cout << number << endl;
    		if(formTeams[x].empty()){
    			list.pop();
    			visited[x] = false;
    		}
    	}
    }
    cout << endl;
  }
  return 0;
}