class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // current pointer banaya jo head se start karega
        ListNode* current = head;

        // Jab tak current aur uska next exist karta ho, tab tak loop chalega
        while (current != NULL && current->next != NULL) {

            // Agar current aur next node ka value same hai
            if (current->val == current->next->val) {

                // Duplicate node ko skip kar diya
                // current ka next ab seedha uske aage wale node ko point karega
                current->next = current->next->next;

            } else {
                // Agar duplicate nahi hai to current ko aage badha do
                current = current->next;
            }
        }

        // Final duplicate-free linked list ka head return
        return head;
    }
};
