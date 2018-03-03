#include <iostream>
using namespace std;

char gameArr[3][3];

void startData() {
	int num = 49;
	for (int i = 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			gameArr[i][j] = num;
			num++;
		}
	}
}

void printData() {
	cout << "_______" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "|" << gameArr[i][j];
		}
		cout << "|" << endl;
		cout << "_______" << endl;
	}
}

void gameStep(int position, char symbol) {
	switch (position)
	{
	case 1:
		gameArr[2][0] = symbol;
		break;
	case 2:
		gameArr[2][1] = symbol;
		break;
	case 3:
		gameArr[2][2] = symbol;
		break;
	case 4:
		gameArr[1][0] = symbol;
		break;
	case 5:
		gameArr[1][1] = symbol;
		break;
	case 6:
		gameArr[1][2] = symbol;
		break;
	case 7:
		gameArr[0][0] = symbol;
		break;
	case 8:
		gameArr[0][1] = symbol;
		break;
	case 9:
		gameArr[0][2] = symbol;
		break;
	default:
		break;
	}
}

bool horizontalCheck(char symbol) {
	bool flag = false;
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			if (gameArr[i][j] != symbol) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}
		}
		if (flag) {
			return true;
		}
	}
	return false;
}

bool verticalCheck(char symbol) {
	bool flag = false;
	for (int j = 0; j < 3; j++) {

		for (int i = 0; i < 3; i++) {
			if (gameArr[i][j] != symbol) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}
		}
		if (flag) {
			return true;
		}
	}
	return false;
}
bool diogonalCheck(char symbol) {
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		if (gameArr[i][i] != symbol) {
			flag = false;
			break;
		}
		else {
			flag = true;
		}
	}
	if (flag) {
		return true;
	}
	for (int i = 0; i < 3; i++) {
		if (gameArr[i][2 - i] != symbol) {
			flag = false;
			break;
		}
		else {
			flag = true;
		}
	}

	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

bool checkWin(char symbol) {
	bool flag;
	flag = horizontalCheck(symbol);
	if (flag) {
		return flag;
	}
	else {
		flag = verticalCheck(symbol);
		if (flag) {
			return flag;
		}
		else {
			flag = diogonalCheck(symbol);
				return flag;
		}
	}
}
bool checkFreeCells() {
	bool flag = false;
	for (int i = 0; i <3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameArr[i][j] != 'X' && gameArr[i][j] != '0') {
				flag = true;
				break;
			}
		}
	}
	return flag;
}

int main() {
	startData();
	printArr();
	while (1) {
		cout << "Step first gamer " << endl;
		int a;
		cin >> a;
		gameStep(a, 'X');
		system("cls");
		printArr();
		cout << endl << endl;
		if (checkWin('X')) {
			cout << "first gammer win";
			break;
		}

		cout << "Step second gamer " << endl;
		cin >> a;
		gameStep(a, '0');
		system("cls");
		printArr();
		cout << endl << endl;
		if (checkWin('0')) {
			cout << "second gammer win";
			break;
		}
		
		if (!checkFreeCells()) {
			cout << "DRAW!!!!";
			break;
		}
	}
	system("pause");
	return 0;
}
