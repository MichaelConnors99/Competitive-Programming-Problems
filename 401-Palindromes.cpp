//28/10/19
//UVA problem 401

#include <bits/stdc++.h>

using namespace std;

string alternate = "ESZJL523";
string invalid = "BCDFGKNPQR4679";
bool palindrome(string s){
	int len = s.length();
	if(len % 2 == 1){
		s.erase(s.begin() + (len-1)/2);
		len--;
	}
	for(int i = 0;i <= ((len)/2)-1;i++){
		if(s[i] != s[len-i-1]){
			return false;
		}
	}
	return true;
}

bool mirror(string s){
	string rev = "";
	int len = s.length();
	if(len % 2 == 1){
		for(int i = 0;i < 8;i++){
			if(s[(len-1)/2] == alternate[i]){
				return false;
			}
		}
		for(int i = 0;i < 14;i++){
			if(s[(len-1)/2] == invalid[i]){
				return false;
			}
		}
		s.erase(s.begin() + (len-1)/2);
		len--;
	}
	for(int i = 0;i < len;i++){
		bool normal = true;
		for(int j = 0;j < 14;j++){
			if(s[i] == invalid[j]){
				return false;
			}
		}
		for(int j = 0;j < 8;j++){
			if(s[i] == alternate[j]){
				if(s[len-i-1] != alternate[7-j]){
					return false;
				}
				normal = false;
			}
		}
		if(normal){
			if(s[i] != s[len-1-i]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	string input;
	while(cin >> input){
		if(palindrome(input) && mirror(input)){
			cout << input <<  " -- is a mirrored palindrome.\n" << endl;
		}
		else if(palindrome(input)){
			cout << input <<  " -- is a regular palindrome.\n" << endl;
		}
		else if(mirror(input)){
			cout << input <<  " -- is a mirrored string.\n" << endl;
		}
		else{
			cout << input <<  " -- is not a palindrome.\n" << endl;
		}
	}
}
