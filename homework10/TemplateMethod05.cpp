#include <iostream>
#include <string>

enum class Report
{
	exam,
	difoffset,
	offset,
};

class Subj
{
public:
	float SubjComplexity() const
	{
		float res = freebieImp() + reportImp() + qualityImp();
		if (res > 10)
			return 10.0;
		else if (res > 5)
			return 0.3 * freebieImp() + reportImp() + 0.7 * qualityImp();
		else
			return 0.7 * freebieImp() + reportImp() + 0.3 * qualityImp();
	}

protected:
	float amountImp() const
	{
		return amount;
	}

	virtual float difficultyImp() const
	{
		return difficulty;
	}

	virtual float qualityImp() const
	{
		return quality * difficultyImp() * amountImp();
	}

	float freebieImp() const
	{
		return freebie;
	}

	float reportImp() const
	{
		switch (report)
		{
			case Report::exam:
				return difficulty * 3;
			case Report::difoffset:
				return difficulty * 2;
			case Report::offset:
				return difficulty * 1;
			default:
				return 0;
		}
	}

	auto getDifficulty() const
	{
		return difficulty;
	}

	auto getQuality() const
	{
		return quality;
	}
	
private:
	int amount; 		// assignments' amount
	float difficulty; 	// assingments' difficulty
	float quality;  	// quality of execution tasks
	float freebie;  	// freebie of teacher
	Report report; 		// reporting form
};

class SubjMath: public Subj
{
protected:
	auto attendanceImp() const
	{
		return static_cast<float> (attendance) / lessons;
	}

	auto activityImp() const
	{
		return activity;
	}

	float difficultyImp() const override
	{
		return (getDifficulty() + attendanceImp()) / 2.0;
	}

	float qualityImp() const override
	{
		return (getQuality() + activityImp()) / 2.0 * difficultyImp() * amountImp();
	}

private:
	const int lessons { 15 };
	int attendance; // number of classes attended
	bool activity;	// involving in work on seminar
};

class SubjProgramming: public Subj
{
protected:
	auto frequencyImp() const
	{
		return frequency / semestr_time;
	}

	float difficultyImp() const override
	{
		return (getDifficulty() + frequencyImp()) / 2.0;
	}

private:
	const int semestr_time { 15 }; 	// weeks at semestr
	int frequency;		// frequency of assignments' turning in by week
};

class SubjPhysics: public Subj
{
protected:
	auto controlsImp() const
	{
		return controls * 1.5;
	}

	float difficultyImp() const override
	{
		return (getDifficulty() + controlsImp()) / 2.0;
	}

private:
	int controls; // number of control events	
};

class SubjEnglish: public Subj
{
protected:
	auto attendanceImp() const
	{
		return static_cast<float> (attendance * lessons) / (lessons * lessons) ;
	}

	auto activityImp() const
	{
		return (activity * attendance * 2) / (lessons * 2);
	}

	auto independenceImp() const
	{
		return independence;
	}

	float difficultyImp() const override
	{
		return (getDifficulty() + attendanceImp()) / 2.0;
	}

	float qualityImp() const override
	{
		return (getQuality() + independenceImp() + activityImp()) / 3.0 * difficultyImp() * amountImp();
	}

private:
	const int lessons { 30 };
	int attendance; // required number of classes attended
	bool activity;	// involving in work on seminar
	float independence; // independence of work
};

int main()
{
	
}

/*
	Differences and features of TemplateMethod:
		Дизайн шаблонннного метода приводит к разделению интерфейса класса на два отдельных интерфейса:
			Клиентский интерфейс: это общедоступный невиртуальный интерфейс. Методы этого интерфейса содержат код для частей общего алгоритма.
			Интерфейс подкласса: это защищённый или приватный интерфейс, который может иметь любую комбинацию виртуальных и невиртуальных методов.ы 
		Т.о. шаблонный метод:
			Позволяет подклассам реализовывать различное поведение (путем переопределения виртуальных методов).
			Позволяет избежать дублирования в коде: общий рабочий процесс алгоритма реализуется один раз в методе шаблона абстрактного класса, а необходимые вариации реализуются в подклассах.
			Контролирует точки, в которых разрешена специализация методов. Если бы подклассы просто переопределяли метод шаблона, они могли бы вносить радикальные и произвольные изменения в реализацию. Напротив, переопределяя только методы ловушек, можно изменить только некоторые конкретные детали кода, а в общем реализация остаётся нетронутой.
*/