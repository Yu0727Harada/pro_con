//
// Created on 2021/05/01.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    string s;
    cin>>s;

    deque<char> d;
    bool muki = true;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'R'){
            muki = !muki;
        }else{
            if(muki){
                if(d.empty()){
                    d.push_back(s[i]);
                }else{
                    if(d.back() == s[i]){
                        d.pop_back();
                    }else{
                        d.push_back(s[i]);
                    }
                }
            }else{
                if(d.empty()){
                    d.push_front(s[i]);
                }else{
                    if(d.front() == s[i]){
                        d.pop_front();
                    }else{
                        d.push_front(s[i]);
                    }

                }

            }

        }
    }

    if(muki){
        while(!d.empty()) {

            cout<<d.front();
            d.pop_front();
        }
    }else{
            while(!d.empty()) {

            cout<<d.back();
            d.pop_back();
        }
    }
    cout<<endl;
    return 0;
}
