//012
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
template<typename T>
struct UnionFind {
	vector<int> d;
	//コンストラクタ
	UnionFind(int n = 0) : d(n, -1) {}
	//根の探索と張り替え
	int find(int x) {
		if (d[x] < 0) return x;
		//根のはりかえ
		return d[x] = find(d[x]);
	}
	//根の結合
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		//大きい方に小さい方をくっつける
		if (d[x] > d[y]) swap(x, y);
		//サイズの更新
		d[x] += d[y];
		//結合
		d[y] = x;
		return true;
	}
	//サイズの取得
	int size(int x) { return -d[find(x)]; }
	//同じ集合に属しているか
	bool same(int x, int y) { return (find(x) == find(y)); }
};

int main()
{
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<int>> g(h,vector<int> (w,-1));
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    UnionFind<int> UF(w*h);
    while(q--)
    {
        int type; cin >> type;
        if(type==1)
        {
            int x,y; cin >>x >> y;
            --x,--y;
            g[x][y] = 1;
            int e1 = x*w+y;
            rep(i,4)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || h<=nx) continue;
                if(ny<0 || w<=ny) continue;
                if(g[nx][ny] == -1) continue;
                int e2 = nx*w+ny;
                UF.unite(e1,e2);
            }
        }
        if(type==2)
        {
            int xa,ya,xb,yb;
            cin >> xa >> ya >> xb >> yb;
            --xa,--ya,--xb,--yb;
            
            int e1 = xa*w+ya;
            int e2 = xb*w+yb;
            if(e1==e2 && g[xa][ya]==-1) cout << "No" << endl;
            else if(UF.same(e1,e2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
