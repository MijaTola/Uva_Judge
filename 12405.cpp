#include <iostream>
#include <queue>

using namespace std;

int main(){
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
	queue<char> q;
	int n;
	cin >> n;
	int c = 0;
	int scarecrow = 0;
	for (int i = 1; i <= n; ++i)
	{
		char type;
		cin >> type;
		if(type == '.')c++;
		else if(c == 1){
			c++;	
		}else if (c >=1)
		{
			c = 0;
			scarecrow++;
		}
		if(c ==3){
			scarecrow++;
			c = 0;
		}
	}
	if(c != 0){
		scarecrow++;
	}
	cout << "Case "	<<k+1<< ": "<<scarecrow << endl;
	}
     return 0;
}
