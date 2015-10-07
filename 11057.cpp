#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
	int n;
	int m;
 	while(cin >> n){
 	vector<int> s;
 	s.clear();
 	int x = 0;
 	int y = 0;
 	int max = INT_MAX;
 	for (int i = 0; i < n; ++i)
 	{
 		int x;
 		cin >> x;
 		s.push_back(x); 
 	}
 	cin >> m;
 	sort(s.begin(), s.end());
 	for (int i = 0; i < n; ++i)
 	{
 		int bus=m;
 		int a=i,b=n;
 		while(b-a>1){
 			int mid = (a+b)>>1;
 			if(s[i]+s[mid]>bus)b=mid;//this change relying of the problem
 			else a=mid;
 		}	
 		if(a != i){
 			if(s[i] + s[a] == m){
 			if(s[i] - s[a] < max){
 				x = s[i];
 				y = s[a];
 			}
 			}	
 		}
 	}
 	cout << "Peter should buy books whose prices are "<< x << " and " <<y <<"." << endl;
 	cout << endl;
 }
 return 0;
}


