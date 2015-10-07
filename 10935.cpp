#include <iostream>
#include <deque>

using namespace std;
deque<int > Q;
int n;

int main (){
do{
cin >> n;
if(n != 0 && n != 1 && n != 2){
Q.clear();
for (int i =  1; i <= n; ++i)
{
	Q.push_back(i);
}
bool sw = false;
cout << "Discarded cards: ";
while(Q.size() > 2){
if(!sw){
	int aux = Q.front();
	cout << aux << ", ";
	Q.pop_front();
	sw = true;
}else{
	int aux = Q.front();
	Q.pop_front();
	Q.push_back(aux);
	sw = false;
}
}
cout << Q.back() << endl;
cout << "Remaining card: "<< Q.front() << endl;
}else if(n == 1){
	cout << "Discarded cards:" << endl;
	cout << "Remaining card: "<< 1 << endl;
}else if(n == 2){
	cout << "Discarded cards: " <<1 <<endl;
	cout << "Remaining card: "<< 2 << endl;
}
}while(n != 0);
return 0;
}