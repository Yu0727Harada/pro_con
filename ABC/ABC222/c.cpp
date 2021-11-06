//
// Created on 2021/10/24.
//

//
// Created on 2021/10/23.
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

class person{
public:
    int num;
    int win;
    person(int _n){
        this->num = _n;
        this->win = 0;
    }
    bool operator<(const person&right)const{
        if(win != right.win){
            return win < right.win;
        }else{
            return num > right.num;
        }
    }
};


int main() {

    int n;
    cin>>n;
    int m;
    cin>>m;

    priority_queue<person> q;

    for (int i = 1; i <= 2*n; ++i) {
        person t(i);
        q.push(t);
    }
    vector<string>mean(2*n+1);
    for (int i = 1; i <= 2*n; ++i) {
        cin>>mean[i];
    }

    for (int i = 0; i < m; ++i) {

        priority_queue<person> next_q;
        while(!q.empty()){
            person one = q.top();
            q.pop();
            person two = q.top();
            q.pop();
            char one_o = mean[one.num][i];
            char two_o = mean[two.num][i];
            if(one_o == two_o){

            }else if(one_o == 'G'){
                if(two_o == 'C'){
                    one.win ++;
                }else if(two_o == 'P'){
                    two.win++;
                }
            }else if(one_o == 'C'){
                if(two_o == 'G'){
                    two.win ++;
                }else if(two_o == 'P'){
                    one.win ++;
                }
            }else if(one_o == 'P'){
                if(two_o == 'C'){
                    two.win++;
                }else if(two_o == 'G'){
                    one.win ++;
                }
            }
            next_q.push(one);
            next_q.push(two);
        }
        q = next_q;

    }

    while(!q.empty()){
        cout<<q.top().num<<endl;
        q.pop();
    }

    return 0;
}
