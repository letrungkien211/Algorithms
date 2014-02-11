/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

Sort a linked list in O(n log n) time using constant space complexity.
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


#define For(i,m,n) for(int i=m; i < n; i++)

class Solution{
public:
    ListNode* merge(ListNode *left, ListNode *right){
	ListNode *fakeHead = new ListNode(1);
	ListNode *z = fakeHead;
	while(left && right){
	    if(left->val<right->val){
		z->next = new ListNode(left->val);
		z = z->next;
		left = left->next;
	    }
	    else{
		z->next = new ListNode(right->val);
		z = z->next;
		right = right->next;
	    }
	}

	while(left){
	    z->next = new ListNode(left->val);
	    z = z->next;
	    left = left->next;
	}

	while(right){
	    z->next = new ListNode(right->val);
	    z = z->next;
	    right = right->next;
	}

	return fakeHead->next;
    }

    ListNode* getMid(ListNode* head){
	ListNode *slow, *fast;
	if(!head||!head->next || !head->next->next){
	    return head;
	}

	for(slow=head, fast = head; fast->next && fast->next->next; slow=slow->next,fast = fast->next->next){

	}
	return slow;
    }

    ListNode *mergeSort(ListNode *head){
	if(!head || !head->next)
	    return head;
	ListNode *mid = getMid(head);
	ListNode *right = mid->next;
	mid->next = NULL;
    
	return merge(mergeSort(head), mergeSort(right));
    }
    ListNode *sortList(ListNode *head) {
	return mergeSort(head);
    }


};

int main(int argc, char** argv){
    srand(time(NULL));
    int n;
    if(argc>1)
	n = atoi(argv[1]);
    else
	n = 100;
    ListNode *head = new ListNode(1);
    ListNode *x = head;
    For(i,0,n){
	x->next = new ListNode(rand()%(n*n));
	x = x->next;
    }
    head = head->next;

    Solution* sol = new Solution();

    head = sol->sortList(head);
    for(ListNode* it = head; it; it = it->next){
	cout << it->val <<" ";
    }
    cout <<endl;
    
    return 0;
}
