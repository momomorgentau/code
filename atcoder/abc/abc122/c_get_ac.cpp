//ABC_122_C_GeT_AC
//700
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> ac(n);
    int now = 0;
    reps(i,1,n)
    {
        if(s[i-1] == 'A' && s[i] == 'C') ++ now;
        ac[i] = now;
    }
    rep(i,q)
    {
        int l,r;
        cin >> l >> r;
        --l, --r;
        printf("%d\n",ac[r]-ac[l]);
    }
    return 0;
}