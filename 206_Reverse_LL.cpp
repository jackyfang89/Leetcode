#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == NULL) return NULL;

    // ListNode* new_head = head;
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode* buildList(vector<int> vals) {
    if (vals.size() == 0) return NULL;

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        ListNode* temp = new ListNode(vals[i]);
        curr->next = temp;
        curr = curr->next;
    }

    return head;
}

void freeList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        std::cout << curr->val;

        if (curr->next != NULL) {
            std::cout << ", ";
        }
        curr = curr->next;
    }

    std::cout << std::endl;
}

int main(){
    
    vector<vector<int>> vals = {
        {1,2,3,4,5},
        {1,2}
    };

    for (int i = 0; i < vals.size(); ++i) {
        ListNode* head = buildList(vals[i]);
        // printList(head);
        head = reverseList(head);
        printList(head);
        freeList(head);
    }



    return 0;
}
