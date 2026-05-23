/**
 * @author Болотин Максим Владимирович
 * @brief  Самостоятельная работа 08
 */

#include "index.hpp"

namespace sw08 {

	static const string appDir = string(getenv("HOME")) + "/Documents/BoapSemTwo/sels/08";
	static const string iFile  = ( appDir + "/Input.txt"  );
	static const string oFile  = ( appDir + "/Output.txt" );

	/**
	 * Задание 1
	 * Нахождение среднего арифметического положительных элементов
	 */
	void task01() {
		message("task01");

		ofstream inputFile(iFile);

		srand( (unsigned) time (nullptr) );

		int length = 10 + rand() % 21;

		cout << "Количество элементов последовательности: " << length << endl << endl;
		cout << "Сгенерированная последовательность: ";

		double positiveSum   = 0;
		int    positiveCount = 0;

		for (int i = 0; i < length; i++) {
			int number = rand() % 101 - 50;

			cout      << number << " ";
			inputFile << number << " ";

			if (number > 0) {
				positiveSum += number;
				positiveCount++;
			}
		}

		cout << endl << endl;

		inputFile.close();

		if (positiveCount > 0) {
			double average = positiveSum / positiveCount;
			cout << "Среднее арифметическое положительных элементов: " << average << endl;
		} else {
			cout << "Положительные элементы отсутствуют." << endl;
		}
	}

	/**
	 * Задание 2
	 * Запись чисел, которые меньше суммы своих соседей
	 */
	void task02() {
		message("task02");

		ifstream inputFile(iFile);

		int previous;
		int current;
		int next;

		if (!(inputFile >> previous)) {
			cout << "Файл Input.txt пуст." << endl;
			return;
		}

		if (!(inputFile >> current)) {
			cout << "Недостаточно данных для обработки." << endl;
			return;
		}

		cout << "Результат обработки последовательности: ";

		if (previous < current) {
			cout << previous << " ";
		}

		while (inputFile >> next) {
			if (current < previous + next) {
				cout << current << " ";
			}

			previous = current;
			current = next;
		}

		if (current < previous) {
			cout << current << " ";
		}

		cout << endl;

		inputFile.close();
	}

	/**
	 * Задание 3
	 * Поиск максимального чётного числа и его номера
	 */
	void task03() {
		message("task03");

		ifstream inputFile(iFile);
		ofstream outputFile(oFile);

		int number;
		int index = 0;

		int maxEven      =  0;
		int maxEvenIndex = -1;

		bool hasEven = false;

		while (inputFile >> number) {
			outputFile << number << " ";

			if (number % 2 == 0) {
				if (!hasEven || number > maxEven) {
					maxEven      = number;
					maxEvenIndex = index;
					hasEven      = true;
				}
			}

			index++;
		}

		inputFile.close();
		outputFile.close();

		if (hasEven) {
			cout << "Максимальное чётное число: " << maxEven      << endl;
			cout << "Порядковый номер: "          << maxEvenIndex << endl;
		} else {
			cout << "Чётные числа отсутствуют." << endl;
		}
	}

	/**
	 * Задание 4
	 * Вывод последовательности из Output.txt
	 */
	void task04() {
		message("task04");

		ifstream outputFile(oFile);

		int number;

		cout << "Последовательность из файла Output.txt: ";

		while (outputFile >> number) {
			cout << number << " ";
		}

		cout << endl;

		outputFile.close();
	}

	/**
	 * Точка входа
	 */
	void index() {

		// create directory if it doesn't exists
		struct stat st = {0};
		if (stat(appDir.c_str(), &st) == -1) {
			mkdir(appDir.c_str(), 0755);
		}

		message("intro");

		task01();
		waitForEnter();

		cout << endl  << endl << "— — —" << endl << endl;
		task02();
		waitForEnter();

		cout << endl  << endl << "— — —" << endl << endl;
		task03();
		waitForEnter();

		cout << endl  << endl << "— — —" << endl << endl;
		task04();
		waitForEnter();
	}

}
