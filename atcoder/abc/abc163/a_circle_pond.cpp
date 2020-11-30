//n
//abc163_a_circle_pond
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;
const double pi = 3.14159265;
int main()
{
    double r;
    cin >> r;
    double ans = 2 * pi * r;
    printf("%.5f\n",ans);

    return 0;
}