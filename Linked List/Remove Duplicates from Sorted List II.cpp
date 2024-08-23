class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
        return NULL;

        map<int, int>count;

        ListNode*temp = head;
        while(temp!=NULL)
        {
            count[temp->val]++;
            temp = temp->next;
        }

        while (head && count[head->val]>1)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        if(!head)
        return NULL;

        ListNode *prev = head;
        temp = head->next;
        while(temp!=NULL)
        {
            if(count[temp->val]>1)
            {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
            }
            else
            {
            prev = temp;
            temp = temp->next;
            }
        }
        return head;
    }
    };