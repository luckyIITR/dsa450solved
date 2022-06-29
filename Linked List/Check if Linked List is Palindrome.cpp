// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head->next == nullptr)
            return head;
        Node *curr = head, *prev = nullptr, *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next == nullptr)
            return true;
        Node *curr = head;
        int n = 0;
        while (curr != nullptr)
        {
            curr = curr->next;
            n++;
        }
        int i = 0;
        Node *mid = head, *prev = nullptr;

        while (i < n / 2)
        {
            i++;
            prev = mid;
            mid = mid->next;
        }
        if (n % 2 == 1)
        {
            Node *reversed = reverse(mid->next);
            while (reversed != nullptr)
            {
                if (reversed->data != head->data)
                    return false;
                head = head->next;
                reversed = reversed->next;
            }
        }

        else
        {
            Node *reversed = reverse(mid);
            while (reversed != nullptr)
            {
                if (reversed->data != head->data)
                    return false;
                head = head->next;
                reversed = reversed->next;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends