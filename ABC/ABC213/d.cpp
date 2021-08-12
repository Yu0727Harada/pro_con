//
// Created on 2021/08/08.
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

vvi edge;
vector<int>visit;
vector<int>route;
vector<int>visit_2;


int main() {

    int n;
    cin>>n;

    edge.resize(n,vi());
    visit.resize(n,-1);
    visit_2.resize(n,0);

    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        sort(all(edge[i]));
    }

    stack<pair<int,int>>s;
    s.push({0,-2});

    while(!s.empty()){

        int next_city_index = INF;
        int now_v = s.top().first;
        int pre = s.top().second;
        s.pop();
        if(visit[now_v] == -1){
            visit[now_v] = pre;
        }
        route.push_back(now_v);

        for (int i = visit_2[now_v]; i < edge[now_v].size(); ++i) {
            if(edge[now_v][i] < next_city_index && visit[edge[now_v][i]] == -1){
                next_city_index = edge[now_v][i];
                visit_2[now_v] = i + 1;
                break;
            }
        }

        if(next_city_index == INF){
            if(now_v == 0){
                break;
            }
        }else{
            s.push({next_city_index,now_v});
            continue;
        }
        s.push({visit[now_v],-1});


    }
    cout<<route[0] + 1;
    for (int i = 1; i < route.size(); ++i) {
        cout<<" "<<route[i] + 1;
    }
    cout<<endl;
    return 0;
}


