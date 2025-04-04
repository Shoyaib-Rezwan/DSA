// ques::F :\shoyaib\BUET\Level1 Term2\Course Materials\Sessional\CSE 106\Linked List\assignment 1 - List - V1 .1.docx.pdf
#include <iostream>
#include <cstdlib>
using namespace std;
template <class X>
class Alist
{
    X *arr;
    int size;
    int current;

public:
    void init(int k)
    {
        size = k;
        current = 0;
        arr = new X[k];
        int item;
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
    }
    void insert(X item)
    {
        size++;
        arr = (X *)realloc(arr, size * sizeof(X));
        for (int i = size - 1; i > current; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[current] = item;
    }
    X remove()
    {
        X temp = arr[current];
        for (int i = current; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        arr = (X *)realloc(arr, size * sizeof(X));
        if (current == size)
            current--;
        return temp;
    }
    void moveToStart() { current = 0; }
    void moveToEnd() { current = size - 1; }
    void prev()
    {
        if (current)
            current--;
        else
            cout << "Current is at the start\n";
    }
    void Next()
    {
        if (current == size - 1)
            cout << "Current is at the end of the list.\n";
        else
            current++;
    }
    int getlength() { return size; }
    void moveToPos(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Out of range!\n";
        }
        else
            current = pos;
    }
    X getValue() { return arr[current]; }
    void ShowList()
    {
        if (size == 0)
            cout << "\nThe list is empty!\n";
        else
        {
            cout << "\n< ";
            for (int i = 0; i < size; i++)
            {
                if (i == current)
                {
                    cout << "| ";
                }
                cout << arr[i] << ' ';
            }
            cout << " >";
        }
    }
    void append(X item)
    {
        size++;
        arr = (X *)realloc(arr, size * sizeof(X));
        arr[size - 1] = item;
    }
    void clear()
    {
        size = 0;
        current = 0;
        free(arr);
    }
    int search(X item)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == item)
                return i;
        }
        return -1;
    }
};
int main()
{
    Alist<char> lst;
    int k;
    cin >> k;
    lst.init(k);
    lst.ShowList();
    lst.insert('x');
    lst.ShowList();
    lst.moveToPos(5);
    lst.ShowList();
    lst.insert('y');
    lst.ShowList();
    lst.moveToEnd();
    lst.ShowList();
    lst.remove();
    lst.ShowList();
    lst.append('z');
    lst.ShowList();
    cout << '\n'
         << lst.search('C');
    cout << '\n'
         << lst.search('c');
    lst.clear();
    lst.ShowList();
}