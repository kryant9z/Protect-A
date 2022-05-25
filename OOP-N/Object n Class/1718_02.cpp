#include<iostream>
#include<string>
#include<iomanip>

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
		id = _id; _firstname = firstname; _lastname = lastname; _salary = salary;
	}
	Employee(const Employee& em)
	{
		id = em.id; firstname = em.firstname; lastname = em.lastname; salary = em.salary;
	}
	//Operator
	friend istream& operator >>(istream& is, Employee& em)
	{
		is >> em.id;
		cin.ignore();
		getline(is, em.firstname);
		getline(is, em.lastname);
		is >> em.salary;
		return is;
	}
	friend ostream& operator <<(ostream& os, Employee em)
	{
		os << "Employee[id=" << em.id << ",name=" << em.getName() << ",salary=$";
		os << setprecision(2) << fixed;
		os << em.salary << "]";
		return os;
	}
	//Do somethings 
	double getAnnualSalary()
	{
		return 12 * salary;
	}
	double raiseSalary(double percent)
	{
		return salary * (1 + percent/100);
	}
	string toString()
	{
		string s="Employee[id=" + to_string(id) + ",name=" + getName() + ",salary=$";
		cout << setprecision(2) << fixed;
		s = to_string(salary) + "]";
	}
	// nạp chồng ++--
	Employee operator ++()//++em
	{
		salary *= 1.1;
		return *this;
	}
	Employee operator ++(int) //em++
	{
		return *this;
	}
	Employee operator --() //--em
	{
		salary *= 0.9;
		return *this;
	}
	Employee operator --(int)//em--
	{
		return *this;
	}
	//+(float)  -(float)
	Employee operator+ (double n)
	{
		salary += n;
		return *this;
	}
	Employee operator- (double n)
	{
		salary -= n;
		return *this;
	}
	//Compare
	bool operator >(Employee em)
	{
		return getAnnualSalary() > em.getAnnualSalary();
	}
	bool operator <(Employee em)
	{
		return getAnnualSalary() < em.getAnnualSalary();
	}
	bool operator ==(Employee em)
	{
		return getAnnualSalary() == em.getAnnualSalary();
	}
	bool operator !=(Employee em)
	{
		return getAnnualSalary() != em.getAnnualSalary();
	}
	bool operator >=(Employee em)
	{
		return getAnnualSalary() >= em.getAnnualSalary();
	}
	bool operator <=(Employee em)
	{
		return getAnnualSalary() <= em.getAnnualSalary();
	}
};
int main()
{
	Employee em1, em2;
	cin >> em1 >> em2;
	cout << em1 << em2;
	double a, b;
	cin >> a >> b;

	if (em1 == em2)
	{
		cout << "BANG NHAU";
	}
	else if (em1 < em2)
	{
		cout << "NHO HON";
	}
	else if (em1 > em2)
	{
		cout << "LON HON";
	}
	cout << "$" << (em1++ - a).getSalary() << endl;
    cout <<"$" << (--em2 + b).getSalary();
	return 0;
}