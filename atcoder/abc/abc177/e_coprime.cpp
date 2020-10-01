#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
const int A = 1000005;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(A);

    rep(i, n) {
        cin >> a[i];
        ++b[a[i]];
    }

    bool ispw = true;
    //pairwise coprime‚Ì”»’è
    for (int i = 2; i < A; ++i) {
        int cnt = 0;
        for (int j = i; j < A; j += i) {
            cnt += b[j];
        }
        if (cnt < 2) continue;
        ispw = false;
        break;
    }

    if (ispw) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    //setwise coprime‚Ì”»’è
    int g = 0;
    rep(i, n) g = gcd(g, a[i]);
    if (g == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;

    return 0;
}