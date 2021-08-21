//ABC_211_B
//Cycle Hit
//17
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    vector<string> S(4);
    rep(i, 4) cin >> S[i];
    int ans = 0;
    for (auto const& s : S)
    {
        if (s == "H") ans |= 1 << 0;
        else if (s == "2B") ans |= 1 << 1;
        else if (s == "3B") ans |= 1 << 2;
        else ans |= 1 << 3;
    }
    if (ans == (1 << 4) - 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

