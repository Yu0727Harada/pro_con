//
// Created on 2020/01/10.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
using gragh = vector<vector<int>>;

int main() {
    int N;
    string c;
    cin>>N;
    cin>>c;
    int L =0;
    int R = 0;
    for (int i = 0; i < N; ++i) {
        if(c[i]=='L') L++;
        if(c[i]=='R') R++;
    }
    int ans = 1;
    ans += L;
    ans += R;

    cout<<ans<<endl;
}
