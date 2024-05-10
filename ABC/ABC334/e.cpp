//
// Created by yu on 2023/12/23.
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
const int mod = 998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main() {
    int h,w;
    cin>>h>>w;
    vector<string>g(h);

    for (int i = 0; i < h; ++i) {
        cin>>g[i];
    }
    UnionFind u(h * w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(g[i][j] == '#'){
                if(i + 1 < h){

                    if(g[i + 1][j] == '#'){
                        u.unite(i * h + j,(i + 1) * h + j);
                    }
                }
                if( i - 1 >= 0){
                    if(g[i - 1][j] == '#'){
                        u.unite((i - 1) * h + j,i * h + j);
                    }

                }
                if(j + 1 < w){
                    if(g[i][j + 1] == '#'){
                        u.unite(i * h + j,i * h + j + 1);
                    }
                }
                if(j - 1 >= 0){
                    if(g[i][j - 1] == '#'){
                        u.unite(i * h + j,i * h + j - 1);
                    }
                }
            }
        }
    }
    int cnt = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(g[i][j] == '#'){
                if(u.d[h * i + j] <0)cnt++;

            }
                    }
    }

    ll ans_p = 0;
    ll q = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(g[i][j] == '.'){
                if(i + 1 < h){

                    if(g[i + 1][j] == '#'){
                        q ++;

                        if(u.same(i * h + j,(i + 1) * h + j)){
                            ans_p += cnt - 1;
                        }else{
                            ans_p += cnt;
                        }
                    }
                }
                if( i - 1 >= 0){
                    if(g[i - 1][j] == '#'){
                        q ++;
                        if(u.same((i - 1) * h + j,i * h + j)){
                            ans_p += cnt +1;
                        }else{
                            ans_p += cnt;
                        }
                    }

                }
                if(j + 1 < w){
                    if(g[i][j + 1] == '#'){
                        q ++;
                        if(u.same(i * h + j,i * h + j + 1)){
                            ans_p += cnt +1;
                        }else{
                            ans_p += cnt;
                        }
                    }
                }
                if(j - 1 >= 0){
                    if(g[i][j - 1] == '#'){
                        q ++;
                        if(u.same(i * h + j,i * h + j - 1)){
                            ans_p += cnt +1;
                        }else{
                            ans_p += cnt;
                        }
                    }
                }
            }
        }
    }
    mint ans = ans_p;
    ans /= q;
    cout<<ans.x<<endl;
    return 0;
}
