#include<iostream>


#define delimetr "--------------------------------------------------\n"
class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//              Constructor:
	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << "\t" << std::endl;
	}
	virtual~Human()
	{
		std::cout << "HDestructor:\t" << this << "\t"<<std::endl;
	}
	
	//				Method:
	 virtual void print()const
	{
		std::cout << last_name << " " << first_name << " " << age << " years" << std::endl;
	}
};
			
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating; // успеваемость
	double attendance; // посещаемость

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;  
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(const double rating)
	{
		this->rating = rating;
	}
	void set_attendence(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	):Human(last_name, first_name,age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendence(attendance);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDectructor:\t" << this << std::endl;
	}
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << group << " " << rating << " " << attendance << std::endl;
	}
};


class Teacher :public Human
{
	std::string speciality;
	int experience;

public:

	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//				Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
	}
	void print()const
	{
		Human::print();
		std::cout << speciality << " " << experience << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDectructor:\t" << std::endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//			Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance) 
	{
		set_subject(subject);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDectructed:\t" << this << std::endl;
	}
	void print()
	{
		Student::print();
		std::cout << subject << std::endl;
	}
};
//#define INHERITANCE_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Payne", "Max", 30);
	human.print();

	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_20", 95, 97);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heisenberg");
	graduate.print();
#endif // INHERITANCE_CHECK

// Generalization  -  обобщение
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_20", 95, 97),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heisenberg"),
		new Student("Vercetty","Tommy",30,"Theft","Vice",98,95),
		new Teacher("Diaz","Ricardo",50,"Weapons distance",20)
	};
	
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		std::cout << delimetr;
		group[i]->print();
	}
	std::cout <<std::endl;
	

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
		std::cout << delimetr;
	}



}