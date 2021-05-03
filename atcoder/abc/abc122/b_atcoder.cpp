//ABC_122_B_ATCoder
//108
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    int now = 0;
    for(auto c:s)
    {
        if(c == 'A' || c == 'T' || c == 'C' || c == 'G')
        {
            ++now;
        }
        else now = 0;
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}