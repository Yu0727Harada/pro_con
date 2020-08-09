//
// Created on 2020/05/31.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


vector<pair<ll,ll>>prime_factorize(ll n){
    vector<pair<ll,ll>>ret;
    for (ll i = 2; i * i < n ; ++i) {
        if(n % i == 0){
            ll ex = 0;//指数
            while(n % i == 0){
                ex++;
                n /= i;
            }
            ret.push_back({i, ex});
        }
    }
    if(n != 1){
        ret.push_back({n,1});
    }
    return ret;
    //example n = 12, ret = [[2,2],[3,1]と返す
}
//素因数分解

int main() {
    ll n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    vector<int>sum(1000);
    sum[1] = 1;
    for (int i = 2; i < 1000; ++i) {
        sum[i] = sum[i - 1] + i;
    }
    //1,2,3,4…の累積和の配列を作る

    auto p = prime_factorize(n);

    ll ans = 0;

    for(auto t_p : p){
        int u = 1000;
        int l = 0;
        int i = (u + l)/2;
        while(!(sum[i] <= t_p.second && t_p.second < sum[i + 1])){
            if(t_p.second < sum[i]){
                u = i;
                i = (u + l)/2;
            }else{
                l = i;
                i = (u+l)/2;
            }
        }
        ans += i;
    }

    cout<<ans<<endl;
    return 0;
}

/*
 正の整数 N が与えられます。N に対して、以下の操作を繰り返し行うことを考えます。

はじめに、以下の条件を全て満たす正の整数z を選ぶ。
ある素数p と正の整数e を用いて、z=pe と表せるN がz で割り切れる
以前の操作で選んだどの整数とも異なるN を、N/z に置き換える
最大で何回操作を行うことができるか求めてください。
 */