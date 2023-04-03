//----------------------------
// ABC 296 A
// Alternately
// 14
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
    if (n == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    rep(i, n - 1)
    {
        if (s[i] == s[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}