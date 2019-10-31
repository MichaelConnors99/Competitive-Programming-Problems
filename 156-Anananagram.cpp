//30/10/19
//UVA problem 156
//print all ananagrams in a given language
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<pair<string,string>> language;
	vector<string> ananagrams;
	string word;
	while(cin >> word && word != "#"){
		string sorted = word;
		transform(sorted.begin(),sorted.end(),sorted.begin(), ::toupper);
		sort(sorted.begin(),sorted.end());
		language.push_back(make_pair(sorted,word));
	}
	sort(language.begin(),language.end());
	for(int i = 0;i < language.size();i++){
		if(language[i].first != language[i-1].first && language[i].first != language[i+1].first){ 
			ananagrams.push_back(language[i].second);
		}
	}
	sort(ananagrams.begin(),ananagrams.end());
	for(string val:ananagrams){
		cout << val << endl;
	}
}
