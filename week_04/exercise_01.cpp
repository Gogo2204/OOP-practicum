#include <iostream>
#include <fstream>

enum class Subject
{
	DIS,
	DSTR,
	OOP,
	Geometry,
	EN
};

class Teacher
{
private:
	char name[50];
	int age;
	Subject subject;
	unsigned salary;

public:

	void setName(const char* name)
	{
		if (!name)
			return;

		std::strcpy(this->name, name);
	}

	void setAge(const int age)
	{
		if (age >= 18 && age <= 70)
			this->age = age;
		else
			this->age = 18;
	}

	void setSubject(const Subject subject)
	{
		this->subject = subject;
	}

	void setSalary(const unsigned salary)
	{
		if (salary <= 500)
			this->salary = salary;
		else
			this->salary = 500;
	}

	const char* getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}

	Subject getSubject() const
	{
		return subject;
	}

	unsigned getSalary() const
	{
		return salary;
	}

	Teacher(const char* name, const int age, const Subject subject, const unsigned salary)
	{
		setName(name);
		setAge(age);
		setSubject(subject);
		setSalary(salary);
	}
};