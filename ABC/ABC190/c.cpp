//
// Created on 2021/01/30.
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



int main() {

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>zyouken;
    vector<pair<int,int>>person;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        zyouken.push_back({a,b});
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; ++i) {
        int c,d;
        cin>>c>>d;
        person.push_back({c,d});
    }

    int ans = 0;
    //n個の要素のbit全探索する
    for (int bit = 0; bit < (1<<k); ++bit) {
        vector<bool>dish(100,0);
            for (int i = 0; i < k; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    dish[person[i].first] = true;
                }else{
                    dish[person[i].second] = true;
                }
            }
            int t_ans = 0;
        for (int i = 0; i < m; ++i) {
            if(dish[zyouken[i].first] && dish[zyouken[i].second]){
                t_ans ++;
            }
        }
        chmax(ans,t_ans);
    }

    cout<<ans<<endl;
    return 0;

}
