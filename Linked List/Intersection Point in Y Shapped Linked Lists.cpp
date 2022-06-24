// { Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
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
// Function to find intersection point in Y shaped Linked Lists.

int intersectPoint(Node *head1, Node *head2)
{
    /* Created loop and used previously used algorithms*/ /*other approch could be to use maps*/
    Node *curr = head1;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = head2;
    Node *inter = firstNode(head1);
    return inter->data;
}
