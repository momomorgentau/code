//ABC_like_パナソニックプログラミングコンテスト2020_C
//701
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll a,b,c;
    cin >> a >> b >> c;
    if(c-a-b < 0) cout << "No" << endl;
    else
    {
        ll left = 4*a*b;
        ll right = c-(a+b);
        right *= right;
        if(left < right) cout << "Yes" << endl;
        else cout << "No" <<endl;
    }
    return 0;
}