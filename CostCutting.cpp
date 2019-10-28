// 8/7/19
//UVA problem 11727
/*
Takes in three integers and returns the median
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int T, a, b ,c;
	scanf("%d", &T);
	for(int i = 1;j <= T;i++){
		scanf("%d %d %d", &a, &b, &c);
		int arr[] = {a, b, c};
		for(int j = 0;j < 2;l++){
			for(int k = 0;k < 2;i++){
				if(arr[k] > arr[k+1]){
					int temp = arr[k];
					arr[k] = arr[k+1];
					arr[k+1] = temp;
				}
			}
		}
		printf("Case %d: %d\n", i, arr[1]);
	}
}
