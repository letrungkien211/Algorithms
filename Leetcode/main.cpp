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
  ListNode(int x, ListNode* n): val(x), next(n){}
};

void Print(ListNode* head){
  ListNode* tmp = head;
  while(tmp){
    cout << tmp->val <<" ";
    tmp = tmp->next;
  }
  cout <<endl;
}

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *current, *prev, *next;
    ListNode *tmp;

    m--;
    n--;
    ListNode *n1,*n2;
    int i = 0;

    if(m==n)
      return head;
    for(n1=NULL, n2=head, i =0; n2&& i<m; i++){
      n1=n2;
      n2=n2->next;
    }
      
    
    for(prev=NULL, current=n2; current && i <=n; i++){
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    if(n1)
      n1->next = prev;
    if(n2)
      n2->next = current;
    if(m==0)
      return prev;
    else
      return head;
  }
};



int main(int argc, char** argv){
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    //  ListNode* head = new ListNode(3, new ListNode(5));
  ListNode* tmp = head;
  while(tmp){
    cout << tmp->val <<" ";
    tmp = tmp->next;
  }

  Solution sol;
  ListNode* a = sol.reverseBetween(head,1,2);
  while(a){
    cout << a->val <<" ";
    a = a->next;
  }
  cout<<endl;
    return 0;
}
