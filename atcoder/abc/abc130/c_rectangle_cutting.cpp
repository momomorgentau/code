//626
//abc130_rectangle_cutting
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    int w,h,x,y;
    cin >> w >> h >> x >> y;
    double ans = (double)w*h/2.0;
    int c = 0;
    if(2*x==w && 2*y == h) c = 1;
    printf("%.10f %d\n",ans,c);
    return 0;
}