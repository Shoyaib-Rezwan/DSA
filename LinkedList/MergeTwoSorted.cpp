/*Input: a: 5->10->15, b: 2->3->20
Output: 2->3->5->10->15->20

Input: a: 1->1, b: 2->4
Output: 1->1->2->4*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
};
void append(Node **head, int data)
{
    if (!*head)
    {
        *head = new Node(data);
    }
    else
    {
        Node *temp = *head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}
void print(Node *head)
{
    while (head)
    {
        cout << head->data << '\t';
        head = head->next;
    }
    cout << '\n';
}
Node *merge(Node *head1, Node *head2)
{
    Node *cur1 = head1;
    Node *cur2 = head2;
    Node *next1 = head1->next;
    Node *next2 = head2->next;
    while (cur1 && cur2)
    {
        // at first compare between cur1 and cur 2 who stores the smallest data
        if (cur1->data < cur2->data)
        {
            // here cur1 contains the smaller data. Now compare between cur2 and next1.If next1 contains the smaller data then don't do anything. But if either next1 is null or cur2 contains the smaller data then ridirect the next pointer of curr1.
            if (!next1 || cur2->data < next1->data)
            {
                cur1->next = cur2;
            }
            cur1 = next1; // modify cur1 and next1
            if (next1)
                next1 = next1->next;
        }
        else
        {
            if (!next2 || cur1->data < next2->data)
            {
                cur2->next = cur1;
            }
            cur2 = next2;
            if (next2)
                next2 = next2->next;
        }
    }
    //be careful while returning the head of the merged lists
    if (head1->data < head2->data)
        return head1;
    else
        return head2;
}
int main()
{
    Node *head1;
    head1 = nullptr;
    Node *head2;
    head2 = nullptr;
    int m, n, data;
    cin >> m >> n;
    while (m--)
    {
        cin >> data;
        append(&head1, data);
    }
    while (n--)
    {
        cin >> data;
        append(&head2, data);
    }
    print(head1);
    print(head2);
    head1 = merge(head1, head2);
    print(head1);
}