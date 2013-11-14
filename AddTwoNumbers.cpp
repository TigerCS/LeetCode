/*
http://oj.leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        ListNode* curl1 = l1;
        ListNode* curl2 = l2;
        while(curl1 || curl2 || carry) {
            int sum = (curl1 ? curl1->val : 0) + (curl2 ? curl2->val : 0) + carry;
            carry  = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            cur->next = newNode;
            cur = newNode;
            if(curl1) curl1 = curl1->next; 
            if(curl2) curl2 = curl2->next;
        }

        return dummy.next;
    }
};
