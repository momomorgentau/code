//ABC_119_C_Syntheric_Kadomatsu
//1346
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a,b,c;
const int INF = 1e9;

int score(vector<int> v)
{
    int res = INF;
    int size = v.size();
    rep(i,size)rep(j,size)rep(k,size)
    {
        if(i == j) continue;
        if(j == k) continue;
        if(k == i) continue;
        int now = abs(a-v[i]) + abs(b-v[j]) + abs(c-v[k]);
        res = min(res,now);
    }
    return res;
}

int dfs(vector<int> v, int merge)
{
    int point = score(v)+merge;
    int size = v.size();

    rep(i,size)reps(j,i+1,size)
    {
        vector<int> tv = v;
        tv[i] += tv[j];
        tv.erase(tv.begin()+j);
        if(size > 3) point = min(point,dfs(tv,merge+10));
    }
    return point;
}

int main()
{
    int n;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    cout << dfs(l,0) << endl;
    return 0;
}