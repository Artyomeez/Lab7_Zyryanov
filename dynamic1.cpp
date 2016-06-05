// dynamic1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
using namespace std;
typedef struct my_list {
	int data;
	struct my_list* next;
} MList;
MList *head=0;

extern "C"
{
	int add(MList* &phead, int data)
	{
		MList *item = new MList;
		item->data = data;
		item->next = NULL;
		item->next = phead; phead = item; return 0;
	}
	//	Функция удаления последнего элемента в очереди
	int del(MList* &phead)
	{
		if (phead == NULL) { phead = phead->next; return 0; }
		int i = 0;
		while (phead->next != NULL) {
			i++;
			phead = phead->next;
		}
		phead->next = NULL;
		return 0;
	}
	//	Функция получения последнего элемента в очереди
	int get(MList* &phead, int pdata)
	{
		MList* tmp = phead;
		int i = 0;
		while (tmp->next != NULL) {
			i++;
			tmp = tmp->next;
		}
		pdata = tmp->data;
		cout << "Element= " << pdata << endl;
		return 0;
	}
	//	Функция вывода списка
	int printlist(MList* &phead) {
		if (phead == NULL) cout << "Spisok pust ";
		else {
			cout << "Spisok: ";
			while (phead != NULL) {
				cout << phead->data << " ";
				phead = phead->next;
			}
			cout << endl;
		}
		return 0;
	}
}

