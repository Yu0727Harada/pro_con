//

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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;


    stack<int>st;
    int f_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '('){
            st.push(i);
            //左かっこがきたらプッシュ
        }else{
            if(st.empty()){
                f_cnt ++;
                //右かっこの時にスタックがからなら前にひだりかっこを足さなければいけない
            }else{
                st.pop();
                //スタックがあるなら整合しているのでポップ
            }
        }
    }
    for (int i = 0; i < f_cnt; ++i) {
        cout<<"(";
    }
    cout<<s;
    while(!st.empty()){
        cout<<")";
        st.pop();
        //閉じ忘れを閉じる
    }
    cout<<endl;

    return 0;
}
