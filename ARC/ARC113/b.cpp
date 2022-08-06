//
// Created by 原田 on 2021/11/11.
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

const int mod = 4;

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

int main() {
    ll a;
    mint b;
    ll c;
    cin>>a>>b.x>>c;

    map<ll,int>a_mp;
    vl a_v;
    a_v.push_back(a % 10);
    a_mp[a%10]++;
    for (int i = 1; i < 4; ++i) {
        a_mp[a_v[i-1] * a % 10]++;
        a_v.push_back(a_v[i-1] * a % 10);
    }

    mint bc_m;
    bc_m = mod_pow(b,c);
    ll ans;
    bc_m.x %= 4;
    if(bc_m.x == 0){
        ans =a_v[a_v.size()-1] % 10;
    }else{
        ans = a_v[bc_m.x - 1] % 10;
    }
    cout<<ans<<endl;



    return 0;
}
