//
// Created by yu on 2023/12/16.



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

   vvi edge(5,vi());
    for (int i = 0; i < 5; ++i) {
        if(i == 4){
            edge[i].push_back(0);
        }else {
            edge[i].push_back(i + 1);
        }
        if (i != 0) {
            edge[i].push_back(i - 1);
        }else{
            edge[i].push_back(4);
        }
    }

    string s;
    cin>>s;
    map<char,int>mp = {{'A',0},{'B',1},{'C',2},{'D',3},{'E',4}};

    int s1 =mp[s[0]];
    int s2 =mp[s[1]];
    string t;
    cin>>t;
    int t1 =mp[ t[0]];
    int t2 =mp[ t[1]];

    int dif_s = INF;
    queue<pair<int,int>>q;
    q.push({s1,0});
    vector<bool> visit(5,false);
    while(!q.empty()){
        int u = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visit[u] = true;
        if(u == s2){
            chmin(dif_s , cnt);
        }
        for (int i = 0; i < edge[u].size(); ++i) {
            if(visit[edge[u][i]] == false){
                q.push({edge[u][i],cnt+1});
            }
        }
    }
    queue<pair<int,int>>q_t;
    int dif_t = INF;
    q_t.push({t1,0});
    vector<bool> visit_t(5,false);
    while(!q_t.empty()){
        int u = q_t.front().first;
        int cnt = q_t.front().second;
        q_t.pop();
        visit_t[u] = true;
        if(u == t2){
            chmin(dif_t , cnt);
        }
        for (int i = 0; i < edge[u].size(); ++i) {
            if(visit_t[edge[u][i]] == false){
                q_t.push({edge[u][i],cnt+1});
            }
        }
    }
    if(dif_s == dif_t){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
