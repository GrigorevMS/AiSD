#include<iostream>
#include"TText.h"
#include"TTextLink.h"
#include<cstring>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

void Sep(string input, string* mas) {
	for (int i = 0; i < 3; i++) {
		mas[i] = "";
	}
	int high = 0;
	int pos = 0;
	string temp = "";
	while (pos < input.size() && high < 3) {
		temp = "";
		while (input[pos] != ' ' && pos < input.size()) {
			temp = temp + input[pos];
			pos += 1;
		}
		mas[high] = temp;
		high += 1;
		while (input[pos] == ' ' && pos < input.size()) {
			pos += 1;
		}
	}
}

void AskStringInput(string& temp) {
	cout << "Input string: ";
	getline(cin, temp);
}

void ShowCommands(void) {
	cout << "List of commands:" << endl;
	cout << endl;
	cout << "    " << "help" << " - print the list of commands on console" << endl;
	cout << endl;
	cout << "    " << "editor" << " - open or close editor window" << endl;
	cout << endl;
	cout << "    " << "setdir [0 / 1 / 2 / 3 / 4]" << " - choose TText object you want to work with" << endl;
	cout << "    " << "copy [0 / 1 / 2 / 3 / 4]" << " - copy TText from current directory to directory number" << endl;
	cout << "    " << "cut" << " - cut current subtree" << endl;
	cout << endl;
	cout << "    " << "read [name of file]" << " - download text from file"<< endl;
	cout << "    " << "write [name of file]" << " - save text in file" << endl;
	cout << "    " << "print [a / c / p]" << " - print text on concsole (all / current line / current part)" << endl << endl;
	cout << endl;
	cout << "    " << "gofirst" << " - go to the first link" << endl;
	cout << "    " << "godown" << " - go to the down link" << endl;
	cout << "    " << "gonext" << " - go to the next link" << endl;
	cout << "    " << "goprev" << " - go to the prev link" << endl;
	cout << "    " << "goup" << " - go to the up link" << endl;
	cout << endl;
	cout << "    " << "dellink" << " - delete current link" << endl;
	cout << endl;
	cout << "    " << "insnext [l / s]" << " - insert link / subtree next to the current one" << endl;
	cout << "    " << "insprev [l / s]" << " - insert link / subtree before the current one" << endl;
	cout << "    " << "insdown [l / s]" << " - insert link / subtree down after the current one" << endl;
	cout << "    " << "insup" << " - insert link above the current one" << endl;
	cout << endl;
	cout << "    " << "change [s]" << " - change current[Str]" << endl;
	cout << endl;
	cout << "    " << "cls" << " - clear the console" << endl;
	cout << "    " << "quit" << " - close the app" << endl;
}

