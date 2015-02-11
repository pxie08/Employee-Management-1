#include "employee.h"

Employee::Employee() {
	name = "No name";
}

istream& operator>> (istream& in, Employee& right) {
	in >> right.name 
	   >> right.ID_number 
	   >> right.age 
	   >> right.weight 
	   >> right.salary;
	return in;
}

ostream& operator<< (ostream& out, const Employee& right) {
	out << right.name << " " 
		<< right.ID_number << " "
		<< right.age << " "
		<< right.weight << " "
		<< right.salary << "\n";
	return out;
}
string Employee::get_name() const {
	return name;
}

string Employee::get_ID() const {
	return ID_number;
}

int Employee::get_age() const {
	return age;
}

int Employee::get_weight() const {
	return weight;
}

double Employee::get_salary() const {
	return salary;
}