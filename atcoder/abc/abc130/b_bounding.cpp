//70
//abc130_b_counding
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    for(auto& e:l)cin>>e;
    int ans = 1;
    int sl = 0;
    for(auto li:l)
    {
        sl += li;
        if(sl<=x)++ans;
        else break;
    }
    cout << ans << endl;

    return 0;
}