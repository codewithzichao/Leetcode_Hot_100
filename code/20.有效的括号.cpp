#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

class Solution{
	public:
	bool isValid(string s) {
		/*
		看到括号匹配问题，一律用栈解决。
		*/
		if(s.size()==0) return true;		
		stack<char> st;
		for(int i=0;i<s.size();i++){
			char c=s[i];
			if(c=='(' || c=='{' || c=='[') st.push(c);
			else if(st.empty()==false && ((st.top()=='(' && c==')') || (st.top()=='[' && c==']') || (st.top()=='{' && c=='}'))){
				st.pop();
			}
			else{
				return false;
			}
		}
		return st.empty()==true?true:false;
				
	}
};

int main(){
	string s;
	cin>>s;
	Solution so1;
	bool ans=so1.isValid(s);
	if(ans) printf("true\n");
	else printf("false\n");

	return 0;
}
