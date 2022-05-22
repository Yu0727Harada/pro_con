//
// Created on 2022/03/26.
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
    ll n,k;
    cin>>n>>k;
    vvi a(2,vi(n));
    vector<vector<ll>> edge(2 * n,vl());

    for (int i = 0; i < n; ++i) {
        cin>>a[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>a[1][i];
    }
    for (int i = 1; i < n; ++i) {

        if(abs(a[0][i] - a[0][i - 1]) <= k){
            edge[0 * n + i].push_back(0 * n + (i - 1));
            edge[0 * n + (i - 1)].push_back(0 * n + i);
        }
        if(abs(a[1][i] - a[0][i - 1]) <= k){
            edge[1 * n + i].push_back(i - 1);
            edge[i - 1].push_back(n + i);

        }
        if(abs(a[0][i] - a[1][i - 1]) <= k){
            edge[0 * n + i].push_back(1 * n + (i - 1));
            edge[1 * n + (i - 1)].push_back(0 * n + i);
        }
        if(abs(a[1][i] - a[1][i - 1]) <= k){
            edge[1 * n + i].push_back(n + i - 1);
            edge[n + i - 1].push_back(n + i);
        }

    }

    vi visit(2 * n,0);
    queue<ll>q;
    q.push(0);
    q.push(n);
    visit[0] = 1;
    visit[n] = 1;

    while(!q.empty()){
        int now_v = q.front();
        q.pop();
        for (int i = 0; i < edge[now_v].size(); ++i) {
            if(visit[edge[now_v][i]] == 0){
                q.push(edge[now_v][i]);
                visit[edge[now_v][i]] = 1;
            }
        }
    }
    if(visit[n - 1] == 1 || visit[2 * n - 1] == 1){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}
