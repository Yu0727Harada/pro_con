//
// Created on 2020/11/22.
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



int main() {

    ll r1,c1;
    ll r2,c2;
    cin>>r1>>c1;
    cin>>r2>>c2;

    ll b1_plus = r1-c1;
    ll b1_minus = r1+c1;
    ll b2_plus = r2-c2;
    ll b2_minus = r2+c2;
    int ans;
    if(r1 == r2 && c1 == c2){
        cout<<0<<endl;
        return 0;
    }

    if((r1+c1) == (r2 + c2) || (r1-c1) == (r2 - c2) || abs(r1 - r2) + abs(c1 - c2) <= 3 ){
        //範囲内にいるなら1手で移動
        ans = 1;
        cout<<ans<<endl;
        return 0;
    }
    if ((r1 + c1)%2 == ( r2 + c2)%2) {
        //二回になななめ移動していけるなら2手
        ans = 2;
        cout<<ans<<endl;
        return 0;
    }
    int x = c2;
    int y = -1 * x + b1_minus ;
    if(abs(y - r2) + abs(x - c2) <= 3 ){
        cout<<2<<endl;
        return 0;
    }
    y = x + b1_plus ;
    if(abs(y - r2) + abs(x - c2) <= 3 ){
        cout<<2<<endl;
        return 0;
    }

    if(abs(r1 - r2) + abs(c1 - c2) <= 6){
        cout<<2<<endl;
        return 0;
    }

    ans = 3;
    cout << ans << endl;
    return 0;

}

