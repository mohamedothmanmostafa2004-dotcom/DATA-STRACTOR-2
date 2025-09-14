#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList list;
    int choice, value, pos;

    do
    {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert Left\n";
        cout << "2. Insert Right\n";
        cout << "3. Insert at Position\n";
        cout << "4. Remove Left\n";
        cout << "5. Remove Right\n";
        cout << "6. Remove at Position\n";
        cout << "7. Search\n";
        cout << "8. Print List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertLeft(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertRight(value);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            list.insertAtPosition(pos, value);
            break;
        case 4:
            list.removeLeft();
            break;
        case 5:
            list.removeRight();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.removeAtPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 8:
            list.print();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "❌ Invalid choice!\n";
        }
    }
    while (choice != 9);

    return 0;
}
