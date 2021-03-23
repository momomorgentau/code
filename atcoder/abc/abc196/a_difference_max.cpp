//ABC_196_A_Difference_Max
//9
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = -10000;
    for(int i = a; i <= b;++i)
    {
        for(int j = c;j<=d;++j)
        {
            ans = max(ans,i-j);
        }
    }

    //int ans = b-c;
    cout << ans <<endl;
    return 0;
}
