//----------------------------
// ABC 296 B
// Chessboard
// 31
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    vector<string> s(8);
    rep(i, 8) cin >> s[i];
    rep(i, 8)rep(j, 8)
    {
        if (s[i][j] == '.') continue;
        char c = 'a' + j;
        cout << c << 8 - i << endl;
        return 0;
    }
    return 0;
}