int main() {
	TText text_list[5];
	TText* text = &text_list[0];
	int dir_number = 0;
	TTextLink* text_link = nullptr;
	TText* text_link_copy;
	bool continue_working = true;
	bool open_editor = false;
	string input_of_commandline = "";
	string* mas = new string[3]; // формат ввода: имя команды, аргумент, аргумент
	string AskInput = "";
	cout << endl;
	while (continue_working) {
		if (open_editor == true) {
			cout << "________________________________________________________________________________" << endl;
			cout << "  Directory number " << dir_number << endl;
			cout << "________________________________________________________________________________" << endl;
			text->Print();
			cout << "________________________________________________________________________________" << endl;
		}
		cout << endl;
		cout << "Your command: ";
		getline(cin, input_of_commandline);
		Sep(input_of_commandline, mas);
		if (mas[0] == "help") {
			ShowCommands();
			system("pause");
		}

		else if (mas[0] == "editor") {
			if (open_editor == true) {
				open_editor = false;
				system("cls");
			}
			else 
				open_editor = true;
		}

		else if (mas[0] == "setdir") {
			if (mas[1] == "0" || mas[1] == "") {
				text = &text_list[0];
				dir_number = 0;
			}
			else if (mas[1] == "1") {
				text = &text_list[1]; 
				dir_number = 1;
			}
			else if (mas[1] == "2") {
				text = &text_list[2]; 
				dir_number = 2;
			}
			else if (mas[1] == "3") {
				text = &text_list[3];
				dir_number = 3;
			}
			else if (mas[1] == "4") {
				text = &text_list[4];
				dir_number = 4;
			}
			else {
				cout << "Wrong number of directory. ";
				system("pause");
			}
		}
		else if (mas[0] == "copy") {
			if (mas[1] == "0") {
				text_list[0] = text->GetCopy();
			}
			else if (mas[1] == "1") {
				text_list[1] = text->GetCopy();
			}
			else if (mas[1] == "2") {
				text_list[2] = text->GetCopy();
			}
			else if (mas[1] == "3") {
				text_list[3] = text->GetCopy();
			}
			else if (mas[1] == "4") {
				text_list[4] = text->GetCopy();
			}
			else {
				cout << "Wrong directory number or missing. ";
				system("pause");
			}
		}
		else if (mas[0] == "cut") {
			text_link = text->GetLink();
		}

		else if (mas[0] == "read") {
			if (mas[1] != "") {
				text->Read(mas[1]);
			}
			else {
				cout << "Missing filename. ";
				system("pause");
			}
		}
		else if (mas[0] == "write") {
			if (mas[1] != "") {
				text->Write(mas[1]);
			}
			else {
				cout << "Missing filename. ";
				system("pause");
			}
		}
		else if (mas[0] == "print" && open_editor == false) {
			if (mas[1] == "a" || mas[1] == "") {
				text->Print();
			}
			else if (mas[1] == "c") {
				cout << text->GetLine();
			}
			else if (mas[1] == "p") {
				text->PrintText(text->GetpCurrent(), 0);
			}
			else {
				cout << "Unnknown command. ";
				system("pause");
			}
		}

		else if (mas[0] == "gofirst") {
			if (!text->GoFirstLink()) {
				cout << "Can't go first. ";
				system("pause");
			}
		}
		else if (mas[0] == "godown") {
			if (!text->GoDownLink()) {
				cout << "Can't go down. ";
				system("pause");
			}
		}
		else if (mas[0] == "gonext") {
			if (!text->GoNextLink()) {
				cout << "Can't go next. ";
				system("pause");
			}
		}
		else if (mas[0] == "goprev") {
			if (!text->GoPrevLink()) {
				cout << "Can't go previous. ";
				system("pause");
			}
		}
		else if (mas[0] == "goup") {
			if (!text->GoUpLink()) {
				cout << "Can't go up. ";
				system("pause");
			}
		}

		else if (mas[0] == "dellink") {
			text->DelLink();
		}

		else if (mas[0] == "insnext") {
			if (mas[1] == "l") {
				AskStringInput(AskInput);
				text->InsNextLnk(new TTextLink(AskInput));
			}
			else if (mas[1] == "s" && text_link!=nullptr) {
				text->InsNextLnk(text_link);
				text_link = nullptr;
			}
			else {
				cout << "Wrong option or missing. ";
				system("pause");
			}
		}
		else if (mas[0] == "insprev") {
			if (mas[1] == "l") {
				AskStringInput(AskInput);
				text->InsPrevLnk(new TTextLink(AskInput));
			}
			else if (mas[1] == "s" && text_link != nullptr) {
				text->InsPrevLnk(text_link);
				text_link = nullptr;
			}
			else {
				cout << "Wrong option or missing. ";
				system("pause");
			}
		}
		else if (mas[0] == "insdown") {
			if (mas[1] == "l") {
				AskStringInput(AskInput);
				text->InsDownLink(new TTextLink(AskInput));
			}
			else if (mas[1] == "s" && text_link != nullptr) {
				text->InsDownLink(text_link);
				text_link = nullptr;
			}
			else {
				cout << "Wrong option or missing. ";
				system("pause");
			}
		}
		else if (mas[0] == "insup") {
			AskStringInput(AskInput);
			text->InsUpLink(new TTextLink(AskInput));
		}

		else if (mas[0] == "change") {
			if (mas[1] == "s") {
				string temp = "";
				cout << "Input string: ";
				getline(cin, temp);
				text->SetLine(temp);
			}
			else {
				cout << "Unnknown command. ";
				system("pause");
			}
		}
		else if (mas[0] == "cls" && open_editor == false) {
			system("cls");
		}
		else if (mas[0] == "quit") {
			system("cls");
			cout << "Goodbye";
			continue_working = false;
			open_editor = false;
		}
		else {
			cout << "Unnknown command. ";
			system("pause");
		}
		cout << endl;
		if (open_editor == true) {
			system("cls");
		}
	}
}