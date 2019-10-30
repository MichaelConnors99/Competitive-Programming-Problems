//30/10/19
//UVA problem 10038

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int arr[n];
		int differences[n];
		string ans = "Jolly\n";
		for(int i = 0;i < n;i++){
			int num;
			cin >> num;
			arr[i] = num;
			if(i > 0 ){
				differences[i] = abs(arr[i] - arr[i-1]);
			}
		}
		sort(differences,differences + n);
		
		for(int i = 1;i < n;i++){
			if(differences[i] != i){
				ans = "Not jolly\n";
			}
		}
		cout << ans;
	}
}
