#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <vector>
typedef long long ll;
using namespace std;
ll solve(string x,char priority,char second);

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		string infix;
		cin >> infix;
		long long x = solve(infix,'*','+'); 
		long long y = solve(infix,'+','*'); 
		cout << "The maximum and minimum are "<< y <<" and "<< x << "."<<endl;
	}
}

ll solve(string x ,char priority,char second){
	stack<char> operators;
	string postfix;
	ll i = 0;
	while(i < x.size())
	{
		string ans = "";
		while(isdigit(x[i])){
			ans += x[i];
			i++;
		}
 		if(ans != "")postfix += ans;
		if(x[i] == priority){
			i++;
			string ii = "";
			postfix += " ";
			while(isdigit(x[i])){ii+=x[i];i++;}
			postfix += ii;
			postfix += " ";
			postfix += priority;
		}else if(x[i] == second) {operators.push(second); i++;postfix += " ";}
	}
	while(!operators.empty()){
		postfix += " ";
		postfix += operators.top();
		operators.pop();
	}
	stack<ll> aux;
	string ii="";
	for (ll i = 0; i < postfix.size(); ++i)
	{
		if(postfix[i] == '+'){
			ll m = aux.top();
			aux.pop();
			ll n = aux.top();
			aux.pop();
			aux.push(m+n);
		}else if(postfix[i] == '*'){
			ll m = aux.top();
			aux.pop();
			ll n = aux.top();
			aux.pop();
			aux.push(m*n);
		}else if(postfix[i] != ' ')ii+=postfix[i];
		else{
			ll l;
			if(ii != "")
			{istringstream convert(ii);
			 convert >> l;
			 aux.push(l);
		     ii = "";
			}
		}
	}
	return aux.top();
}