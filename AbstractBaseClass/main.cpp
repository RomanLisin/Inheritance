#include<iostream>
using namespace std;
//#define VEHICLE
#ifdef VEHICLE
class Vehicle
{
public:
	virtual void move() = 0;
};

class GroundVehicle :public Vehicle {};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Car to move" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Car bmw;
	bmw.move();
}
#endif // VEHICLE

class Square
{
	int side;
	char** ch_Fig;

public:
	const int get_side()const
	{
		return side;
	}
    char** get_chFigure()const
	{
		return ch_Fig;
	}
	void set_side(int sideP)
	{
		this->side = sideP;
	}
	void set_chFigure(char** chFigureP)
	{
		this->ch_Fig = chFigureP;
	}

	//					Constructor:
	Square(int sideP, char** chFigureP)
	{
		set_side(sideP);
		set_chFigure(chFigureP);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	Square() :Square(5, new char* [side])
	{
		for (int i = 0; i < side; i++)ch_Fig[i] = new char[side] {};
		std::cout << "SDefaultConstructor:\t" << this << std::endl;
	}
	Square(int sideP) :Square()
	{
		set_side(sideP);
		std::cout << "S1ArgConstructor:\t" << this << std::endl;
	}

	//					CopyCosntuctor:
	Square(const Square& other) :Square(other.side,other.ch_Fig)
	{
		for (int i = 0; i < other.side; i++)
		{
			for (int j = 0; j < other.side; j++)
			{
				this->ch_Fig[i][j] = other.ch_Fig[i][j];
			}
		}
		std::cout << "ScopyConstructor:\t" << this << std::endl;
	}

	//					MoveConstructor:
	Square(Square&& other):Square(other.side,other.ch_Fig)
	{
		other.ch_Fig = nullptr;
		other.side = 0;
		std::cout << "SMoveConstructor:\t" << this << std::endl;
	}

	//					  Destructor:
	~Square()
	{
		for (int i = 0; i < side; i++)delete[]ch_Fig[i];
		delete[] ch_Fig;
		ch_Fig = nullptr;
		side = 0;
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	//				   	CopyAssignment:
	Square& operator=(const Square& other)
	{
		if (this == &other)return *this;
		for (int i = 0; i < side; i++)delete[]this->ch_Fig[i];
		delete[] this->ch_Fig;
		this->ch_Fig = nullptr;
		Square(other.side,other.ch_Fig);
		std::cout << "SCopyAssignment:\t" << std::endl;
		return *this;
	}
	void print()
	{
		std::cout << std::endl;
		for (int i = 0; i < side; i++)
		{
			std::cout << "\t";
			for (int j = 0; j < side; j++)
			{
				std::cout << "**";
			}
			std::cout << std::endl;
		}
	}
};

void main()
{
	Square A(5);
	Square B;
	B = A;
	B.print();
	A.print();
}