/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 10
 */

#include "index.hpp"

namespace lw10 {

	/**
	 * Declare functions
	 */
	double computeFunction(int choice, double a, double x) {
		switch (choice) {
			case  1:
				/* y = ( √x + √a + 1 ) / √(x·a) */
				return ( sqrt( x ) + sqrt( a ) + 1 ) / sqrt( x * a );
			case  2:
				/* y = ( sin(a·x) + sin²(a) ) / ( 4 + sin²(x) ) */
				return ( sin( a * x ) + pow( sin( a ), 2 ) ) / ( 4 + pow( sin( x ), 2 ) );
			case  3:
				/* y = ( ∛(a + x) + ∛(a + 2) ) / (a + x) */
				return ( cbrt( a + x ) + cbrt( a + 2 ) ) / ( a + x );
			case  4:
				/* y = ln( |2·a·x| / |a − x| ) */
				return log( abs( 2 * a * x ) / abs( a-x ) );
			case  5:
				/* y = 1 / ( e^(a·x) + 2e^a ) */
				return 1 / ( exp( a * x ) + 2 * exp( a ) );
			case  6:
				/* y = ( sin⁵(x) + a·x ) / ( x + cos⁵(x) ) */
				return ( pow( sin( x ), 5 ) + a * x ) / ( x + pow( cos( x ), 5 ) );
			case  7:
				/* y = ⁵√( (a + 30) / (a + √(a·x)) ) */
				return pow( ( a + 30 ) / ( a + sqrt( a * x ) ), 1.0 / 5.0 );
			case  8:
				/* y = ln(a² + x²) / |a + x| */
				return log( a * a + x * x ) / abs( a + x );
			case  9:
				/* y = 1.5 · cos⁴( (a + x) / (2a² + 2x²) ) */
				return 1.5 * pow( cos( ( a + x ) / ( 2 * a * a + 2 * x * x ) ), 4 );
			case 10:
				/* y = √(a + sin(x)) / ∛(4 + cos(x)) */
				return sqrt( a + sin( x ) ) / cbrt( 4 + cos( x ) );
			case 11:
				/* y = ln(x⁴ − a²) / (a⁴ + 28) */
				return log( pow( x,4 )-a * a ) / ( pow( a,4 ) + 28 );
			default:
				cout << "Неверный номер функции.";
				return 0;
		}
	}

	/**
	 * Table printing
	 */
	void printTableHeader() {
		cout << string(30,'-') << "\n";
		cout << setw(10) << "x" << setw(20) << "y" << "\n";
		cout << string(30,'-') << "\n";
	}
	void printTableFooter() {
		cout << string(30,'-') << "\n";
	}
	void printRow(double x, double y) {
		cout << setw(10) << fixed << setprecision(4) << x
			 << setw(20) << fixed << setprecision(6) << y << "\n";
	}

	/**
	 * Цикл с предусловием
	 */
	void loopWhile(double x_start, int funcChoice, double a, double N, double h) {
		double x = x_start;
		int i=0;
		while (i <= N) {
			double y = computeFunction(funcChoice, a, x);
			printRow(x,y);
			x += h;
			i++;
		}
	}

	/**
	 * Цикл с постусловием
	 */
	void loopDoWhile(double x_start, int funcChoice, double a, double N, double h) {
		double x = x_start;
		int i = 0;
		do {
			double y = computeFunction(funcChoice, a, x);
			printRow(x,y);
			x += h;
			i++;
		} while(i <= N);
	}

	/**
	 * Цикл с параметром
	 */
	void loopFor(double x_start, int funcChoice, double a, double N, double h) {
		for(int i=0; i <= N; i++) {
			double x = x_start + i * h;
			double y = computeFunction(funcChoice, a, x);
			printRow(x,y);
		}
	}

	/**
	 * Code entrypoint
	 */
	void index() {

		message("intro");

		int funcChoice = 0, loopChoice = 0;

		while (funcChoice < 1 || funcChoice > 11) {
			cout << "Введите соответствующий номер функции y=f(x) из таблицы условия задачи [1-11]: ";
			cin  >> funcChoice;
		}

		message("methods");

		while (loopChoice < 1 || loopChoice > 3) {
			cout << "Введите номер способа решения [1-3]: ";
			cin  >> loopChoice;
		}

		double N, a, x_start, x_end;

		cout << "\n";
		cout << "Введите исходные данные для функции из таблицы (используйте точку для нецелых чисел):";
		cout << "\n";
		cout << " N:      "; cin >> N;
		cout << " a:      "; cin >> a;
		cout << " x(нач): "; cin >> x_start;
		cout << " x(кон): "; cin >> x_end;
		cout << "\n";

		double h = ( x_end - x_start ) / N;

		printTableHeader();

		switch(loopChoice) {
			case 1: { // while loop
				loopWhile(x_start, funcChoice, a, N, h);
				break;
			}
			case 2: { // do-while loop
				loopDoWhile(x_start, funcChoice, a, N, h);
				break;
			}
			case 3: { // for loop
				loopFor(x_start, funcChoice, a, N, h);
				break;
			}
			default:
				cout << "Неверный номер способа решения.";
		}

		printTableFooter();
	}
}
