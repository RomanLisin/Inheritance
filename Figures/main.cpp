#include<iostream>

class Figure
{
protected:
    char** ch_Fig;
    int side;
    double S;
    double P;

public:
    virtual void print() = 0;
    virtual void printSP() = 0;
    virtual void printTxt(double S, double P) = 0;
   // virtual Square& operator=(const Square& other) = 0;
    //virtual Square& operator=(Square&& other) = 0;
};

class Square :public Figure
{

    const int get_side()const
    {
        return side;
    }
    char** get_chFigure()const
    {
        return ch_Fig;
    }
    const double get_S()const
    {
        return S;
    }
    const double get_P()const
    {
        return P;
    }
    void set_side(int sideP)
    {
        this->side = sideP;
    }
    void set_chFigure(char** chFigureP)
    {
        this->ch_Fig = chFigureP;
    }
    void set_S(double S)
    {
        this->S = S;
    }
    void set_P(double P)
    {
        this -> P = P;
    }
    
public:
    //                    Constructor:

    explicit Square(int sideP):Figure()
    {
        set_side(sideP);
        this->ch_Fig = new char* [side];
        for (int i = 0; i < side; i++)ch_Fig[i] = new char [side] {};
        std::cout << "SquareConstructor:\t" << this << std::endl;
    }

    Square() :Square(5)
    {
        std::cout << "SquareDefaultConstructor:\t" << this << std::endl;
    }

    //					CopyCosntuctor:
    Square(const Square& other) :Square(other.side)
    {
        for (int i = 0; i < other.side; i++)
        {
            for (int j = 0; j < other.side; j++)
            {
                this->ch_Fig[i][j] = other.ch_Fig[i][j];
            }
        }
        std::cout << "SquareCopyConstructor:\t" << this << std::endl;
    }

    //					MoveConstructor:
    Square(Square&& other) :Square(other.side)
    {
        other.ch_Fig = nullptr;
        other.side = 0;
        std::cout << "SquareMoveConstructor:\t" << this << std::endl;
    }

    //					  Destructor:
    virtual ~Square()
    {
        for (int i = 0; i < side; i++)delete[]ch_Fig[i];
        delete[] ch_Fig;
        ch_Fig = nullptr;
        side = 0;
        std::cout << "SquareDestructor:\t" << this << std::endl;
    }

    //				   	CopyAssignment:
    Square& operator=(const Square& other)
    {
        if (this == &other)return *this;
        for (int i = 0; i < other.side; i++)delete[]this->ch_Fig[i];
        delete[] this->ch_Fig;
        this->ch_Fig = nullptr;
        //Square(other.side, other.ch_Fig);
        this->side = other.side;
        this->ch_Fig = other.ch_Fig;

        std::cout << "SquareCopyAssignment:\t" << std::endl;
        return *this;
    }

    Square& operator=(Square&& other)
    {
        if (this == &other)return *this;

        for(int i=0;i<this->side;i++)delete[] ch_Fig[i];
        delete[]ch_Fig;
        this->ch_Fig = other.ch_Fig;
        this->side = other.side;

        other.ch_Fig = nullptr;
        other.side = 0;

        std::cout << "SquareMoveAssignment:\t" << this << std::endl;
        return *this;
    }

    void print() override
    {
        std::cout << std::endl;
        for (int i = 0; i < side; i++)
        {
            std::cout << "\t\t";
            for (int j = 0; j < side; j++)
            {
                std::cout << "**";
            }
            std::cout << std::endl;
        }
    }
    void printTxt(double S, double P)
    {
        std::cout << "The area of a square is: " << S << " sm^2"
        << "\tPerimetr is: " << P << " sm" << std::endl;
    }
    void printSP() override
    {
        P = side * 4;
        S = side * side;
        printTxt(S, P);
    }
};

class Circle :public Square
{
    double radius = this->side / 2;
    int a = 2;
    int b = 2;
public:

    //              DefaultConstructor:
    Circle():Square()
    {
        std::cout << "SDefaultConstructor:\t" << this << std::endl;
    }
    
    //               1ArgConstructor:
    explicit Circle(int sideP) :Circle()
    {

        std::cout << "CConstructor:\t" << this << std::endl;
    }

    //               CopyConstructor:
    Circle(const Circle& ohter) :Circle()
    {
        std::cout << "CCopyConstructor:\t" << this << std::endl;
    }

