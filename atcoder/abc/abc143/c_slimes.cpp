//66
//abc143_c_slimes
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;


int main() 
{
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    rep(i, n) {
        if (s[i] == s[i + 1]) --ans;
    }
    cout << ans << endl;
    return 0;
}