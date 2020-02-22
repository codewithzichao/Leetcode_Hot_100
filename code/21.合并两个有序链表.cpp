#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode * buildList(int arr[],int n){
	ListNode * dummy=new ListNode(0);
	ListNode * cur=dummy;

	for(int i=0;i<n;i++){
		ListNode * node=new ListNode(arr[i]);
		cur->next=node;
		cur=cur->next;
	}

	return dummy->next;
}

class Solution{
	public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1==nullptr) return l2;
		if(l2==nullptr) return l1;

		ListNode * dummy=new ListNode(0);
		ListNode * cur=dummy;

		while(l1!=nullptr || l2!=nullptr){
			if(l1!=nullptr && l2!=nullptr){
				if(l1->val<=l2->val){
					cur->next=l1;
					cur=cur->next;
					l1=l1->next;
				}
				else{
					cur->next=l2;
					cur=cur->next;
					l2=l2->next;
				}
			}
			else if(l1==nullptr){
				cur->next=l2;
				cur=cur->next;
				break;
			}
			else{
				cur->next=l1;
				cur=cur->next;
				break;
			}
		}

		return dummy->next;
	}
};

int main(){
	int n1,n2;
	scanf("%d%d",&n1,&n2);

	int arr1[n1];
	for(int i=0;i<n1;i++){
		int x;
		scanf("%d",&x);
		arr1[i]=x;
	}
	int arr2[n2];
	for(int i=0;i<n2;i++){
		int x;
		scanf("%d",&x);
		arr2[i]=x;
	}

	ListNode  * l1=buildList(arr1,n1);
	ListNode * l2=buildList(arr2,n2); 

	Solution so1;
	ListNode * ans=so1.mergeTwoLists(l1,l2);
	while(ans!=nullptr){
		printf("%d",ans->val);
		if(ans->next!=nullptr){
			printf("->");
		}
		ans=ans->next;
	}
	printf("\n");
	return 0;
	
}