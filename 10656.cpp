#include <iostream>
#include <sstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n != 0){
		stringstream ss;
		bool sw = false;
		while(n--)
		{
			int x;
			cin >> x;
			if(x != 0){ 
				if(!sw){
			    sw = true;
			    ss << x;
				}else{	
					ss<<" ";
					ss << x;
				}
			}
		}
		string word = ss.str();
		if(sw) cout << word << endl;
		else cout << 0 << endl;
	}
}