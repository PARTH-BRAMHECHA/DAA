/*
 Name:Parth Anand Bramhecha
 Class:Te-09  Batch:L-9
 Roll number:33115
 Date:10/7/24
*/
#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

struct st {
    int weight;   // holds weight of the item
    int profit;   // holds materialistic value of the item
    float density;   // holds p/w value (profit-to-weight ratio)
};

// global variables
int n; // holds the number of items
st data[100];  // declaring an array for holding input data
float cap; // holds the capacity of the knapsack
st knapsack[100]; // to hold the items in knapsack
int k = 0; // pointer to knapsack object
float prof = 0; // holds the total profit 

// Method to get input
void input() {
    const int MAX_ATTEMPTS = 3;
    
    // Input for number of items
    for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
        try {
            int temp;
            if (!(cin >> temp) || temp <= 0) {
                throw invalid_argument("Invalid input. Please enter a positive integer.");
            }
            n = temp;
            break;
        } catch (const invalid_argument& e) {
            cerr << e.what() << " Try again." << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
        }
    }

    // Input for knapsack capacity
    for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
        try {
            float temp;
            if (!(cin >> temp) || temp <= 0) {
                throw invalid_argument("Invalid input. Please enter a positive float.");
            }
            cap = temp;
            break;
        } catch (const invalid_argument& e) {
            cerr << e.what() << " Try again." << endl;
            cin.clear();  // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
        }
    }

    // Input for weights and profits of items
    for (int i = 0; i < n; i++) {
        // Input for weight of i-th element
        for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
            try {
                int temp;
                if (!(cin >> temp) || temp <= 0) {
                    throw invalid_argument("Invalid input. Please enter a positive integer.");
                }
                data[i].weight = temp;
                break;
            } catch (const invalid_argument& e) {
                cerr << e.what() << " Try again." << endl;
                cin.clear();  // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
            }
        }

        // Input for profit of i-th element
        for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
            try {
                int temp;
                if (!(cin >> temp) || temp <= 0) {
                    throw invalid_argument("Invalid input. Please enter a positive integer.");
                }
                data[i].profit = temp;
                break;
            } catch (const invalid_argument& e) {
                cerr << e.what() << " Try again." << endl;
                cin.clear();  // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input buffer
            }
        }
        
        // Calculate density after successful inputs
        data[i].density = static_cast<float>(data[i].profit) / data[i].weight;
    }
}

// Method to show the output
void show() {
    cout << "SR.NO" << "\t" << "Weight" << "\t" << "Profit" << "\t" << "P/W" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << data[i].weight << "\t" << data[i].profit << "\t" << data[i].density << endl;
    }
}

// Method to sort according to the density
void sort() {
    for (int i = 1; i < n; i++) {
        st key = data[i];
        int j = i - 1;

        // Move elements of data[0..i-1],
        // that are greater than key.density,
        // to one position ahead of their
        // current position
        while (j >= 0 && data[j].density < key.density) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

// Method to add into knapsack
void add(int i) {
    knapsack[k] = data[i];
    k++;
}

// Method to add into knapsack - overloaded
void add(int n, int i) {
    knapsack[k].profit = data[i].profit;
    knapsack[k].density = data[i].density;
    knapsack[k].weight = n;
    k++;
}

// Method to fill the knapsack
void fill() {
    int totalweight = 0;
    for (int l = 0; l < n; l++)
        totalweight = totalweight + data[l].weight;
    int temp = totalweight > cap ? cap : totalweight; // temporarily hold the capacity which is minimum value of knapsack and totalweight
    int i = 0;
    while (temp > 0 && i < n) {
        if (temp > data[i].weight) {
            add(i);
            temp = temp - data[i].weight;
        } else {
            add(temp, i);
            temp = 0;
        }
        i++;
    }
}

// Method to show knapsack
void showknap() {
    cout << "The knapsack contains:" << endl;
    cout << "SR.NO" << "\t" << "Weight" << "\t" << "Profit" << "\t" << "P/W" << endl;
    for (int i = 0; i < k; i++) {
        cout << i + 1 << "\t" << knapsack[i].weight << "\t" << knapsack[i].profit << "\t" << knapsack[i].density << endl;
    }
}

// Method to calculate total profit
float totalprofit() {
    for (int i = 0; i < k; i++) {
        prof = prof + knapsack[i].density * knapsack[i].weight;
    }
    return prof;
}

int main() {
    try {
        input();
        cout <<endl<< "ENTERED VALUES ARE:" << endl;
        show();
        sort();
        cout << endl;
        fill();
        showknap();
        cout <<endl<< "Expected profit is :" << totalprofit() << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}
