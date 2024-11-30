#include <iostream>
#include "func.hpp"


void add(Node* head, int new_data)
{
    Node* p = head;
    while(p->next != nullptr)
    {
        p=p->next;
    }

    Node* q = new Node;
    q->data = new_data;
    q->next = nullptr;
    p->next = q;

}

void fill(Node* head, int& n)
{
    std::cout << "n=";
    std::cin >> n;

    for(int i=0; i<n; i++)
    {
        int new_data;
        std::cin >> new_data;
        add(head, new_data);
    }
}

void write(Node* head)
{
    Node* p = head->next;
    while(p != nullptr)
    {
        std::cout << p->data << " ";
        p=p->next;
    }

}

bool simple(int x)
{
    if(x<2)
        return false;
    else 
    {
        for(int i=2; i<=sqrt(x); i++)
        {
            if(x%i==0)
            {
                return false;
            }
        }
    }
    
    return true;
}

void remove(Node* head)
{
    Node* p = head;
    while(p->next != nullptr)
    {
        if(simple(p->next->data))
        {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        }
        p=p->next;
    }

}

void duplicate(Node* head)
{
    Node* p =head;
    while(p->next != nullptr)
    {
        if((p->next->data)%10==0)
        {
            Node* q = new Node;
            q->data = p->next->data;
            q->next = p->next->next;
            p->next->next = q;
            p=p->next->next;
        }
        else
            p=p->next;
    }
}

void clean(Node* head)
{
    Node* p =head;
    while(p->next != nullptr)
    {
        Node* tmp = p;
        p=p->next;
        delete tmp;
    }
}


bool palindrom(int x)
{
    int reverse = 0;
    int n1=x;
    while(x>0)
    {
        reverse = 10*reverse + x%10;
        x/=10;
    }
    if(n1==reverse)
        return true;
    else
        return false;
}

bool find_palindrom(Node* head)
{
    Node* p =head->next;
    while(p != nullptr)
    {
        if(palindrom(p->data))
        {
            return true;
        }
        p=p->next;
    }
    return false;
}

Node* element_by_index(Node* head, int index)
{
    Node* p = head->next;
    int i = 0;
    while(i != index)
    {
        i++;
        p=p->next;
    }
    return p;
}

void sort(Node* head, int n)
{
    for(int i=0; i<n-1;i++)
        for(int j=i+1; j<n; j++)
        {
            int& element1 = element_by_index(head,i)->data;
            int& element2 = element_by_index(head,j)->data;
            if(element1 <= element2)
            {
                int tmp = element1;
                element1 = element2;
                element2 = tmp;
            }
        }
}
