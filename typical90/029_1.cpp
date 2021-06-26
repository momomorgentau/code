//029
//*5
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n,w;
    cin >> w >> n;
    vector<int> W(w,0);
    rep(i,n)
    {
        int l,r;cin >> l >> r;
        --l,--r;
        int mx = -1;
        reps(i,l,r+1) mx = max(mx,W[i]);
        reps(i,l,r+1) W[i] = mx+1;
        printf("%d\n",mx+1);
    }

 
    return 0;
}