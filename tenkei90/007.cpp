//
// Created by 原田 on 2021/07/16.
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
    int n;
    cin>>n;
    vi class_l(n + 2);
    class_l[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin>>class_l[i];
    }
    class_l[n+1] = INF + 10;

    sort(all(class_l));

    int q;
    cin>>q;

    while(q){
        q--;
        ll ans = 0;
        int b;
        cin>>b;

        int ok = 0;
        int ng = n + 1;
        while(ng - ok > 1){
            int  mid = (ok + ng )/ 2;
            if(class_l[mid] < b){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        if(ok == 0){
            ans += abs(class_l[ng] - b);
        }else if(ng == n + 1){
            ans += abs(class_l[ok] - b);
        }else{
            ans += min(abs(class_l[ok] - b),abs(class_l[ng] - b));
        }
        cout<<ans<<endl;
    }

    return 0;
}
