/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 16
 */

#include "index.hpp"

namespace lw16 {

	static const string appDir  = string(getenv("HOME")) + "/Documents/BoapSemTwo";
	static const string iFile = ( appDir + "/16/Input.txt"  );

	/**
	 * T.1
	 * Ввод размера массива с проверкой корректности данных
	 */
	int arrayInput(const int maxSize = 100) {
		int size{};

		do {
			cout << "Введите размер массива: " << endl;
			cin >> size;

			if (cin.fail() || size <= 0 || size > maxSize) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Ошибка! Повторите ввод.\n" << endl;
			}
		} while (size <= 0 || size > maxSize);

		return size;
	}



	/**
	 * T.2
	 * Заполнение массива:
	 *  - с клавиатуры
	 *  - случайными числами
	 *  - из файла
	 */
	void arrayInputViaKeyboard(vector<int>& arr, const int size) {
		for (int i{}; i < size; ++i) {
			cout << "элемент[" << i << "] = ";
			cin >> arr[i];
		}
	}

	void arrayInputViaRandom(vector<int>& arr, const int size, const int min, const int max) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(min, max);

		for (int i{}; i < size; ++i) {
			arr[i] = dist(gen);
		}
	}

	void arrayInputViaFile(vector<int>& arr, const int size, const string& fileName) {
		ifstream file(fileName);

		if (!file.is_open()) {
			cout << "Не удалось открыть файл.\n";
			return;
		}

		for (int i{}; i < size; ++i) {
			if (!(file >> arr[i])) {
				cout << "В файле недостаточно данных.\n";
				arr[i] = 0;
			}
		}
	}



	/**
	 * T.3
	 * Вывод элементов массива на экран
	 */
	void arrayPrint(const vector<int>& arr, const int size) {
		cout << "Массив: ";

		for (int i{}; i < size; ++i) {
			cout << arr[i] << ' ';
		}

		cout << "\n";
	}



	/**
	 * T.4, I.1 - Произведение элементов с номерами, кратными заданному числу
	 */
	long long productByNumberMultiplicity(const vector<int>& arr, const int size, const int number) {
		long long product{1};
		bool found{};

		for (int i{1}; i <= size; ++i) {
			if (i % number == 0) {
				product *= arr[i - 1];
				found = true;
			}
		}

		return found ? product : 0;
	}



	/**
	 * T.4, I.2 - Сумма элементов между первым и последним нулевыми элементами
	 */
	int sumBetweenFirstAndLastZero(const vector<int>& arr, const int size) {
		int first{-1};
		int last{-1};

		for (int i{}; i < size; ++i) {
			if (arr[i] == 0) {
				if (first == -1) {
					first = i;
				}

				last = i;
			}
		}

		if (first == -1 || first == last) {
			return 0;
		}

		int sum{};

		for (int i{first + 1}; i < last; ++i) {
			sum += arr[i];
		}

		return sum;
	}

	/**
	 * Методическое указание к лабораторной работе 16
	 * Функция mainArrayS()
	 */
	void mainArrayS() {

		// print message introduction in program
		message("intro");

		/**
		 * T.1
		 * Ввод размера массива
	 	*/
		const int size{arrayInput()};
		vector<int> arr(size);

		int choice{};

		cout << "Выберите способ заполнения:\n";
		cout << "1 - С клавиатуры\n";
		cout << "2 - Случайными числами\n";
		cout << "3 - Из файла\n";
		cout << "Ваш выбор: " << endl;
		cin >> choice;

		/**
		 * T.2
		 * Выбор способа заполнения массива
	 	*/
		switch (choice) {
			case 1:
				arrayInputViaKeyboard(arr, size);
				break;

			case 2:
				arrayInputViaRandom(arr, size, -10, 10);
				break;

			case 3:
				arrayInputViaFile(arr, size, iFile);
				break;

			default:
				cout << "Некорректный выбор.\n";
				return;
		}

		/**
		 * T.3
		 * Вывод массива
	 	*/
		arrayPrint(arr, size);

	}

	/**
	 * Функция mainVector()
	 * Вариант задания лабораторной работы (3)
	 */
	void mainVector() {

		// print message introduction in program
		message("indy");

		const int size{arrayInput()};
		vector<int> arr(size);

		/**
		 * T.2
		 * Заполнение массива
	 	*/
		arrayInputViaKeyboard(arr, size);

		/**
		 * T.3
		 * Вывод массива
	 	*/
		arrayPrint(arr, size);

		int number{};
		cout << "Введите число для проверки кратности номеров элементов: ";
		cin >> number;

		/**
		 * T.4
		 * I.1 - Вычисление произведения элементов
	 	*/
		cout << "Произведение элементов с номерами, кратными "
			<< number << ": "
			<< productByNumberMultiplicity(arr, size, number) << "\n";

		/**
		 * T.4
		 * I.2 - Вычисление суммы между нулевыми элементами
	 	*/
		cout << "Сумма элементов между первым и последним нулевыми элементами: "
			<< sumBetweenFirstAndLastZero(arr, size) << "\n";

	}

	void index() {

		/**
		 * T.5
		 * Вызов функций лабораторной работы
	 	*/
		mainArrayS();
		mainVector();
		

	}

}
