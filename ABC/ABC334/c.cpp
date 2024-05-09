//
// Created by yu on 2023/12/23.
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
    int n;
    int k;
    cin>>n>>k;
    vi k_l(k);

    for (int i = 0; i < k; ++i) {
        cin>>k_l[i];
    }
    if(k % 2 == 0){
        ll ans = 0;
        for (int i = 0; i < k; i += 2) {
            ans += abs(k_l.at(i) - k_l.at(i + 1));
        }
        cout<<ans<<endl;
    }else{
        vi k_left(k,0);
        vi k_r(k,0);
        ll ans = LINF;
        for (int i = 0; i < k; i += 2) {
            if(i != 0){
                k_left.at(i) += k_left.at(i - 1);
                if(i + 1 != k)k_left.at(i + 1) += k_left.at(i - 1);
            }
            if(i + 1 != k){
                k_left.at(i) += abs(k_l.at(i) - k_l.at(i + 1));
                k_left.at(i + 1) += abs(k_l.at(i) - k_l.at(i + 1));
            }
        }
        for (int i = k - 1; i >= 0; i -= 2) {
            if(i != k -1){
                k_r.at(i) += k_r.at(i + 1);
                if(i != 0)k_r.at(i - 1) += k_r.at(i + 1);
            }
            if(i - 1 >= 0){
                k_r.at(i) += abs(k_l.at(i) - k_l.at(i - 1));
                k_r.at(i - 1) += abs(k_l.at(i) - k_l.at(i - 1));
            }
        }

        for (int i = 0; i < k; ++i) {
            ll cnt = 0;
            if(i >= 2){
                cnt += k_left[i - 2];
            }
            if(i + 2 <= k -1)cnt +=k_r[i + 2];
            if(i % 2 == 1){
                cnt += abs(k_l.at(i - 1) - k_l.at(i + 1));
            }
            chmin(ans,cnt);
        }
        cout<<ans<<endl;

    }

    return 0;
}
