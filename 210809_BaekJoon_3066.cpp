﻿#include <iostream>
#define MAX_SIZE 40000 + 1
using namespace std;

int binarySearch(int left, int right, int val);

int lisArr[MAX_SIZE];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int tcNum;
	cin >> tcNum;

	for (int i = 0; i < tcNum; i++) {
		int inputNum;
		cin >> inputNum;

		int inputArr[MAX_SIZE];
		int lisIdx = 0;
		cin >> lisArr[lisIdx];

		for (int j = 1; j < inputNum; j++) {
			cin >> inputArr[j];

			if (lisArr[lisIdx] < inputArr[j]) {
				lisArr[++lisIdx] = inputArr[j];
			}

			else {
				int searchIdx = binarySearch(0, lisIdx, inputArr[j]);
				lisArr[searchIdx] = inputArr[j];
			}
		}

		cout << lisIdx + 1 << "\n";
	}

	return 0;
}

int binarySearch(int left, int right, int val) {
	while (left < right) {
		int mid = (left + right) / 2;

		if (lisArr[mid] < val) {
			left = mid + 1;
		}

		else {
			right = mid;
		}
	}

	return right;
}