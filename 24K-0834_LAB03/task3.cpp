#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int ID;
    string itemName;
    int price;
    Node *prev;
    Node *next;

    Node(int ID, string itemName, int price) : ID(ID), itemName(itemName), price(price)
    {
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int id, string itemName, int price)
    {
        Node *newNode = new Node(id, itemName, price);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtFront(int id, string itemName, int price)
    {
        Node *newNode = new Node(id, itemName, price);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFromFront()
    {
        if (!head)
        {
            cout << "Cart is empty!!!!!!!!!!" << endl;
            return;
        }
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void removeFromEnd()
    {
        if (!tail)
        {
            cout << "Cart is empty!!!!!!" << endl;
            return;
        }
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void searchByID(int ID)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->ID == ID)
            {
                cout << "Item Found -> ID: " << temp->ID << ", Name: " << temp->itemName << ", Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << ID << " not found!!!!!!!!!" << endl;
    }

    void updatePrice(int ID, int newPrice)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->ID == ID)
            {
                temp->price = newPrice;
                cout << "Price updated for ID " << ID << ". New Price: $" << newPrice << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << ID<< " not found.\n";
    }

    void displayForward()
    {
        cout << "\nCart (Front -> End):"<<endl;
        Node *temp = head;
        while (temp)
        {
            cout << "ID: " << temp->ID << ", itemName: " << temp->itemName << ", Price: $" << temp->price << " | ";
            temp = temp->next;
        }
    }

    void displayBackward()
    {
        cout << "\nCart (End -> Front):\n";
        Node *temp = tail;
        while (temp)
        {
            cout << "ID: " << temp->ID << ", itemName: " << temp->itemName << ", Price: $" << temp->price << " | ";
            temp = temp->prev;
        }
    }

    int countItems()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void mostExpensiveItem()
    {
        if (!head)
        {
            cout << "Cart is empty.\n";
            return;
        }
        Node *temp = head;
        Node *maxNode = head;
        while (temp)
        {
            if (temp->price > maxNode->price)
            {
                maxNode = temp;
            }
            temp = temp->next;
        }
        cout << "Most Expensive Item -> ID: " << maxNode->ID << ", itemName: " << maxNode->itemName << ", Price: $" << maxNode->price << endl;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList cart;

    cart.insertAtEnd(1, "Laptop", 1000);
    cart.insertAtEnd(2, "Phone", 700);
    cart.insertAtEnd(3, "Tablet", 400);
    cart.insertAtFront(0, "Smartwatch", 200);

    cart.displayForward();
    cart.displayBackward();

    cart.searchByID(2);
    cart.updatePrice(3, 450);

    cout << "\nTotal Items: " << cart.countItems() << endl;
    cart.mostExpensiveItem();

    cart.removeFromFront();
    cart.removeFromEnd();

    cart.displayForward();

    return 0;
}
