#include <iostream>
using namespace std;
#define MAX_N 30
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int correct[30];
	int A[30];
	for (int i = 1; i <= n; ++i) cin >> correct[i];
	int y;
	while(cin >> y){
		A[y] = correct[1];
		for (int i = 2; i <= n; ++i)
		{
			int x;
			cin >> x;
			A[x] = correct[i] ;
		}
		int L[MAX_N], L_id[MAX_N], P[MAX_N];
 		int lis = 0, lis_end = 0;
  		for (int i = 1; i <= n; ++i) {
    	int pos = lower_bound(L, L + lis, A[i]) - L;
   		 L[pos] = A[i];
    	L_id[pos] = i;
    	P[i] = pos ? L_id[pos - 1] : -1;
    	if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }
}
cout << lis << endl;	
 }
	return 0;
}
