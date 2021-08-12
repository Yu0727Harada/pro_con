//
// Created by 原田 on 2021/08/02.
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
    vvi edge(n,vi());
    vi memo(n,INF);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vi odd;
    vi even;

    queue<pair<int,int>>q;
    memo[0] = 1;
    odd.push_back(0 + 1);

    q.push({0,1});
    while(!q.empty()){
        int v = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < edge[v].size(); ++i) {
            if(memo[edge[v][i]] > cnt + 1){
                q.push({edge[v][i],cnt+1});
                memo[edge[v][i]] = cnt + 1;
                if((cnt + 1) % 2 == 0)even.push_back(edge[v][i] + 1);
                else odd.push_back(edge[v][i] + 1);
            }
        }
    }

    if(odd.size() > even.size()){
        for (int i = 0; i < n/2; ++i) {
            cout<<odd[i]<<endl;
        }
    }else{
        for (int i = 0; i < n/2; ++i) {
            cout<<even[i]<<endl;
        }
    }

    return 0;
}
