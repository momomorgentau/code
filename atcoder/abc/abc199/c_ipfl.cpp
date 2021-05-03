//ABC_199_C
//IPFL
//436
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,q;
    string s;
    cin >> n >> s >> q;
    vector<string> v(2);
    //substr(a,b)
    //sのa番目からb文字を取得する
    v[0] = s.substr(0,n);
    v[1] = s.substr(n,n);
    while(q--)
    {
        int t,a,b; 
        cin >> t >> a >> b;
        if(t == 1){
            --a,--b;
            int sa = a / n;
            int sb = b / n;
            int idxa = a % n;
            int idxb = b % n;
            //v[a][b]とすると、
            //v[a]に入ってる文字の b 番目にアクセス可能
            swap(v[sa][idxa],v[sb][idxb]);
        }
        else swap(v[0],v[1]);
    }
    cout << v[0] << v[1] << endl;
    return 0;
}