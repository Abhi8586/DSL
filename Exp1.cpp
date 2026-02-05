#include <iostream>
using namespace std;

int main()
{
    int a[50], n, i, choice, pos, val, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(i = 0; i < n; i++)
        cin >> a[i];

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Traverse (Display)\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Update\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Array elements: ";
                for(i = 0; i < n; i++)
                    cout << a[i] << " ";
                cout << endl;
                break;

            case 2:
                if(n == 50){
                    cout << "Array full!\n";
                    break;
                }

                cout << "Enter position (1 to " << n+1 << "): ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> val;

                pos--;

                if(pos < 0 || pos > n){
                    cout << "Invalid position\n";
                    break;
                }

                for(i = n; i > pos; i--)
                    a[i] = a[i-1];

                a[pos] = val;
                n++;
                break;

            case 3:
                cout << "Enter position (1 to " << n << "): ";
                cin >> pos;

                pos--;

                if(pos < 0 || pos >= n){
                    cout << "Invalid position\n";
                    break;
                }

                for(i = pos; i < n-1; i++)
                    a[i] = a[i+1];

                n--;
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> key;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == key)
                    {
                        cout << "Element found at position " << i+1 << endl;
                        break;
                    }
                }
                if(i == n)
                    cout << "Element not found\n";
                break;

            case 5:
                cout << "Enter position (1 to " << n << "): ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> val;

                pos--;

                if(pos < 0 || pos >= n){
                    cout << "Invalid position\n";
                    break;
                }

                a[pos] = val;
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}