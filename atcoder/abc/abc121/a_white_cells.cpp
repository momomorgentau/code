//ABC_121_A_White_Cells
//18
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int h,w,hi,wi;
    cin>> h >> w >> hi >> wi;
    int ans = h*w - (hi*w + (wi*(h-hi)));
    cout << ans << endl;

    return 0;
}