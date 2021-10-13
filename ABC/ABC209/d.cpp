//
// Created by 原田 on 2021/09/30.
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
    int q;
    cin>>n>>q;

    vvi edge(n,vi());
    vi node(n,-1);

    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<pair<int,int>>q_e;
    q_e.push({0,0});

    while(!q_e.empty()){
        int v = q_e.front().first;
        int c = q_e.front().second;
        q_e.pop();

        for (int i = 0; i < edge[v].size(); ++i) {
            if(node[edge[v][i]] == -1){
                node[edge[v][i]] = (c + 1) % 2;
                q_e.push({edge[v][i],(c + 1) % 2});
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int t,a;
        cin>>t>>a;
        t--;
        a--;
        if(node[t] == node[a]){
            cout<<"Town"<<endl;
        }else{
            cout<<"Road"<<endl;
        }
    }

    return 0;
}
