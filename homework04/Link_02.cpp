#include <iostream>
#include <vector>
#include <string>

struct Lesson;
struct Student;

struct Lesson
{
	Lesson() = default;

	Lesson (std::string lesson, std::vector<Student*> link={})
		: lesson_name { lesson }
		, link { link }
	{

	}

	std::string lesson_name;
	std::vector<Student*> link;
};

struct Student
{
	Student() = default;

	Student (std::string name, std::vector<Lesson*> link={})
		: student_name { name }
		, link { link }
	{

	}

	std::string student_name;
	std::vector<Lesson*> link;
};

void makelink(Student& student, Lesson& lesson1, Lesson& lesson2 )
{
	student.link = { &lesson1, &lesson2 };
	lesson1.link.push_back(&student);
	lesson2.link.push_back(&student);
}

void makelink(Student& student, Lesson& lesson1, Lesson& lesson2, Lesson& lesson3)
{
	student.link = { &lesson1, &lesson2, &lesson3 };
	lesson1.link.push_back(&student);
	lesson2.link.push_back(&student);
	lesson3.link.push_back(&student);
}

void output(Lesson& lesson)
{
	int i = 0;
	for ( ; i < lesson.link.size() - 1; ++i)
	{
		std::cout << (*lesson.link[i]).student_name << ", ";
	}
	std::cout << (*lesson.link[i]).student_name << std::endl;
}

void output(Student& student)
{
	int i = 0;
	for ( ; i < student.link.size() - 1; ++i)
	{
		std::cout << (*student.link[i]).lesson_name << ", ";;
	}
	std::cout << (*student.link[i]).lesson_name << std::endl;
}

int main()
{
	// Lessons' definitions
	Lesson math { "math" };
	Lesson physics { "physics" };
	Lesson informatics { "informatics" };
	Lesson foreing_language { "foreing language" };
	Lesson physical_culture { "physical culture" };
	Lesson chemistry { "chemistry" };
	std::vector<Lesson> arr_lesson { math, physics, informatics, foreing_language, physical_culture, chemistry };

	// Student's definitions
	Student gandolf { "Gandolf" };
	Student frodo { "Frodo" };
	Student tom { "Tom" };
	Student bilbo { "Bilbo" };
	std::vector<Student> arr_student { gandolf, frodo, tom, bilbo };

	// making of links
	makelink(frodo, informatics, physical_culture);
	makelink(bilbo, foreing_language, math);
	makelink(tom, physics, math, chemistry);
	makelink(gandolf, physics, foreing_language, chemistry);

	// some possible output
	std::cout << "What is being learnt by Gandolf? He is learning ";
	output(gandolf);

	std::cout << "And who is learning foreing_language? It is being learnt by ";
	output(foreing_language);

	std::cout << "And who is learning chemistry? It is being learnt by ";
	output(chemistry);
	
}
