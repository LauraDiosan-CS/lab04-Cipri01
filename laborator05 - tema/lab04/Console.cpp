#include "Console.h"
#include <iostream>
using namespace std;

//Descr: main menu
//In: -
//Out: -
void Console::menu() {
	cout << "---MENU---" << endl;
	cout << "1 -> Adding an expense to the list..." << endl;
	cout << "2 -> Change the expenses in the list..." << endl;
	cout << "3 -> Determining the expenses with certain properties..." << endl;
	cout << "4 -> Obtaining properties of different sublists..." << endl;
	cout << "5 -> Filtering the list of expenses..." << endl;
	cout << "s -> Show all expenses..." << endl;
	cout << "x -> EXIT!..." << endl;
}

//Descr: menu for add
//In: -
//Out: -
void Console::menu_for_add() {
	cout << "1 -> Add an expense to the list.." << endl;
	//cout << "2 -> Insert an expense to the list..." << endl;
}

//Descr: menu for change operations
//In: -
//Out: -
void Console::menu_for_change() {
	cout << "1 -> Delete the expenses from a given day..." << endl;
	cout << "2 -> Delete the expenses from a given range [day_start, day_end]..." << endl;
	cout << "3 -> Delete the expenses of a certain type... " << endl;
}

//Descr: menu for detrmining properties
//In: -
//Out: -
void Console::menu_for_determining_properties() {
	cout << "1 -> Display of all expenses for the current month..." << endl;
	cout << "2 -> Display of all expenses of a certain type..." << endl;
	cout << "3 -> Display of all expenses of a certain type and condition ( > )..." << endl;
	cout << "4 -> Display of all expenses of a certain type and condition ( = )..." << endl;
}

//Descr: menu for obtaining properties
//In: -
//Out: -
void Console::menu_for_obtaining_properties() {
	cout << "1 -> Determining the sum of all expenses of a particular type..." << endl;
	cout << "2 -> Displaying the day with the highest expenses..." << endl;
	cout << "3 -> Displaying the amounts spent daily in descending order..." << endl;
	cout << "4 -> Displaying the amounts spent daily for a particular type in ascending order..." << endl;
}

//Descr: menu for filter operations
//In: -
//Out: -
void Console::menu_for_filter() {
	cout << "1 -> Filtering the expenses so that only the expenses of a certain type remain..." << endl;
	cout << "2 -> Filtering the expenses so that only the expenses of a certain type and those that respect a condition remain ( < )..." << endl;
	cout << "3 -> Filtering the expenses so that only the expenses of a certain type and those that respect a condition remain ( < )..." << endl;
}

//Descr: read option methods
//In: -
//Out: the option
char Console::read_option() {
	cout << "Give the option:  ";
	char option;
	cin >> option;
	return option;
}

//Descr: run function ( connect all the methods )
//In: -
//Out: connect all the methods
int Console::run() {
	while (true) {
		this->menu();
		char option = read_option();
		switch(option){
		case '1':
			this->run_for_add();
			break;
		case '2':
			this->run_for_change();
			break;
		case '3':
			this->run_for_display();
			break;
		case '4':
			this->run_for_properties();
			break;
		case '5':
			this->run_for_filter();
			break;
		case 's':
			this->handle_show_all();
			break;
		case 'x':
			return 0;
		default:
			break;
		}
	}
}

//Descr: run function for add
//In: -
//Out: -
void Console::run_for_add() {
	this->menu_for_add();
	char option = read_option();
	switch (option){
	case '1':
		this->handle_insert_expense();
		break;
	default:
		break;
	}
}

//Descr: handle method for add
//In: -
//Out: -
void Console::handle_insert_expense() {
	int day, amount;
	char* type;
	cout << "Give the day for expense:  ";
	day = read_int();
	cout << "Give the amount for expense:  ";
	amount = read_int();
	cout << "Give the type for expense:  ";
	type = read_char_pointer();
	this->service_for_expenses.addExpense(day, amount, type);

}

//Descr: read method for integer
//In: -
//Out: an integer
int Console::read_int() {
	int number;
	cin >> number;
	return number;
}

//Descr: read method for pointers
//In: -
//Out: a pointer
char* Console::read_char_pointer() {
	char ch[100];
	cin >> ch;
	char* ch_p = new char[strlen(ch) + 1];
	strcpy_s(ch_p, strlen(ch) + 1, ch);
	return ch_p;
}

//Descr: run function for change operations
//In: -
//Out: -
void Console::run_for_change() {
	this->menu_for_change();
	char option = read_option();
	switch (option){
	case '1':
		this->handle_delete_by_day();
		break;
	case '2':
		this->handle_delete_in_range();
		break;
	case '3':
		this->handle_delete_by_type();
	default:
		break;
	}
} 

//Descr: handle method for delete by day
//In: -
//Out: -
void Console::handle_delete_by_day() {
	cout << "Give the day for delete:  ";
	int day_for_delete = read_int();
	this->service_for_expenses.deleteExpenseByDay(day_for_delete);
}

//Descr: handle method for delete in range
//In: -
//Out: -
void Console::handle_delete_in_range() {
	cout << "Give first day:  ";
	int day1 = read_int();
	cout << "Give last day:  ";
	int day2 = read_int();
	this->service_for_expenses.deleteExpensesBetweenTwoDays(day1, day2);
}

//Descr:
//In:
//Out:
void Console::handle_delete_by_type() {
	cout << "Guve the type for delete:  ";
	char* type = read_char_pointer();
	this->service_for_expenses.deleteExpenseByType(type);
}

