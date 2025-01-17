#include <iostream>
#include "func.hpp"


void add(Node* sent, int data)
{
    Node* q = new Node;
    q->data = data;
    q->next = sent;
    q->prev = sent->prev;
    q->prev->next = q;
    q->next->prev = q;
}

void fill(Node* sent, int n)
{
    for(int i=0;i<n;i++)
    {
        int data;
        std::cin >> data;
        add(sent,data);
    }
}

void write(Node* sent)
{
    Node* p = sent->next;
    while(p!=sent)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
}

bool different_digits(Node* sent)
{
    Node* p = sent->next;
    while(p != sent)
    {
        if(p->data >=100 && p->data <= 999 && !same_digits(p->data))
        {
            return true;
        }
        p=p->next;
    }
    return false;
}

bool same_digits(int x)
{
    int first = x%10;
    int second = (x%100)/10;
    int third = x/100;

    return (first==second && first==third);
}

void sort(int n, Node* sent)
{
    for(int i=0; i<n; i++)
    {
        Node* p = sent->next;
        while(p->next != sent)
        {
            if(p->data > (p->next->data))
            {
                std::swap(p->data, p->next->data);
            }
            p= p->next;
        }
    }
}

void del(Node* sent)
{
    Node* p =sent->next;
    while(p != sent)
    {
        if(even_digits(p->data))
        {
            Node* tmp = p->prev->next;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p=p->prev;
            delete tmp;
        }
        p= p->next;
    }
}

bool even_digits(int x)
{
    while(x != 0 )
    {
        if(x%2!=0)
        {
            return false;
        }
        x/=10;

    }
    return true;
}

void dupl(Node* sent)
{
    Node* p = sent->next;
    while(p!=sent)
    {
        if(odd_digits(p->data))
        {
            Node* q = new Node{p->data, p->next, p};
            p->next = q;
            p->next->prev = q;
            p = p->next;
        }
        p = p->next;
    }
}

bool odd_digits(int x)
{
    while(x != 0 )
    {
        if(x%2==0)
        {
            return false;
        }
        x/=10;

    }
    return true;
}