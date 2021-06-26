//ABC_205_B
//Permutation_on_Check
//16
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int,int,int>;

int main()
{
    int n;
    cin >> n;
    vector<int> used(n+1);
    int cnt = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (used[a] == 1) continue;
        ++cnt;
        used[a] = 1;
    }
    if (cnt == n)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

