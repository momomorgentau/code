//ABC_205_A
//kcal
//6
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int,int,int>;

int main()
{
    double a, b;
    cin >> a >> b;
    double ans = a * b / 100;
    printf("%.7f\n", ans);

    return 0;
}

