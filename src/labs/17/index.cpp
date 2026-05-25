/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 17
 */

#include "index.hpp"

namespace lw17 {

	static const string appDir  = string(getenv("HOME")) + "/Documents/BoapSemTwo";
	static const string iFile = ( appDir + "/17/Input.txt"  );
	static const string oFile = ( appDir + "/17/Output.txt"  );

	// T.1 - Ввод количества строк и столбцов массива
	int matrixSizeInput(const string hint = "ряда", const int maxSize = 10) {
		int size{};

		do {
			cout << "Введите размер " << hint << " (1-" << maxSize << "): ";
			cin >> size;

			if (cin.fail() || size <= 0 || size > maxSize) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Ошибка ввода. Повторите.\n";
			}
		} while (size <= 0 || size > maxSize);

		return size;
	}

	// T.2 - Заполнение массива с клавиатуры
	void matrixFillKeyboard(vector<vector<int>>& matrix, const int rows, const int cols) {
		for (int i{}; i < rows; ++i) {
			for (int j{}; j < cols; ++j) {
				cout << "matrix[" << i << "][" << j << "] = ";
				cin >> matrix[i][j];
			}
		}
	}

	// T.2 - Заполнение массива случайными числами
	void matrixFillRandom(vector<vector<int>>& matrix, const int rows, const int cols, const int min, const int max) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(min, max);

		for (int i{}; i < rows; ++i) {
			for (int j{}; j < cols; ++j) {
				matrix[i][j] = dist(gen);
			}
		}
	}

	// T.2 - Заполнение массива из файла
	void matrixFillFile(vector<vector<int>>& matrix, const int rows, const int cols, const string& fileName) {
		ifstream file(fileName);

		if (!file.is_open()) {
			cout << "Не удалось открыть файл.\n";
			return;
		}

		for (int i{}; i < rows; ++i) {
			for (int j{}; j < cols; ++j) {
				if (!(file >> matrix[i][j])) {
					cout << "В файле недостаточно данных.\n";
					matrix[i][j] = 0;
				}
			}
		}
	}

	// T.3 - Вывод массива на экран
	void matrixPrint(const vector<vector<int>>& matrix, const int rows, const int cols) {
		cout << endl << "Матрица:\n";

		for (int i{}; i < rows; ++i) {
			for (int j{}; j < cols; ++j) {
				cout << matrix[i][j] << '\t';
			}

			cout << "\n";
		}
	}

	// T.4 / I.1 - Сумма и количество положительных элементов ниже второстепенной диагонали
	void columnPositiveStatsBelowSecondaryDiagonal(
		const vector<vector<int>>& matrix,
		const int rows,
		const int cols,
		vector<int>& sums,
		vector<int>& counts
	) {
		for (int j{}; j < cols; ++j) {
			sums[j] = 0;
			counts[j] = 0;

			for (int i{}; i < rows; ++i) {
				if (i + j > cols - 1 && matrix[i][j] > 0) {
					sums[j] += matrix[i][j];
					++counts[j];
				}
			}
		}
	}

	// T.4 / I.2 - Проверка строки из положительных элементов
	bool hasPositiveOnlyRow(const vector<vector<int>>& matrix, const int rows, const int cols) {
		for (int i{}; i < rows; ++i) {
			bool positiveOnly{true};

			for (int j{}; j < cols; ++j) {
				if (matrix[i][j] <= 0) {
					positiveOnly = false;
					break;
				}
			}

			if (positiveOnly) {
				return true;
			}
		}

		return false;
	}

	// T.5 - Вывод результата в файл
	void saveResults(
		const vector<int>& sums,
		const vector<int>& counts,
		const bool hasPositiveRow,
		const int cols,
		const string& fileName
	) {
		ofstream file(fileName);

		if (!file.is_open()) {
			cout << "Не удалось открыть файл результатов.\n";
			return;
		}

		file << "Суммы по столбцам:\n";

		for (int i{}; i < cols; ++i) {
			file << sums[i] << ' ';
		}

		file << "\nКоличество элементов:\n";

		for (int i{}; i < cols; ++i) {
			file << counts[i] << ' ';
		}

		file << "\nНаличие строки только из положительных элементов: ";
		file << (hasPositiveRow ? "Да" : "Нет") << "\n";
	}

	void mainMatrix() {

		message("intro");

		// T.1 - Ввод размеров матрицы
		const int rows{matrixSizeInput("строки")};
		const int cols{matrixSizeInput("столбца")};

		vector<vector<int>> matrix(rows, vector<int>(cols));

		int choice{};

		cout << endl << "Выберите способ заполнения:\n";
		cout << "1 - С клавиатуры\n";
		cout << "2 - Случайными числами\n";
		cout << "3 - Из файла\n";
		cout << endl << "Ваш выбор: ";
		cin >> choice;

		// T.2 - Выбор способа заполнения массива
		switch (choice) {
			case 1:
				matrixFillKeyboard(matrix, rows, cols);
				break;

			case 2:
				matrixFillRandom(matrix, rows, cols, -10, 10);
				break;

			case 3:
				matrixFillFile(matrix, rows, cols, iFile);
				break;

			default:
				cout << "Некорректный выбор.\n";
				return;
		}

		// T.3 - Вывод массива
		matrixPrint(matrix, rows, cols);

		vector<int> sums(cols);
		vector<int> counts(cols);

		// T.4 / I.1 - Обработка столбцов
		columnPositiveStatsBelowSecondaryDiagonal(matrix, rows, cols, sums, counts);

		cout << endl << "Суммы элементов:\n";
		for (int i{}; i < cols; ++i) {
			cout << sums[i] << ' ';
		}

		cout << endl << "\nКоличество элементов:\n";
		for (int i{}; i < cols; ++i) {
			cout << counts[i] << ' ';
		}

		cout << "\n";

		// T.4 / I.2 - Проверка строк
		const bool hasPositiveRow{hasPositiveOnlyRow(matrix, rows, cols)};

		cout << endl << "Строка только из положительных элементов: ";
		cout << (hasPositiveRow ? "Да" : "Нет") << "\n";

		// T.5 - Сохранение результатов
		saveResults(sums, counts, hasPositiveRow, cols, oFile);

	}

	void index() {

		mainMatrix();

	}

}