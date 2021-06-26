//ABC_112_C
//Pyramid
//1147
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n),y(n),h(n);
    rep(i,n)cin >> x[i] >> y[i] >> h[i];
    rep(cx,101)rep(cy,101)
    {
        int  H = -1;
        rep(i,n) 
        {
            if(h[i]==0) continue;
            H = abs(x[i]-cx) + abs(y[i]-cy) + h[i];
        }
        bool ok = true;
        rep(i,n)
        {
            int now = max(H -abs(x[i]-cx) - abs(y[i]-cy),0);
            if(h[i] != now) ok = false;
        }
        if(ok)
        {
            cout << cx << " " << cy << " " << H << endl;
            return 0;
        }
    }
       
    return 0;
}