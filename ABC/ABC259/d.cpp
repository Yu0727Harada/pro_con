//
// Created on 2022/07/09.
//


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>
//#include <atcoder/all>


#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

struct UnionFind {
    vector<int>d;//リンクの情報,子の場合は親の番号、親の場合は連結成分のsize*(-1)
    UnionFind(int n=0):d(n,-1){} //structの初期化。デフォルトのnを0に設定してdを-1(すなわち全ての成分は親であり、サイズは1にする
    int find(int x) {//根を探す
        if(d[x] < 0) return x;
        else  return d[x] = find(d[x]);//根じゃなかったら根を探しに行ってメモ化する。
    }
    bool unite(int x,int y) {//成分を連結する
        x = find(x);
        y = find(y);
        if (x == y) return false;//すでに同じ連結成分
        if(d[x] < d[y]) swap(x,y);//大きいのに小さいのをつける。x←y
        //x.size > y.size
        d[x] += d[y];//xのサイズをふやす
        d[y] = x;//yの根をxにする
        return true;
    }
    bool same(int x,int y) {return find(x)==find(y);}
    int size(int x) {return -d[find(x)];}

};

int main() {
    int n;
    cin>>n;

    ll sx,sy;
    cin>>sx>>sy;
    ll tx,ty;
    cin>>tx>>ty;
    vector<pair<pair<ll,ll>,ll>>v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i].first.first>>v[i].first.second>>v[i].second;
    }

    UnionFind u(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j)continue;
            ll d = ((v[j].first.first - v[i].first.first) * (v[j].first.first - v[i].first.first)) + ((v[j].first.second - v[i].first.second) * (v[j].first.second - v[i].first.second));
            if(d == abs(v[j].second - v[i].second) * abs(v[j].second - v[i].second)){
                u.unite(i,j);
            }else if((abs(v[i].second - v[j].second) * abs(v[i].second - v[j].second)) < d && d < (v[i].second + v[j].second) * (v[i].second + v[j].second)){
                u.unite(i,j);
            }else if(d == (v[i].second + v[j].second) * (v[i].second + v[j].second)){
                u.unite(i,j);
            }
        }
    }

    int s_c = -1;
    int t_c = -1;
    for (int i = 0; i < n; ++i) {
        if(((sx - v[i].first.first)  * (sx - v[i].first.first)) + ((sy - v[i].first.second) * (sy - v[i].first.second)) == v[i].second * v[i].second){
            s_c = i;
        }
        if((tx - v[i].first.first) * (tx - v[i].first.first) + (ty - v[i].first.second) * (ty - v[i].first.second) == v[i].second * v[i].second){
            t_c = i;
        }
    }

    if(u.same(s_c,t_c)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
