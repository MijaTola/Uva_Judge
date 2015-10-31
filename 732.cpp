#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int tam;
string a, b;
stack<char> actions, s;
vector< stack<char> > result;

void solve(int i, int j) {
    if (i == tam && j == tam) {
        result.push_back(actions);
        return;
    }

    if (i < tam	) {
        actions.push('i');
        s.push(a[i]);
        solve(i + 1, j);
        s.pop();
        actions.pop();
    }

    if (!s.empty() && s.top() == b[j]) {
        actions.push('o');
        char tmp = s.top();
        s.pop();
        solve(i, j + 1);
        s.push(tmp);
        actions.pop();
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie();
    while (cin >> a) {
        cin >> b;
        result.clear();

        string x = a;
        string y = b;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (x != y) {
            cout << "[" << endl << "]" << endl;
            continue;
        }
        tam = a.size();
        solve(0, 0);
        cout << "[" << endl;
        for (int i = 0; i < result.size(); ++i){
            string x = "";
            bool first = false;
            while (!result[i].empty()){
                if(first) x = " "+ x;
            	first = true;
                x =result[i].top()+ x;
                result[i].pop();
            }
            cout << x << endl;
        }

        cout << "]" << endl;
    }
    return 0;
}