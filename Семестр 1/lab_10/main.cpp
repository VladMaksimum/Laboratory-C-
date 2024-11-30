#include <iostream>
#include "func.hpp"


int main()
{
    Node* head = new Node{0,nullptr};
    int n;
    fill(head,n);
    
    if(!find_palindrom(head))
    {
        sort(head,n);
    }
    else
    {
        remove(head);
        duplicate(head);
    }

    write(head);
    clean(head);

    return 0;
}


