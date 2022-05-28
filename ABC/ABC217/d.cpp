//
// Created on 2021/09/04.
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

    ll l;
    int q;
    cin>>l>>q;
    set<int>a;
    a.insert(0);
    a.insert(l);

    while(q){
        q--;
        int c;
        ll x;
        cin>>c>>x;
        if(c == 1){
            a.insert(x);

        }else{
//            int ok = a.size() - 1;
//            int ng = 0;
//            int mid;
            int target;
            target = x;
//            while(abs(ok - ng) > 1){
//                mid = (ok + ng) / 2;
//                if(a[mid] < target){
//                    ng = mid;
//                }else{
//                    ok = mid;
//                }
//            }
            auto index = a.lower_bound(target);
            auto max_index = index--;
            int max_v = *max_index;
            int min_v = *index;
            cout<<max_v - min_v<<endl;
        }
    }


    return 0;
}