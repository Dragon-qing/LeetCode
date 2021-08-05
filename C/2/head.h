#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* li,*j,*k,*L;
        li=new ListNode;
        j=nullptr;
        L=li;
        j=l1;
        k=l2;
        while(j!=NULL||k!=NULL){
            if(j==NULL){
               L->val+=k->val;
               k=k->next;
               if(L->val>=10){
                    L->val-=10;
                    L->next=new ListNode(1);
               }else{
                    if(k!=NULL){
                    L->next=new ListNode();
                    }
                }
                 L=L->next;
            }else if(k==NULL){
                L->val+=j->val;
               j=j->next;
               if(L->val>=10){
                    L->val-=10;
                    L->next=new ListNode(1);
               }else{
                    if(j!=NULL){
                    L->next=new ListNode();
                    }
                }
                 L=L->next;
            }else{
                L->val=j->val+k->val+L->val;
                if(L->val>=10){
                    L->val-=10;
                    L->next=new ListNode(1);
                    j=j->next;
                    k=k->next;
                }else{
                    j=j->next;
                    k=k->next;
                    if(!(j==NULL&&k==NULL)){
                        L->next=new ListNode();
                    }
                }
                L=L->next;
            }
        }
        return li;
    }
}; 