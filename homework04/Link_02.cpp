#include <iostream>
#include <vector>
#include <string>

struct Lesson;
struct Student;

struct Lesson
{
	Lesson() = default;

	Lesson (const std::string& lesson, const std::vector<Student*>& link={})
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

	Student (const std::string& name, const std::vector<Lesson*>& link={})
		: student_name { name }
		, link { link }
	{

	}

	std::string student_name;
	std::vector<Lesson*> link;
};

void makelink(Student& student, Lesson& lesson)
{
	student.link.push_back(&lesson);
	lesson.link.push_back(&student);
}

void output(const Lesson& lesson)
{
	for (int i = 0 ; i < lesson.link.size(); ++i)
	{
		if (i == lesson.link.size() - 1)
			std::cout << (*lesson.link[i]).student_name;
		else
			std::cout << (*lesson.link[i]).student_name << ", ";
	}
	std::cout << std::endl;
}

void output(const Student& student)
{
	for (int i = 0; i < student.link.size(); ++i)
	{
		if (i == student.link.size() - 1)
			std::cout << (*student.link[i]).lesson_name;
		else
			std::cout << (*student.link[i]).lesson_name << ", ";
	}
	std::cout << std::endl;
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

	// Student's definitions
	Student gandolf { "Gandolf" };
	Student frodo { "Frodo" };
	Student tom { "Tom" };
	Student bilbo { "Bilbo" };
	
	// making of links
	makelink(frodo, physical_culture);
	makelink(frodo, informatics);
	makelink(bilbo, foreing_language);
	makelink(bilbo, chemistry);
	makelink(tom, math);
	makelink(tom, physics);
	makelink(tom, chemistry);
	makelink(gandolf, foreing_language);
	makelink(gandolf, informatics);
	makelink(gandolf, chemistry);
	makelink(gandolf, physics);

	// making vectors with lessons and students
	std::vector<Lesson> arr_lesson { math, physics, informatics, foreing_language, physical_culture, chemistry };
	std::vector<Student> arr_student { gandolf, frodo, tom, bilbo };

	// some possible output
	std::cout << "What is being learnt by Gandolf? He is learning ";
	output(arr_student[0]);

	std::cout << "And who is learning foreing_language? It is being learnt by ";
	output(arr_lesson[3]);

	std::cout << "And who is learning chemistry? It is being learnt by ";
	output(arr_lesson[5]);
	
}
