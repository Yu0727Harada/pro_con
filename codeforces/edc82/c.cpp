//
// Created on 2020/02/13.
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
int solve(){
    vector<vector <int > > edge_gragh (26,vector<int>(0,-1));
    string s;
    cin>>s;
    for (int i = 0; i < s.size()-1; ++i) {
        int A,B;
        A = s[i]-'a';
        B = s[i+1] -'a';
        edge_gragh[A].push_back(B);
        edge_gragh[B].push_back(A);
        if(edge_gragh[A].size()>=3 || edge_gragh[B].size()>= 3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    vector<int>al(26,0);
    for (int j = 0; j < 26; ++j) {
        if(edge_gragh[j].size()==1){
            cout<<char(j+'a');
            al[j] = 1;
            queue<int>q;
            q.push(edge_gragh[j][0]);
            while(!(q.empty())){
                int now;
                now = q.front();
                q.pop();
                cout<<char(now+'a');
                al[now] =1;
                int next;
                if(now !=edge_gragh[now][0]) q.push(edge_gragh[now][0]);
                else q.push(edge_gragh[now][1]);
            }
        }
    }
    for (int k = 0; k < 26; ++k) {
        if(al[k]==0)cout<<char(k+'a');
    }
    cout<<endl;

}


int main() {
    int n;
    cin>>n;
    while(n){
        n--;
        solve();
    }

}
