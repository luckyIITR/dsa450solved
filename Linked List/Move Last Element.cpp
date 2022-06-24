/****************************************************************
Following is the Linked list node structure already written

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;
    LinkedListNode(T data)
    {
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

LinkedListNode<int> *moveToFront(LinkedListNode<int> *head)
{

    LinkedListNode<int> *curr = head, *prev = nullptr;
    if (curr->next == nullptr)
        return head;
    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = nullptr;
    curr->next = head;
    head = curr;
    return head;
}