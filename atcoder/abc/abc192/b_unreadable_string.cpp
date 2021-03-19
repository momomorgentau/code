//ABC_192_B_uNrEaDaBlE_sTrInG
//23
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
    string s;
    cin >> s;
    bool ok = true;
    rep(i, s.size())
    {
        int idx = i + 1;
        if (idx & 1)
        {
            if (isupper(s[i])) ok = false;
        }
        else 
        {
            if (islower(s[i])) ok = false;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}