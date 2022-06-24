// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    Node *curr = head1;
    map<int, int> mp;
    while (curr != nullptr)
    {
        mp[curr->data]++;
        curr = curr->next;
    }
    curr = head2;
    Node *head = nullptr, *head_itr = nullptr, *temp = nullptr;
    while (curr != nullptr)
    {
        if (mp[curr->data] > 0)
        {
            temp = new Node(curr->data);
            mp[curr->data]--;
            if (head == nullptr)
            {
                head = temp;
                head_itr = head;
            }
            else
            {
                head_itr->next = temp;
                head_itr = temp;
            }
        }
        curr = curr->next;
    }
    return head;
}