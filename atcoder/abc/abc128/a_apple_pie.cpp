//12
//abc128_a_apple_pie
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int a,p;
    cin >> a >> p;
    int l = p + a * 3;
    int ans = l / 2;
    cout << ans << endl;
    return 0;
}