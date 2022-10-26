#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

double distance(const std::pair<double, double>& P1, const std::pair<double, double>& P2);
void printVertex(const std::pair<double, double>& P);
void printVertices(const std::vector<std::pair<double, double>>& points);

class Figure
{
public:
	explicit Figure(const std::vector<std::pair <double, double>>& arr):
		points { arr }
	{

	}

	Figure(const Figure& other) = default;

	Figure(Figure&& other) = default;

	virtual ~Figure() = default;

	virtual double area() const=0;
	virtual double perimeter() const=0;
	virtual void printInfo() const=0;

	friend std::ostream& operator<< (std::ostream& stream, const Figure& figure);

protected:
	std::vector<std::pair <double, double>> points;
};

class Polygon: public Figure
{
public:
	explicit Polygon(const std::vector<std::pair <double, double>>& arr):
		Figure { arr }
	{

	}

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;
};

class Triangle: public Polygon
{
public:
	explicit Triangle(const std::vector<std::pair <double, double>>& arr):
		Polygon { arr } 
	{
		if (points.size() != 3)
		{
			std::cerr << "Error: not correspond size for Triangle";
			std::exit(0);
		}
	}

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;

private:
	
};

class Quadrangle: public Polygon
{
public:
	explicit Quadrangle(const std::vector<std::pair <double, double>>& arr):
		Polygon { arr } 
	{
		if (points.size() > 4)
		{
			std::cerr << "Error: not correspond size for Quadrangle";
			std::exit(0);
		}
	}	

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;
};

class Parallelogram: public Quadrangle
{
public:
	explicit Parallelogram(const std::vector<std::pair <double, double>>& arr):
		Quadrangle { arr }
	{
		if (points.size() > 3)
		{
			std::cerr << "Error: not correspond size for Parallelogram";
			std::exit(0);
		}
	}

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;

	auto getFirstSide() const
	{
		return distance(points[0], points[1]);
	}

	auto getSecondSide() const
	{
		return distance(points[1], points[2]);
	}
};

class Rectangle: public Parallelogram
{
public:
	explicit Rectangle(const std::vector<std::pair <double, double>>& arr):
		Parallelogram { arr }
	{
		if (points.size() > 3)
		{
			std::cerr << "Error: not correspond size for Rectangle";
			std::exit(0);
		}
		else if (points.size() == 3 && (points[0].first != points[1].first || points[1].second != points[2].second))
		{
			std::cerr << "Error: not correspond type setting method for Rectangle. It is set with 3 consistent points: bottom left, top left and top right vertices.";
			std::exit(0);			
		}
	}

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;
};

class Square: public Rectangle
{
public:
	explicit Square(const std::vector<std::pair <double, double>>& arr):
		Rectangle { arr }
	{
		if (points.size() != 2)
		{
			std::cerr << "Error: not correspond size for Square";
			std::exit(0);
		}
		else if (points[0].first != points[1].first)
		{
			std::cerr << "Error: not correspond type setting method for Square. It is set with 2 consistent points: bottom left, top left vertices.";
			std::exit(0);
		}

		a = distance(points[0], points[1]);
		points.pop_back();
		points[0] = std::make_pair(points[0].first + a / 2, points[0].second + a / 2);
	}

	explicit Square(const std::vector<std::pair <double, double>>& arr, double side):
		Rectangle { arr }, a { side }
	{
	if (points.size() != 1)
		{
			std::cerr << "Error: not correspond size for Square";
			std::exit(0);
		}	
	}

	Square(const Square& other) = default;

	Square(Square&& other) = default;

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;
	
private:
	double a;
};

class Ellipse: public Figure
{
public:
	explicit Ellipse(const std::vector<std::pair <double, double>>& arr):
		Figure { arr } 
	{
		if (points.size() > 3)
		{
			std::cerr << "Error: not correspond size for Ellipse";
			std::exit(0);
		}
		if (points.size() == 3)
		{
			a = distance(points[0], points[1]);
			b = distance(points[0], points[2]);
		}
	}

	explicit Ellipse(const std::vector<std::pair <double, double>>& arr, double big, double small):
		Figure { arr }, a { big }, b { small }
	{
		if (points.size() != 1)
		{
			std::cerr << "Error: not correspond size for Ellipse";
			std::exit(0);
		}
	}

	Ellipse(const Ellipse& other) = default;

	Ellipse(Ellipse&& other) = default;

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;

private:
	double a;
	double b;

};

class Circle: public Ellipse
{
public:
	explicit Circle(const std::vector<std::pair <double, double>>& arr):
		Ellipse { arr }
	{
		if (points.size() != 2)
		{
			std::cerr << "Error: not correspond size for Circle";
			std::exit(0);
		}

		rad = distance(points[0], points[1]);
		points.pop_back();
	}	

	explicit Circle(const std::vector<std::pair <double, double>>& arr, double R):
		Ellipse { arr }, rad { R } 
	{
		if (points.size() != 1)
		{
			std::cerr << "Error: not correspond size for Circle";
			std::exit(0);
		}
	}

	Circle(const Circle& other) = default;

	Circle(Circle&& other) = default;

	double area() const override;
	double perimeter() const override;
	void printInfo() const override;
	
private:
	double rad;
};

double Polygon::area() const
{
	double sq = 0;
	for (int i = 1; i < points.size() - 1; ++i)
	{
		Triangle triangle {std::vector<std::pair <double, double>> {points[0], points[i], points[i + 1]}};
		sq += triangle.area();
	}

	return sq;
}

double Polygon::perimeter() const
{
	double pm = 0;
	for (size_t i = 0; i < points.size(); ++i)
		pm += distance(points[i % points.size()], points[(i + 1) % points.size()]);

	return pm;
}

