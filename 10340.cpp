#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string word;
	string word2;
	while(cin >> word >>word2){
		int c = 0;
		bool ve = true;
		for (int i = 0; i < word.size(); ++i)
		{
			ve = false;
			for (int j = c; j < word2.size(); ++j)
			{
				if(word[i] == word2[j]){
					ve = true;
					c = j+1;
					break;
				}
			}
			if(!ve) break;
		}
		if(ve) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
return 0;
}
