/**
 * @author Болотин Максим Владимирович
 * @brief  Самостоятельная работа 06
 */

#include "index.hpp"

namespace sw06 {

	/**
	 * T.1. Вычисление кусочной функции разными способами.
	 */
	void task01() {
		message("task01");

		double x      = 0.0;
		double y      = 0.0;
		int    choice = 0;

		cout << "Введите x: ";
		cin  >> x;

		cout << endl
			 << "Способы вычисления:"                 << endl
			 << " 1. Полное ветвление;"               << endl
			 << " 2. Составные логические выражения;" << endl
			 << " 3. Условная операция."              << endl
			 << endl;

		while (choice < 1 || choice > 3) {
			cout << "Выберите способ [1-3]: ";
			cin  >> choice;
		}

		switch (choice) {
			case 1:
				if (x < -5) {
					y = cos(2) / x;
				}
				else if (x <= 2) {
					y = x * sin(x);
				}
				else if (x < 3) {
					y = (x + 10) / (2 + x * x);
				}
				else {
					y = x + cbrt(x);
				}
				break;

			case 2:
				if (x < -5) {
					y = cos(2) / x;
				}

				if (x >= -5 && x <= 2) {
					y = x * sin(x);
				}

				if (x > 2 && x < 3) {
					y = (x + 10) / (2 + x * x);
				}

				if (x >= 3) {
					y = x + cbrt(x);
				}
				break;

			case 3:
				y = (x < -5)
					? cos(2) / x
					: (x <= 2)
						? x * sin(x)
						: (x < 3)
							? (x + 10) / (2 + x * x)
							: x + cbrt(x);
				break;
		}

		cout << endl << "Результат: y = " << y << endl;
	}

	/**
	 * T.2. Гадание на ромашке.
	 */
	void task02() {
		message("task02");

		int petals = 0;

		cout << "Введите количество лепестков [10-50]: ";
		cin  >> petals;

		if (petals < 10 || petals > 50) {
			cout << "Ошибка. Количество лепестков должно быть от 10 до 50." << endl << endl;
			return;
		}

		cout << endl << "Результат гадания: ";

		switch (petals % 6) {
			case 0:
				cout << "любит";
				break;
			case 1:
				cout << "не любит";
				break;
			case 2:
				cout << "плюнет";
				break;
			case 3:
				cout << "поцелует";
				break;
			case 4:
				cout << "к сердцу прижмет";
				break;
			case 5:
				cout << "к черту пошлет";
				break;
		}

		cout << endl;
	}

	/**
	 * T.3. Вычисление суммы ряда.
	 */
	void task03() {
		message("task03");

		double x       = 0.0;
		double epsilon = 0.0;

		cout << "Введите x: ";
		cin  >> x;

		cout << "Введите epsilon (0 < epsilon < 1): ";
		cin  >> epsilon;

		if (epsilon <= 0 || epsilon >= 1) {
			cout << "Ошибка. Некорректное значение epsilon." << endl << endl;
			return;
		}

		double sum  = 0.0;
		double term = x;
		int    n    = 0;

		while (fabs(term) >= epsilon) {
			sum += term;
			n++;
			term *= (-1.0) * x * x / ((2 * n) * (2 * n + 1));
		}

		cout << endl << "Сумма ряда S = " << sum << endl;
	}

	/**
	 * T.4. Табулирование функции двух переменных.
	 */
	void task04() {
		message("task04");

		double a  = 0.0;
		double b  = 0.0;
		double c  = 0.0;
		double d  = 0.0;
		double dx = 0.0;
		double dy = 0.0;

		cout << "Введите  a: "; cin >>  a;
		cout << "Введите  b: "; cin >>  b;
		cout << "Введите  c: "; cin >>  c;
		cout << "Введите  d: "; cin >>  d;
		cout << "Введите dx: "; cin >> dx;
		cout << "Введите dy: "; cin >> dy;

		cout << endl;
		cout << fixed << setprecision(2);
		cout << setw(8) << "y\\x";

		for (double x = a; x <= b + 0.0001; x += dx) {
			cout << setw(8) << x;
		}

		cout << endl;

		for (double y = c; y <= d + 0.0001; y += dy) {

			cout << setw(8) << y;

			for (double x = a; x <= b + 0.0001; x += dx) {
				if ((4 - x * x - y * y) >= 0 && x != y) {
					double z = exp(sqrt(4 - x * x - y * y)) / (x - y);
					cout << setw(8) << z;
				}
				else {
					cout << setw(8) << "(*)";
				}
			}
		}
	}

	void index() {
		message("intro");

		task01();
		task02();
		task03();
		task04();
	}
}
