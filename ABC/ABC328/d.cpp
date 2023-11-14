//
// Created on 2023/11/11.
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
    deque<int>t;
    vector<char>ans;
    string s;
    cin>>s;
    int state;

    for (int i = 0; i < s.size(); ++i) {
        if(state == 0){
            if(s[i] == 'A'){
                state = 1;
            }else{
                ans.push_back(s[i]);
            }
        }else if(state == 1){
            if(s[i] == 'A'){
                t.push_back(state);
                state = 1;
            }else if(s[i] == 'B'){
                state = 2;
            }else if(s[i] == 'C'){

                while(!t.empty()){
                    if(t.front() == 1){
                        ans.push_back('A');
                    }else if(t.front() == 2){
                        ans.push_back('A');
                        ans.push_back('B');
                    }
                    t.pop_front();
                }
                ans.push_back('A');
                ans.push_back('C');
                state = 0;
            }
        }else if(state == 2){
            if(s[i] == 'A'){
                t.push_back(state);
                state = 1;
            }else if(s[i] == 'B'){

                while(!t.empty()){
                    if(t.front() == 1){
                        ans.push_back('A');
                    }else if(t.front() == 2){
                        ans.push_back('A');
                        ans.push_back('B');
                    }
                    t.pop_front();
                }
                ans.push_back('A');
                ans.push_back('B');
                ans.push_back('B');
                state = 0;
            }else if(s[i] == 'C'){
                if(!t.empty()){
                    state = t.back();
                    t.pop_back();
                }else{
                    state = 0;
                }
            }
        }
    }

    t.push_back(state);

    while(!t.empty()){
        if(t.front() == 1){
            ans.push_back('A');
        }else if(t.front() == 2){
            ans.push_back('A');
            ans.push_back('B');
        }
        t.pop_front();
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}
