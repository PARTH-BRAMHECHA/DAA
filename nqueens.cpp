#include <iostream>
#include <vector>

using namespace std;

// Function to print the board
void print_board(const vector<int>& queens) {
    int n = queens.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (queens[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on the board
bool is_safe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || 
            abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solve_n_queens_recursive(vector<int>& queens, int row, int& count) {
    int n = queens.size();
    if (row == n) {
        ++count;
        cout << "Solution " << count << ":" << endl;
        print_board(queens);
        return;
    }
    
    for (int col = 0; col < n; ++col) {
        if (is_safe(queens, row, col)) {
            queens[row] = col;
            solve_n_queens_recursive(queens, row + 1, count);
            // Backtrack
            queens[row] = -1;
        }
    }
}

// Function to initialize and start the N-Queens problem solver
void solve_n_queens(int n) {
    vector<int> queens(n, -1);
    int count = 0;
    solve_n_queens_recursive(queens, 0, count);
    
    if (count == 0) {
        cout << "No solutions found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (n): ";
    cin >> n;
    
    solve_n_queens(n);
    return 0;
}
