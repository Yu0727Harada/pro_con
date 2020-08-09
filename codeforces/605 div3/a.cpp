//
// Created on 2019/12/12.
//

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
using gragh = vector<vector<int>>;
const long long LINF = 1e18;

ll solve(){
    vector<int>move ={-1,0,1};
    ll ans = LINF;
    ll a,b,c;
    cin>>a>>b>>c;
    ll distance;
    for (int d1:move) {
        for (int d2:move) {
            for(int d3:move){
                distance = abs((a+d1)-(b+d2))+abs((a+d1)-(c+d3))+abs((b+d2)-(c+d3));
                ans = min(ans,distance);
            }

        }
    }
    return ans;
}

int main() {
    int q;
    cin>>q;

    for (int i = 0; i < q; ++i) {
        ll ans;
        ans = solve();

        cout<<ans<<endl;
    }
}
