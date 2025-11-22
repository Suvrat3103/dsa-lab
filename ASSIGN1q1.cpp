#include <iostream>
using namespace std;

#define MAX 100

int main() {
    int arr[MAX], n = 0, choice, pos, element, key;
    bool running = true;

    while (running) {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // CREATE
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                break;

            case 2: // DISPLAY
                if (n == 0) {
                    cout << "Array is empty!" << endl;
                } else {
                    cout << "Array elements: ";
                    for (int i = 0; i < n; i++) cout << arr[i] << " ";
                    cout << endl;
                }
                break;

            case 3: // INSERT
                if (n >= MAX) {
                    cout << "Array is full! Cannot insert." << endl;
                } else {
                    cout << "Enter position (1 to " << n+1 << "): ";
                    cin >> pos;
                    cout << "Enter element: ";
                    cin >> element;
                    if (pos < 1 || pos > n+1) {
                        cout << "Invalid position!" << endl;
                    } else {
                        for (int i = n; i >= pos; i--) arr[i] = arr[i-1];
                        arr[pos-1] = element;
                        n++;
                        cout << "Element inserted!" << endl;
                    }
                }
                break;

            case 4: // DELETE
                if (n == 0) {
                    cout << "Array is empty! Cannot delete." << endl;
                } else {
                    cout << "Enter position (1 to " << n << "): ";
                    cin >> pos;
                    if (pos < 1 || pos > n) {
                        cout << "Invalid position!" << endl;
                    } else {
                        for (int i = pos-1; i < n-1; i++) arr[i] = arr[i+1];
                        n--;
                        cout << "Element deleted!" << endl;
                    }
                }
                break;

            case 5: // LINEAR SEARCH
                if (n == 0) {
                    cout << "Array is empty!" << endl;
                } else {
                    cout << "Enter key to search: ";
                    cin >> key;
                    int found = -1;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == key) {
                            found = i;
                            break;
                        }
                    }
                    if (found != -1)
                        cout << "Element found at position " << found+1 << endl;
                    else
                        cout << "Element not found!" << endl;
                }
                break;

            case 6: // EXIT
                running = false;
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}