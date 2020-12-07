//182
//abc148_d_brick_break
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int mxa = 1;
    int num = 0;
    rep(i,n)
    {
        if(a[i] == mxa)
        {
            ++mxa;
            ++num;
        }
    }
    int ans = n-num;
    if(ans == n) ans = -1;
    cout << ans << endl;

    return 0;
}