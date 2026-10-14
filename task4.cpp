#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
private:
	int N;
	vector<vector<int>> board;
	vector<int> dx, dy;

	bool isValid(int row, int col) {
		return row >= 0 && row < N &&
			col >= 0 && col < N &&
			board[row][col] == -1;
	}

	bool solveKnightTour(int row, int col, int moveNumber) {
		if (moveNumber == board.size() * board.size() + 1) return true;
		if (!isValid(row, col)) return false;
		board[row][col] = moveNumber;
		for (int i = 0; i < 8; i++){
			if (solveKnightTour(row + dx[i], col + dy[i], moveNumber + 1)) return true;
		}
		board[row][col] = -1;
		return false;
	}

public:
	Solution(int n) {
		N = n;
		board.assign(N, vector<int>(N, -1));

		dx = { -2, -2, -1, -1, 1, 1, 2, 2 };
		dy = { -1, 1, -2, 2, -2, 2, -1, 1 };
	}

	bool knightTour(int startRow, int startCol) {
		if (!isValid(startRow, startCol)) {
			return false;
		}

		return solveKnightTour(startRow, startCol, 1);
	}

	void printBoard() {
		cout << "\nKnight's Tour:\n\n";

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << setw(4) << board[i][j];
			}
			cout << '\n';
		}
	}
};

int main() {
	int N, row, col;

	cout << "Enter board size N: ";
	cin >> N;

	if (!cin || N <= 0) {
		cout << "Invalid board size.\n";
		return 0;
	}

	cout << "Enter starting row and column (0-based): ";
	cin >> row >> col;

	if (!cin || row < 0 || row >= N ||
		col < 0 || col >= N) {
		cout << "Invalid starting position.\n";
		return 0;
	}

	Solution obj(N);

	if (obj.knightTour(row, col)) {
		obj.printBoard();
	}
	else {
		cout << "\nNo Knight's Tour found.\n";
	}
	int x;
	cin >> x;
	return 0;
}