    //               MoveConstructor:
    Circle& operator=(Circle&& other)
    {
        if (this == &other)return *this;
        //this->clear();
        for (int i = 0; i < this->side; i++)delete[] ch_Fig[i];
        delete[]ch_Fig;
        this->side = other.side;
        this->ch_Fig = other.ch_Fig;
        other.ch_Fig = nullptr;
        other.side = 0;
        std::cout << "SMoveAssignment:\t" << this << std::endl;
        return *this;
    }

    // r^2 = x^2 + y^2
    // r^2 = (x-r)^2 + (y-r)^2    �� ��������� �� ������ �� �
    void print() override
    {

        std::cout << std::endl;
        for (int i = 0; i <= side; i++)
        {
            std::cout << "\t";
            for (int j = 0; j <= side; j++)
            {
                double x = (i - radius * (1 - a / 2)) / a;
                double y = (j - radius * b) / 2;
                std::cout << ((radius * radius > x * x + y * y) ? "*" : " ");
              
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    void printSP() override
    {
        P = 2*3,14*radius;
        S = 3,14*radius*radius;
        printTxt(S, P);
    }
};

    class Rectangle :public Square
{
    int sideB;

public:
    const int get_sideB()const
    {
        return sideB;
    }
    int get_sideB()
    {
        return sideB;
    }

    void set_sideB(int sideBP)
    {
        this->sideB = sideBP;
    }

    //         Constructor:
    Rectangle(int sideAP, int sideBP=3) :Square(sideAP)
    {
        set_sideB(sideBP);
        std::cout << "RConstructor:\t" << this << std::endl;
    }

    virtual ~Rectangle()
    {
        for (int i = 0; i < this->side; i++)delete[]ch_Fig[i];
        delete[]ch_Fig;
        ch_Fig = nullptr;
        side = 0;
        sideB = 0;
        std::cout << "RDestructor:\t" << this << std::endl;
    }
    void print() override
    {
        std::cout << std::endl;
        for (int i = 0; i < side; i++)
        {
            std::cout << "\t";
            for (int j = 0; j < sideB; j++)
            {
                std::cout << "**";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }
    void printSP() override
    {
        P = (side+sideB)*2;
        S = side*sideB;
        printTxt(S, P);
    }
};

class Triangle :public Rectangle
{
    int sideC;

public:
    int get_sideC()
    {
        return sideC;
    }
    void set_sideC(int sideC)
    {
        this->sideC = sideC;
    }

    //              DefaultConstructor:
    Triangle(int sideA, int sideB, int sideC=5) :Rectangle(sideA, sideB)
    {
        set_sideC(sideC);
        std::cout << "TriangleConstructor:\t" << this << std::endl;
    }    
    Triangle() :Triangle(side, get_sideB(), sideC)
    {
        std::cout << "TriangleDefaultConstructor:\t" << this << std::endl;
    }
    //               1ArgConstructor:
    explicit Triangle(int sideP) : Triangle(sideP,get_sideB(), sideC)
    {

        std::cout << "Treangle1ArgConstructor:\t" << this << std::endl;
    }

    //               CopyConstructor:
    Triangle(const Circle& ohter) :Triangle(side,get_sideB(), sideC)
    {
        std::cout << "TriangleCopyConstructor:\t" << this << std::endl;
    }

    //               MoveConstructor:
    Triangle& operator=(Triangle&& other)
    {
        if (this == &other)return *this;
        //this->clear();
        for (int i = 0; i < this->side; i++)delete[] ch_Fig[i];
        delete[]ch_Fig;
        this->side = other.side;
        this->ch_Fig = other.ch_Fig;
        other.ch_Fig = nullptr;
        other.side = 0;
        std::cout << "TriangleMoveAssignment:\t" << this << std::endl;
        return *this;
    }

    ~Triangle()
    {
        for (int i = 0; i < side; i++)delete[]ch_Fig[i];
        delete[]ch_Fig;
        ch_Fig = nullptr;
        side = 0;
        std::cout << "TreangleDestructor:\t";
    }
   
};

void main()
{
    setlocale(LC_ALL, "");

    Square A(4);
    A.print(); A.printSP();

    std::cout << std::endl;
    Rectangle B(2, 6);
    B.print(); B.printSP();

    std::cout << std::endl;
    Circle C(10);
    C.print(); 
    //Circle D;
   // D = C;
    //D.print();
}