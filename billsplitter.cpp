#include <bits/stdc++.h>
using namespace std;

// Function to input names and their corresponding labels
void input(map<string, int>& nameMap, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the name: ";
        string name;
        cin >> name;
        nameMap[name] = i; // Directly insert into the map
        cout << endl;
    }
}

// Function to find the label (index) of a given name
int find_label(map<string, int>& nameMap, const string& name) {
    auto it = nameMap.find(name);
    if (it != nameMap.end()) {
        return it->second;
    } else {
        cerr << "Name not found!" << endl;
        return -1; // Return an invalid index if name is not found
    }
}

// Function to find the name corresponding to a given label (index)
string find_name(map<string, int>& nameMap, int label) {
    for (const auto& pair : nameMap) {
        if (pair.second == label) {
            return pair.first;
        }
    }
    return "Unknown"; // Return a placeholder if the label is not found
}

int main() {
    int n; // Number of persons
    cout << "Enter the number of persons: ";
    cin >> n;
    map<string, int> nameMap;

    // Input pairs of names and their labels
    input(nameMap, n);

    int arr[n][n];
    memset(arr, 0, sizeof(arr)); // Initialize the 2D array to 0

    int test = 0;
    while (test != -1) {
        int expense;
        string payer;
        cout << "What's the expense? : ";
        cin >> expense;
        cout << "WHO PAID IT? : ";
        cin >> payer;

        int x = find_label(nameMap, payer);
        if (x == -1) continue; // Skip if the name is not found

        int expensePerPerson = expense / n;
        for (int i = 0; i < n; i++) {
            if (i != x) arr[x][i] += expensePerPerson;
        }

        cout << "Press -1 to stop OR press any number to continue : ";
        cin >> test;
    }

    cout << "\nExpense matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nPayment settlements:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int v1 = arr[i][j];
            int v2 = arr[j][i];
            int diff = v1 - v2;
            string name_i = find_name(nameMap, i);
            string name_j = find_name(nameMap, j);

            if (diff == 0) {
                cout << name_i << " and " << name_j << " have no payment" << endl;
            } else if (diff < 0) {
                cout << name_i << " needs to pay " << name_j << " Rs." << abs(diff) << endl;
            } else {
                cout << name_j << " needs to pay " << name_i << " Rs." << abs(diff) << endl;
            }
        }
    }

    return 0;
}
