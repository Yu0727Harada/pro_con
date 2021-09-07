
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
#include <atcoder/all>
#include "../../atcoder/lazysegtree.hpp"

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

vector<mint>ten;
vector<mint>one;

struct S{
    mint val;
    int len;
};

using F = int;

S op(S s_l, S s_r){
    return {s_l.val * ten[s_r.len] + s_r.val,s_l.len + s_r.len};
}

S e(){
    return {0,0};
}

S mapping(F f,S s){
    if(f == -1)return s;
    return {(mint)f * one[s.len],s.len};
}

F composition(F f,F g){
    if(f == -1) return g;
    else return f;

}

F id(){
    return -1;
}

int main() {
    int n;
    cin>>n;
    int q;
    cin>>q;


    ten.resize(n+1);
    one.resize(n+1);
    ten[0] = 1;
    for (int i = 1; i <= n; ++i) {
        ten[i] = ten[i-1] * 10;
    }
    one[1] = 1;
    for (int i = 2; i <= n; ++i) {
        one[i] = one[i-1] + ten[i-1];
    }

    vector<S>v(n,{1,1});

    atcoder::lazy_segtree<S,op,e,F,mapping,composition,id>seg(v);

    while(q){
        q--;
        int l,r;
        int d;
        cin>>l>>r>>d;
        l--;
        seg.apply(l,r,d);
        cout<<seg.all_prod().val.x<<endl;
    }

    return 0;
}
