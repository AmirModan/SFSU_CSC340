#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

bool isWon(char c, char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		if (((c == arr[i][0]) && (arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2])) || ((c == arr[0][i]) && (arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))) {
			return true;
		} 
	}
	if (((c == arr[0][0]) && (arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) || ((c == arr[2][0]) && (arr[2][0] == arr[1][1]) && (arr[1][1] == arr[0][2]))) {
		return true;
	}
	else {
		return false;
	}
}

bool isDraw(char arr[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void displayBoard(char arr[][3]) {

	cout << endl;
	cout << "-------------" << endl;
	cout << "| " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " |" << endl;
	cout << "-------------" << endl;

}

void makeAMove(char arr[][3], char c) {

	int row, col;
	bool moveMade = false;

	while (!moveMade) {
		cout << "Enter a row (0, 1, 2) for player " << c << "   : ";
		cin >> row;
		cout << "Enter a column (0, 1, 2) for player " << c << ": ";
		cin >> col;

		if (*(arr[row] + col) == ' ') {
			*(arr[row] + col) = c;
			moveMade = true;
		}
		else {
			cout << "This cell is already occupied. Try a different cell" << endl;
		}
	}	

}

int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
} 