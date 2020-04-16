//16/04/20
//UVA Problem 10487

#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int n,m;
int main(){
    int count = 1;
    while(cin >> n && n != 0){
        cout << "Case " << count << ":\n";
        count++;
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        cin >> m;
        int query;
        int ans = INT_MAX;
        int sum = 0;
        int difference = 0;
        while(m--){
            ans = INT_MAX;
            cin >> query;
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    difference = abs((arr[i] + arr[j]) - query);
                    if(difference < ans && i != j){
                        ans = difference;
                        sum = arr[i] + arr[j];
                    }
                }
            }
            cout << "Closest sum to " <<  query << " is " << sum << ".\n";
        }
    }
}
