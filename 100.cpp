#include <iostream>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false); cin.tie(0);
     int x, j;
   while(cin >> x >> j){
        int maxi = -99999999;
        cout << x <<" "<<j <<" ";
        if(x > j) swap(x,j);
        for (int i = x; i <= j; ++i)
        {
           unsigned int n = i;
            int count = 0;
            while(n != 1){
                if(n%2!=0) n = n*3+1;
                else n = n >> 1; 
                count++;
            }
            if(count > maxi) maxi = count;
        }
        cout << maxi+1 << endl;
   }
    return 0;
}
    