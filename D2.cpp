#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; // Define MAX_BOOKS globally

class Lib {
public:
    int cost;
    string name;

    void info() {
        cout << "Enter name of book: ";
        cin.ignore(); // Clear the buffer before reading a line
        getline(cin, name);
        cout << "Enter cost of book: ";
        cin >> cost;
    }

    // Static method to display all books
    static void displayAll(Lib books[], int n) {
        cout << "\tName\tCost\n";
        for (int i = 0; i < n; ++i) {
            cout << "\t" << books[i].name << "\t" << books[i].cost << "\n";
        }
    }

    // Static method to sort books in descending order by cost
    static void sortDescending(Lib books[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (books[i].cost < books[j].cost) {
                    // Swap
                    Lib temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    // Static method to display books with cost less than 500
    static void displayCostLessThan500(Lib books[], int n) {
        for (int i = 0; i < n; ++i) {
            if (books[i].cost < 500) {
                cout << "\t" << books[i].name << "\t" << books[i].cost << "\n";
            }
        }
    }
    
    // Static method to display number of books with cost more than 500
    static void displayCostMoreThan500(Lib books[], int n) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].cost > 500) {
                ++count;
            }
        }
        cout << "Number of books greater than 500: " << count << endl;
    }

    // Static method to delete duplicate entries based on the name only in the original array
    static void deleteDuplicate(Lib books[], int& n) {
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                if (books[j].name == books[i].name) {
                    // Shift all elements to the left
                    for (int k = j; k < n - 1; ++k) {
                        books[k] = books[k + 1];
                    }
                    --n; // Reduce the total count
                } else {
                    ++j;
                }
            }
            ++i;
        }
        cout << "\nDuplicates removed based on book name in the original array.\n";
        cout << "Unique books after removing duplicates:" << endl;
        displayAll(books, n);
    }
    
    // Static method to delete duplicate entries using a temporary array without modifying the original array
    static void deleteduplicatetemp(const Lib books[], int n) {
        Lib tempBooks[MAX_BOOKS];
        int tempCount = 0;

        for (int i = 0; i < n; ++i) {
            bool isDuplicate = false;
            for (int j = 0; j < tempCount; ++j) {
                if (books[i].name == tempBooks[j].name) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                tempBooks[tempCount++] = books[i];
            }
        }

        cout << "\nDuplicates removed using temporary array.\n";
        cout << "Unique books from the temporary array:" << endl;
        displayAll(tempBooks, tempCount);
    }
};

int main() {
    Lib books[MAX_BOOKS];
    int n = 0;  // Initialize number of books to 0
    int i, ch, choice;

    do {
        cout << "\n1. Insert data\n2. Display data\n3. Sort in descending order\n4. Display books with cost less than 500\n5. Display number of books with cost more than 500\n6. Delete duplicate entries in original array\n7. Delete duplicate entries with temporary array\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of books: ";
                cin >> n;
                if (n > MAX_BOOKS) {
                    cout << "Number of books exceeds the maximum limit of " << MAX_BOOKS << endl;
                    n = MAX_BOOKS;  // Limit the number of books to MAX_BOOKS
                }
                for (i = 0; i < n; ++i) {
                    books[i].info();
                }
                break;
            case 2:
                cout << "\tName\tCost\n";
                Lib::displayAll(books, n);
                break;
            case 3:
                Lib::sortDescending(books, n);
                cout << "Books sorted in descending order:" << endl;
                Lib::displayAll(books, n);
                break;
            case 4:
                cout << "Books with cost less than 500:" << endl;
                Lib::displayCostLessThan500(books, n);
                break;
            case 5:
                Lib::displayCostMoreThan500(books, n);
                break;
            case 6:
                Lib::deleteDuplicate(books, n);
                break;
            case 7:
                Lib::deleteduplicatetemp(books, n);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        if (ch != 1) {
            cout << "\nEnter 1 to continue, 0 to exit: ";
            cin >> choice;
        } else {
            choice = 1;  // Automatically continue if data was just entered
        }
    } while (choice == 1);

    return 0;
}