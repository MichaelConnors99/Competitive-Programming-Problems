//16/04/20
//UVA problem 1260
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int D;
        cin >> D;
        int arr[D];
        int ans[D];
        for(int i = 0;i < D;i++){
            cin >> arr[i];
        }
        for(int i = 1; i < D;i++){
            int count = 0;
            for(int j = 0;j < i;j++){
                if(arr[i] >= arr[j]){
                    count++;
                }
            }
            ans[i] = count;
        }
        
        int sum = 0;
        for(int i = 1;i < D;i++){
            sum += ans[i];
        }
        cout << sum << endl;
    }
}
