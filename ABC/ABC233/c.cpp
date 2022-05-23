//
// Created on 2021/12/25.
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

ll n,x;
ll ans;
void dfs(ll now_num, int now_box,vector<vector<ll>> box,int one_num,vl box_one){
    if(now_num == x && now_box == n){
        ans += one_num;
        return;
    }
    if(now_box == n)return;
    for (int i = 0; i < box[now_box].size(); ++i) {
        if(now_num <= LINF / box[now_box][i]){
            dfs(now_num * box[now_box][i],now_box + 1,box,one_num,box_one);
        }
    }
    if(box_one[now_box] > 0){
        dfs(now_num,now_box + 1,box,one_num * box_one[now_box],box_one);
    }

}

int main() {


    cin>>n>>x;

    vector<vector<ll>> box(n,vl());
    vl box_one(n,0);
    for (int i = 0; i < n; ++i) {
        ll l;
        cin>>l;
        for (int j = 0; j < l; ++j) {
            ll a;
            cin>>a;
            if(a == 1){
                box_one[i]++;
            }else{
                box[i].push_back(a);
            }
        }
    }

    ans = 0;
    dfs(1,0,box,1,box_one);

    cout<<ans<<endl;

    return 0;
}
