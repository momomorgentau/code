//ABC_197_C_
//ORXOR
//809
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    //ansには大きな値を入れておく
    ll ans = 1e18;
    //nまでで十分だが、最大ケースにしてある
    rep(i,1<<20)
    {
        ll bit = i;
        //はじめa[0]をいれる
        ll tmp = a[0];
        //グループ分けした数を入れる配列
        vector<ll> v;
        rep(j,n-1)
        {
            //a[1]から開始
            ll bit1 = bit & (1<<j);
            ll bit2 = bit & (1<<(j+1));

            if(bit1*2 == bit2)
            {
                //等しい場合にはORをとる
                tmp = tmp | a[j+1];
            }
            else
            {
                //異なる場合には配列にいれて、仕切り直し
                v.emplace_back(tmp);
                tmp = a[j+1];
            }
        }
        //最後の数も忘れずに入れる
        v.emplace_back(tmp);
        //0のXORは0である（０なら演算に影響を与えない）
        ll now = 0;
        //XOR演算
        for(auto vi:v) now = now ^ vi;
        //最小値であれば更新
        ans = min(ans,now);  
    }
    cout << ans << endl;
    return 0;
}