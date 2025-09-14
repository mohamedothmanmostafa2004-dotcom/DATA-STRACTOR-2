#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertLeft(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertRight(int value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int value)
    {
        if (pos < 0)
        {
            cout << "❌ Invalid position!" << endl;
            return;
        }
        if (pos == 0)
        {
            insertLeft(value);
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "❌ Position out of range!" << endl;
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeLeft()
    {
        if (!head)
        {
            cout << "❌ List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeRight()
    {
        if (!head)
        {
            cout << "❌ List is empty!" << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void removeAtPosition(int pos)
    {
        if (!head)
        {
            cout << "❌ List is empty!" << endl;
            return;
        }
        if (pos == 0)
        {
            removeLeft();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (!temp || !temp->next)
        {
            cout << "❌ Position out of range!" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    void search(int value)
    {
        Node* temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                cout << "✔ Value found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "❌ Value not found in list." << endl;
    }

    void print()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

#endif
