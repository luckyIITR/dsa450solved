// { Driver Code Starts
// Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
public:
    /* Iterative Method */

    struct Node *reverseList(struct Node *head)
    {
        struct Node *curr = head, *prev = nullptr, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    /* Recursive method*/
    struct Node *reverse(struct Node *curr, struct Node *prev)
    {
        if (curr == nullptr)
        {
            return prev;
        }
        struct Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        return reverse(curr, prev);
    }
    // Function to reverse a linked list.
    struct Node *a_2reverseList(struct Node *head) // Approch 2
    {
        struct Node *prev = reverse(head, nullptr);
        return prev;
    }
};

// { Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;

        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;

        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends