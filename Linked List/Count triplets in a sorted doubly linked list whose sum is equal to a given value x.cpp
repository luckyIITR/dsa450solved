/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/
#include <map>
int countTriplets(DLLNode *head, int x)
{
    DLLNode *p1 = head, *p2 = nullptr, *p3 = nullptr;
    int count = 0, rem1 = 0, rem2 = 0;

    while (p1->next->next != nullptr)
    {
        map<int, bool> mp;
        rem1 = x - p1->data;
        p2 = p1->next;
        while (p2 != nullptr)
        {
            rem2 = rem1 - p2->data;
            if (mp[rem2])
                count++;
            else
                mp[p2->data] = true;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return count;
}