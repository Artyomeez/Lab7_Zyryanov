// dynamic1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <string>
using namespace std;
#define SIZE 100

int tree[SIZE];
int endptr = 0;
extern "C"
{
	int printtree()
{
	for (int i = 0; i < endptr; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	return 0;
}

int swap(int i, int j) {
	int tmp;
	tmp = tree[i];
	tree[i] = tree[j];
	tree[j] = tmp;
	return 0;
}

int add(int value)
{
	tree[endptr] = value;
	int pos = endptr;
	endptr++;
	while (tree[pos] < tree[(pos - 1) / 2] && pos != 0) {
		swap(pos, (pos - 1) / 2);
		pos = (pos - 1) / 2;
	}
	return 0;
}

int del()
{
	endptr--;
	int pos = 0;
	tree[pos] = tree[endptr];
	while (((tree[pos] > tree[pos * 2 + 1] && (pos * 2 + 1)<endptr) ||
		(tree[pos] > tree[pos * 2 + 2] && (pos * 2 + 2)<endptr))
		&& pos < endptr)
	{
		if (pos * 2 + 2 >= endptr) {
			swap(pos, pos * 2 + 1);
			pos = pos * 2 + 1;
		}
		else {
			if (tree[pos * 2 + 1] < tree[pos * 2 + 2]) {
				swap(pos, pos * 2 + 1);
				pos = pos * 2 + 1;
			}
			else {
				swap(pos, pos * 2 + 2);
				pos = pos * 2 + 2;
			}
		}
	}
	return 0;
}

int get(int &value)
{
	value = tree[0];
	return 0;
}
}

