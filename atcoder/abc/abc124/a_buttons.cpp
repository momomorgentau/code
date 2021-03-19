//12
//abc125_a_buttons
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int a,b;
    cin >> a >> b;
    int ans = max({a+a-1,a+b,b+b-1});
    cout << ans << endl;

    return 0;
}

