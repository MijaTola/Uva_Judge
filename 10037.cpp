#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);	
	int cases;
	cin >> cases;
	while(cases--)
	{
	 	int n;
	 	cin >> n;
	 	vector<int> v;
	 	for (int k = 0; k < n; ++k)
	 	{
	 		int x;
	 		cin >> x;
	 		v.push_back(x);
	 	}
	 	stringstream ss;
	 	sort(v.begin(), v.end());
	 	int seg = 0;
	 	while(v.size() >=4){

	 		int fast1 = v[0];
	 		int fast2 = v[1];

	 		int slow1 = v[v.size()-1];
	 		int slow2 = v[v.size()-2];

	 		int p1 = slow1 + fast1 + slow2 +fast1; //2f1 + s1+s2
	 		int p2 = fast2 + fast1 + slow1 +fast2; //2f2 + s1 +f1;	
	 		v.erase(v.end()-2,v.end()); 
	 		if(p2 < p1){
	 			seg += p2;
	 			ss << fast1 << " " << fast2 << endl;
	 			ss << fast1 <<endl;
	 			ss << slow2 <<" "<< slow1 <<endl; 
	 			ss << fast2 << endl;
	 		}else{
	 			seg += p1;
	 			ss << fast1 << " " << slow2 << endl;
	 			ss << fast1 << endl;
	 			ss << fast1 << " " << slow1 << endl;
	 			ss << fast1 << endl; 
	 		}
	 	}
	 	if(v.size() == 3){
	 	int fast1 = v[0];
	 	int fast2 = v[1];
	 	int slow1 = v[2];
	 	seg += fast1 + fast2 + slow1;
	 	ss << fast1 << " " << fast2 << endl;
	 	ss << fast1 << endl;
	 	ss << fast1 << " " << slow1 << endl; 
	 	}

	 if(v.size() == 2){
	 	int fast1 = v[0];
	 	int fast2 = v[1];
	 	seg += fast2;
	 	ss <<fast1<<" "<<fast2 <<endl;
	 }

	 if(v.size() == 1){
	 seg += v[0];
	 ss << v[0] << endl;
	 }
	cout << seg << endl;
	string word = ss.str();
	cout << word;
	if(cases) cout << endl;
	}
	return 0;
}
