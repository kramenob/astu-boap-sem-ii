/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 12
 */

#include "index.hpp"

namespace lw12 {

    /**
     * Recursive function to convert a number to base p (2 <= p <= 9)
     */
    void convertToBase(int n, int base) {
        if (n < base) {
            cout << n;
            return;
        }

        convertToBase(n / base, base);
        cout << n % base;
    }

    /**
     * Recursive function to compute Tn(x)
     */
    int T_n(int n, int x) {
        if (n == 0) return 1;
        if (n == 1) return x;

        return 2 * x * T_n(n - 1, x) - T_n(n - 2, x);
    }

	void index() {

		// print message introduction in program
		message("intro");

        // --- Task 1: Convert number to base p ---
        int number, base = 0;

        cout << "Введите число: ";
        cin  >>  number;

		while (base < 2 || base > 9) {
			cout << "Выберите систему счисления [2-9]: ";
			cin  >>  base;
		}

		cout << "Результат в " << base << "-ичной системе счисления: ";
        convertToBase(number, base);
        cout << endl;

        // --- Task 2: Compute Tn(x) ---
        int n = -1, x;

		while (n < 0) {
			cout << "Теперь введите номер последовательности { T₀(x)=1, T₁(x)=x, T𝓷(x)=2xT𝓷 - 1(x) - T𝓷-2(x) }: ";
			cin  >>  n;
			if (n < 0) {
				cout << "Номер последовательности должен быть больше 0, разумеется.." << endl;
			}
		}

        cout << "Значение x-аргумента: ";
        cin  >>  x;

		int result = T_n(n, x);
		cout << "T_" << n << "(" << x << ") = " << result << endl;

	}

}
