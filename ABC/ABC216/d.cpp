//
// Created on 2021/08/29.
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

vector<int> h; //入次数
vector<int> l_depth; //最大経路長
vector<int> ans; //答えを格納
int n;
vvi edge;

void topoBFS(){
    queue<int> unchecked;
    for(int i=0; i<n; i++){
        if(h[i]==0){
            unchecked.push(i); //入次数が0の頂点をキューに入れる
            l_depth[i] = 0; //そのような頂点は深さが0
        }
    }
    while(!unchecked.empty()){
        int current = unchecked.front();
        unchecked.pop();
        ans.push_back(current); //キューから取り出したらすぐソート後のリストに加える

        for(int next: edge[current]){ //「行ける」頂点について
            h[next]--; //入次数を減らす
            l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路
            if(h[next]==0){ //入次数0になったらキューに追加
                unchecked.push(next);
            }
        }
    }
}

int main() {

    int m;
    cin>>n>>m;

    edge.resize(n,vi());
    h.resize(n,0);
    for (int i = 0; i < m; ++i) {
        int k;
        cin>>k;
        int last;
        cin>>last;
        last--;
        for (int j = 1; j < k; ++j) {
            int now;
            cin>>now;
            now--;
            edge[last].push_back(now);
            h[now]++;
            last = now;
        }
    }
    l_depth.resize(n, -1);
    topoBFS();

    bool isDAG = ans.size()==n; //DAGであるかどうか
    if(isDAG){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
