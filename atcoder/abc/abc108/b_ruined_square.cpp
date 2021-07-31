//ABC_108_C
//Ruined_Square
//319
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2-x1;
    int dy = y2-y1;
    int x3,y3,x4,y4;
    x3 = x2 - dy;
    y3 = y2 + dx;
    x4 = x1 - dy;
    y4 = y1 + dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


	return 0;
}