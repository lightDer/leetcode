/**
* Definition for singly-linked list.
* struct ListNode {
*   int val;
*   ListNode *next;
*   ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(0) { }
};

class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = new ListNode(0);

        if (!l1 && !l2) return 0;

        if (!l1) l1 = new ListNode(0);
        if (!l2) l2 = new ListNode(0);

        int val = (l1->val + l2->val);
        bool lt10 = false;
        if (val >= 10) {
            lt10 = true;
            val = val % 10;
        }
        sum->val = val;

        ListNode *t1 = l1->next;
        ListNode *t2 = l2->next;
        ListNode *now = sum;
        ListNode *next = 0;
        while (t1 || t2) {

            if (!t1) t1 = new ListNode(0);
            if (!t2) t2 = new ListNode(0);

            int val = (t1->val + t2->val);
            if (lt10) 
                val += 1; 
            if (val >= 10) {
                lt10 = true;
                val = val % 10;
            }
            else {
                lt10 = false;
            }
            next = new ListNode(val);
            now->next = next;
            now = next;

            t1 = t1->next;
            t2 = t2->next;
        }
        if (lt10) now->next = new ListNode(1);
        return sum;
    }

    void addNode(ListNode * list, ListNode * node) {
        list->next = node;
    }

    void listNodes(ListNode * list) {
        printf("list: %d \n", list->val);
        
        ListNode *next = list->next;
        while (next) {
            printf("list: %d \n", next->val);
            next = next->next;
        }
    }
};

int main() {

    ListNode l_0(9);
    ListNode l_1(8);
    //ListNode l_2(3);

    Solution sol;
    sol.addNode(&l_0, &l_1);
    //sol.addNode(&l_1, &l_2);

    ListNode m_0(1);
    //ListNode m_1(6);
    //ListNode m_2(4);

    //sol.addNode(&m_0, &m_1);
    //sol.addNode(&m_1, &m_2);

    sol.listNodes(sol.addTwoNumbers(&l_0, &m_0));

    return 0;
}

