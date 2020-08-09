//
// Created on 2020/03/07.
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
    string ans;
    bool permission = true;
    int q;
    string s;
    cin>>s>>q;
    int l;
    ans = s;
    while(q){
        int t;
        cin>>t;
        if(t == 1){
            if (permission) permission = false;
            else permission = true;
        }else{
            int f;
            char c;
            cin>>f>>c;
            if(permission){
                if(f==2) {
                    ans.push_back(c);
                    //l++;
                }
                else {
                    auto temp = ans.begin();
                    ans.insert(temp,c);
                    //l++;
                }
            }
            if(!permission){
                if(f==1) {
                    ans.push_back(c);
                    //l++;
                }
                else {
                    auto temp = ans.begin();
                    ans.insert(temp,c);
                    //l++;
                }
            }

        }

        q--;
    }
    if(permission){
        for (int i = 0; i < ans.size(); ++i) {
            cout<<ans[i];
        }
        cout<<endl;
        return 0;
    }else{
        for (int i = ans.size()-1; i >= 0; --i) {
            cout<<ans[i];
        }
        cout<<endl;
    }

}


//文字列の先頭への追加をinsertではなく、deque(前からも後ろからも出せるデータ構造）を使うと早い
//文字列の反転をbool関数で管理する。
//２つの配列を持って先頭に追加する文字、後ろに追加する文字で管理して、あとでjoinしてもよい。