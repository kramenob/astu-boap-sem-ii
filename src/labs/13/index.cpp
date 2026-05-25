/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 13
 */


#include "index.hpp"

namespace lw13 {

	static const string appDir = string(getenv("HOME")) + "/Documents/BoapSemTwo/";

	/**
	 * Создание файла с числами из клавиатуры
	 */
    static bool createFromKeyboard(const char* filename, int n) {
		// open output file for writing numbers (overwrite)
        ofstream fof(filename, ios::trunc);

		// return false if file failed to open
        if (!fof) {
            cout << endl << "🚨 Файл НЕ создан" << endl;
            exit(1);
		};

		// prompt user to enter numbers
        cout << "Введите " << n << " целых числа через пробел: ";

		// loop through required amount of numbers
        for (int i = 0; i < n; ++i) {

			// read number from keyboard and write to file
            int x; cin >> x; fof << x << " ";

        };

		// file successfully created and filled
        return true;
    }

	/**
	 * Создание файла с случайными числами
	 */
    static bool createRandom(const char* filename, int n, int a, int b) {

		// open output file for writing random numbers (overwrite)
        ofstream fof(filename, ios::trunc);

		// return false if file failed to open
        if (!fof) {
            cout << endl << "🚨 Файл НЕ создан" << endl;
            exit(1);
		};

		// initialize random number generator
        mt19937 gen((unsigned)time(nullptr));  // random generator seeded with current time
        uniform_int_distribution<> dist(a, b); // integer distribution in range [a, b]

		// generate and write numbers to file
        for (int i = 0; i < n; ++i) {
			fof << dist(gen) << " ";
		};

		// file successfully created and filled
        return true;
    }

	/**
	 * Функция для вывода содержимого текстового файла
	 */
    static void Print_f(const char filename[]) {
		// open file for reading
        ifstream fif(filename);

		// handle missing file
        if (!fif) {
            cout << endl << "🚨 Файл НЕ создан" << endl;
            exit(1);
		};

		// print header text
		cout << endl << "Содержимое файла: ";

		// read numbers and print to console
        int x;
        while (fif >> x) cout << x << " ";

		// end line after printing
        cout << endl;
    }

    /**
     * Read integer with optional range validation.
     * If minVal <= maxVal, enforce [minVal, maxVal]; else, just validate integer input.
     * Handles invalid input (characters, empty lines) robustly.
     */
    static int input(const char* prompt, int minVal = 1, int maxVal = -1) {
        int n = 0;
        while (true) {
            cout << endl << prompt; // prompt user for input
            string line;            // input line
            getline(cin, line);     // read entire line

			// check empty input
            if (line.empty()) {
                cout << "⚠️ Пустой ввод. Введите целое число." << endl;
                continue;
            };

			// check if whole line is a valid integer
            stringstream ss(line);
            if (!(ss >> n) || !(ss.eof())) {
                cout << "⚠️ Неверный ввод. Введите целое число." << endl;
                continue;
            };

			// optional range check
            if (minVal <= maxVal && (n < minVal || n > maxVal)) {
                cout << "⚠️ Число должно быть в диапазоне [" << minVal << ", " << maxVal << "]" << endl;
                continue;
            };

			// all checks passed, return valid input
            return n;
        }
    }

	/**
	 * Задание 1
	 */
	void task01() {
		// Print task statement
		message("task01");

		// flush leftover newline before reading sequence length
        int n = input("Введите длину последовательности: ");

		// choose input method
        int choice = input("Нотация:\n 1. Клавиатура;\n 2. Случайные числа\nВведите метод ввода [1-2]: ", 1, 2);

        bool ok = false; // flag of successful file creation

        if (choice == 1) {
			ok = createFromKeyboard((appDir + "Input.txt").c_str(), n); // create file using keyboard input
		} else {
            int a = input("Введите a: ");                               // read validated a
            int b = input("Введите b: ");                               // read validated b
            if (a > b) swap(a, b);                                      // ensure correct range order
            ok = createRandom((appDir + "Input.txt").c_str(), n, a, b); // create file using random generator
        };

		// terminate program with error code 1
        if (!ok) {
            cout << endl << "🚨 Файл НЕ создан" << endl;
            exit(1);
        };

		// print result status
        cout << endl << "Файл создан" << endl;

		// wait for user input
		waitForEnter();
	}

