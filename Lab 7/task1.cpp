#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void insertEnd(Node*& head, string name, int score) {
    Node* newNode = new Node{name, score, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int getMax(Node* head) {
    int mx = head->score;
    Node* temp = head->next;
    while (temp) {
        if (temp->score > mx)
            mx = temp->score;
        temp = temp->next;
    }
    return mx;
}

int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void radixSort(Node*& head) {
    if (!head || !head->next)
        return;

    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        Node* buckets[10] = {NULL};
        Node* bucketTails[10] = {NULL};

        Node* curr = head;
        while (curr) {
            int digit = (curr->score / exp) % 10;
            Node* nextNode = curr->next;
            curr->next = NULL;

            if (!buckets[digit]) {
                buckets[digit] = curr;
                bucketTails[digit] = curr;
            } else {
                bucketTails[digit]->next = curr;
                bucketTails[digit] = curr;
            }
            curr = nextNode;
        }

        head = NULL;
        Node* tail = NULL;
        for (int i = 0; i < 10; i++) {
            if (buckets[i]) {
                if (!head) {
                    head = buckets[i];
                    tail = bucketTails[i];
                } else {
                    tail->next = buckets[i];
                    tail = bucketTails[i];
                }
            }
        }
    }
}

void displayList(Node* head) {
    while (head) {
        cout << head->name << " - " << head->score << endl;
        head = head->next;
    }
}

int main() {
    srand(time(0));
    Node* head = NULL;

    string names[10] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", 
                        "Grace", "Helen", "Ian", "Jane"};

    for (int i = 0; i < 10; i++) {
        int score = rand() % 101;
        insertEnd(head, names[i], score);
    }

    cout << "Original Student Records:\n";
    displayList(head);

    radixSort(head);

    cout << "\nSorted Student Records (Ascending by Score):\n";
    displayList(head);

    return 0;
}
