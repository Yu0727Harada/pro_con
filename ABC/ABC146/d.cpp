
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

class edge{
public:
    int a;
    int b;
    int c;
    edge(){
        a = -1;
        b = -1;
        c = -1;
    }
};

int main() {
    int n;
    cin>>n;

    vector<edge> l(n-1);
    vector<vector<pair<int,int>>> g(n,vector<pair<int,int>>());
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        l[i].a = a;
        l[i].b = b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    vi visit(n,0);
    queue<int>q;
    visit[0] = 1;
    q.push(0);
    int k = 0;
    while(!q.empty()){
        int n_v = q.front();
        q.pop();
        set<int> used;
        for(auto item:g[n_v]){
            if(l[item.second].c != -1){
                used.insert(l[item.second].c);
            }
        }
        int low = 1;
        for(auto item:g[n_v]){
            if(l[item.second].c == -1){
                for (int i = low; i < INF; ++i) {
                    if(used.count(i) > 0)continue;
                    else{
                        l[item.second].c = i;
                        chmax(k,i);
                        used.insert(i);

                        q.push(item.first);
                        visit[item.first] = 1;
                        low = i;
                        break;
                    }
                }
            }
        }

    }
    cout<<k<<endl;
    for (int i = 0; i < n-1; ++i) {
        cout<<l[i].c<<endl;
    }
    return 0;
}
