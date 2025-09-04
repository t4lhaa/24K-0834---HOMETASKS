#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authorList; 
    int authorCount;

public:
    ResearchPaper(const string inputAuthors[], int size) {
        authorCount = size;
        authorList = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authorList[i] = inputAuthors[i];
        }
    }

    ResearchPaper(const ResearchPaper& src) {
        authorCount = src.authorCount;
        authorList = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authorList[i] = src.authorList[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& src) {
        if (this != &src) {
            delete[] authorList;

            authorCount = src.authorCount;
            authorList = new string[authorCount];
            for (int i = 0; i < authorCount; i++) {
                authorList[i] = src.authorList[i];
            }
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authorList;
    }

    void displayAuthors() const {
        cout << "Authors: ";
        for (int i = 0; i < authorCount; i++) {
            cout << authorList[i];
            if (i < authorCount - 1) cout << ", ";
        }
        cout << endl;
    }
};

int main() {
    string team1[] = {"Ali", "Ahmed", "Talha"};
    ResearchPaper paper1(team1, 3);

    cout << "Paper 1: ";
    paper1.displayAuthors();

    ResearchPaper paper2(paper1);
    cout << "Paper 2 (copied from Paper 1): ";
    paper2.displayAuthors();

    string team2[] = {"Adam", "Irfan"};
    ResearchPaper paper3(team2, 2);
    cout << "Paper 3 before copy: ";
    paper3.displayAuthors();

    paper3 = paper1;
    cout << "Paper 3 after assignment (copied from Paper 1): ";
    paper3.displayAuthors();

    return 0;
}