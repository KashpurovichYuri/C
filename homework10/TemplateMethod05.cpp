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
				return difficulty * 5;
			case Report::difoffset:
				return difficulty * 3;
			case Report::offset:
				return difficulty * 1;
			default:
				return 0;
		}
	}

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
		return (difficulty + attendanceImp()) / 2.0;
	}

	float qualityImp() const override
	{
		return (quality + activityImp()) / 2.0 * difficultyImp() * amountImp();
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
		return (difficulty + frequencyImp()) / 2.0;
	}

private:
	const int semestr_time { 15 }; 	// weeks at semestr
	int frequency;  				// frequency of assignments' turning in by week
};

class SubjPhysics: public Subj
{
protected:
	auto controlsImp() const
	{
		return controls * 0;
	}

	float difficultyImp() const override
	{
		return (difficulty + controlsImp()) / 2.0;
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
		return (difficulty + attendanceImp()) / 2.0;
	}

	float qualityImp() const override
	{
		return (quality + independenceImp() + activityImp()) / 3.0 * difficultyImp() * amountImp();
	}

private:
	const int lessons { 30 };
	int attendance; 	// required number of classes attended
	bool activity;		// involving in work on seminar
	float independence; // independence of work
};

int main()
{
	
}