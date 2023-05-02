//----------------------------
// ABC 298 A
// Job Interview
// -
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    bool ok = false;
    bool ng = false;
    for(const auto&c:s)
    {
        ok |= c == 'o';
        ng |= c == 'x';
    }
    if(ok && !ng) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

