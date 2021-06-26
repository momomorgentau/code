//ABC_205_C
//POW
//63
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int,int,int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0)
    {
        cout << "=" << endl;
    }
    else if (c % 2 == 0)
    {
        if (abs(a) < abs(b)) cout << "<" << endl;
        else if (abs(a) > abs(b)) cout << ">" << endl;
        else cout << "=" << endl;
    }
    else
    {
        if (a < 0 && b < 0)
        {
            if (a > b) cout << ">" << endl;
            else if (a == b) cout << "=" << endl;
            else cout << "<" << endl;
        }
        else if (a < 0)
        {
            cout << "<" << endl;
        }
        else if(b < 0)
        {
            cout << ">" << endl;
        }
        else
        {
            if (abs(a) < abs(b)) cout << "<" << endl;
            else if (abs(a) > abs(b)) cout << ">" << endl;
            else cout << "=" << endl;
        }
    }

    return 0;
}

