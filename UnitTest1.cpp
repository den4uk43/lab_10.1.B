#include "pch.h"
#include "CppUnitTest.h"
#include "/ap_labs/lab_10.1 B/lab_10.1 B/lab_10.1.B.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStudentLevelB
{
	TEST_CLASS(UnitTestStudentLevelB)
	{
	public:

		// 1. Тест пошуку найбільшого середнього балу для різних спеціальностей (перевірка union)
		TEST_METHOD(TestFindMaxAverageGrade)
		{
			const int N = 3;
			Student students[N];

			// Студент 1: Комп'ютерні науки -> оцінка з програмування (4 + 4 + 5) / 3 = 4.333...
			students[0].prizvyshche = "Іваненко";
			students[0].kurs = 2;
			students[0].specialnist = KOMPYUTERNI_NAUKY;
			students[0].fizyka = 4;
			students[0].matematyka = 4;
			students[0].tretyaOtsinka.programuvannya = 5;

			// Студент 2: Інформатика -> оцінка з чисельних методів (5 + 5 + 4) / 3 = 4.666...
			students[1].prizvyshche = "Петренко";
			students[1].kurs = 3;
			students[1].specialnist = INFORMATYKA;
			students[1].fizyka = 5;
			students[1].matematyka = 5;
			students[1].tretyaOtsinka.chyselniMetody = 4;

			// Студент 3: Математика та економіка -> оцінка з педагогіки (3 + 4 + 3) / 3 = 3.333...
			students[2].prizvyshche = "Сидоренко";
			students[2].kurs = 1;
			students[2].specialnist = MATEMATYKA_TA_EKONOMIKA;
			students[2].fizyka = 3;
			students[2].matematyka = 4;
			students[2].tretyaOtsinka.pedagogika = 3;

			double maxAvg = FindMaxAverageGrade(students, N);

			Assert::AreEqual(14.0 / 3.0, maxAvg, 0.001);
		}

		// 2. Тест обчислення середнього балу окремо для кожної гілки union
		TEST_METHOD(TestCalcStudentAverage_AllBranches)
		{
			// Гілка 1: Програмування
			Student st1;
			st1.specialnist = KOMPYUTERNI_NAUKY;
			st1.fizyka = 5;
			st1.matematyka = 4;
			st1.tretyaOtsinka.programuvannya = 3;
			Assert::AreEqual(4.0, CalcStudentAverage(st1), 0.001);

			// Гілка 2: Чисельні методи
			Student st2;
			st2.specialnist = INFORMATYKA;
			st2.fizyka = 5;
			st2.matematyka = 5;
			st2.tretyaOtsinka.chyselniMetody = 5;
			Assert::AreEqual(5.0, CalcStudentAverage(st2), 0.001);

			// Гілка 3: Педагогіка
			Student st3;
			st3.specialnist = TRUDOVE_NAVCHANNYA;
			st3.fizyka = 3;
			st3.matematyka = 3;
			st3.tretyaOtsinka.pedagogika = 3;
			Assert::AreEqual(3.0, CalcStudentAverage(st3), 0.001);
		}

		// 3. Тест обчислення відсотка студентів з "4" або "5" з фізики
		TEST_METHOD(TestCalcGoodPhysicsPercent)
		{
			const int N = 4;
			Student students[N];

			students[0] = { "Коваленко", 1, KOMPYUTERNI_NAUKY, 5, 3, { 4 } };      // підходить (5)
			students[1] = { "Бондаренко", 2, INFORMATYKA, 4, 5, { 5 } };           // підходить (4)
			students[2] = { "Ткаченко", 3, FIZYKA_TA_INFORMATYKA, 3, 4, { 4 } };   // не підходить (3)
			students[3] = { "Шевченко", 4, TRUDOVE_NAVCHANNYA, 2, 3, { 3 } };      // не підходить (2)

			double percent = CalcGoodPhysicsPercent(students, N);

			Assert::AreEqual(50.0, percent, 0.001);
		}

		// 4. Тест граничних випадків (порожній масив / N = 0)
		TEST_METHOD(TestEmptyArray)
		{
			Student* emptyArr = nullptr;
			Assert::AreEqual(0.0, FindMaxAverageGrade(emptyArr, 0), 0.001);
			Assert::AreEqual(0.0, CalcGoodPhysicsPercent(emptyArr, 0), 0.001);
		}
	};
}