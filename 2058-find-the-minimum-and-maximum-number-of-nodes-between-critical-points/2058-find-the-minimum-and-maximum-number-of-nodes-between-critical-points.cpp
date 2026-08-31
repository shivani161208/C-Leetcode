/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1, -1};
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        while(curr->next != NULL){
            ListNode* nxt = curr->next;
            bool localMax = (curr->val > prev->val && curr->val > nxt->val);
            bool localMin = (curr->val < prev->val && curr->val < nxt->val);

            if(localMax || localMin){
                if(first == -1) first = pos;
                else minDist = min(minDist,pos-last);
                last = pos;
            }
            prev = curr;
            curr = nxt;
            pos++;
        }
        if(first == last) return {-1,-1};
        int maxDist = last-first;
        return {minDist,maxDist};
    }
};