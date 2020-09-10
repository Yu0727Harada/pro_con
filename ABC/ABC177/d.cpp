//
// Created on 2020/09/09.
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
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>friendship(n,vector<int>());

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
    queue<pair<int,int>>q;
    for (int i = 0; i < n; ++i) {

        q.push({i,1});
    }
    int ans = 0;
    int sum = 0;
    vector<bool>check(n,false);
    while(!q.empty()){
        int v = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(!check[v]){
            check[v] =true;
        }
        chmax(ans,cnt);
        for (int i = 0; i < friendship[v].size(); ++i) {
            if(!check[friendship[v][i]]){
                q.push({friendship[v][i],cnt+1});
                check[friendship[v][i]] = true;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
