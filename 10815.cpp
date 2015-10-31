#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

int main(){	
	ios::sync_with_stdio(false); cin.tie(0);
	string x;
	set<string> dictionary;
	while(cin >> x){
		transform(x.begin(), x.end(),x.begin() , ::tolower);
		regex rgx("[a-z]++");
		regex_iterator<string::iterator> rit (x.begin(),x.end(),rgx);
		regex_iterator<string::iterator> rend;
		while(rit != rend)
		{
			dictionary.insert(rit -> str());
			rit++;
		}
		
		/*string y = "";
		for (int i = 0; i <= x.size(); ++i)
		{
			if(isalpha(x[i])){
				y+=tolower(x[i]);
			}else if(y != ""){
				dictionary.insert(y);
				y = "";
			}
		}*/
	
	}

	for (std::set<string>::iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		cout << *i << endl;	
	

	return 0;
}