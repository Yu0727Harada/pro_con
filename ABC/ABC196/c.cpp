//
// Created on 2021/03/20.
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
    ll n;
    cin>>n;
    ll ans = 0;

//    vector<ll> num(6,-1);
//
    vector<ll> z = {1,10,100,1000,10000,100000,1000000,10000000};
//
//    queue<vector<ll>> st;
//    st.push(num);
//    while (!st.empty()) {
//
//        auto temp = st.front();
//        st.pop();
//        int keta = -1;
//        for (int j = 0; j < 6; ++j) {
//            if(temp[j] == -1){
//                keta = j;
//                break;
//            }
//        }
//        if(keta == -1){


//            ll a = 0;
//            int cnt = 0;
//            for (int j = 0; j < 6; ++j) {
//                if(temp[j] == 0 && cnt == 0){
//
//                }else{
//                    if(temp[j] == 0){
//                        a *= 10;
//                    }else{
//                        a += temp[j] * z[cnt];
//                    }
//                    cnt ++;
//                }
//            }
//            a += a * z[cnt];

    for (ll i = 1; i <= 1000000; ++i) {
        string s_a = to_string(i);
        ll a = i + i * z[s_a.size()];
        if(1 <= a && a <= n){
            string s = to_string(a);
            if(s.size() % 2 == 0) {
                bool ok = true;
                for (int j = 0; j < s.size() / 2; ++j) {
                    if(s[j] == s[j + s.size()/2]){
                        continue;
                    }else{
                        ok = false;
                        break;
                    }
                }
                if(ok)ans ++;
            }
        }
    }
//    if(keta != -1){
//        for (int j = 0; j <= 9; ++j) {
//            temp[keta] = j;
//            st.push(temp);
//        }
//    }







    cout<<ans<<endl;
    return 0;
}
