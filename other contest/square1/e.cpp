//
// Created on 2020/09/02.
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

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
const long long mod = 1000000007;

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

mint dis(ll last,ll target){
    vector<mint>beki(34);
    mint ret=1;
    beki[0] = last;
    for (int i = 1; i < 31; ++i) {
        beki[i] = beki[i-1] * beki[i-1];
    }
    for (int i = 0; i < 31; ++i) {
        if(target & (1<<(i))){
            ret *= beki[i];
        }
    }
    return ret;
}

int main() {
    int n;
    int q;
    cin>>n>>q;
    vector<ll>city(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>city[i];
    }
    int now = 1;
    int next = 2;
    vector<mint>ans_list(n+1,0);
    mint sum = 0;
    for (int i = 2; i <= n; ++i) {
        mint distance = dis(city[now],city[next]);
        sum += distance;
        ans_list[i] = sum;
        now = next;
        next ++;
    }
    mint ans;
    now = 1;
    for (int i = 0; i < q; ++i) {
        cin>>next;
        if(next < now)ans += (ans_list[now] - ans_list[next]);
        else ans += (ans_list[next] - ans_list[now]);
        now = next;
    }
    next = 1;
    if(next < now)swap(next,now);
    ans += (ans_list[next] - ans_list[now]);

    cout<<ans.x<<endl;
    return 0;
}
/*
E - 散歩 (E869120 and Path Length) 解説
        https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e
        べき乗
        繰り返し二乗法

        */
