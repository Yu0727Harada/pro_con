//
// Created by yu on 2023/12/16.
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
    cin>>n;
    vector<pair<int,int>>event(n);
    for (int i = 0; i < n; ++i) {
        cin>>event[i].first>>event[i].second;
        event[i].second--;
    }
    vi item(n,0);
    deque<int> ans;
    int l_ans = 0;
    int ll_ans = 0;
    for (int i = n-1; 0 <= i; --i) {
        if(event[i].first == 2){
            item[event[i].second]++;
            l_ans++;
            chmax(ll_ans,l_ans);
        }else{
            if(item[event[i].second] > 0){
                l_ans--;
                ans.push_front(1);
                item[event[i].second]--;
            }else{
                ans.push_front(0);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if(item[i] != 0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ll_ans<<endl;
    while (!ans.empty()) {
        cout<<ans.front()<<endl;
        ans.pop_front();
    }
    return 0;
}
