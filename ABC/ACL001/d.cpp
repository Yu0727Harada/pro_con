//
// Created on 2020/09/26.
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
    int n,k;
    cin>>n>>k;

    vector<vector<int>>g(n+1,vector<int>());
    vector<int>A(n+1);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin>>a;
        A[i] = a;
        for (int j = 1; j < i; ++j) {
            if(abs(A[j] - a) <= k){
                g[j].push_back(i);
            }
        }
    }
    int ans = 0;
    stack<pair<int,int>>q;
    vector<int>cnt(n+1,-1);
    for (int i = 1; i <= n; ++i) {
        if(cnt[i] == -1){
            q.push({i,1});
        }
        while(!q.empty()){
            int v = q.top().first;
            int c = q.top().second;
            q.pop();
            if(cnt[v] < c){
                cnt[v] = c;
                for (int j = 0; j < g[v].size(); ++j) {
                    if(cnt[v] < c + 1){
                        q.push({g[v][j],c+1});
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        chmax(ans,cnt[i]);
    }

    cout<<ans<<endl;
    return 0;
}
