//n
//abc163_b_homework
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{
    int n,m;
    cin >> n >> m;
    int d = 0;
    rep(i,m)
    {
        int a;
        cin >> a;
        d += a;
    }
    int ans = max(n-d,-1);
    cout << ans << endl;
    return 0;
}