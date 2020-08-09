//
// Created on 2020/05/17.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edge(n,vector<int>());

    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int>q;
    vector<int>ans(n,-1);//++すること
    ans[0] = 0;
    q.push(0);
    while(!q.empty()){
        int now_room = q.front();
        q.pop();
        for (int i = 0; i < edge[now_room].size(); ++i) {
            if(ans[edge[now_room][i]] == -1){
                ans[edge[now_room][i]] = now_room + 1;
                q.push(edge[now_room][i]);
            }
        }
    }

    int cnt;
    cnt = count(all(ans),-1);
    if(cnt == 0){
        cout<<"Yes"<<endl;
        for (int i = 1; i < ans.size(); ++i) {
            cout<<ans[i]<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }
    
    return 0;
}
