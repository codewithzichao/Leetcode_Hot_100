#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
	public:
	/*
	滑动窗口思想。碰到字串问题，第一时间就应该想到滑动窗口。
	*/
	string minWindow(string s, string t) {
		if(t.size()==0 || s.size()==0) return "";

		unordered_map<char,int> m_t;
		unordered_map<char,int> window;
		for(int i=0;i<t.size();i++) m_t[t[i]]++;

		int left=0,right=0;//双指针，滑动窗口的左右位置
		int start=0,minlen=INT_MAX;//start表示最后的字符串的开始的位置,minlen表示最后的字符串的长度
		int match=0;//窗口内与目标字符串匹配的数目

		//移动right
		while(right<s.size()){
			char c1=s[right];
			if(m_t.count(c1)){
				window[c1]++;
				if(window[c1]==m_t[c1]){
					match++;
				}
			}
			right++;

			//如果已经匹配了，说明窗口内的字符串包含了目标字符串，接下来，就需要缩减窗口大小，移动left，找到包含目标字符串的最小子串
			while(match==m_t.size()){
				char c2=s[left];
				if(right-left<minlen){
                    start=left;
                    minlen=right-left;
                }
				if(m_t.count(c2)){
					window[c2]--;
					if(window[c2]<m_t[c2]){
						match--;
					}
				}
				left++;
			}
		}

		return minlen==INT_MAX?"":s.substr(start,minlen);
	}
};

int main(){
	string s,t;
	cin>>s>>t;

	Solution so1;
	string ans=so1.minWindow(s,t);
	cout<<ans<<endl;
	return 0;
}