#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string itemName;
    int price;
    Node *next;
    Node(string itemName, int price) : itemName(itemName), price(price)
    {
        next = nullptr;
    }
};

class Cart
{
private:
    Node *head;

public:
    Cart()
    {
        head = nullptr;
    }

    void insertAtFront(string item, int price)
    {
        Node *newNode = new Node(item, price);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string item, int price)
    {
        Node *newNode = new Node(item, price);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string target, string item, int price)
    {
        Node *temp = head;
        while (temp != nullptr && temp->itemName != target)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
            return;
        Node *newNode = new Node(item, price);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(string target)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemName == target)
            {
                cout << target << " found! Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found in cart.\n";
    }

    void display()
    {
        Node *temp = head;
        cout << "\nShopping Cart Items:\n";
        while (temp != nullptr)
        {
            cout << temp->itemName << " - $" << temp->price << " | ";
            temp = temp->next;
        }
    }

    ~Cart()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    Cart cart;

    cart.insertAtEnd("Laptop", 1000);
    cart.insertAtEnd("Phone", 700);
    cart.insertAtEnd("Tablet", 400);
    cart.insertAtEnd("Headphones", 150);
    cart.display();
    
    cart.insertAtFront("Smartwatch", 200);
    cart.insertAtEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);
    cart.search("Tablet");
    cart.display();

    return 0;
}
