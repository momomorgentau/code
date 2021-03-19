//abc191_D_Circle_Lattice_Points
//1953
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int b = 10000;

ll x, y, r;
ll xd; //10000以下を切り捨てたｘ

bool judge(ll xi, ll yi)
{
    ll dist = (xi - x) * (xi - x) + (yi - y) * (yi - y);
    return dist <= r * r;
}


int f(ll s, ll t)
{
    int res = 0;
    ll left = 0;
    ll right = 1; //計算の都合上rightは1を基準にする

    for (ll i = s; i >= t; i -= b)
    {
        while (1) 
        {
            bool ok1 = judge(xd -left * b, i);
            bool ok2 = judge(xd -(left+1) * b, i);
            if (ok1 && ok2) ++left;
            else if (ok1 && !ok2)
            {
                res += left + 1; //leftは+1したものを答え加える
                break;
            }
            else
            {
                if (left == 0) break;
                else --left;
            }
        }
        while (1)
        {
            bool ok1 = judge(xd + right * b, i);
            bool ok2 = judge(xd + (right + 1) * b, i);
            if (ok1 && ok2) ++right;
            else if (ok1 && !ok2)
            {
                res += right; //rightはそのまま答えに加える
                break;
            }
            else
            {
                if (right == 1) break;
                else --right;
            }
        }
    }
    return res;
}

int main()
{
    double tx, ty, tr;
    cin >> tx >> ty >> tr;
    x = round(tx * b);
    y = round(ty * b);
    r = round(tr * b);
    //第一象限に持ってくる
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    //xの下4桁を捨てる
    xd = x / b;
    xd *= b;

    ll inf = 2e9;

    ll ans = f(inf+50000,-inf-50000);
    cout << ans << endl;
    return 0;
}


