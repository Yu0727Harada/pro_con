//
// Created on 2021/11/20.
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

const int mod = 998244353;
const int mod_1 = 998244352;

struct mint_1 {
    ll x; // typedef long long ll;
    mint_1(ll x=0):x((x%mod_1+mod_1)%mod_1){}
    mint_1 operator-() const { return mint_1(-x);}
    mint_1& operator+=(const mint_1 a) {
        if ((x += a.x) >= mod_1) x -= mod_1;
        return *this;
    }
    mint_1& operator-=(const mint_1 a) {
        if ((x += mod_1-a.x) >= mod_1) x -= mod_1;
        return *this;
    }
    mint_1& operator*=(const mint_1 a) {
        (x *= a.x) %= mod_1;
        return *this;
    }
    mint_1 operator+(const mint_1 a) const {
        mint_1 res(*this);
        return res+=a;
    }
    mint_1 operator-(const mint_1 a) const {
        mint_1 res(*this);
        return res-=a;
    }
    mint_1 operator*(const mint_1 a) const {
        mint_1 res(*this);
        return res*=a;
    }
    mint_1 pow(ll t) const {
        if (!t) return 1;
        mint_1 a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod_1
    mint_1 inv() const {
        return pow(mod_1-2);
    }
    mint_1& operator/=(const mint_1 a) {
        return (*this) *= a.inv();
    }
    mint_1 operator/(const mint_1 a) const {
        mint_1 res(*this);
        return res/=a;
    }
};

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

mint mod_pow (mint a, ll n){
    mint ret;
    if(n == 0) {
        ret.x = 1;
        return ret;
    }
    if(n == 1){
        ret = a;
        return ret;
    }
    if( n % 2 == 1){
        return (a * mod_pow(a,n - 1));
    }
    mint t = mod_pow(a,n / 2);
    return t * t;
}
//a^nを計算する
mint_1 mod_pow_1 (mint_1 a, ll n){
    mint_1 ret;
    if(n == 0) {
        ret.x = 1;
        return ret;
    }
    if(n == 1){
        ret = a;
        return ret;
    }
    if( n % 2 == 1){
        return (a * mod_pow_1(a,n - 1));
    }
    mint_1 t = mod_pow_1(a,n / 2);
    return t * t;
}

int main() {
    ll n,k,m;
    cin>>n>>k>>m;
    if(m % mod == 0){
        cout<<0<<endl;
    }else{
        mint_1 kn;
        kn = mod_pow_1(k,n);
        mint ans = mod_pow(m,kn.x);
        cout<<ans.x<<endl;

    }

    return 0;
}
