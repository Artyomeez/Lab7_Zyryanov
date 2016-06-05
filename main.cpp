#include<stdio.h>
#include <dlfcn.h>
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include <string>
using namespace std;

#define SIZE 100

int tree[SIZE];
int endptr = 0;
typedef struct my_list {
	int data;
	struct my_list* next;
} MList;
MList *head = 0;

typedef int(*pFunc)();

int main(int argc, char *argv[])
{
	pFunc pfunc;  
	void *handle = dlopen(argv[1], RTLD_LAZY);     //�������� ���������� � ����������-������ ����������
	if (!handle) {   //���� ������ �������� ����������
		cout << "Error lib" << endl; return 1;
	}

	if (strstr(argv[1], "libdynamic1.so"))  //���� �������� - ������ ����������
	{
		
		string command;
		int data, size, ncommand;
		int pdata = 0;
		cin >> ncommand;
		for (int i = 0; i<ncommand; i++) {
			cin >> command;
			if (!command.compare(0, 3, "add")) {
				int  dat;
				cin >> dat;
				pfunc = (pFunc)dlsym(handle, "add");  //��������� ������� add �� ����������
				pfunc(head, dat); 		      //�������� ��� �������
			}
			if (!command.compare(0, 3, "del")) {
				pfunc = (pFunc)dlsym(handle, "del");   
				pfunc(head);
			}
			if (!command.compare(0, 3, "get")) {
				pfunc = (pFunc)dlsym(handle, "get"); 
				pfunc(head, pdata);
			}
		}
				pfunc = (pFunc)dlsym(handle, "printlist");
				pfunc(head);
	}
	if (strstr(argv[1], "libdynamic2.so"))  //���� �������� - ������ ����������
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string op;
			cin >> op;
			if (!op.compare("add")) {
				int value;
				cin >> value;
				pfunc = (pFunc)dlsym(handle, "add");
				pfunc(value);
				pfunc = (pFunc)dlsym(handle, "printtree");
				pfunc();
			}
			else if (!op.compare("del")) {
				pfunc = (pFunc)dlsym(handle, "del");
				pfunc();
				pfunc = (pFunc)dlsym(handle, "printtree");
				pfunc();
			}
			else if (!op.compare("get")) {
				int res;
				pfunc = (pFunc)dlsym(handle, "get");
				pfunc(res);
				cout << res << endl;
			}
		}
	}
	dlclose(handle);    //�������� ����������
	system("pause");
	return 0;
}