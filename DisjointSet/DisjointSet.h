#include <bits/stdc++.h>
using namespace std;
class SetObject;
class ElementObject
{
public:
    int data;
    SetObject *Set;
    ElementObject *next;
    ElementObject(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class SetObject
{
public:
    ElementObject *head;
    ElementObject *tail;
    int size;
    SetObject()
    {
        size = 0;
    }
};
void MakeSet(ElementObject *x)
{
    SetObject *s = new SetObject;
    s->head = x;
    s->tail = x;
    x->Set = s;
    s->size++;
}
ElementObject *FindSet(ElementObject *x)
{
    return x->Set->head;
}
void Union(ElementObject *x, ElementObject *y)
{
    SetObject *sx = x->Set;
    SetObject *sy = y->Set;
    if (sx == sy)
        return;
    if (sx->size < sy->size)
        swap(sx, sy);
    sx->tail->next = sy->head;
    ElementObject *temp = sy->head;
    while (temp)
    {
        temp->Set = sx;
        temp = temp->next;
    }
    sx->size = sx->size + sy->size;
    sx->tail = sy->tail;
    delete sy;
}