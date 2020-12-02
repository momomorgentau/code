//113
//abc160_c_maximum_volume

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;


int main()
{
    double l;
    cin >> l;
    double l3 = l / 3;
    double ans = l3 * l3 * l3;
    printf("%.7f", ans);
    return 0;
}