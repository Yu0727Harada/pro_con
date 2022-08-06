//
// Created by 原田 on 2021/07/01.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

vector<pair<ll,ll>> b;
ll ans;
void cnt(ll m,ll n){//m=>階層数,n=>バーガーのレベル
    if(m == 1 && n > 0){
        ans += 0;
        return ;
    }else if(m == 1 && n == 0){
        ans += 1;
        return ;
    }
    else if(m == b[n - 1].first + 1){
        ans += b[n - 1].second;
        return ;
    }else if(m < b[n - 1].first + 1){
        cnt(m - 1,n - 1);
    }else if(m == b[n - 1].first + 2){
        ans += b[n - 1].second + 1;
        return ;
    }else if(m == b[n - 1].first + b[n - 1].first + 3){
        ans += b[ n - 1].second + 1 + b[n - 1].second;
        return ;
    }else if(m > b[n - 1].first + 2){
        ans += b[n - 1].second + 1;
        cnt(m - b[n - 1].first - 2,n - 1);
    }

}

int main() {

    ll n;
    cin>>n;
    ll x;
    cin>>x;
    ans = 0;
    b.resize(51,{0,0});

    b[0] = {1,1};//all,patty
    for (int i = 1; i <= 50; ++i) {
        b[i] = {2 * b[i - 1].first + 3,2 * b[i - 1].second + 1};
    }

    cnt(x,n);
    cout<<ans<<endl;



    return 0;
}
