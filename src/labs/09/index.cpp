/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 09
 */

#include "index.hpp"

namespace lw09 {

	/**
	 * Метод 1.
	 * Используются вложенные полные ветвления. Он состоит в том,
	 * что максимальное из двух чисел сравнивается с третьим.
	 */
	void caseOne( int a, int b, int c, int &maxNum ) {
		// use of nested full branches
		if ( a > b ) {
			if ( a > c ) { 
				maxNum = a;
			} else {
				maxNum = c;
			}
		} else {
			if ( b > c ) {
				maxNum = b;
			} else {
				maxNum = c;
			}
		}
	}

	/**
	 * Метод 2.
	 * Используются неполные ветвления и сложные логические выражения.
	 * Основан на том, что максимальное среди нескольких чисел – это такое число,
	 * которое больше всех остальных. Поэтому поочерёдно для каждого из трёх чисел
	 * происходит проверка одновременного выполнения двух условий: оно должно быть
	 * больше каждого из двух оставшихся чисел.
	 */
	void caseTwo( int a, int b, int c, int &maxNum ) {
		// use of incomplete branches and complex logical expressions
		if ( a > b && a > c ) {
			maxNum = a;
		} else if ( b > a && b > c ) {
			maxNum = b;
		} else {
			maxNum = c;
		}
	}

	/**
	 * Метод 3.
	 * Переменной Max присваивается большее из чисел x и y.
	 * Затем Max сравнивается с третьим числом z.
	 */
	void caseThree( int a, int b, int c, int &maxNum ) {
		// assign maximum of a and b to maxNum
		maxNum = (a > b) ? a : b;
		// then compare with c
		maxNum = (maxNum > c) ? maxNum : c;
	}

	/**
	 * Метод 4.
	 * Написать программный код выбора максимального числа из трех,
	 * используя условную арифметическую операцию (?:).
	 */
	void caseFour( int a, int b, int c, int &maxNum ) {
		// use conditional operator ?: to find the maximum
		maxNum = (a > b ? (a > c ? a : c) : (b > c ? b : c));
	}

	/**
	 * Проверка режима отладки.
	 */
	bool isDebug(string debug) {
		// check if debug mode is enabled
		if (
			debug == "Y"
			|| debug == "Yes"
			|| debug == "y"
			|| debug == "yes"
			|| debug == "Да"
			|| debug == "да"
		) {
			return true;
		} else {
			return false;
		}
	}

	void index() {

		// print message introduction in program
		message("intro");

		// define variables
		int a, b, c;
		string debug;
		int choice;

		// numbers typing
		cout << "Введите поочерёдно три целых числа:";
		cout << "\n";
		cout << " 1. "; cin >> a; // number 1
		cout << " 2. "; cin >> b; // number 2
		cout << " 3. "; cin >> c; // number 3

		// print message about methods
		message("methods");

		cout << "Закомментируем `break` во всех альтернативах и проведём общее тестирование? [N/y]: ";
		cin  >> debug;

		if ( isDebug(debug) ) {
			// use any option
			choice = 1;
		} else {
			// solving method choice
			cout << "\n";
			cout << "Выберите способ решения [1-4]: ";
			cin  >> choice;
		}

		// define variable for max number
		int maxNum;

		// solving methods
		switch(choice) {

			case 1: {

				caseOne( a, b, c, maxNum );

				// check debug mode
				if ( !isDebug(debug) ) {
					break;
				}
			}

			case 2: {

				caseTwo( a, b, c, maxNum );

				// check debug mode
				if ( !isDebug(debug) ) {
					break;
				}
			}

		case 3: {

				caseThree( a, b, c, maxNum );

				// check debug mode
				if ( !isDebug(debug) ) {
					break;
				}
		}

		case 4: {

				caseFour( a, b, c, maxNum );

				// check debug mode
				if ( !isDebug(debug) ) {
					break;
				}
		}

			default:
				cout << "\n";
				cout << "Неверный выбор способа!" << endl;
				return;

		}

		// showing the result
		cout << "\n";
		cout << "Наибольшее число: " << maxNum << " (Из чисел [" << a << ", " << b << ", " << c << "])" << endl;
		return;

	}

}