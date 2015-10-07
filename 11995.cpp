#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int n;
	int command;
	int x;
	while(cin >> n && n != 0){
	stack<int> pile;
	queue<int> que;
	priority_queue<int> h;
	string type;
	bool s = true;
	bool q = true;
	bool p = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> command >> x;
		if(command == 1){
			if(s)
			pile.push(x);
			if(q)
			que.push(x);
			if(p)
			h.push(x);
		}else if(command == 2){
			if(s){
				if(pile.empty() || pile.top() != x)
					s = false;
				else
					pile.pop();
			}
			if(q){
				if(que.empty() || que.front() != x)
					q = false;
				else
					que.pop();
			}
			if(p){
				if(h.empty() || h.top() != x)
					p = false;
				else
					h.pop();
			}
		}
	}

	if(s && !q && !p)
		cout << "stack";	
	else if(!s && q && !p)
		cout << "queue";
	else if(!s && !q && p)
		cout << "priority queue";
	else if(!s && !q && !p)
		cout << "impossible";
	else
		cout << "not sure";

	cout << endl;
}	

	return 0;
}