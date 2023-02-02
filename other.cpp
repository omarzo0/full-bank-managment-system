#include<iostream>
#include<conio.h>
#include<cstdlib>
#include <algorithm>
#include <Windows.h>
#include <stdio.h>

using namespace std;
char ans;
int ph, idno, c1 = 0, c2 = 0, atmpin[4];
struct node {
	int no = 0, dd = 0, mm = 0, yyyy = 0, bal = 0, pin[4], status = 0;
	long long mobile = 0, id = 0;
	char name[50];
	int r1[4], r2[4], r3[4], r4[4];
	string city;
	node* pre;
	node* next;
	node()
	{
		pre = 0;
		next = 0;
	}
} *start;
class Bank {
public:
	void createacc();
	void deposit();
	void wdraw();
	void display();
	void delacc();
	void search();
	void transfer();
	void update();
	void recover();
	void intro();
	Bank() {
		start = NULL;
	}
};
//////////////////////////////////////////BANK SERVICES FUNCTIONS///////////////////////////////////////////////
void Bank::createacc() {
	int atmpin[4], ran1[4], ran2[4], ran3[4], ran4[4];
	char c;
	node* temp = new node();
	cout << "\t\t\t ACCOUNT NUMBER : ";
	cin >> temp->no;
	cout << "\t\t\t ACCOUNT HOLDER NAME : ";
	cin.ignore();
	cin.getline(temp->name, 50);
	cout << "\t\t\t DATE OF BITH [dd/mm/yyyy] : ";
	cin >> temp->dd >> c >> temp->mm >> c >> temp->yyyy;
	cout << "\t\t\t 14-DIGIT NATIONAL NUMBER : ";
	cin >> temp->id;
	cout << "\t\t\t COUNTRY : ";
	cin >> temp->city;
	cout << "\t\t\t PHONE NUMBER [+20] : ";
	cin >> temp->mobile;
	cout << "\t\t\t OPENING BALANCE : EG ";
	cin >> temp->bal;
	cout << "\t\t\t YOUR DEBIT CARD NUMBERS IS : ";
	srand((int)time(0));
	for (int i = 0; i < 4; i++) {
		ran1[i] = (rand() % 9) + 1;
		ran2[i] = (rand() % 9) + 1; /////for issue debit card number////
		ran3[i] = (rand() % 9) + 1;
		ran4[i] = (rand() % 9) + 1;
		cout << ran1[i] << ran2[i] << ran3[i] << ran4[i] << " ";
	}
	cout << "\n\t\t\t SET 4-DIGIT ATM CARD PIN : ";
	for (int i = 0; i < 4; i++)
	{
		atmpin[i] = _getch();
		printf("*");
		atmpin[i] = (atmpin[i] - 49) + 1; //////for print staric instead of numbers/////
		temp->pin[i] = atmpin[i];
	}
	temp->status = 1;
	for (int i = 0; i < 4; i++) {
		temp->r1[i] = ran1[i];
		temp->r2[i] = ran2[i];
		temp->r3[i] = ran3[i];
		temp->r4[i] = ran4[i];
	}
	temp->next = NULL;
	if (start == NULL) {
		temp->pre = NULL;
		start = temp;
	}
	else
	{
		node* temp2 = new node();
		temp2 = start;
		while (temp2->next != NULL) {
			temp2 = temp2->next;
		}
		temp2->next = temp;
		temp->pre = temp2;
	}
	cout << "\n\n\t\t\t Bank Account Successfully Added !!!! \n";
	cout << "\n\n\t\t\t\t press enter to continue ";
	cin.ignore();
	cin.get();
}
void Bank::deposit() {
	node* temp = new node;
	int acc, amount, check = 0;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t ENTER ACCOUNT NUMBER : ";
	cin >> acc;
	temp = start;
	while (temp != NULL) { /////loop to search depositor acc no/////
		if (temp->no == acc) {
			cout << "\n\t\t\t ACCOUNT DETAILS\n";
			cout << "\t\t\t *******************************\n";
			cout << "\t\t\t ACCOUNT HOLDER : " << temp->name << "\n";
			cout << "\t\t\t ACCOUNT NO : " << temp->no << "\n";
			cout << "\t\t\t DEBIT CARD NO : ";
			for (int i = 0; i < 4; i++) {
				cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
			} cout << "\n";
			cout << "\t\t\t ACCOUNT BALANCE : EG " << temp->bal << "\n";
			cout << "\t\t\t *******************************\n\n";
			cout << "\t\t\t ENTER AMOUNT TO DEPOSIT : EG ";
			cin >> amount;
			cout << "\n\t\t\t PREVIOUS BALANCE : EG " << temp->bal;
			temp->bal = temp->bal + amount;
			cout << "\n\t\t\t NEW BALANCE : EG " << temp->bal;
			check = 1;
			cout << "\n\n\t\t\t\t press enter to continue ";
			cin.ignore();
			cin.get();
			return;
		}
		temp = temp->next;
	}
	if (check == 0) {
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}
}
void Bank::wdraw() {
	node* temp = new node;
	int acc, wamount, check = 0;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t ENTER ACCOUNT NUMBER : ";
	cin >> acc;
	temp = start;
	while (temp != NULL) { ////loop to search user acc no for withdrawl/////
		if (temp->no == acc) {
			cout << "\n\t\t\t ACCOUNT DETAILS\n";
			cout << "\t\t\t *******************************\n";
			cout << "\t\t\t ACCOUNT HOLDER : " << temp->name << "\n";
			cout << "\t\t\t ACCOUNT NO : " << temp->no << "\n";
			cout << "\t\t\t DEBIT CARD NO : ";
			for (int i = 0; i < 4; i++) { //////for print staric instead of numbers/////
				cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
			} cout << "\n";
			cout << "\t\t\t ACCOUNT BALANCE : EG " << temp->bal << "\n";
			cout << "\t\t\t *******************************\n\n";
			while (check != 1) { ////loop to check amount till it is not correct/////
				cout << "\t\t\t ENTER AMOUNT TO WITHDRAW : EG ";
				cin >> wamount;
				if (wamount <= temp->bal) {
					cout << "\n\t\t\t PREVIOUS BALANCE : EG " << temp->bal;
					temp->bal = temp->bal - wamount;
					cout << "\n\t\t\t NEW BALANCE : EG " << temp->bal;
					check = 1;
					cout << "\n\n\t\t\t\t press enter to continue ";
					cin.ignore();
					cin.get();
				}
				else {
					cout << "\a\n\t\t\t NOT SUFFICIENT AMOUNT IN YOUR ACCOUNT !!!! \n";
				}
			}
		}
		temp = temp->next;
	}
	if (check == 0) {
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}
}
void Bank::search() {
	node* temp = new node;
	int acc, check = 0;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t ENTER ACCOUNT NUMBER : ";
	cin >> acc;
	temp = start;
	while (temp != NULL) {
		if (temp->no == acc) {
			cout << "\n\t\t\t ACCOUNT DETAILS\n";
			cout << "\t\t\t *******************************\n";
			cout << "\t\t\t ACCOUNT HOLDER : " << temp->name << "\n";
			cout << "\t\t\t ACCOUNT NO : " << temp->no << "\n";
			cout << "\t\t\t DATE OF BIRTH : " << temp->dd << "/" << temp->mm << "/" << temp->yyyy << "\n";
			cout << "\t\t\t COUNTRY : " << temp->city << "\n";
			cout << "\t\t\t NATIONAL ID : " << temp->id << "\n";
			cout << "\t\t\t CONTACT NO : (+20) " << temp->mobile << "\n";
			cout << "\t\t\t DEBIT CARD NO : ";
			for (int i = 0; i < 4; i++) {
				cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
			} cout << "\n";
			cout << "\t\t\t ACCOUNT BALANCE : EG " << temp->bal << "\n";
			cout << "\t\t\t *******************************\n\n";
			check = 1;
			cout << "\n\n\t\t\t\t press enter to continue ";
			cin.ignore();
			cin.get();
			return;
		}
		temp = temp->next;
	}
	if (check == 0) {
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}

}
void Bank::delacc() {
	int accno;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}

	cout << "\n\t\t\t ENTER ACCOUNT NO TO CLOSE THAT ACCOUNT : ";
	cin >> accno;
	if (start->no == accno)
	{
		node* delptr = start;
		start = start->next;
		cout << "\n\t\t\t ACCOUNT " << accno << " SUCCESSFULLY CLOSED !!!! \n";
		delete delptr;
		return;
	}
	else {

		node* prev = NULL;
		node* delptr = start;
		while (delptr->pre != NULL)
		{
			prev = delptr;
			delptr = delptr->next;
			cout << "\n\t\t\t ACCOUNT " << start->no << " SUCCESSFULLY CLOSED !!!! \n";
			prev->next = delptr->next;
			delete delptr;

		}
	}

	cout << "\n\n\t\t\t\t press enter to continue ";
	cin.ignore();
	cin.get();
	/*temp2 = temp2->next;
}
if (temp2->next->no == accno)
{
	temp = temp2->next;
	delete(temp);
	temp2->next = NULL;
	cout << "\n\t\t\t ACCOUNT " << start->no << " SUCCESSFULLY CLOSED !!!! \n";
	return;
}
else {
	cout << "\a\n\t\t\t No Account Found !!!! \n";
}*/
}
void Bank::transfer() {
	node* temp = new node;
	int amount, reciever, depositor, check = 0;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t AMOUNT TRANSFER FROM [ACCOUNT NO] : ";
	cin >> depositor;
	cout << "\t\t\t AMOUNT TRANSFER TO [ACCOUNT NO] : ";
	cin >> reciever;
	cout << "\t\t\t ENTER AMOUNT TO TRANSFER : Rs ";
	cin >> amount;
	temp = start;
	while (temp != NULL) { /////loop to search depositor//////
		if (temp->no == depositor) {
			if (amount <= temp->bal) {
				check = 1;
			}
			else {
				check = -1;
			}
		}
		temp = temp->next;
	}
	temp = start;
	while (temp != NULL) { ////loop to search reciever/////
		if (temp->no == reciever) {
			if (check == 1) {
				temp->bal = temp->bal + amount;
				check = 2;
			}
		}
		temp = temp->next;
	}
	temp = start; ////after adding amount to reciever,, cut amount from depositor's account////
	while (temp != NULL) {
		if (temp->no == depositor) {
			if (check == 2) {
				temp->bal = temp->bal - amount;
				cout << "\n\t\t\t TRANSACTION SUCCESSFULL !!!! \n";
				cout << "\n\n\t\t\t\t press enter to continue ";
				cin.ignore();
				cin.get();
				check = 3;
			}
		}
		temp = temp->next;
	}
	if (check != 3) {
		cout << "\a\n\t\t\t TRANSACTION NOT SUCCESSFULL !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}
	if (check == -1) {
		cout << "\n\t\t\t DEPOSITOR HASN'T SUFFICIENT AMOUNT !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}
}
void Bank::update() {
	node* temp = new node;
	int acc, atmpin[4], check = 0, ans;
	char in, c;
	string name;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t ENTER ACCOUNT NUMBER : ";
	cin >> acc;
	temp = start;
	while (temp != NULL) {
		if (temp->no == acc) {
			in = 'y';
			while (in == 'y' || in == 'Y') {
				system("cls");
				cout << "\t\t\t\t\t\t\t*UPDATE*\n\n";
				cout << "\n\t\t\t ACCOUNT DETAILS\n";
				cout << "\t\t\t *******************************\n";
				cout << "\t\t\t 1. ACCOUNT HOLDER : " << temp->name << "\n";
				cout << "\t\t\t 2. ACCOUNT NO : " << temp->no << "\n";
				cout << "\t\t\t 3. DATE OF BIRTH : " << temp->dd << "/" << temp->mm << "/" << temp->yyyy <<
					"\n";
				cout << "\t\t\t 4. COUNTRY : " << temp->city << "\n";
				cout << "\t\t\t 5. NATIONAL ID : " << temp->id << "\n";
				cout << "\t\t\t 6. CONTACT NO : (+20) " << temp->mobile << "\n";
				cout << "\t\t\t 7. ACCOUNT BALANCE : EG " << temp->bal << "\n";
				cout << "\t\t\t 8. DEBIT CARD NO : ";
				for (int i = 0; i < 4; i++) {
					cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
				} cout << "\n";
				cout << "\t\t\t 9. ATM CARD PIN : ";
				for (int j = 0; j < 4; j++) {
					cout << temp->pin[j];
				}
				cout << "\n\t\t\t *******************************\n\n";
				check = 1;
				cout << "\n\t\t\t WHICH DETAIL DO YOU WANT TO UPDATE [1-9] ? : ";
				cin >> ans;
				switch (ans) {
				case 1:
					cout << "\n\t\t\t ENTER NEW NAME : ";
					cin.ignore();
					cin.getline(temp->name, 50);;
					cout << "\n\t\t\t UPDATED SUCCESFULLY !!!! \n";
					break;
				case 2:
					cout << "\a\n\t\t\t SORRY YOU CAN'T UPDATE THIS INFO !!!! \n ";
					break;
				case 3:
					cout << "\n\t\t\t ENTER DOB [dd/mm/yyyy] : ";
					cin >> temp->dd >> c >> temp->mm >> c >> temp->yyyy;
					break;
				case 4:
					cout << "\n\t\t\t ENTER CITY NAME : ";
					cin >> temp->city;
					cout << "\n\t\t\t UPDATED SUCCESFULLY !!!! \n";
					break;
				case 5:
					cout << "\n\t\t\t ENTER NEW CNIC NUMBER : ";
					cin >> temp->id;
					cout << "\n\t\t\t UPDATED SUCCESFULLY !!!! \n";
					break;
				case 6:
					cout << "\n\t\t\t ENTER NEW CONTACT NUMBER [+92] : ";
					cin >> temp->mobile;
					cout << "\n\t\t\t UPDATED SUCCESFULLY !!!! \n";
					break;
				case 7:
					cout << "\a\n\t\t\t PLEASE DEPOSIT THE AMOUNT TO OFFICER !!!! \n ";
					break;
				case 8:
					cout << "\a\n\t\t\t SORRY YOU CAN'T UPDATE THIS INFO !!!! \n ";
					break;
				case 9:
					cout << "\n\t\t\t ENTER NEW PIN : ";
					for (int i = 0; i < 4; i++) {
						atmpin[i] = _getch();
						printf("*");
						atmpin[i] = (atmpin[i] - 49) + 1;
						temp->pin[i] = atmpin[i];
					}
					cout << "\n\t\t\t UPDATED SUCCESFULLY !!!! \n";
					break;
				default: cout << "\a\n\t\t\t WRONG INPUT !!!! \n";
				}
				cout << "\n\t\t\t DO YOU WANT TO UPDATE ANOTHER INFO (y/n) ? ";
				cin >> in;
			}
		}
		temp = temp->next;
	}
	if (check == 0) {
		cout << "\a\n\t\t\t No Account Found !!!! \n";
	}
}
void Bank::recover() {
	int accno, atmpin[4], check = 0;
	node* temp = new node;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\t\t\t ENTER ACCOUNT NUMBER : "; cin >> accno;
	temp = start;
	while (temp != NULL) {
		if (temp->no == accno) {
			check = 1;
			cout << "\n\t\t\t ACCOUNT DETAILS\n";
			cout << "\t\t\t *******************************\n";
			cout << "\t\t\t 1. ACCOUNT HOLDER : " << temp->name << "\n";
			cout << "\t\t\t 2. ACCOUNT NO : " << temp->no << "\n";
			cout << "\t\t\t 3. ACCOUNT BALANCE : EG " << temp->bal << "\n";
			cout << "\t\t\t 4. DEBIT CARD NO : ";
			for (int i = 0; i < 4; i++) {
				cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
			} cout << "\n";
			cout << "\t\t\t 5. ATM SERVICES : ";
			if (temp->status == 1) {
				cout << "ACTIVE\n";
			}
			if (temp->status == 0) {
				check = 2;
				cout << "TEMPORARY BLOCKED\n";
				cout << "\n\t\t\t ENTER NEW PIN TO UNBLOCK YOUR ATM SERVICES : ";
				for (int i = 0; i < 4; i++) {
					atmpin[i] = _getch();
					printf("*");
					atmpin[i] = (atmpin[i] - 49) + 1;
					temp->pin[i] = atmpin[i];
				}
				temp->status = 1;
				cout << "\n\t\t\t YOUR ATM SERVICES SUCCESSFULLY UNBLOCKED...!!! ";
			}
		} temp = temp->next;
	}
	if (check == 0) {
		cout << "\a\n\t\t\t No Account Found !!!! \n";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
	}
	if (check != 2 && check == 1) {
		cout << "\n\a\n\t\t\t ATM SERVICES ARE ALREADY ACTIVE ...!!!! \n ";
	}
}
void Bank::display() {
	struct node* temp;
	if (start == NULL)
	{
		cout << "\a\n\t\t\t No Account Found !!!!";
		cout << "\n\n\t\t\t\t press enter to continue ";
		cin.ignore();
		cin.get();
		return;
	}
	temp = start;
	cout << "\t\t\t Bank Accounts Are \n\n";
	while (temp != NULL)
	{
		cout << "\t\t\t ***********************************\n";
		cout << "\t\t\t ACCOUNT HOLDER : " << temp->name << "\n";
		cout << "\t\t\t ACCOUNT NO : " << temp->no << "\n";
		cout << "\t\t\t NATIONAL ID : " << temp->id << "\n";
		cout << "\t\t\t CONTACT NO : (+20) " << temp->mobile << "\n";
		cout << "\t\t\t DEBIT CARD NO : ";
		for (int i = 0; i < 4; i++) {
			cout << temp->r1[i] << temp->r2[i] << temp->r3[i] << temp->r4[i] << " ";
		} cout << "\n";
		cout << "\t\t\t ACCOUNT BALANCE : EG " << temp->bal << "\n";
		cout << "\t\t\t ***********************************\n\n";
		temp = temp->next;
	}
	cout << "\n\n\t\t\t\t press enter to continue ";
	cin.ignore();
	cin.get();

}
void Bank::intro()
{
	cout << " \n\t\t\t\t\t ";
	cout << "\n\t\t\t\t\t Bank Managment System";
	cout << " \n\t\t\t\t\t ";
	cout << "\n\n\n\n\n MADE BY :\n 1.Omar Khaled \n 2.Mohamed Yasser\n 3.Ali Khaled Habash\n 4.Marco Makram\n 5.Marwan Hany\n 6.Yousef Fawzy\n";
	cout << "\n Galala university";
	cout << "\n\n\n\n\n\n\t\t\t\t\t Press enter to continue";
	cin.get();
}
//////////////////////////////////////////ATM CLASS///////////////////////////////////////////////
class atm {
private:
	int accno, clear;
public:
	void enter() {
		system("Cls");
		int check = 0;
		int atmpin[4];
		node* temp = new node();
		if (start == NULL)
		{
			cout << "\a\n\t\t\t No Account Found !!!!";
			return;
		}
		cout << "\n\n\t\t\t\t ENTER ACCOUNT NUMBER : ";
		cin >> accno;
		temp = start;
		while (temp != NULL) {
			if (temp->no == accno) {
				check = 1;
				if (temp->status == 1) {
					check = 2;
					int x = 0;
					while (x != 3) {
						temp = start;
						cout << "\t\t\t\t ENTER PIN : ";
						for (int i = 0; i < 4; i++) {
							atmpin[i] = _getch();
							printf("*");
							atmpin[i] = (atmpin[i] - 49) + 1;
							atmpin[i];
						} check = 3;
						while (temp != NULL) {
							if (temp->no == accno) {
								if (temp->pin[0] == atmpin[0] && temp->pin[1] == atmpin[1] &&
									temp->pin[2] == atmpin[2] && temp->pin[3] == atmpin[3]
									&& temp->no == accno) {
									clear = 1;
									cout << "\n\n\t\t\t PRESS ENTER TO CONTINUE.... ";
									cin.ignore();
									cin.get();
									return;
								}
								if (check == 3 && clear == 0) {
									cout << "\n\a\t\t\t\t INCORRECT PIN ...!!!\n";
								}
							}temp = temp->next;
						} x++;
						if (x == 3) {
							temp = start;
							while (temp != NULL) {
								if (temp->no == accno) {
									temp->status = 0;
									cout << "\n\a\t\t\t\t YOUR CARD HAS BEEN CAPTURED...!!!\n";
									cout << "\t\t\t\t CONTACT TO YOUR BRANCH...!!!\n";
									return;
								}
							}
						}
					}
				}
			}temp = temp->next;
		}
		if (check == 1 && check != 2) {
			cout << "\n\a\t\t\t\t YOUR SERVICES ARE TEMPORARY BLOCKED...!!!\n";
			cout << "\t\t\t\t CONTACT TO YOUR BRANCH...!!!\n";
		}
		if (check == 0) {
			cout << "\a\n\t\t\t No Account Found !!!!";
			cout << "\n\n\t\t\t\t press enter to continue ";
			cin.ignore();
			cin.get();
		}
	}
	void cdepo() {
		node* temp = new node;
		int amount;
		temp = start;
		while (temp != NULL) {
			if (temp->no == accno) {
				cout << "\t\t\tACCOUNT HOLDER : " << temp->name << "\n";
				cout << "\t\t\t\t\t\t PLEASE ENTER AMOUNT : EG "; cin >> amount;
				temp = start;
				temp->bal += amount;
				cout << "\t\t\t\t\t\t AMOUNT DEPOSITED...!!!\n";
				cout << "\t\t\t\t\t\t NEW BALANCE IS : EG " << temp->bal;
				cout << "\n\n\t\t\t\t press enter to continue ";
				cin.ignore();
				cin.get();

				return;
			}
			temp = temp->next;
		}
	}
	void enquiry() {
		node* temp = new node;
		temp = start;
		while (temp != NULL) {
			if (temp->no == accno) {
				cout << "\t\t\tACCOUNT HOLDER : " << temp->name << "\n";
				cout << "\t\t\t\t\t\t ACCOUNT NO : " << temp->no;
				cout << "\n\t\t\t\t\t\t YOUR AVAILABLE BALANCE IS : EG " << temp->bal;
				cout << "\n\n\t\t\t\t press enter to continue ";
				cin.ignore();
				cin.get();

				return;
			}
			temp = temp->next;
		}
	}
	void cashwith() {
		node* temp = new node;
		temp = start;
		int amount;
		while (temp != NULL) {
			if (temp->no == accno) {
				cout << "\t\t\tACCOUNT HOLDER : " << temp->name << "\n";
				cout << "\t\t\t\t\t\t YOUR AVAILABLE BALANCE IS : EG " << temp->bal;
				cout << "\n\t\t\t\t\t\t PLEASE ENTER AMOUNT TO WITHDRAWl : EG "; cin >> amount;
				if (temp->bal >= amount) {
					temp->bal -= amount;
					cout << "\n\t\t\t\t\t\t PLEASE RECIEVE YOUR CASH ....\n";
					cout << "\n\n\t\t\t\t press enter to continue ";
					cin.ignore();
					cin.get();

				}
				else {
					cout << "\a\n\t\t\t\t\t\t NOT SUFFICIENT AMOUNT ....\n";
					cout << "\n\n\t\t\t\t press enter to continue ";
					cin.ignore();
					cin.get();

				}
				return;
			}
			temp = temp->next;
		}
	}
	void pinchange() {
		node* temp = new node;
		int atmpin1[4], atmpin2[4], check = 0;
		temp = start;
		while (temp != NULL) {
			if (temp->no == accno) {
				cout << "\t\t\tACCOUNT HOLDER : " << temp->name << "\n";
				do {
					cout << "\n\t\t\t\t\t\t ENTER NEW PIN : ";
					for (int i = 0; i < 4; i++) {
						atmpin1[i] = _getch();
						printf("*");
						atmpin1[i] = (atmpin1[i] - 49) + 1;
						atmpin1[i];
					}
					cout << "\n\n\t\t\t\t\t\t CONFIRM NEW PIN : ";
					for (int j = 0; j < 4; j++) {
						atmpin2[j] = _getch();
						printf("*");
						atmpin2[j] = (atmpin2[j] - 49) + 1;
						atmpin2[j];
					}
					if (atmpin1[0] == atmpin2[0] && atmpin1[1] == atmpin2[1] &&
						atmpin1[2] == atmpin2[2] && atmpin1[3] == atmpin2[3]) {
						cout << "\n\t\t\t\t\t\t PIN UPDATED SUCCESSFULLY....!!!!\n";
						temp->pin[0] = atmpin1[0]; temp->pin[1] = atmpin1[1];
						temp->pin[2] = atmpin1[2]; temp->pin[3] = atmpin1[3];
						check = 1;
						cout << "\n\n\t\t\t\t press enter to continue ";
						cin.ignore();
						cin.get();

						return;
					}
					else {
						cout << "\a\n\n\t\t\t\t\t\t PIN NOT MATCHED....!!!! \n";
						cout << "\n\n\t\t\t\t press enter to continue ";
						cin.ignore();
						cin.get();

					}
				} while (check != 1);
			}
			temp = temp->next;
		}
	}
	void function() {
		int c;
		node* temp = new node();
		enter();
		if (clear == 1) {
			clear = 0;
			do {
				system("Cls");
				cout << "\t\t\t *ATM*\n\n";
				cout << "\t\t\t [1] CASH DEPOSIT [2] CASH WITHDRAWL \n";
				cout << "\t\t\t [3] PIN CHANGE [4] BALANCE ENQUIRY \n";
				cout << "\t\t\t [5] EXIT\n";
				cout << "\t\t\t MAKE DECISION 1-5 ";
				cout << "\n\t\t\t\t\t"; cin >> c;
				switch (c) {
				case 1:
					system("Cls");
					atm::cdepo();
					break;
				case 2:
					system("Cls");
					atm::cashwith();
					break;
				case 3:
					system("Cls");
					atm::pinchange();
					break;
				case 4:
					system("Cls");
					atm::enquiry();
					break;
				case 5:
					if (c == 5)
					{
						cout << "\n\n\n\n\n\n\t\t\t\t THANK YOU FOR CHOOSING NATIONAL BANK ATM SERVICE ...... \n\n\n\n\n\n ";
						Sleep(3000);
						system("cls");
						break;
					}

				default: cout << "\a\n\t\t\t WRONG INPUT !!!! \n";
				}

			} while (c != 5);
		}
	}
};
/////////////////////////////////////////MAIN FUCTION////////////////////////////////////////////
int main() {
	system("Color E0");
	int c1, c2;
	Bank b;
	b.intro();
	atm a;
	system("Cls");
	do {
		cout << "\t\t\t\t 1. BANK SERVICE    \n\t\t\t\t 2. ATM SERVICE \n\n";
		cout << "\t\t\t\t MAKE DECISIONE > ";
		cin >> c1;
		if (c1 != 1 && c1 != 2)
		{
			cout << "\n\t\t\t\t ERROR 404 \n\t\t\t\t please choose 1 or 2 \n\n";
			cout << "\n\n\t\t\t\t press enter to continue ";
			cin.ignore();
			cin.get();
			system("cls");

		}
		switch (c1) {
		case 1:
			do {
				system("Cls");
				cout << "\t\t\t *BANK MANAGMENT SYSTEM*\n\n";
				cout << "\t\t\t [1] CREATE NEW ACCOUNT \t[2] CLOSE AN ACCOUNT \n";
				cout << "\t\t\t [3] DEPOSIT            \t[4] withdraw\n";
				cout << "\t\t\t [5] SEARCH             \t[6] TRANSFER \n";
				cout << "\t\t\t [7] DISPLAY            \t[8] UPDATE\n";
				cout << "\t\t\t [9] EXIT\n\n";
				cout << "\t\t\t MAKE DECISION 1-9 ";
				cin >> c2;
				switch (c2)
				{
				case 1:
					system("Cls");
					cout << "\t\t\t\t\t  *****CREATE AN ACCOUNT*****\n\n";
					b.createacc();
					break;
				case 2:
					system("Cls");
					cout << "\t\t\t\t\t\t *DELETE AN ACCOUNT*\n\n";
					b.delacc();
					break;
				case 3:
					system("Cls");
					cout << "\t\t\t\t\t\t\t*DEPOSIT*\n\n";
					b.deposit();
					break;
				case 4:
					system("Cls");
					cout << "\t\t\t\t\t\t\t*WITHDRAW*\n\n";
					b.wdraw();
					break;
				case 5:
					system("Cls");
					cout << "\t\t\t\t\t\t *SEARCH AN ACCOUNT*\n\n";
					b.search();
					break;
				case 6:
					system("Cls");
					cout << "\t\t\t\t\t\t\t*MONEY TRANSFER*\n\n";
					b.transfer();
					break;
				case 7:
					system("Cls");
					cout << "\t\t\t\t\t\t\t*DISPLAY*\n\n";
					b.display();
					break;
				case 8:
					system("Cls");
					cout << "\t\t\t\t\t\t\t*UPDATE THE ACCOUNT*\n\n";
					b.update();
					break;
				case 9:
					if (c2 == 9)
					{
						cout << "\n\n\n\n\n\n\t\t\t\t  THANK YOU FOR CHOOSING NATIONAL BANK...... \n\n\n\n\n\n ";
						Sleep(3000);
						system("cls");
						break;
					}
					cin.ignore();
					cin.get();
				default: cout << "\n\n\t\t\t PRESS ENTER ANY KEY TO RETURN TO MAIN MENU.... ";
				}

			} while (c2 != 9);
			break;
		case 2:
			a.function();
			cin.ignore();
			cin.get();
			break;
		}
	} while (c1 != 3);
	system("Cls");
	cout << "\n\n\n\n\n\n\t\t\t\t\t THANK YOU FOR CHOOSING NATIONAL BANK...... \n\n\n\n\n\n ";
}