#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
	Employee();
	friend istream& operator>> (istream& in, Employee& right);
	friend ostream& operator<< (ostream& out, const Employee& right);
	string get_name() const;
	string get_ID() const;
	int get_age() const;
	int get_weight() const;
	double get_salary() const;
private:
	string name;
	string ID_number;
	int age;
	int weight;
	double salary;
};

#endif