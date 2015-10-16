#include <iostream>

using namespace std;

int main(){

	int n;
	string x;
	cin >> n;
	while(n--){
		cin >> x;
		int sum = 0;
		int count = 1;
		for (int i = 0; i < x.size(); ++i)
		{
			if(x[i] == 'O'){
				sum += count;
				count++;
			}else if(x[i] == 'X') count = 1;
		}
		cout << sum << endl;
	}	
	return 0;
}