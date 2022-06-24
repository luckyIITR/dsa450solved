#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
pair<Node *, bool> poi(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast->next != nullptr)
    {
        fast = fast->next;
        if (fast->next == nullptr)
            return make_pair(nullptr, false);
        fast = fast->next;
        slow = slow->next;
        if (slow == fast)
            return make_pair(slow, true);
    }
    return make_pair(nullptr, false);
}

Node *firstNode(Node *head)
{
    if (head == nullptr)
        return nullptr;

    pair<Node *, bool> check = poi(head);
    if (check.second == false)
        return nullptr;
    Node *fast = check.first;
    Node *slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}