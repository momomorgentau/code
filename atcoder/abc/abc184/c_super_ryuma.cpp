//782
//abc184_c_super_ryuma
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    i2 -= i1;
    j2 -= j1;
    i1 = 0;
    j1 = 0;
    i2 = abs(i2);
    j2 = abs(j2);

    if (i2 == 0 && j2 == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    if (i2 + j2 <= 3 || i2 == j2)
    {
        cout << 1 << endl;
        return 0;
    }

    if (i2 + j2 <= 6 || (i2 + j2) % 2 == 0 || abs(i2 - j2) <= 3)
    {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
    return 0;
}

//in contest
/*
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;
using P = pair<int, int>;

int x[4] = { 0,0,-3,  3 };
int y[4] = { 3,-3,0,0 };

int main()
{
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;


    int dx = r1 - r2;
    int dy = c1 - c2;

    bool ok = false;

    if (dx == 0 && dy == 0)
    {
        cout << 0 << endl;
        return 0;
    }


    if (abs(dx) + abs(dy) <= 3) ok = true;
    if (abs(dx) == abs(dy)) ok = true;


    if (ok)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<int> col1x, col1y,col2x,col2y;
    rep(i, 5)
    {
        rep(j, 5)
        {
            col1x.emplace_back(r1 - i - 2);
            col1y.emplace_back(c1 - j - 2);
            col2x.emplace_back(r2 - i - 2);
            col2y.emplace_back(c2 - j - 2);

        }
    }
    rep(i, 4)
    {
        col1x.emplace_back(r1 + x[i]);
        col1y.emplace_back(c1 + y[i]);
        col2x.emplace_back(r2 + x[i]);
        col2y.emplace_back(c2 + y[i]);
    }

    rep(i, col1x.size())
    {
        rep(j, col1x.size())
        {
            if (col1x[i] == col2x[j] && col1y[i] == col2y[j]) ok = true;
        }
    }


    int rel = 0;
    int jx;
    int jy;
    if (dx > 0) jx = r1 - abs(dx);
    else jx = r1 + abs(dx);
    if (dy > 0) jy = c1 - abs(dx);
    else jy = abs(dx);


    if (c2 - 4 <= jy && jy <= c2 + 4) ok = true;

    if ((abs(dx) + abs(dy)) % 2 == 0) ok = true;

    if (ok)
    {
        cout << 2 << endl;
        return 0;

    }
    else
    {
        cout << 3 << endl;
        return 0;

    }
}
*/
