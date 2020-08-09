#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int>points(N);
    int point_sum;
    for (int i = 0; i < N; ++i) {
        cin>>points[i];
        point_sum+=points[i];
    }
    
    vector<vector <int> >DP(N+1,vector<int>(point_sum+1,0));
    DP[0][0] = 1;

    for (int j = 0; j < N; ++j) {
        for (int k = 0; k <= point_sum; ++k) {
              if (DP[j][k]==1){
                    if (k+points[j]<=point_sum) {
                        DP[j + 1][k + points[j]] = DP[j][k] * 1;
                    }
                    DP[j + 1][k] = DP[j][k] * 1;
            }
        }

    }

    int ans = 0;
    for (int l = 0; l <= point_sum; ++l) {
        ans += DP[N][l];
    }

    cout<<ans<<endl;

}