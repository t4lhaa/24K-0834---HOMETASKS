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

class ShoppingCart
{
private:
    Node *head;

public:
    ShoppingCart()
    {
        head = nullptr;
    }

    void addToTail(string itemName, int price)
    {
        Node *newNode = new Node(itemName, price);
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

    void deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "Cart is empty!!!!!!!!!\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void searchByItemName(string target)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemName == target)
            {
                cout << "Item Name: " << temp->itemName << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found in cart.\n";
    }

    void searchByPosition(int pos)
    {
        Node *temp = head;
        int index = 1;
        while (temp != nullptr)
        {
            if (index == pos)
            {
                cout << temp->itemName << " - $" << temp->price << "is at position " << pos << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "No item found at position " << pos << endl;
    }

    void display()
    {
        Node *temp = head;
        cout << "\nShopping Cart items:" << endl;
        while (temp != nullptr)
        {
            cout << temp->itemName << " - $" << temp->price << " | ";
            temp = temp->next;
        }
    }

    ~ShoppingCart()
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
    ShoppingCart cart;

    cart.addToTail("Laptop", 1000);
    cart.addToTail("Phone", 700);
    cart.addToTail("Tablet", 400);
    cart.addToTail("Headphones", 150);

    cout << "Initial cart:";
    cart.display();

    cart.deleteFromFront();
    cart.display();

    cart.searchByItemName("Tablet");
    cart.searchByPosition(2);

    return 0;
}