//Descr: run method for display 
//In: -
//Out: -
void Console::run_for_display() {
	this->menu_for_determining_properties();
	char option = read_option();
	switch (option){
	case '1':
		this->handle_show_all();
		break;
	case '2':
		this->handle_show_by_type();
		break;
	case '3':
		this->handle_show_by_type_and_condition_bigger();
		break;
	case '4':
		this->handle_show_by_type_and_condition_equal();
		break;
	default:
		break;
	}
}

//Descr: handle method for show all
//In: -
//Out: -
void Console::handle_show_all() {
	int length = this->service_for_expenses.getSizeRepo();
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < length; i++) {
		cout << this->service_for_expenses.getAll()[i];
	}
	cout << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

//Descr: handle method for show by type
//In: -
//Out: -
void Console::handle_show_by_type() {
	cout << "Type for display is:  ";
	char* type = read_char_pointer();
	Expense expense_for_display[100];
	int contor = 0;
	this->service_for_expenses.getExpenseByType(type, expense_for_display, contor);
	this->show_them(contor, expense_for_display);
}

//Descr: handle method for show an Expense list
//In: -
//Out: -
void Console::show_them(int length, Expense expenses[]) {
	for (int i = 0; i < length; i++) {
		cout << expenses[i] << endl;
	}
}

//Descr: handle method for show by type and condition bigger
//In: -
//Out: -
void Console::handle_show_by_type_and_condition_bigger() {
	cout << "Type for display is:  ";
	char* type = read_char_pointer();
	cout << "The value for condition is:  ";
	int value = read_int();
	Expense expense_for_display[100];
	int contor = 0;
	this->service_for_expenses.getExpenseByTypeAndConditionBigger(type, value, expense_for_display, contor);
	this->show_them(contor, expense_for_display);
}

//Descr: handlte method for show by tyoe and condition equal
//In: -
//Out: -
void Console::handle_show_by_type_and_condition_equal() {
	cout << "Type for display is:  ";
	char* type = read_char_pointer();
	cout << "The value for condition is:  ";
	int value = read_int();
	Expense expense_for_display[100];
	int contor = 0;
	this->service_for_expenses.getExpenseByTypeAndConditionEqual(type, value, expense_for_display, contor);
	this->show_them(contor, expense_for_display);
}

//Descr: run methos for properties
//In: -
//Out: -
void Console::run_for_properties() {
	this->menu_for_obtaining_properties();
	int option = read_option();
	switch (option){
	case '1':
		this->handle_max_amount_by_type();
		break;
	case '2':
		this->handle_max_day_by_amounts();
		break;
	case '3':
		this->handle_sort_days_desc_by_amounts();
		break;
	case '4':
		this->handle_sort_amounts_asc_by_value();
	default:
		break;
	}
}

//Descr: handlle method for max amount by type
//In: -
//Out: -
void Console::handle_max_amount_by_type() {
	cout << "Give the type:  ";
	char* type = read_char_pointer();
	int sum_value = this->service_for_expenses.getSumOfAmountsOfExpensesByType(type);
	cout << "The sum for type '"<<type<<"' is: " << sum_value;
	cout << endl;
}

//Descr: handle method for max day by amounts
//In:
//Out:
void Console::handle_max_day_by_amounts() {
	int max_day = this->service_for_expenses.getDayWithMaximumValueForAmount();
	cout << "The day with maximum value for amount is: " << max_day << endl;
}

//Descr: handle method for sort decending by amounts
//In: -
//Out: -
void Console::handle_sort_days_desc_by_amounts() {
	int sorted_list[100] = {};
	int contor = 0;
	this->service_for_expenses.sortDaysByAmount(sorted_list, contor);
	this->show_list_of_int(sorted_list, contor);
}

//Descr: method for displaying an integet=r list
//In: -
//Out: -
void Console::show_list_of_int(int sorted_list[], int contor) {
	for (int i = 0; i < contor; i++) {
		cout << sorted_list[i] << " ";
		cout << endl;
	}
}

//Descr: handle method for dort ascending by value
//In: -
//Out: -
void Console::handle_sort_amounts_asc_by_value() {
	cout << "Give the type:  ";
	char* type = read_char_pointer();
	int sorted_list[100] = {};
	int contor = 0;
	this->service_for_expenses.sortAmountsByType(type, sorted_list, contor);
	this->show_list_of_int(sorted_list, contor);
}

//Descr: run  function for filter
//In: -
//Out: -
void Console::run_for_filter() {
	this->menu_for_filter();
	int option = read_option();
	switch (option){
	case '1':
		this->handle_filter_by_type();
		break;
	case '2':
		this->handle_filter_by_type_and_condition_smaller();
		break;
	case '3':
		this->handle_show_by_type_and_condition_equal();
		break;
	default:
		break;
	}
}

//Descr: ahndle methood for filter by type
//In: -
//Out: -
void Console::handle_filter_by_type() {
	cout << "Give the type:  ";
	char* type = read_char_pointer();
	this->service_for_expenses.filterByType(type);
}

//Descr: ahndle method for filter by type and condition smaller
//In: -
//Out: -
void Console::handle_filter_by_type_and_condition_smaller() {
	cout << "Give the type:  ";
	char* type = read_char_pointer();
	cout << "Give the value:  ";
	int value = read_int();
	this->service_for_expenses.filterByTypeAndConditionSmaller(type, value);
}

//Descr: ahndle method for filter by type and condition equal
//In: -
//Out: -
void Console::handle_filter_by_type_and_condition_equal() {
	cout << "Give the type:  ";
	char* type = read_char_pointer();
	cout << "Give the value:  ";
	int value = read_int();
	this->service_for_expenses.filterByTypeAndConditionEqual(type, value);
}