	/**
	 * Задание 2
	 */
	void task02() {
		// Print task statement
		message("task02");

        Print_f((appDir + "Input.txt").c_str()); // call file print helper

		// wait for user input
		waitForEnter();
	}

	/**
	 * Задание 3
	 */
	void task03() {
		// Print task statement
		message("task03");

		// open input and output files
        ifstream fif( ( appDir + "Input.txt"  ).c_str()                           ); // open text file for reading
        ofstream fof( ( appDir + "Output.bin" ).c_str(), ios::binary | ios::trunc ); // open binary file for writing (overwrite)

		// handle file open errors
        if (!fif || !fof) {
			cout << endl << "Ошибка файла" << endl;
			return;
		};

		// variable for numbers and counter
        int x, count = 0;

		// write integers to binary file
        while (fif >> x) {
			fof.write( (char*)&x, sizeof(x) );
			count++;
		};

		// print number of written elements
        cout << endl << "Элементов записано: " << count << endl;

		// wait for user input
		waitForEnter();
	}

	/**
	 * Задание 4
	 */
	void task04() {
		// Print task statement
		message("task04");

		// open binary file for reading
        ifstream fif( ( appDir + "Output.bin" ).c_str(), ios::binary );

		// handle missing file
        if (!fif) {
			cout << endl << "Бинарный файл не найден" << endl;
			return;
		};

		// header text
		cout << endl << "Содержимое бинарного файла: ";

		// read integers from binary file and print
        int x;
        while ( fif.read( (char*)&x, sizeof(x) ) ) {
			cout << x << " ";
		};

		// end line after printing
        cout << endl;

		// wait for user input
		waitForEnter();
	}

	/**
	 * Методические указания
	 */
	void task() {
		// Print intro for base task
		message("intro");

		/** Задание 1 */
		task01();

		/** Задание 2 */
		task02();

		/** Задание 3 */
		task03();

		/** Задание 4 */
		task04();

	}

	/**
	 * Задание для самостоятельного решения
	 * Вариант 3
	 */
	void indy() {
		// Print intro for independent task
		message("inditro");

        int d = 10, a = 0, b = 100;            // parameters for random generation
        mt19937 gen((unsigned)time(nullptr));  // random generator
        uniform_int_distribution<> dist(a, b); // distribution for random integers

        ofstream fof((appDir + "f.txt").c_str(), ios::trunc);              // create source file f (overwrite)
        for (int i = 0; i < d; ++i) fof << dist(gen) << " "; // fill file with random numbers
        fof.close();                                         // close file f

		/**
		 * Read user input for filtering criteria
		 */
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline
        int m = input("Введите m: ");                        // read validated m
        int n = input("Введите n: ");                        // read validated n

		/**
		 * Define input and output file streams
		 *  - fif: f-input-file  `f.txt`
		 *  - gof: g-output-file `g.txt`
		 */
        ifstream fif( ( appDir + "f.txt" ).c_str() ); // open source file
        ofstream gof( ( appDir + "g.txt" ).c_str() ); // open destination file

		/**
		 * Filter numbers from f.txt and write to g.txt
		 */
        int i;
		while (fif >> i) {                  // while fif give valid numbers
			if (i % m == 0 && i % n != 0) { // if i is divisible by m and not by n
				gof << i << " ";            // write i to g.txt
			};
		};
        cout << endl << "Результат сохранен в g.txt" << endl; // notify about completion
	}

	/**
	 * Work entrypoint
	 */
	void index() {

		// create directory if it doesn't exists
		struct stat st = {0};
		if (stat(appDir.c_str(), &st) == -1) {
			mkdir(appDir.c_str(), 0755);
		}

		// flush leftover input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		/**
		 * Методические указания
		 */
		task();

		/**
		 * Задание для самостоятельного решения
		 */
		indy();

	}

}
