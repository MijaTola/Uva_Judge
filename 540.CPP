#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int t;
int n;
deque<int> Q;
int matriz[100][100];
string command;
string number;
vector<int> positions;
int main(){
cin >> t;
for (int i = 0; i < t; ++i)
{
	cin >> n;
	positions.push_back(n);
	for (int j = 0; j < n; ++j)
	{
		int x; 
		cin >> x;
		matriz[i][j] = x;
	}
}
string command;
int number;
cin >> command;
while(command != "STOP"){
cin >> number;
bool sw = false;
int i = 0;
int choice;
if(command == "QUEUE")
{
while(i < positions.size() && !sw)
{
	for (int j = 0; j < positions[i]; ++j)
	{
		if(matriz[i][j] != number){
			sw = true;
		}else{
			sw = false;
		}
	}
	if(sw){
		matriz[i][positions[i]+1] = number;
		positions[i] = positions[i]+1;
	}
	i++;
	Q.push_back(number);
}
}else if(command == DEQUEUE){
	int isEmpty;
	int x = Q.front();
	while(i < positions.size() && !sw)
	{
	for (int j = 0; j < positions[i]; ++j)
	{
		if(matriz[i][j] != number){
			sw = true;
		}else{
			sw = false;
		}
	}
	i++;
	}
}
}
}
}
