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

#define For(i,m,n) for(int i=m; i < n; i++)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* node): val(x), next(node){}
};

void push_back(ListNode** current, int val){
    ListNode* newnode = new ListNode(val, NULL);
    if(!*current){
	*current = newnode;
    }
    else{
	ListNode* it = *current;
	while(it->next)
	    it=it->next;
	it->next = newnode;
    }
}

void push_front(ListNode** current, int val){
    *current = new ListNode(val, *current);
}


ListNode* merge(ListNode *left, ListNode *right){
    ListNode *z = NULL;
    while(left && right){
	if(left->val<right->val){
	    push_back(&z, left->val);
	    left = left->next;
	}
	else{
	    push_back(&z, right->val);
	    right = right->next;
	}
    }

    while(left){
	push_back(&z, left->val);
	left = left->next;
    }

    while(right){
	push_back(&z, right->val);
	right = right->next;
    }

    return z;
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

int main(int argc, char** argv){
    srand(time(NULL));
    int n = 10;
    ListNode *head = NULL;
    For(i,0,n){
	push_back(&head, rand()%(n*n));
    }

    cout <<endl;
    head = mergeSort(head);
    for(ListNode* it = head; it; it = it->next){
	cout << it->val <<" ";
    }
    cout <<endl;
    
    return 0;
}
