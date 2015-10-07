#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

vector<string> words;
string rule;
void solve(string ouput,int index);
int main (){
int n;
while(cin >> n){
	string x;
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		getline(cin, x);
		words.push_back(x);
	}
	int rulesNumber;
	cin >> rulesNumber;
	for (int i = 0; i < rulesNumber; ++i)
	{
		cin >> rule;
		string ouput = "";
		cout << "--" << endl; 
		solve(ouput, 0);
	}
	words.clear();
}
}
void solve(string ouput,int index){
	if(index == rule.size()){
		cout << ouput << endl;
		return;
	}	
	if(rule[index] == '#'){
		for (int i = 0,sz = words.size(); i < sz; ++i)
		{
			solve(ouput+words[i],index+1);
		}
	}else if(rule[index] == '0'){
		for (char i = '0'; i <= '9'; ++i)
		{
			solve(ouput+i,index+1);
		}
	}

}

