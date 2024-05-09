//
// Created by yu on 2023/12/19.
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

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d < 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

int main() {
    ll h,w;
    cin>>h>>w;
    ll r_s,c_s;
    cin >> r_s >> c_s;
    r_s--;
    c_s--;
    int n;
    cin>>n;
    vi r_l(n);
    vi c_l(n);
    for (int i = 0; i < n; ++i) {
        int r,c;
        cin>>r>>c;
        r--;
        c--;
        r_l[i] = r;
        c_l[i] = c;

    }

    auto nr = r_l;
    auto nc = c_l;
    sort(all(nr));
    nr.erase(unique(all(nr)),nr.end());
    sort(all(nc));
    nc.erase(unique(all(nc)),nc.end());

    vi r_res;
    vi c_res;
    for (int i = 0; i < n; ++i) {
        int r_t = lower_bound(nr.begin(),nr.end(),r_l[i]) - nr.begin();
        int c_t = lower_bound(nc.begin(),nc.end(),c_l[i]) - nc.begin();
        r_res.push_back(r_t);
        c_res.push_back(c_t);
    }

    ll r_s_t = lower_bound(nr.begin(),nr.end(),r_s) - nr.begin();
    ll c_s_t = lower_bound(nc.begin(), nc.end(), c_s) - nc.begin();

    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        char d;
        cin>>d;
        ll dis;
        cin>>dis;

        if(d == 'U'){
            if(nr[r_s_t - 1] >= r_s - dis){
                r_s = nr[r_s_t - 1] + 1;
            }else{
                r_s = r_s - dis;
            }
        }else if(d == 'D'){
            if(nr[r_s_t + 1] <= r_s + dis){
                r_s = nr[r_s_t + 1] - 1;
            }else{
                r_s = r_s + dis;
            }
        }else if(d == 'R'){
            if(nc[c_s_t + 1] <= c_s + dis ){
                c_s = nc[c_s_t + 1] - 1;
            }else{
                c_s = c_s + dis;
            }
        }else if(d == 'L'){
            if(nc[c_s_t - 1]>= c_s - dis){
                c_s = nc[c_s_t - 1] + 1;
            }else{
                c_s = c_s - dis;
            }
        }
        r_s_t = lower_bound(nr.begin(),nr.end(),r_s) - nr.begin();
        c_s_t = lower_bound(nc.begin(), nc.end(), c_s) - nc.begin();
        cout<<r_s + 1<<" "<<c_s + 1<<endl;
    }

    return 0;
}
