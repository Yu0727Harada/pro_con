//
// Created on 2022/07/02.
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
    ll n,q,x;
    cin>>n>>q>>x;
    vl w(n);
    for (int i = 0; i < n; ++i) {
        cin>>w[i];
    }
    vi visit(n);
    vi mod_route;
    vi mod_potato;
    int pre_i = 0;
    int now_i = 0;
    while(true){
        int n_w = 0;
        int cnt = 0;
        while(n_w < x){
            n_w += w[now_i % n];
            now_i++;
            cnt++;
        }
        if(visit[pre_i % n] == 1){
            break;
        }else{
            mod_potato.push_back(cnt);
            mod_route.push_back(pre_i % n);
            visit[pre_i % n] = 1;
        }
        pre_i = now_i;
    }
    bool find = false;
    vi mod_ans;
    for (int i = 0; i < mod_route.size(); ++i) {
        if(mod_route[i] == pre_i % n)find = true;
        if(find)mod_ans.push_back(mod_potato[i]);
    }
    for (int i = 0; i < q; ++i) {
        ll k;
        cin>>k;
        k --;
        if(k <= mod_potato.size()) {
            cout << mod_potato[k] << endl;
        }else{
            k -= mod_potato.size();
            cout<<mod_ans[k % mod_ans.size()]<<endl;
        }
    }




    return 0;
}
