#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int>Llist(N,0);


    int ans =0;
    for (int i = 0; i < N; ++i) {
        cin>>Llist[i];
    }
    std::sort(Llist.begin(),Llist.end());

    for (int a = 0; a < N - 2; ++a) {
        for (int b = a+1; b <N-1 ; ++b) {
            for(int c = b+1;c<N;++c){
                if(Llist[c] > abs(Llist[a]-Llist[b])){
                    if(Llist[c]<(Llist[a]+Llist[b])){
                        ans ++;
                        continue;
                    }
                    else{
                        break;
                    }

                }

            }

        }
    }

    cout<<ans<<endl;
}
