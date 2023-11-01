//
// Created on 2023/07/18.
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

#include <iostream>
#include <vector>
using namespace std;

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(ll N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}


int main() {
    ll n;
    cin>>n;

    vector<bool> l = Eratosthenes(1001000);

    vector<ll> li;

    for (ll i = 2; i < 1001000; ++i) {
        if(l[i])li.push_back(i);
    }

    ll t = li.size();
    ll ans = 0;
    for (ll i = 0; i < t; ++i) {

        ll ok_j = i;
        ll ng_j = t;
        ll mid_j;
        while((ng_j - ok_j) > 1){
            mid_j = (ok_j + ng_j) / 2;
            ll x = li[i] * li[i];
            if(x > LINF / li[mid_j - 1]){
                ng_j = mid_j;
                continue;
            }
            x *= li[mid_j - 1];
            if(x > LINF / li[mid_j]){
                ng_j = mid_j;
                continue;
            }
            x *= li[mid_j];
            if(x > LINF / li[mid_j]){
                ng_j = mid_j;
                continue;
            }
            x *= li[mid_j];

            if(x > n){
                ng_j = mid_j;
            }else{
                ok_j = mid_j;
            }
        }
        if(i + 1 < ok_j){

            ans += ((ok_j - i) * ((ok_j - i) - 1)) / 2;
        }else{
            continue;
        }

        ll j = ok_j + 1;
        ll y;
        y = li[i] * li[i];
        if(y > LINF / li[i + 1]){
            continue;
        }
        y *= li[i + 1];
        if(y > LINF / li[j]){
            continue;
        }
        y *= li[j];
        if(y > LINF / li[j]){
            continue;
        }
        y *= li[j];
        while(y <= n){

            ll ok = i;
            ll ng = j;
            ll mid;
            while((ng - ok) > 1){
                mid = (ok + ng) / 2;
                ll x = li[i] * li[i];
                if(x > LINF / li[mid]){
                    ng = mid;
                    continue;
                }
                x *= li[mid];
                if(x > LINF / li[j]){
                    ng = mid;
                    continue;
                }
                x *= li[j];
                if(x > LINF / li[j]){
                    ng = mid;
                    continue;
                }
                x *= li[j];
                if(x > n){
                    ng = mid;
                }else{
                    ok = mid;
                }
            }
            if(i < ok && ok < j) {
                ans += ok - i;
            }
            j++;
            y = li[i] * li[i];
            if(y > LINF / li[i + 1]){
                break;
            }
            y *= li[i + 1];
            if(y > LINF / li[j]){
                break;
            }
            y *= li[j];
            if(y > LINF / li[j]){
                break;
            }
            y *= li[j];
        }

    }
    cout<<ans<<endl;
    return 0;
}
