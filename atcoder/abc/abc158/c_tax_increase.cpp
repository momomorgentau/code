//174
//abc158_c_tax_increase
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = -1;
    rep(i,1300)
    {
        int x = i;
        if(x * 8 / 100 == a && x / 10 == b)
        {
            ans = x;
            break;
        }
    }
    cout << ans <<endl;
    return 0;
}