void Polygon::printInfo() const
{
	std::cout << "This Figure is Polygon with vertices: ";
	printVertices(points);
	std::cout << "The perimeter is " << perimeter() << " and the area is " << area();
}

double Triangle::area() const
{
	double pm = perimeter() / 2;
	double sq = pm;
	for (size_t i = 0; i < points.size(); ++i)
		sq *= (pm - distance(points[i % points.size()], points[(i + 1) % points.size()]));
	sq = pow(sq, 0.5);

	return sq;
}

double Triangle::perimeter() const
{
	return Polygon::perimeter();
}

void Triangle::printInfo() const
{
	std::cout << "This Figure is Triangle with vertices: ";
	printVertices(points);
	std::cout << "The perimeter is " << perimeter() << " and the area is " << area();
}

double Quadrangle::area() const
{
	return Polygon::area();
}

double Quadrangle::perimeter() const
{
	return Polygon::perimeter();
}


void Quadrangle::printInfo() const
{
	std::cout << "This Figure is Quadrangle with vertices: ";
	printVertices(points);
	std::cout << "The perimeter is " << perimeter() << " and the area is " << area();
}

double Parallelogram::area() const
{
	double sq = 0;
	Triangle triangle {std::vector<std::pair <double, double>> {points[0], points[1], points[2]}};
	sq += 2 * triangle.area();
	
	return sq;
}

double Parallelogram::perimeter() const
{
	return 2 * (getFirstSide() + getSecondSide());
}

void Parallelogram::printInfo() const
{
	std::cout << "This Figure is Parallelogram with given vertices: ";
	printVertices(points);
	std::cout << "The lenghts of the sides are " << getFirstSide() << " and " << getSecondSide()  << ". "
		<< "The perimeter is " << perimeter() << " and the area is " << area();
}

double Rectangle::area() const
{
	return getFirstSide() * getSecondSide();
}

double Rectangle::perimeter() const
{
	return Parallelogram::perimeter();
}

void Rectangle::printInfo() const
{
	std::cout << "This Figure is Rectangle with given vertices: ";
	printVertices(points);
	std::cout << "The lenghts of the sides are " << getFirstSide() << " and " << getSecondSide()  << ". "
		<< "The perimeter is " << perimeter() << " and the area is " << area();
}

double Square::area() const
{
	return a * a;
}

double Square::perimeter() const
{
	return 4 * a;
}

void Square::printInfo() const
{
	std::cout << "This Figure is Square with center: ";
	printVertex(points[0]);
	std::cout << ". " << "The lenght of the side is " << a << ". "
		<< "The perimeter is " << perimeter() << " and the area is " << area();
}

double Ellipse::area() const
{
	return M_PI * a * b;
}

double Ellipse::perimeter() const
{
	return M_PI * (a + b);
}

void Ellipse::printInfo() const
{
	std::cout << "This Figure is Ellipse with center: ";
	printVertex(points[0]);
	std::cout << ". " << "The semi-major axis is " << a << " and " << "the semi-minor axis is " << b << ". "
		<< "The perimeter is " << perimeter() << " and the area is " << area();
}

double Circle::area() const
{
	return M_PI * rad * rad;
}

double Circle::perimeter() const
{
	return M_PI * 2 * rad;
}

void Circle::printInfo() const
{
	std::cout << "This Figure is Circle with center: ";
	printVertex(points[0]);
	std::cout << ". " << "The radius is " << rad << ". "
		<< "The perimeter is " << perimeter() << " and the area is " << area();
}

std::ostream& operator<< (std::ostream& stream, const Figure& figure)
{
	figure.printInfo();
	return stream;
}

double distance(const std::pair<double, double>& P1, const std::pair<double, double>& P2)
{
	return pow((P2.first - P1.first) * (P2.first - P1.first) + (P2.second - P1.second) * (P2.second - P1.second), 0.5);
}

void printVertex(const std::pair<double, double>& P)
{
	std::cout << "(" << P.first << ", " << P.second << ")";
}

void printVertices(const std::vector<std::pair<double, double>>& points)
{
	for (size_t i = 0; i < points.size() - 1; ++i)
	{
		printVertex(points[i]);
		std::cout << ", ";
	}
	printVertex(points[points.size() - 1]);
	std::cout << ". ";
}

int main()
{
	Polygon               polygon1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(0, 2), std::make_pair(2, 2), std::make_pair(2, 0), std::make_pair(1, -1)}};
	Triangle             triangle1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(0, 2), std::make_pair(2, 2)}};
	Quadrangle         quadrangle1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, -2), std::make_pair(0, 2), std::make_pair(2, 2), std::make_pair(4, -2)}};
	Parallelogram   parallelogram1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, -2), std::make_pair(1, 2), std::make_pair(5, 5)}};
	Rectangle           rectangle1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(0, 3), std::make_pair(4, 3)}};
	Square                 square1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(0, 5)}};
	Ellipse               ellipse1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(5, 0), std::make_pair(0, 3)}};
	Circle 	               circle1 {std::vector<std::pair <double, double>>
		{std::make_pair(0, 0), std::make_pair(5, 0)}};
	Circle 	               circle2 {circle1};

	std::vector<Figure*> figures;
	figures.push_back(&polygon1);
	figures.push_back(&triangle1);
	figures.push_back(&quadrangle1);
	figures.push_back(&parallelogram1);
	figures.push_back(&rectangle1);
	figures.push_back(&square1);
	figures.push_back(&ellipse1);
	figures.push_back(&circle1);
	figures.push_back(&circle2);
	
	for (int i = 0; i < figures.size(); ++i)
	{
		std::cout << *figures[i] << std::endl;
	}
}
