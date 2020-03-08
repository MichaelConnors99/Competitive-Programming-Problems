//UVA 11581

#include <bits/stdc++.h>

using namespace std;

int arr[3][3];
void f(){
	//Simulates process
	int temp[3][3];
	memcpy(temp, arr, sizeof(temp));
	arr[0][0] = (temp[0][1] + temp[1][0])%2;
	arr[2][0] = (temp[1][0] + temp[2][1])%2;
	arr[0][2] = (temp[0][1] + temp[1][2])%2;
	arr[2][2] = (temp[2][1] + temp[1][2])%2;
	arr[0][1] = (temp[0][0] + temp[0][2] + temp[1][1])%2;
	arr[1][0] = (temp[0][0] + temp[2][0] + temp[1][1])%2;
	arr[1][2] = (temp[0][2] + temp[2][2] + temp[1][1])%2;
	arr[2][1] = (temp[2][0] + temp[2][2] + temp[1][1])%2;
	arr[1][1] = (temp[1][0] + temp[0][1] + temp[1][2] + temp[2][1])%2;
}
int fi(int before[3][3]){
	//recursively simulates until infinite
	f();
	int similar = 0;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(arr[i][j] == before[i][j]){
				similar++;
			}
		}
	}
	int temp[3][3];
	memcpy(temp, arr, sizeof(temp));
	if(similar == 9){
		return -1;
	}
	else{
		return 1 + fi(temp);
	}
}
int main(){
	int n;
	cin >> n;
	int row;
	int temp[3][3];
	while(n--){
		for(int i = 0;i < 3;i++){
			cin >> row;
			arr[i][0] = row / 100;
			arr[i][1] = (row / 10) % 10;
			arr[i][2] = row % 10;
			temp[i][0] = row / 100;
			temp[i][1] = (row / 10) % 10;
			temp[i][2] = row % 10;
		}
		int ans = fi(temp);
		cout << ans << endl;
	}
}
