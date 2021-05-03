//ABC_196_F_Substring_2
//2274
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s,t;
    cin >> s >> t;
    reverse(t.begin(),t.end());
    int n = s.size(), m = t.size();
    int c = n-m+1;
    //異なる数字の場所の数を記録
    vector<int> d(c);
    rep(bit,2)
    {
        vector<int> x(n),y(m);
        //片方の0,1を反転
        rep(i,n) x[i] = ((s[i]-'0') ? !bit:bit);
        rep(i,m) y[i] = ((t[i]-'0') ? bit:!bit);
        vector<int> comv(c);
        comv = comvolution(x,y);
        //comvの結果を足し合わせる。
        rep(i,c) d[i] += comv[i];
        
    }
    int ans = *min_element(d.begin(),d.end());
    cout << ans << endl;
    return 0;
}
