//
// Created by 原田 on 2022/05/16.
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



int main() {
    string s;
    cin>>s;
    int k;
    cin>>k;
    ll ans = 0;
    int now_k = 0;
    deque<int>d;
    char last = '@';
    ll x_cnt = 0;
    ll now_v = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'X'){
            if(last != 'X'){
                x_cnt = 1;
            }else{
                x_cnt ++;
            }
            last = 'X';
        }else if(s[i] == '.'){

            if(d.size() > k){
                now_v -= d.front();
                d.pop_front();
            }
            d.push_back(x_cnt);
            now_v += x_cnt;
            chmax(ans,now_v);
            last = '.';
            x_cnt = 0;
        }

    }
    if(d.size() > k){
        now_v -= d.front();
        d.pop_front();
    }
    d.push_back(x_cnt);
    now_v += x_cnt;
    chmax(ans,now_v);
    last = '.';
    chmax(ans,x_cnt);
    if(d.size() == 0 )cout<<ans<<endl;
    else cout<<ans + (d.size() - 1) <<endl;

    return 0;
}
//尺取り　左をforで回してやるとバグりにくい
//kを超えない高さで取れるところで二分探索する　尺取りは大体二分探索でかける
