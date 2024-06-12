
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

struct node{
public:
    int to_node;
    ll x_diff;
    ll y_diff;
    node(int _to,ll x,ll y){
        this->to_node = _to;
        this->x_diff = x;
        this->y_diff = y;
    }
};


int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>position(n,{-LINF - 10,-LINF - 10});//確定しているポジション
    position[0] = {0,0};

    vector<vector<node>>edge(n,vector<node>());

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        ll x,y;
        cin>>x>>y;
        node tmp(b,x,y);
        edge[a].push_back(tmp);
        node tmp2(a,-x,-y);
        edge[b].push_back(tmp2);
    }

    queue<int>q;
    q.push(0);
    vi visit(n,0);//-2 ->?
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(visit[v] == -2)continue;
        visit[v] = 1;
        for (int i = 0; i < edge[v].size(); ++i) {
            node next = edge[v][i];
            if(position[next.to_node].first == -LINF - 10 && position[next.to_node].second == -LINF -10){
                position[next.to_node] = {position[v].first + next.x_diff, position[v].second + next.y_diff};
                q.push(next.to_node);
            }else{
                if(position[next.to_node].first ==  position[v].first + next.x_diff && position[next.to_node].second == position[v].second + next.y_diff){
                    if(visit[next.to_node] == 0)q.push(next.to_node);
                }else{
                    visit[next.to_node] = -2;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if(position[i].first == -LINF -10 || visit[i] == -2 || visit[i] == 0){
            cout<<"undecidable"<<endl;
        }else{
            cout<<position[i].first<<" "<<position[i].second<<endl;
        }
    }

    return 0;
}
