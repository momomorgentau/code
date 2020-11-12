//212
//abc181_c_collinearity
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);

    rep(i, n) cin >> x[i] >> y[i];

    rep(i, n)rep(j, n)rep(k, n) 
    {
        if (i >= j)continue;
        if (j >= k)continue;
        int x1 = x[i];
        int x2 = x[j];
        int x3 = x[k];

        int y1 = y[i];
        int y2 = y[j];
        int y3 = y[k];

        int l1 = (x1 - x2) * (y2 - y3);
        int l2 = (x2 - x3) * (y1 - y2);
        if (l1 == l2) 
        {
            cout << "Yes" << endl;
            return 0;
        }


    }
    cout << "No" << endl;
    return 0;

}

