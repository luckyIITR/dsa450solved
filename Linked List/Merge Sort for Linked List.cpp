// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *findmid(Node *head)
    {
        if (head == nullptr or head->next == nullptr)
            return head;
        Node *slow = head;
        Node *fast = head->next;
        while (fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *head1, Node *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        Node *ans = new Node(-1);
        Node *end = ans;
        while (head1 != nullptr and head2 != nullptr)
        {
            if (head1->data < head2->data)
            {
                end->next = head1;
                end = head1;
                head1 = head1->next;
            }
            else
            {
                end->next = head2;
                end = head2;
                head2 = head2->next;
            }
        }
        if (head1 != nullptr)
            end->next = head1;
        if (head2 != nullptr)
            end->next = head2;
        ans = ans->next;
        return ans;
    }
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        if (head == nullptr or head->next == nullptr)
            return head;

        Node *mid = findmid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = nullptr;

        left = mergeSort(left);
        right = mergeSort(right);

        Node *result = merge(left, right);
        return result;
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends