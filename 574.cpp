#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int t,n;
vector <int> v;
string a;
int c;
bool solve(int pos, int sum, bool find){
	sum += v[pos];
	if(find)return true;
	if(sum > t) {
		a = "";
		return false;
	}
	if(v[pos] == t){
		cout << t << endl;
		return true;
	}
	if(pos == n) return false;
 	if(sum < t && sum != 0){
 		stringstream aa;
 		aa << v[pos];
 		a += aa.str()+"+" ;
 	}else if(sum == t){
		cout << a << v[pos] << endl;
		a = "";
		c++;
		return true;
		}
	while(pos < n){
		find = solve(pos+1, sum, find);
		if(find) return true;
		else{
		stringstream aa;
 		aa << v[pos];
 		a += aa.str()+"+" ;
		}
		pos ++;
	}
	return false;
}

int main(){
	while(cin >> t >> n && t != 0 && n != 0){
	bool sw = false;
	v.clear();
	c = 0;
	for (int i = 0; i < n; ++i)
	{
	 	int x;
	 	cin >> x;
	 	v.push_back(x);
	}
	cout << "Sums of " << t << ":"<< endl;
	for (int i = 0; i < n; ++i)
	{
    	solve(i,0,false);	
	}
	if(c == 0) cout << "NONE" << endl;
	a = "";
	c = 0;
	}
	return 0;

}