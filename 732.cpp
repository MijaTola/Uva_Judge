#include <iostream> 
#include <string> 
#include <algorithm> 
#include <vector> 
#include <deque> 
using namespace std;
deque <char> pile;
deque <char> act;
vector< deque<char> > result;
string word;
string anagramed;
int wlenght;
void solve(int i, int j);

int main(){
while(getline(cin,word)&& getline(cin,anagramed)){
	result.clear();

	sort(word.begin(), word.end());
	sort(anagramed.begin(), anagramed.end());
	if(word != anagramed){
		cout << "[" << endl << "]" << endl;
		continue;
	}
	wlenght = word.size();
	solve(0,0);
	cout <<"["<< endl;
		for (int i = 0; i < result.size(); ++i)
		{
			bool sw = true;
			while(!result[i].empty()){
				if(!sw)
					cout << " ";
				sw = false;
				cout << result[i].front();
				result[i].pop_front();
			}
			cout << endl;	
		}
	cout <<"]"<< endl;
}
}

void solve(int i, int j){
	  if (i == wlenght && j == wlenght) { 
         result.push_back(act); 
         return; 
     } 
 
     if (i < wlenght) { 
         act.push_back('i'); 
         pile.push_back(word[i]); 
         solve(i + 1, j); 
         pile.pop_back(); 
         act.pop_back(); 
     } 
 
     if (!pile.empty() && pile.back() == anagramed[j]) { 
         act.push_back('o'); 
         char x = pile.back(); 
         pile.pop_back(); 
         solve(i, j + 1); 
         pile.push_back(x); 
         act.pop_back(); 
     }
}

