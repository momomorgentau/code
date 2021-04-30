//ABC_197_D
//Opssite
//831
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    double x0,y0,x2,y2;
    cin >> n >> x0 >> y0 >> x2 >> y2;

    double mx,my;
    mx = (x0+x2)/2;
    my = (y0+y2)/2;

    x0 -= mx;
    y0 -= my;


    double theta = 2*M_PI / n;
    double s,c;
    s = sin(theta);
    c = cos(theta);
    double ansx,ansy;
    ansx = x0 * c - y0 * s + mx;
    ansy = x0 * s + y0 * c + my;
    printf("%.6f %.6f\n",ansx,ansy);
    return 0;
}