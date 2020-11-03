//
// Created on 2020/11/01.
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
    int n,m;
    cin>>n>>m;
    vector<int>h(n+1);
    for (int i = 0; i < n; ++i) {
        cin>>h[i];
    }
    h[n] = INF;
    vector<int>w(m);
    for (int j = 0; j < m; ++j) {
        cin>>w[j];
    }
    sort(all(h));
    ll ans = LINF;


    vector<int>mae(n);
    mae[0] = abs(h[0]-h[0+1]);
    for (int i = 2; i < n; i+=2) {
        mae[i] = mae[i-2] + abs(h[i]-h[i+1]);
    }
    vector<int>ushiro(n+3,0);
    for (int l = n-1; l >= 0; l-=2) {
        ushiro[l] = ushiro[l+2] + abs(h[l]-h[l-1]);
    }

    for (int k = 0; k < m; ++k) {
        int ok = n;
        int ng = 0;
        int mid =  (ok + ng)/2;
        while(abs(ok - ng) > 1){
            if(h[mid] >= w[k]){
                ok = mid;
            }else{
                ng = mid;
            }
            mid =  (ok + ng)/2;
        }
        ll temp_ans = 0;
        if(ok % 2 ==0){
            temp_ans+=mae[ok-2];
            temp_ans += abs(w[k] - h[ok]);
            temp_ans += ushiro[ok+2];
        }else{
            if(ok-3>=0){
                temp_ans+=mae[ok-3];
            }
            temp_ans += abs(w[k] - h[ok-1]);
            temp_ans+=ushiro[ok+1];
        }
        ans = min(temp_ans,ans);
    }
    cout<<ans<<endl;

    return 0;
}
