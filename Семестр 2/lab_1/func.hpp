#pragma once

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void add(Node* sent, int data);
void fill(Node* sent, int n);
void write(Node* sent);

bool different_digits(Node* sent);
bool same_digits(int x);
void sort(int n, Node* sent);
void del(Node* sent);
bool even_digits(int x);
void dupl(Node* sent);
bool odd_digits(int x);