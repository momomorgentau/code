//ABC_123_B_Five_Dishes
//148
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    vector<int> v(5);
    rep(i,v.size()) cin >> v[i];
    int ans = 1e9;
    do
    {
        int now = 0;
        for(auto vi:v)
        {
            now += (10 - (now % 10)) % 10;
            now += vi;
        }
        ans = min(now,ans);
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << endl;
    return 0;
}
