/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 11
 */

#include "index.hpp"

namespace lw11 {

	/**
	 * Fraction struct
	 */
	struct Fraction {
		long long num;
		long long den;
	};

	/**
	 * Function to compute GCD using Euclidean algorithm
	 * Require: T.2.
	 */
	long long gcd(long long a, long long b) {
		a = llabs(a);
		b = llabs(b);
		while (b != 0) {
			long long t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	/**
	 * Reduce fraction to irreducible form
	 * Require: T.3.
	 */
	void reduce(Fraction &f) {
		long long g = gcd(f.num, f.den);
		if (g != 0) {
			f.num /= g;
			f.den /= g;
		}
		if (f.den < 0) {
			f.den = -f.den;
			f.num = -f.num;
		}
	}

	/**
	 * Returns the sum as an irreducible fraction
	 * Require: T.4.
	 */
	Fraction sum(const Fraction &a, const Fraction &b) {
		Fraction result;
		result.num = a.num * b.den + b.num * a.den;
		result.den = a.den * b.den;
		reduce(result);
		return result;
	}

	/**
	 * Count digits in number
	 * Require: T.5.
	 */
	int countDigits(long long x) {
		if (x == 0) return 1;
		x = llabs(x);
		int count = 0;
		while (x > 0) {
			x /= 10;
			count++;
		}
		return count;
	}

	/**
	 * Print fraction in formatted form
	 * Length of line between numerator and denominator equals max digits
	 * Require: T.6.
	 */
	void printFraction(const Fraction &f) {
		int len = max(countDigits(f.num), countDigits(f.den));
		cout << f.num << endl;
		for (int i = 0; i < len; i++) cout << "-";
		cout << endl;
		cout << f.den << endl << endl;
	}

	/**
	 * Input fraction from user with validation
	 * Require: T.1.
	 */
	Fraction inputFraction(const string& prefix = "") {
		// declare local integer
		Fraction f;
		// ask user to input while it's not correct
		while (true) {
			// tell what to do
			if (!prefix.empty()) {
				cout << prefix << " (формат ч/з): ";
			} else {
				cout << "Введите дробь (формат ч/з): ";
			}

			long long num, den;
			char slash;

			// get user input
			cin >> num >> slash >> den;

			// validate input
			if (cin.fail() || slash != '/' || den == 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Некорректная запись. Пожалуйста, введите дробь (формат: числитель/знаменатель).\n";
			} else {
				// if okay return this input
				f.num = num;
				f.den = den;
				return f;
			}
		}
	}


	void task() {
		message("intro");

		// T.1. Написать функцию, обеспечивающую ввод дроби с клавиатуры и проверку на корректность;
		cout << "### Требование 1." << endl;
		Fraction f1 = inputFraction("Введите первую дробь"); Fraction f1_cached = f1;
		Fraction f2 = inputFraction("Введите вторую дробь");
		cout << endl;
		waitForEnter();

		// T.2. Написать функцию, возвращающую наибольший общий делитель двух натуральных чисел;
		cout << "### Требование 2." << endl
			 << "Наибольший общий делитель числителей: "   << gcd(f1.num, f2.num) << endl
			 << "Наибольший общий делитель знаменателей: " << gcd(f1.den, f2.den) << endl
			 << endl;
		waitForEnter();

		// T.3. Написать функцию сокращения дроби;
		cout << "### Требование 3." << endl
			 << "Сокращённая запись дроби " << f1.num << "/" << f1.den; cout << " это "; reduce(f1); cout << f1.num << "/" << f1.den << endl
			 << "Сокращённая запись дроби " << f2.num << "/" << f2.den; cout << " это "; reduce(f2); cout << f2.num << "/" << f2.den << endl
			 << endl;
		waitForEnter();

		// T.4. Написать функцию, вычисляющую сумму двух дробей, Возвращаемая дробь должна быть несократимой;
		Fraction result = sum(f1, f2);
		cout << "### Требование 4." << endl
			 << "Сумма двух дробей в виде несократимой дроби " << result.num << "/" << result.den; cout << endl
			 << endl;
		waitForEnter();

		// T.5. Написать функцию подсчитывающую количество цифр в числе;
		cout << "### Требование 5." << endl
			 << "Количество цифр в числах (на примере дроби " << f1_cached.num << "/" << f1_cached.den << "):" << endl
			 << " - в числителе ("   << f1_cached.num << ") чисел: " << countDigits(f1_cached.num) << ";" << endl
			 << " - в знаменателе (" << f1_cached.den << ") чисел: " << countDigits(f1_cached.den) << ";" << endl
			 << endl;
		waitForEnter();

		// T.6. Написать функцию вывода дроби на экран (длина черты между числителем и знаменателем должна быть равна количеству цифр большего из выводимых чисел);
		cout << "### Требование 6." << endl
			 << "Рукописная запись суммы дробей:" << endl;
		printFraction(result);
		waitForEnter();

		// T.7. Вызывая функцию нахождения суммы дробей нужное количество раз, вывести результаты на экран.
		cout << "### Требование 7." << endl
			 << "Результаты представлены выше." << endl
			 << endl;
		waitForEnter();
	}

	void indy() {
		message("indintro");

		int n = 0;
		while (n < 1) {
			cout << "Введите номер элемента последовательности n: ";
			cin >> n;
			if (cin.fail()) {
				cin.clear(); // clear the error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				n = 0; // reset n so the loop continues
				cout << "Число n должно быть больше 1." << endl;
			}
		}

		// Helper function for dividing two fractions
		auto addOne = [](const Fraction &f) -> Fraction {
			return sum(f, {1,1});
		};
		auto divide = [](const Fraction &f1, const Fraction &f2) -> Fraction {
			Fraction result;
			result.num = f1.num * f2.den;
			result.den = f1.den * f2.num;
			reduce(result);
			return result;
		};
		Fraction a{1,1}; // a1 = 1
		for (int i = 1; i < n; i++) {
			a = divide(addOne(a), addOne(a));
		}
		cout << "Элемент a_" << n << " последовательности: " << endl;
		printFraction(a);
	}



	/**
	 * Lab code entrypoint
	 */
	void index() {

		/**
		 * Задание
		 */
		task();

		/**
		 * Индивидуальное задание
		 */
		indy();

	}

}
