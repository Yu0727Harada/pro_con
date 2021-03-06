//
// Created on 2021/04/06.
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
    string a;
    string b;
    cin>>a>>b;

    if(a.size() != b.size()){
        if(a.size() > b.size()){
            cout<<"GREATER"<<endl;
            return 0;
        }else if(a.size() < b.size()){
            cout<<"LESS"<<endl;
            return 0;
        }
    }else{

        for (int i = 0; i < a.size(); ++i) {
            if(a[i] > b[i]){
                cout<<"GREATER"<<endl;
                return 0;
            }else if(a[i] < b[i]){
                cout<<"LESS"<<endl;
                return 0;
            }else{
                continue;
            }
        }



    }
cout<<"EQUAL"<<endl;
    return 0;
}
