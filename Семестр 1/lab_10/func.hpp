#pragma once

struct Node
{
    int data;
    Node* next;
};

void add(Node* head, int new_data);
void fill(Node* head, int& n);
void write(Node* head);

void remove(Node* head);
void clean(Node* head);
bool find_palindrom(Node* head);
bool palindrom(int x);
void sort(Node* head, int n);
void duplicate(Node* head);
Node* element_by_index(Node* head, int index);
bool simple(int x);