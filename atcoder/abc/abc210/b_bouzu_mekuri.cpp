//ABC_210_B
//Bouzu Mekuri
//22
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i, n)
    {
        if (s[i] == '1')
        {
            if (i % 2 == 0) cout << "Takahashi" << endl;
            else cout << "Aoki" << endl;
            break;
        }
    }
    return 0;
}