/*
Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

Examples:
input: 3->6->2->12->56->8   k=2
output: 2->3->6->8->12->56

//to sort a K sorted array we will use the min heap technique.We will create a min heap of size k+1 and build heap with 1st k+1 elements and then obviuosly the smallest number in the list will be at the top of the heap.Each time we will plac ethe top at the current poisition of the list and add another element from the list to the heap(If there are no elements left then put INF in the heap)
*/
#include <iostream>
using namespace std;
#define INF INT32_MAX
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
class Solution
{
    int *arr;
    int heapSize;
    void init(int k)
    {
        arr = new int[k + 2];
        heapSize = k + 1;
    }
    void heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;
        if (left <= heapSize && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right <= heapSize && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }
    void buildHeap()
    {

        for (int i = heapSize / 2; i >= 1; i--)
        {

            heapify(i);
        }
    }

public:
    Node *kAwaySort(Node *head, int k)
    {
        init(k);
        k++;
        Node *temp = head;
        Node *curr = head;
        int i = 1;
        while (k--)
        {
            arr[i++] = temp->data;
            temp = temp->next;
        }
        buildHeap();

        while (curr)
        {
            curr->data = arr[1];
            curr = curr->next;
            if (temp)
            {
                arr[1] = temp->data;
                temp = temp->next;
            }
            else
                arr[1] = INF;
            heapify(1);
        }
        return head;
    }
};
int main()
{
    Node *head = new Node;
    head = nullptr;
    int m, data, k;
    cin >> m;
    while (m--)
    {
        cin >> data;
        append(&head, data);
    }
    cin >> k;
    Solution ob;
    head = ob.kAwaySort(head, k);
    print(head);
}