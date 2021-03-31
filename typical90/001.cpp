//1
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n,l,k;
    cin >> n >> l >> k;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];
    
    int ac = 1, wa = 1e9;
    while(wa-ac > 1)
    {
        int wj = (wa+ac)/2;
        int now = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(now + a[i+1]-a[i] >= wj && l-a[i+1] >= wj)
            {
                ++cnt;
                now = 0;
            }
            else now += a[i+1]-a[i];
        }
        if(cnt >= k) ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
    
    return 0;
} 