#include <iostream>
#include <string>
using namespace std;

string ReturnPhoneNumber()
{
    string numbah = "+380";
    for (int i = 0; i < 9; i++)
    {
        numbah += to_string(rand() % 10);
    }
    return numbah;
}

string RandomInitials()
{
    string firstNames[] = { "William", "Patrick", "Derek", "Silvia", "Mona", "Quentin", "Zara", "Clara" };
    string lastNames[] = { "Jones", "O'Alle", "Connor", "Smith", "Valentine", "McRae", "Fraser", "O'Neil" };

    int f = rand() % 8;
    int l = rand() % 8;

    string result;
    result += firstNames[f][0];
    result += ". ";
    result += lastNames[l];

    return result;
}


void FillArrayFORTask3(string** arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        arr[0][i] = RandomInitials();
        arr[1][i] = ReturnPhoneNumber();
    }
}


void PrintContacts(string** arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << arr[0][i] << "  |  " << arr[1][i] << endl;
    }
}


int Search(string** arr, int count, string key)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[0][i] == key || arr[1][i] == key)
            return i;
    }
    return -1;
}



int main()
{
    int n;
    cout << "How many contacts do you want? >>> ";
    cin >> n;

    string** contacts = new string * [2];
    contacts[0] = new string[n];
    contacts[1] = new string[n];

    FillArrayFORTask3(contacts, n);

    cout << "\n=== CONTACT LIST ===\n";
    PrintContacts(contacts, n);

    cout << "\nEnter name or phone to search >>> ";
    string key;
    cin.ignore();
    getline(cin, key);

    int index = Search(contacts, n, key);

    if (index == -1)
        cout << "NOT FOUND!\n";
    else
    {
        cout << "FOUND: " << contacts[0][index] << " | " << contacts[1][index] << endl;

        cout << "Do you want to modify it? (y/n) >>> ";
        char c;
        cin >> c;

        if (c == 'y')
        {
            cout << "Enter new name >>> ";
            cin.ignore();
            getline(cin, contacts[0][index]);

            cout << "Enter new phone >>> ";
            getline(cin, contacts[1][index]);

            cout << "UPDATED!\n";
        }
    }

    cout << "\n=== FINAL CONTACT LIST ===\n";
    PrintContacts(contacts, n);

    delete[] contacts[0];
    delete[] contacts[1];
    delete[] contacts;

    return 0;
}
