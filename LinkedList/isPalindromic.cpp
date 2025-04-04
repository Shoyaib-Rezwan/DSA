// you are given a linked list of integers. Check whether its a palindrome or not
// time complexity O(n)
// space complexity O(1)
// hint: split the linked list into two halves, reverse the last halve and compare them
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
Node **split(Node *head)
{
    // calculate length
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    // calculate middle

    if (cnt % 2)
    {
        cnt = cnt / 2 + 1;
    }
    else
    {
        cnt = cnt / 2;
    }
    Node *prev = new Node;
    prev = nullptr;
    temp = head;
    while (cnt--)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;

    Node **arr = new Node *[2];
    arr[0] = head;
    arr[1] = temp;
    return arr;
}
Node *reverse(Node *head)
{
    Node *prev, *curr, *Next;
    prev = nullptr;
    curr = head;
    Next = head->next;
    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        if (Next)
            Next = Next->next;
    }
    return prev;
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
bool isPalindrom(Node *head)
{
    if (!head->next)
        return true; // handle the case when there is only one element
    // the second list will contain one less element than the 1st list if the whole list contains odd elements.

    Node **arr = split(head);
    arr[1] = reverse(arr[1]);
    while (arr[1])
    {
        if (arr[1]->data != arr[0]->data)
            return false;
        else
        {
            arr[1] = arr[1]->next;
            arr[0] = arr[0]->next;
        }
    }
    return true;
}
int main()
{
    Node *head = new Node;
    head = nullptr;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        append(&head, data);
    }
    // print(head);
    //     Node **arr = split(head);
    //     print(arr[0]);
    //     print(arr[1]);
    //     arr[1] = reverse(arr[1]);
    //     print(arr[1]);
    cout << isPalindrom(head);
}