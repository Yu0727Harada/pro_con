//
// Created on 2021/06/06.
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
    int m;
    cin>>n>>m;

    vector<vector<int>> e(n,vector<int>());
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        e[a].push_back(b);
    }

    vi cont(n,0);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vi visit(n,0);
        queue<int>q;
        q.push(i);
        visit[i] = 1;
        cnt++;
        while(!q.empty()){
            int n_v = q.front();
            q.pop();

            for(auto item:e[n_v]){
                if(visit[item] == 0) {
                    visit[item] = 1;
                    cnt ++;
                    q.push(item);
                }else{
//                    cnt += cont[item];
                }
            }
        }
        cont[i] = cnt;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cont[i] ;
    }
    cout<<ans<<endl;
    return 0;
}
