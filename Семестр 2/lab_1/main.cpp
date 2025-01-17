#include <iostream>
#include "func.hpp"


int main()
{
    Node* sent = new Node;
    sent->next = sent;
    sent->prev = sent;

    int n;
    std::cout << "n=";
    std::cin >> n;
    fill(sent,n);

    if(!different_digits(sent))
    {
        sort(n,sent);
    }
    else
    {
        del(sent);
        dupl(sent);
    }

    write(sent);
    
}


