//ABC_208_B
//Weak Password
//64
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    bool same = true;
    bool seq = true;
    rep(i, 3)
    {
        if (s[i] != s[i + 1]) same = false;
        if (s[i] == '9')
        {
            if (s[i + 1] != '0')
                seq = false;
        }
        else
        {
            if (s[i + 1] != s[i] + 1)
                seq = false;
        }
    }
    if (same || seq) cout << "Weak" << endl;
    else cout << "Strong" << endl;

    return 0;
}