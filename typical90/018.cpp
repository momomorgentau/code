//018
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

const double pi = 3.1415926535;

int main()
{
    double t,l,x,y;
    int q;
    cin >> t >> l >> x >> y >> q;
    while(q--)
    {
        double qi; cin >> qi;
        double yi,zi;
        double theta = (qi/t)*2*pi;
        yi = -sin(theta) * l/2;
        zi = l/2 * (1 - cos(theta));

        
        double lx,ly,lz;
        lx = sqrt(x*x+(yi-y)*(yi-y));
        ly = sqrt((0-x)*(0-x)+(yi-y)*(yi-y)+(zi-0)*(zi-0));
        lz = zi;
        double u = (lx*lx)+(ly*ly)-(lz*lz);
        double b = 2*lx*ly;
        double ans = acos(u/b) * 180.0 / pi;
        printf("%.8f\n",ans);
    }
    
    return 0;
}
