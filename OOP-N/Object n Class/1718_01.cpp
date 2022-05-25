#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Employee
{
	int id;
	string firstname;
	string lastname;
	double salary;
public:
	//get-set
	int getID()
	{
		return id;
	}
	string getFirstname()
	{
		return firstname;
	}
	string getLastname()
	{
		return lastname;
	}
	string getName()
	{
		return firstname + " " + lastname;
	}
	double getSalary()
	{
		return salary;
	}
	void setSalary(double _salary) //set
	{
		salary = _salary;
	}
	//Create-Delete
	Employee(int _id = 0, string _firstname = "firstname", string _lastname = "lastname", double _salary = 0)
	{
		id = _id, _firstname = firstname, _lastname = lastname, _salary = salary;
	}
	Employee(const Employee& em)
	{
		id = em.id, firstname = em.firstname, lastname = em.lastname, salary = em.salary;
	}
	~Employee() {};
	//Do somethings
	double getAnnualSalary()
	{
		return 12 * salary;
	}
	double raiseSalary(double percent)
	{
		return salary * (1 + percent / 100);
		//return salary + salary*percent/100;
	}
	string toString()
	{
		string s = "Employee[id=" + to_string(id) + ",name=" + getName() + ",salary=$";
		cout << setprecision(2) << fixed;
		s = to_string(salary) + "]";
	}

	//In-out
	friend istream&operator>>(istream& is, Employee& e) {
		is >> e.id;
		cin.ignore();
		getline(is, e.firstname);
		getline(is, e.lastname);
		is >> e.salary;
		return is;
	}
	friend ostream& operator <<(ostream& os, Employee em)
	{
		os << "Employee[id=" << em.id << ",name=" << em.getName() << ",salary=$";
		os << setprecision(2) << fixed;
		os << em.salary << "]" << endl;
		return os;
	}

};
int main()
{
	Employee em;
	double x;
	cin >> em;
	cin >> x;
	cout << em;
	cout << fixed;
	cout << "$" << setprecision(2) << fixed << em.raiseSalary(x) << endl;
	em.setSalary(em.raiseSalary(x));
	cout << "$" << setprecision(2) << fixed << em.getAnnualSalary();
//	system("pause");
	return 0;
}