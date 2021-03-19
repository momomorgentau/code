//ABC195_B_Many_Oranges
//483
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll a,b,w;
    cin >> a >> b >> w;
    w *= 1000;

    //wが実現できるか判定
    ll n = 1;
    while(n<=w)
    {
        if(n * a <= w && w <= n * b ) break;
        n++;
    }
    if(n == w+1)
    {
         cout << "UNSATISFIABLE" << endl;
         return 0;
    }
    //wができることが確定した。
    ll mn = (w+b-1) / b;
    ll mx = w / a;
    cout << mn <<" "<< mx << endl;  
    return 0;
}

