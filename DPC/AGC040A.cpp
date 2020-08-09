#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main() {
    string S;
    cin>>S;
    vector<int>ans(S.size()+1);

    int i = 0;
    int count =1;

    while (true)
    {
        while (S[i] == S[i + 1]) {
            count++;
            i++;
            if(i+1>=S.size()){
                break;
            }

        }

        if (S[i] == '<') {
            for (int j = 0; j <= count; ++j) {
                ans[(i + 1) - j] = max(count - j,ans[(i+1)-j]);
            }
        } else if (S[i] == '>') {
            for (int j = 0; j <= count; ++j) {
                ans[(i + 1) - j] = max(j,ans[(i+1)-j]);
            }
        }

        if (i + 1 >= S.size()) {
            break;
        }
        i++;
        count = 1;
    }


    auto answer= std::accumulate(ans.begin(),ans.end(),0LL);
    cout<<answer<<endl;

}