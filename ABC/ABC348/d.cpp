//
// Created by yu on 2024/05/10.
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
    int h,w;
    cin>>h>>w;
    vvi g(h,vi(w,1));
    pair<int,int> st;
    pair<int,int> en;
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < w; ++j) {
            if(s[j] == '#'){
                g[i][j] = 0;
            }else if(s[j] == 'S'){
                st = {i,j};
            }else if(s[j] == 'T'){
                en = {i,j};
            }
        }
    }
    int n;
    cin>>n;
    vvi el(h,vi(w,0));
    vvi edge(h*w,vi());
    for (int i = 0; i < n; ++i) {
        int r,c,e;
        cin>>r>>c>>e;
        r--;c--;
        el[r][c] = e;
    }

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
                {-1, 0},
                {0,  -1},
        };
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(el[i][j]){
                queue<pair<int,pair<int,int>>>q;
                q.push({el[i][j],{i,j}});
                vvi visit(h,vi(w,0));
                visit[i][j] = 1;
                while(!q.empty()){
                    int cnt = q.front().first;
                    pair<int,int> v = q.front().second;
                    q.pop();
                    if(cnt - 1 < 0)break;
                    for (int k = 0; k < 4; ++k) {
                        if(0 <= v.first + move[k].first && v.first + move[k].first < h && 0 <= v.second + move[k].second && v.second + move[k].second < w){
                           if(visit[v.first + move[k].first][v.second + move[k].second] || !g[v.first + move[k].first][v.second + move[k].second])continue;

                           q.push({cnt - 1,{v.first + move[k].first,v.second + move[k].second}});
                            visit[v.first + move[k].first][v.second + move[k].second] = 1;

                        }
                    }
                }
                for (int k = 0; k < h; ++k) {
                    for (int l = 0; l < w; ++l) {
                        if(visit[k][l] && (el[k][l] || (k == en.first && l == en.second))){
                            if(i == k && l == j)continue;
                            edge[i * w + j].push_back(k*w + l);
                        }
                    }
                }
            }
        }
    }

    queue<int>q;
    q.push(st.first * w + st.second);
    vi visit(h * w,0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for (int i = 0; i < edge[v].size(); ++i) {
            if(!visit[edge[v][i]]){
                q.push(edge[v][i]);
                visit[edge[v][i]] = 1;
                if(edge[v][i] == en.first * w + en.second){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;

    return 0;
}

