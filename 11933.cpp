#include <iostream>

using namespace std;

int main(){

	int n;

	while(cin >> n&&n){
	int a = 0; int b = 0; int c = 0;	
	for (int i = 0; i < 32; ++i)
	{ 
		if(n&(1<<i)){
			if(c%2==0){
				a |=(1<<i);
			}else b |= (1<<i);
			c++;
		}	
	}
	cout << a << " " << b << endl;
	}
	return 0;
}