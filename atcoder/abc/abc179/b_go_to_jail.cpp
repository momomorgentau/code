#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<bool> eq;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (a == b) eq.emplace_back(1);
        else eq.emplace_back(0);
    }

    int cnt = 0;
    rep(i, n) {
        if (eq[i]) cnt++;
        else cnt = 0;

        if (cnt >= 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}