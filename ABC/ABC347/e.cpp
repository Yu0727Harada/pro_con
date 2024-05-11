//
// Created by yu on 2024/05/11.
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
    int n,q;
    cin>>n>>q;
    vi sum(n+10,0);
    vector<vector<int>> li(n,vector<int>());
    set<int>st;
    int size = 0;
    for (int i = 1; i <= q; ++i) {
        int x;
        cin>>x;
        x--;
        li[x].push_back(i);
        if(st.count(x) == 0){
            st.insert(x);
            size++;
            sum[i] = sum[i - 1] + size;
        }else{
            st.erase(x);
            size--;
            sum[i] = sum[i - 1] + size;
        }
    }

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < li[i].size(); j += 2) {
            if(li[i].size() == j + 1){
                ans += sum[q] - sum[li[i][j] - 1];
            }else{
                ans += sum[li[i][j + 1] -1] - sum[li[i][j] - 1];
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}
