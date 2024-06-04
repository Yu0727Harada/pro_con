
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
    int m;
    cin>>m;
    vector<string>s(3);
    for (int i = 0; i < 3; ++i) {
        cin>>s[i];
    }
    int ans = INF;

    vector<vvi> num(10,vvi(3,vi()));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            num[s[i][j] - '0'][i].push_back(j);
        }
    }

    for (int i = 0; i < 10; ++i) {

        for (int j = 0; j < num[i][0].size(); ++j) {
            for (int k = 0; k < num[i][1].size(); ++k) {
                for (int l = 0; l < num[i][2].size(); ++l) {
                    int first_s = num[i][0][j];
                    int second_s = num[i][1][k];
                    int third_s = num[i][2][l];

                    if(first_s == second_s){
                        second_s += m;
                    }
                    if(second_s == third_s){
                        third_s += m;
                    }
                    if(first_s == third_s){
                        third_s += m;
                    }
                    if(first_s == second_s){
                        second_s += m;
                    }
                    if(second_s == third_s){
                        third_s += m;
                    }
                    if(first_s == third_s){
                        third_s += m;
                    }
                    int tmp = max(first_s,max(second_s,third_s));
                    chmin(ans,tmp);
                }

            }
        }


    }
    if(ans == INF)ans = -1;
    cout<<ans<<endl;

    return 0;
}
