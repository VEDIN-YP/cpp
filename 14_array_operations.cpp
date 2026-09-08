#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int sum = 0;

    cout << "Enter 10 numbers:" << endl;

    // Taking input
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Displaying array
    cout << "\nArray elements are: ";

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    // Finding sum
    for(int i = 0; i < 10; i++)
    {
        sum = sum + arr[i];
    }

    float average = sum / 10.0;

    // Finding largest and smallest
    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 1; i < 10; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }

        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    cout << "\n\nSum = " << sum;
    cout << "\nAverage = " << average;
    cout << "\nLargest number = " << largest;
    cout << "\nSmallest number = " << smallest;

    return 0;
}