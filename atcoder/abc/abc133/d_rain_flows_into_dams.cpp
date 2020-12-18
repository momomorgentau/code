//938
//abc133_d_rain_flow_into_dams
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    //ifstream in("input.txt");
    //cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];


    ll ac = 0;
    ll wa = 1e10;

    while (1)
    {
        ll mid = (ac + wa) / 2;
        if (mid % 2 == 1) --mid;
        //cout << ac << " " << wa << " " << mid <<endl;
        vector<ll> ans(n);
        vector<ll> ta(n);

        ans[0] = mid;

        ta[0] = mid / 2;
        ta[n - 1] = mid / 2;
        int ok = 0;

        reps(i, 1, n)
        {
            ll r = a[i - 1] - ta[i - 1];

            if (i != n - 1)
            {
                ta[i] = r;
                ans[i] = r * 2;
            }
            else
            {
                ans[i] = r * 2;
                if (a[n - 1] == ta[n - 1] + r) ok = 0;
                else if (a[n - 1] < ta[n - 1] + r) ok = +1;
                else ok = -1;
                break;
            }
        }
        if (ok == 1) wa = mid;
        else if (ok == -1) ac = mid;
        else
        {
            for (auto ai : ans) cout << ai << " ";
            cout << endl;
            break;
        }
    }


    return 0;
}


