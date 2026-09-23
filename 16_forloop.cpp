#include <iostream>
using namespace std;

int main() {

    int arr[10];
    int search;
    int count = 0;

    cout << "Enter 10 numbers:\n";

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "\nEnter number to search: ";
    cin >> search;

    cout << "\nSearching...\n";

    for (int i = 0; i < 10; i++) {

        if (arr[i] == search) {
            cout << "Found at position " << i + 1 << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "Number not found.\n";
    }
    else {
        cout << "\n" << search << " appears "
             << count << " time(s).\n";
    }

    return 0;
}