/**
 * @author Болотин Максим Владимирович
 * @brief  Самостоятельная работа 07
 */

#include "index.hpp"

namespace sw07 {

	/**
	 * Вычисление коэффициента индивидуального варианта
	 * a_n = (-1)^n * 2^n / n!
	 */
	double variantCoefficient(int n, double previous) {
		return previous * (-2.0 / n);
	}

	/**
	 * Задание 1
	 */
	void task01() {
		message("task01");

		// T.1: ввод x и точности вычисления
		double x;
		double eps;

		cout << "Введите значение x: ";
		cin  >> x;

		cout << "Введите точность вычисления eps: ";
		cin  >> eps;

		// T.1: начальные значения ряда
		double coefficient = -2.0;
		double xPower      = x;
		double term        = coefficient * xPower;
		double sum         = 0.0;
		int    n           = 1;
		int    iterations  = 0;

		// T.1: вычисление суммы ряда через рекуррентные соотношения
		while (abs(term) >= eps) {
			sum += term;
			iterations++;

			n++;
			coefficient = variantCoefficient(n, coefficient);
			xPower     *= x;
			term        = coefficient * xPower;
		}

		cout << "Приближенная сумма ряда: "         << sum        << endl;
		cout << "Количество выполненных итераций: " << iterations << endl;
	}

	/**
	 * Задание 2
	 */
	void task02() {
		message("task02");
		message("chebyshev");

		// T.2.1: рекурсивный перевод числа в p-ичную систему
		auto toBase = [&](auto self, int number, int base) -> void {
			if (number >= base) {
				self(self, number / base, base);
			}

			cout << number % base;
		};

		// T.2.2: рекурсивное вычисление многочлена Чебышёва
		auto chebyshev = [&](auto self, int n, double x) -> double {
			if (n == 0) {
				return 1.0;
			}

			if (n == 1) {
				return x;
			}

			return 2 * x * self(self, n - 1, x) - self(self, n - 2, x);
		};

		int number;
		int base;

		cout << "Введите натуральное число: ";
		cin  >> number;

		cout << "Введите основание системы счисления (2-9): ";
		cin  >> base;

		cout << "Число в новой системе счисления: ";
		toBase(toBase, number, base);
		cout << endl;

		int    n;
		double x;

		cout << "Введите номер многочлена Чебышёва n: ";
		cin  >> n;

		cout << "Введите значение x для вычисления многочлена: ";
		cin  >> x;

		double result = chebyshev(chebyshev, n, x);

		cout << "Значение многочлена Чебышёва Tn(x): " << result << endl;
	}

	/**
	 * 
	 */
	void index() {
		message("intro");

		task01();
		task02();

	}

}
