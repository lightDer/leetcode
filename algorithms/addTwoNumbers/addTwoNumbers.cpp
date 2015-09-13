/**
* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
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
        ListNode *tmp = sum;
        int carry = 0, val;

        do {
            if (!l1) l1 = new ListNode(0);
            if (!l2) l2 = new ListNode(0);

            val = (l1->val + l2->val) + carry;
            tmp->val = val % 10;
            carry = val / 10;

            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2 || carry) {
                tmp->next = new ListNode(0);
                tmp = tmp->next;
            }
        }
        while (l1 || l2);

        if (carry)
            tmp->val = 1;
        return sum;
    }

    void addNode(ListNode * list, ListNode * node) {
        list->next = node;
    }

    void listNodes(ListNode * list) {
        do {
            printf("list: %d \n", list->val);
            list = list->next;
        }
        while (list);
    }
};

int main() {

    ListNode l_0(5);
    //ListNode l_1(8);
    //ListNode l_2(3);

    Solution sol;
    //sol.addNode(&l_0, &l_1);
    //sol.addNode(&l_1, &l_2);

    ListNode m_0(5);
    //ListNode m_1(6);
    //ListNode m_2(4);

    //sol.addNode(&m_0, &m_1);
    //sol.addNode(&m_1, &m_2);

    sol.listNodes(sol.addTwoNumbers(&l_0, &m_0));

    return 0;
}

