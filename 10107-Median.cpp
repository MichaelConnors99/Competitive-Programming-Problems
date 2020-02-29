//28/2/20
//UVA problem 10107
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<int> v;
	int median;
	while(cin >> n){
		median= 0;
		v.push_back(n);
		sort(v.begin(),v.end());
		if(v.size() % 2 == 0){
			median = v[v.size() / 2] + v[v.size() / 2 + 1];
		}
		else{
			median = v[v.size() / 2 + 1];
		}
		cout << median << endl;
	}
}
