//89
//abc164_b_battle
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;

using P = pair<int,int>;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    bool turn = true;
    while(a>0&&c>0)
    {
        if(turn) c -= b;
        else a -= d;
        turn = !turn;
    }

    string ans;
    if(a<=0) ans = "No";
    else ans = "Yes";
    cout << ans << endl;
    return 0;
}
