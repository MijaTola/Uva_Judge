#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n,maxSum,submatrix,m[150][150];

int main(){
					
cin >> n;
for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
{
	cin >> m[i][j];
	if(j > 0) m[i][j] += m[i][j-1];
}
//using 1D DP range here :P
maxSum = -127*100*100;
for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j){		
submatrix = 0;
for (int k = 0; k < n; ++k){
 if(i > 0) submatrix += m[k][j] - m[k][i-1];
 else  submatrix += m[k][j];
 if(submatrix < 0) submatrix = 0; //kadane greedy
 maxSum = max(maxSum,submatrix);
}
}
cout << maxSum << endl;
return 0;
}