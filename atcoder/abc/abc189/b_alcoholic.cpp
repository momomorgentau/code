//abc189_b_alcoholic
//274
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n,x;
    cin >> n >> x;
    int now = 0;
    int xint = x*100;
    int ans = -1;
    rep(i,n)
    {
        int vi,pi;
        cin >> vi >> pi;
        now += vi * pi;
        if(now > xint) 
        {
            ans = i+1;
            break;
        }

    }
    cout << ans << endl;
	return 0;
}