//565
//abc189_c_mandarin_orange
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n)
    {
        int mx = a[i];
        int tans = 0;
        for(int j1 = i-1; j1>=0;--j1)
        {
            if(a[j1] >= mx) tans += mx;
            else break;
        }
        for(int j2 = i; j2<n;++j2)
        {
            if(a[j2] >= mx) tans += mx;
            else break;
        }
        ans = max(ans,tans);
    }
    cout << ans << endl;
	return 0;
}