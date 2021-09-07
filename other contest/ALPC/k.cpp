//
// Created by 原田 on 2021/08/16.
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
#include <atcoder/all>

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

class F{
public:
    mint sum;
    mint len;
};

class S{
public:
    mint b;
    mint c;
};

F op(F s_l,F s_r){
    return {s_l.sum + s_r.sum ,s_l.len + s_r.len};
}

F e(){
    return {0,0};
}

F mapping(S s,F f){
    return {f.sum*s.b+s.c*f.len,f.len};
}

S composition(S f,S g){
    return {f.b*g.b,f.b*g.c+f.c};
}

S id(){
    return {1,0};
}

int main() {

    int n,q;
    cin>>n>>q;

    vector<F> v(n);
    for (int i = 0; i < n; ++i) {
        mint a;
        cin>>a.x;
        v[i].sum = a;
        v[i].len = 1;
    }

    atcoder::lazy_segtree<F,op,e,S,mapping,composition,id>seg(v);

    while(q){
        q--;
        int k;
        cin>>k;
        if(k){
            int l,r;
            cin>>l>>r;
            cout<<seg.prod(l,r).sum.x<<endl;
        }else{
            int l,r;
            S s;
            cin>>l>>r;
            cin>>s.b.x>>s.c.x;
            seg.apply(l,r,s);
        }




    }

    return 0;
}
