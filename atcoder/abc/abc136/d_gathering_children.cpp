//794
//abc136_d_gathering_children
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n, 0);
    int r = 0;
    int l = 0;
    bool isr = true;
    int ir = 0;
    int il = 0;

    rep(i, n)
    {
        if (isr) {
            ++r;
            if (s[i] == 'L')
            {
                --r;
                ir = i - 1;
                il = i;
                l = 1;
                isr = false;
                if (i == n - 1)
                {
                    ans[ir] = (r + 1) / 2 + l / 2;
                    ans[il] = r / 2 + (l + 1) / 2;
                }
            }
        }
        else
        {
            ++l;
            if (s[i] == 'R' || i == n - 1)
            {
                if (s[i] == 'R') --l;
                ans[ir] = (r + 1) / 2 + l / 2;
                ans[il] = r / 2 + (l + 1) / 2;
                isr = true;
                r = 1;

            }
        }
    }

    for (auto a : ans) cout << a << " ";
    cout << endl;


    return 0;
}
