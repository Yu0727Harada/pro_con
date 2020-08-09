//
// Created on 2020/03/01.
//

//#include <bits/stdc++.h>
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
using gragh = vector<vector<int>>;

int main() {

    int n;
    int m;
    cin>>n>>m;
    vector<int> ans(n,-1);
    for (int i = 0; i < m; ++i) {
        int s,c;
        cin>>s>>c;
        s --;
        if(c==0 && s==0 && n!= 1){
            cout<<-1<<endl;
            return 0;
        }
        if(ans[s] == -1 || ans[s]==c){
            ans[s] = c;
            continue;
        }

            cout<<-1<<endl;
            return 0;


    }

    for (int j = 0; j < n; ++j) {
        if(ans[j] == -1 && j != 0) ans[j]=0;
        if(ans[j] == -1 && j == 0 && n!=1) ans[j] = 1;
        if(ans[j]==-1 && j==0 && n ==1) ans[j]=0;

    }
    int out = 0;
    for (int k = 0; k < n; ++k) {
        out += ans[k] * pow(10,n-(k+1));
    }


    cout<<out<<endl;
}
