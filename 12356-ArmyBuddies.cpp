//31/10/19
//UVA problem 12356

#include <bits/stdc++.h>

using namespace std;

int main(){
	int size,losses;
	while((cin >> size >> losses) && losses != 0){
		int left[size+1];
		int right[size+1];
		for(int i = 1;i <= size;i++){
			left[i] = i-1;
			right[i] = i + 1;
		}
		left[1] = -1;
		right[size] = -1;
		while(losses--){
			int L, R;
			cin >> L >> R;
			left[right[R]] = left[L];
			if(left[L] != -1){
				cout << left[L];
			}
			else{
				cout << "*";
			}
			right[left[L]] = right[R];
			if(right[R] != -1){
				cout << " " << right[R] << endl; 
			}
			else{
				cout << " *" << endl;
			}
		}
		cout << "-" << endl;
	}
}
