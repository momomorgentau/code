//1964
//abc181_f_silver_woods
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

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
		if (x < y) swap(x, y);
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

const int top = 100;
const int bottom = -100;

double dist(int x1, int x2, int y1, int y2)
{
    double dx = (double) x1-x2;
    double dy = (double) y1-y2;
    return dx*dx+dy*dy;
}

int main()
{
    int n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    rep(i,n) cin >> x[i] >> y[i];

    double up = 200, low = 0;

    rep(bi,80)
    {
        double mid = (up+low)/2;
        UnionFind<int> uf(n+2);
        //壁同士の判定
        if(top-mid < bottom + mid) uf.unite(n,n+1);
        //上下の壁との判定
        rep(i,n)
        {
            if(y[i] + mid > top - mid) uf.unite(i,n);
            if(y[i] - mid < bottom + mid) uf.unite(i,n+1);
        }
        //釘同士の判定
        rep(i,n)rep(j,n)
        {
            if(i > j) continue;
            if(dist(x[i],x[j],y[i],y[j]) < 4*mid*mid) uf.unite(i,j);         
        }
        if(uf.same(n,n+1)) up = mid;
        else low = mid;
    }
    cout << setprecision(7) <<endl;
    cout << low << endl;
}