//
// Created on 2020/08/19.
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
const long long INF = 1e11;

vector<ll> dik(vector<vector<ll>>e, int start){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>q;
    vector<ll>dist(e.size()+1,INF);
    dist[start] = 0;
    vector<ll>c(e.size()+1,0);//0->まだ　1->候補 2->済
    c[start] = 2;
    q.push({0,start});

    while(!q.empty()){
        auto sum = accumulate(all(c),0LL);
        if(sum >= 2 * c.size()-1)break;
        //0LL long long,0 int,0.0 double
        int d = q.top()[0];
        int b = q.top()[1];
        q.pop();
        c[b] = 2;
        if(dist[b] < d)continue;
        for (int i = 1; i < e.size(); ++i) {
            if(c[i] != 2 && e[b][i] < INF){
                c[i] = 1;
                if(dist[i] > dist[b] + e[b][i]){
                    dist[i] = dist[b] + e[b][i];
                    q.push({dist[i],i});
                }
            }
        }
    }
    return dist;

}


int main() {
    int n,k;
    cin>>n>>k;
    vector<vector<ll>>edge(n+1,vector<ll>(n+1,INF));
    for (int i = 0; i < k; ++i) {
        int q;
        cin>>q;
        if(q){
            ll c,d,e;
            cin>>c>>d>>e;
            chmin(edge[c][d],e);
            chmin(edge[d][c],e);

        }else{
            ll a,b;
            cin>>a>>b;
            auto distance = dik(edge,a);
            if(distance[b] >= INF){
                cout<<-1<<endl;
            }else{
                cout<<distance[b]<<endl;
            }
        }

    }
    return 0;
}
