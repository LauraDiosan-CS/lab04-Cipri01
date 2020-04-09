#ifndef CONSOLE_H
#include "Service.h"

class Console {
private:
	Service service_for_expenses;
public:
	void menu();
	void menu_for_add();
	void menu_for_change();
	void menu_for_determining_properties();
	void menu_for_obtaining_properties();
	void menu_for_filter();
	int run();
	char read_option();
	void run_for_add();
	void handle_insert_expense();
	int read_int();
	char* read_char_pointer();
	void run_for_change();
	void handle_delete_by_day();
	void handle_delete_in_range();
	void handle_delete_by_type();
	void run_for_display();
	void handle_show_all();
	void handle_show_by_type();
	void handle_show_by_type_and_condition_bigger();
	void handle_show_by_type_and_condition_equal();
	void show_them(int length, Expense expenses[]);
	void run_for_properties();
	void handle_max_amount_by_type();
	void handle_max_day_by_amounts();
	void handle_sort_days_desc_by_amounts();
	void handle_sort_amounts_asc_by_value();
	void show_list_of_int(int sorted_list[], int contor);
	void run_for_filter();
	void handle_filter_by_type();
	void handle_filter_by_type_and_condition_smaller();
	void handle_filter_by_type_and_condition_equal();

};
#endif // !CONSOLE_H
