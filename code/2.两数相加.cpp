#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
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

class  Solution{
	public:
	/*
	其实就是模拟加法的过程，我觉得链表题应该是最简单的。
	*/
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * dummy= new ListNode(0);
		ListNode * cur=dummy;
		int carry=0;

		while(l1!=nullptr || l2!=nullptr){
			int a1=(l1!=nullptr)?l1->val:0;
			int a2=(l2!=nullptr)?l2->val:0;
			int temp=a1+a2+carry;
			carry=temp/10;

			ListNode * node =new ListNode(temp%10);
			cur->next=node;
			cur=cur->next;

			if(l1!=nullptr) l1=l1->next;
			if(l2!=nullptr) l2=l2->next;

		}

		if(carry!=0){
			ListNode * node=new ListNode(carry);
			cur->next=node;
			cur=cur->next;
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
	ListNode * ans=so1.addTwoNumbers(l1,l2);
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