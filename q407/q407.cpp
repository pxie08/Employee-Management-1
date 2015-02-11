/****************************
** q407.cpp
** Employee Management 1
** Patrick Xie, 4/7/11
****************************/

#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	
	//Variables
	ifstream fin;
	string filename;
	Employee emp;
	list<Employee> master_list;
	map<string, list<Employee>::iterator> name_map;
	map<string, list<Employee>::iterator> id_number_map;
	map<int, list<Employee>::iterator> age_map;
	map<int, list<Employee>::iterator> weight_map;
	map<double, list<Employee>::iterator> salary_map;
	int response;
	list<Employee>::iterator iter;
	string in_name;
	string in_idnum;
	int in_age;
	int in_weight;
	double in_salary;
	int int_in_salary;
	int salary_key;
	int ecount;
	//geting file name to open
	cout << "Enter file name: ";
	cin >> filename;
	fin.open(filename.c_str());

	if(fin.fail())
		cout<<"FAIL\n\n";
	//pushs employee objects into the master_list
	while(fin >> emp){
		master_list.push_back(emp);
	}
	//creates maps to specific variables in each object
	iter = master_list.begin();
	while(iter!= master_list.end()){
		name_map[(*iter).get_name()] = iter;
		id_number_map[(*iter).get_ID()]=iter;
		age_map[(*iter).get_age()]=iter;
		weight_map[(*iter).get_weight()]=iter;
		//casts into int from user's double
		salary_key = 100*((int)(*iter).get_salary());
		salary_map[salary_key]=iter;
		iter++;
	}
	//menu for look up
	do{
		cout<< "1.) Look up employee by name.\n"
			<< "2.) Look up employee by ID number.\n"
			<< "3.) Look up employee by age.\n"
			<< "4.) Look up employee by weight.\n"
			<< "5.) Look up employee by salary.\n"
			<< "6.) Print all records.\n"
			<< "7.) Quit.\n"
			<< "Enter your choice:";
		cin >> response;
		cout<< "\n";
		//ecount's are for counting number of variables found in list
		//since values are unique, only 1 should exist if it exist
		//if not found, ecount = 0, prompt user to search another value
		switch(response){
		case 1:
			cout << "What is the name of the employee?";
			cin >> in_name;
			ecount = name_map.count(in_name);
			if(ecount == 1)
				cout<< "Name: " <<(*name_map[in_name]).get_name() << "\n"
					<< "ID Number: " << (*name_map[in_name]).get_ID() << "\n"
					<< "Age: " << (*name_map[in_name]).get_age() << "\n"
					<< "Weight: " << (*name_map[in_name]).get_weight() << "\n"
					<< "Salary: " << (*name_map[in_name]).get_salary() << "\n\n";
			else
				cout<< "This name does not exist in the file.\n\n";
			break;
		case 2:
			cout << "What is the ID number of the employee?";
			cin >> in_idnum;
			ecount = id_number_map.count(in_idnum);
			if( ecount == 1)
				cout<< "Name: " <<(*name_map[in_idnum]).get_name() << "\n"
					<< "ID Number: " << (*name_map[in_idnum]).get_ID() << "\n"
					<< "Age: " << (*name_map[in_idnum]).get_age() << "\n"
					<< "Weight: " << (*name_map[in_idnum]).get_weight() << "\n"
					<< "Salary: " << (*name_map[in_idnum]).get_salary() << "\n\n";
			else
				cout<< "This name does not exist in the file.\n\n";
			break;
		case 3:
			cout << "What is the age of the employee?";
			cin >> in_age;
				ecount = age_map.count(in_age);
			if( ecount == 1)
				cout<< "Name: " <<(*age_map[in_age]).get_name() << "\n"
					<< "ID Number: " << (*age_map[in_age]).get_ID() << "\n"
					<< "Age: " << (*age_map[in_age]).get_age() << "\n"
					<< "Weight: " << (*age_map[in_age]).get_weight() << "\n"
					<< "Salary: " << (*age_map[in_age]).get_salary() << "\n\n";
			else
				cout<< "This name does not exist in the file.\n\n";
			break;
		case 4:
			cout << "What is the weight of the employee?";
			cin >> in_weight;
			ecount = weight_map.count(in_weight);
			if( ecount == 1)
				cout<< "Name: " <<(*weight_map[in_weight]).get_name() << "\n"
					<< "ID Number: " << (*weight_map[in_weight]).get_ID() << "\n"
					<< "Age: " << (*weight_map[in_weight]).get_age() << "\n"
					<< "Weight: " << (*weight_map[in_weight]).get_weight() << "\n"
					<< "Salary: " << (*weight_map[in_weight]).get_salary() << "\n\n";
			else
				cout<< "This name does not exist in the file.\n\n";
			break;
		//converts the salary into a int, double does not work
		case 5:
			cout << "What is the salary of the employee?";
			cin >> in_salary;
			int_in_salary = 100*(int)in_salary;
			ecount = salary_map.count(int_in_salary);
			if( ecount == 1)
				cout<< "Name: " <<(*salary_map[int_in_salary]).get_name() << "\n"
					<< "ID Number: " << (*salary_map[int_in_salary]).get_ID() << "\n"
					<< "Age: " << (*salary_map[int_in_salary]).get_age() << "\n"
					<< "Weight: " << (*salary_map[int_in_salary]).get_weight() << "\n"
					<< "Salary: " << (*salary_map[int_in_salary]).get_salary() << "\n\n";
			else
				cout<< "This name does not exist in the file.\n\n";
			break;
		case 6:
			iter = master_list.begin();
			while (iter!= master_list.end()){
				cout<< "Name: " <<(*iter).get_name() << "\n"
					<< "ID Number: " << (*iter).get_ID() << "\n"
					<< "Age: " <<(*iter).get_age() << "\n"
					<< "Weight: " << (*iter).get_weight() << "\n"
					<< "Salary: " << (*iter).get_salary() << "\n\n";
				iter++;
			}
			cout << "\n";
			break;
		case 7:
			break;
		default:
			cout << "This option does not exist, please try again.\n\n";
			break;
		}
	}while(response !=7);
	fin.close();
	return 0;
}