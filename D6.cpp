#include <iostream>
#define MAX 10
using namespace std;

class queue {
public:
    int q[MAX], f = -1, r = -1, n;

    void insert() {
        cout << "\nEnter number to be inserted in a queue: ";
        cin >> n;
        if (r == MAX - 1) {
            cout << "\nOverflow";
        } else {
            r++; // Move rear pointer
            q[r] = n;
            if (f == -1) {
                f = 0; // Set front if first element
            }
        }
    }

    void insert_f() {
        cout << "\nEnter number to be inserted at front: ";
        cin >> n;
        if (f == 0) {
            cout << "\nOverflow"; // No space at the front
        } else {
            if (f == -1) {
                f = 0;
                r = 0;
                q[f] = n;
            } else {
                f--; // Move front pointer backward
                q[f] = n;
            }
        }
    }

    void del() {
        if (f == -1) {
            cout << "\nUnderflow";
        } else {
            cout << "\nDeleted number from front: " << q[f++];
            if (f > r) { // Reset when queue is empty
                f = -1;
                r = -1;
            }
        }
    }

    void del_r() {
        if (r == -1) {
            cout << "\nUnderflow";
        } else {
            cout << "\nDeleted number from rear: " << q[r--];
            if (f > r) { // Reset when queue is empty
                f = -1;
                r = -1;
            }
        }
    }
};

int main() {
    int ch;
    queue q1;

    do {
        cout << "\nEnter your choice:\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Delete from rear\n5. Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nInsertion at the rear end:";
            q1.insert();
            break;

        case 2:
            cout << "\nInsertion at the front end:";
            q1.insert_f();
            break;

        case 3:
            cout << "\nDeletion at the front end:";
            q1.del();
            break;

        case 4:
            cout << "\nDeletion at the rear end:";
            q1.del_r();
            break;

        case 5:
            cout << "\nExiting from the code!";
            return 0;

        default:
            cout << "\nInvalid choice!";
        }
    } while (ch != 5);
    return 0;
}
