#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data = 0, Node *prev = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
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
        temp->next = new Node(data, temp, nullptr);
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
Node **split(Node *head, int N)
{
    Node *curr = new Node;
    Node *Prev = new Node;
    curr = head;
    Prev->next = head;
    // counting size
    int cnt = 0;
    while (curr)
    {
        cnt++;
        curr = curr->next;
    }
    cnt = ceil((double)cnt / N);
    Node **arr = new Node *[cnt + 1];
    curr = head;
    int i = 0;
    int j = N;
    while (curr)
    {
        arr[i++] = curr;
        j = N;
        while (j--)
        {
            Prev = curr;
            curr = curr->next;
            if (!curr)
                break;
        }
        Prev->next = nullptr;
        if (curr)
            curr->prev = nullptr;
    }
    arr[i] = nullptr;
    return arr;
}
Node *reverse(Node *head)
{
    Node *curr = new Node;
    curr = head;
    do
    {
        swap(curr->prev, curr->next);
        if (!curr->prev)
            break;
        curr = curr->prev;
    } while (1);
    return curr;
}
Node *merge(Node *head1, Node *head2)
{
    Node *curr = head1;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = head2;
    return head1;
}
Node *reverseByGroup(Node *head, int N)
{
    Node **arr = split(head, N);
    arr[0] = reverse(arr[0]);
    for (int i = 1; arr[i]; i++)
    {
        arr[0] = merge(arr[0], reverse(arr[i]));
    }
    return arr[0];
}
int main()
{
    Node *head = new Node;
    head = nullptr;
    for (int i = 0; i < 5; i++)
    {
        append(&head, i + 1);
    }
    head = reverseByGroup(head, 3);
    print(head);
}