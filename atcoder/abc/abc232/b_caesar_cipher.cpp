//----------------------------
//ABC 232 B
//Caesar Cipher
//82
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    string s, t;
    cin >> s >> t;
    bool ok = true;
    int d = (s[0] - 'a') - (t[0] - 'a');
    if (d < 0) d += 26;
    rep(i, s.size())
    {
        int td = ((s[i] - 'a') - (t[i] - 'a'));
        if (td < 0) td += 26;
        if (d != td)
        {
            ok = false;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
