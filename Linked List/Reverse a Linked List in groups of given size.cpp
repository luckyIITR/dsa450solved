// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        struct node *curr = head, *prev = nullptr, *next = nullptr;
        struct node *start = nullptr, *end = nullptr, *sudo_head = head;
        while (curr != nullptr)
        {
            // Reverse in k group first
            int counter = 0;
            prev = nullptr;
            sudo_head = curr;
            while (curr != nullptr && counter < k)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                counter++;
            }

            // Then append Reveresed Group in Required LL
            if (start == nullptr)
            {
                start = prev;
                end = sudo_head;
            }
            else
            {
                end->next = prev;
                end = sudo_head;
            }
        }
        return start;
    }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends