#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include"TDatValue.h"
#include"TTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
#include"ExtraFunctions.h"
using namespace std;


void ShowCommands(void) {
	cout << " List of commands:" << endl;
	cout << endl;
	cout << "    " << " help" << " - print the list of commands on console" << endl;
	cout << endl;
	cout << "    " << " read [name of file]" << " - download Table from file" << endl;
	cout << "    " << " write [name of file]" << " - save Table in file" << endl;
	cout << "    " << " print [*]" << " - print Table on concsole (all rows / current row)" << endl;
	cout << endl;
	cout << "    " << " insert" << " - insert record into Table" << endl;
	cout << "    " << " delete" << " - delete record from Table" << endl;
	cout << "    " << " find" << " - find record in Table" << endl;
	cout << endl;
	cout << "    " << " info" << " - show info about Table" << endl;
	cout << "    " << " quit" << " - close the app" << endl;
}


int main() {
	bool continue_working = true;
	string input_of_commandline = ""; // сюда будем запоминать пользовательский ввод команд
	string* mas = new string[3]; // сюда будем записывать пользовательский ввод в формате: команда, аргумент,аргумент
	TTable* Table;
	TKey Key = "";
	int pValue_count; // этим полем определяется количество столбцов значений таблицы
	string* columnname;
	string* values;

	// запрос информации о количестве столбцов и их названиях
	cout << endl;
	cout << " How many colums you want in the Table: ";
	cin >> pValue_count; // этим полем определяется количество столбцов значений таблицы
	columnname = new string[pValue_count];
	cout << " Enter the names of columns: ";
	getline(cin, input_of_commandline);
	getline(cin, input_of_commandline);
	/*for (int i = 0; i < pValue_count; i++) {

	}*/
	Sep(input_of_commandline, columnname, pValue_count);
	Table = new TSortTable(50, pValue_count, columnname); // этой строкой определяется используеммый тип таблицы


	cout << endl;
	cout << " 'help' for information about command . . . ";

	while (continue_working) {

		cout << endl << endl;
		cout << " Your command: ";
		getline(cin, input_of_commandline);
		Sep(input_of_commandline, mas, 3);

		if (mas[0] == "help") {
			ShowCommands();
		}

		else if (mas[0] == "read") {
			if (mas[1] != "") {
				Table->Read(mas[1]);
			}
			else {
				cout << " Missing Filename . . . ";
				cout << endl;
			}
		}

		else if (mas[0] == "write") {
			if (mas[1] != "") {
				Table->Write(mas[1]);
			}
			else {
				cout << " Missing Filename . . . ";
				cout << endl;
			}
		}

		else if (mas[0] == "print") {
			if (mas[1] == "*") {
				Table->Print();
			}
			else {
				cout << " Wrong argument . . . ";
				cout << endl;
			}
		}

		else if (mas[0] == "insert") {
			int kolvo = 0;
			int success_kolvo = 0;
			int finish_code = 0;

			cout << " How many values you want to add: ";
			cin >> kolvo;
			cout << endl;

			for (int i = 0; i < kolvo; i++) {
				cout << " Key: ";
				cin >> Key;
				cout << " Arguments: ";
				getline(cin, input_of_commandline);
				getline(cin, input_of_commandline);

				values = new string[Table->GetColumnCount()];
				Sep(input_of_commandline, values, Table->GetColumnCount());
				Table->InsRecord(Key, new TWord(values, Table->GetColumnCount()));

				finish_code = Table->GetRetCode();
				if (finish_code == 0) // OK
					success_kolvo++;
				else if (finish_code == 3) { // SUCH_RECORD_ALREADY_EXISTS
					cout << " Error: SUCH_RECORD_ALREADY_EXISTS" << endl;
				}
				else if (finish_code == 3) { // NOT_ENOUGH_MEMORY
					cout << " Error: NOT_ENOUGH_MEMORY" << endl;
				}
				cout << endl;
			}
			cout << " INSERT " << kolvo - success_kolvo << " " << success_kolvo;
			cout << endl;
		}

		else if (mas[0] == "delete") {
			TKey key_copy = "";
			int kolvo = 0;
			int success_kolvo = 0;
			int finish_code = 0;

			cout << " How many values you want to delete: ";
			cin >> kolvo;
			cout << endl;

			for (int i = 0; i < kolvo; i++) {
				cout << " Key: ";
				cin >> key_copy;

				Table->DelRecord(key_copy);

				finish_code = Table->GetRetCode();
				if (finish_code == 0) // OK
					success_kolvo++;
				else if (finish_code == 2) { // NO_SUCH_RECORD
					cout << " Error: NO_SUCH_RECORD " << endl;
				}
				cout << endl;
			}
			cout << " DELETE " << kolvo - success_kolvo << " " << success_kolvo;
			cout << endl;
		}

		else if (mas[0] == "find") {
			int finish_code = 0;
			TDatValue* ret = nullptr;
			TKey key_copy = "";

			cout << " Key: ";
			cin >> key_copy;

			ret = Table->FindRecord(key_copy);

			finish_code = Table->GetRetCode();
			if (finish_code == 0) { // OK
				cout << endl;
				Table->PrintHead();
				cout << ret->ToStr();
				cout << endl << endl;
				cout << " FIND 0 1";
				cout << endl;
			}
			else if (finish_code == 2) { // NO_SUCH_RECORD
				cout << " FIND 1 0";
				cout << endl;
			}
		}

		else if (mas[0] == "info") {
			cout << " RetCode: "; // код завершения операции
			cout << Table->GetRetCode() << endl;
			cout << " DataCount: "; // количество записей в таблице
			cout << Table->GetDataCount() << endl;
			cout << " ColumnCount: ";// количество колонок таблицы
			cout << Table->GetColumnCount() << endl;
			cout << " Efficiency: "; // показатель эффективности выполнения операции
			cout << Table->GetEfficiency() << endl;
		}

		else if (mas[0] == "quit") {
			//system("cls");
			cout << " Goodbye . . . ";
			cout << endl << endl;
			continue_working = false;
		}

		else {
			cout << " Unnknown command . . . ";
			cout << endl;
		}

	}
}