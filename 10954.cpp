#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int main(){
	
	while(cin >> n && n != 0)
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		priority_queue<int> numbers;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			numbers.push(x*(-1));
		}
		int sum = 0;
		int total = 0;
		while(numbers.size() > 1){
			sum = abs(numbers.top());
			numbers.pop();
			sum += abs(numbers.top());
			numbers.pop();
			total += sum;
			numbers.push(sum*(-1));
		}
		
	cout << total << endl;
    }

}
