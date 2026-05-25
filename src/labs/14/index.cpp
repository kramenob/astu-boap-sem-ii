/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 14
 */

#include "index.hpp"

namespace lw14 {

	static const string appDir = string(getenv("HOME")) + "/Documents/BoapSemTwo/14/";

    // Task 2: normalize spaces and punctuation
    string normalizeSpaces(const string &input) {
        string result;
        bool prevSpace = false;
        const string punct = ".,:;!?";

        for (size_t i = 0; i < input.size(); ++i) {
            char c = input[i];

            if (isspace((unsigned char)c)) {
                // mark possible space only if result does not already end with space
                if (!result.empty() && result.back() != ' ') {
                    prevSpace = true;
                }
                continue;
            }

            // remove space before punctuation (but keep space if previous char is punctuation)
            if (punct.find(c) != string::npos) {

                if (result.size() >= 2 && result.back() == ' ' && punct.find(result[result.size() - 2]) == string::npos) {
                    result.pop_back();
                }

                result.push_back(c);
                // ensure exactly one space after punctuation
                if (result.back() != ' ' && (result.size() == 1 || result[result.size() - 1] != ' ')) {
                    result.push_back(' ');
                }

                prevSpace = false;
                continue;

            }

            if (prevSpace && !result.empty() && result.back() != ' ') {
                result.push_back(' ');
            }

            result.push_back(c);
            prevSpace = false;
        }

        // trim trailing space
        if (!result.empty() && result.back() == ' ') result.pop_back();
        return result;
    }

    // Task 4: process Input.txt -> Output.txt
    void processFile(const string &_fif, const string &_fof) {

        ifstream fif((appDir + _fif).c_str());
        ofstream fof((appDir + _fof).c_str());

        if (!fif.is_open()) {
            cout << "Не удалось открыть Input.txt" << endl;
            return;
        }

        // write UTF-8 BOM so Output.txt opens correctly
        fof << "\xEF\xBB\xBF";

        string line;
        while (getline(fif, line)) {
            fof << normalizeSpaces(line) << endl;
        }

    }

    // Task 5: find words containing substring
    bool findWordsWithSubstring(const string &filename, const string &word) {

        ifstream fif((appDir + filename).c_str());
        if (!fif.is_open()) {
            cout << "Не удалось открыть Output.txt" << endl;
            return false;
        }

        bool found = false;
        string token;
        while (fif >> token) {
            if (token.find(word) != string::npos) {
                cout << token << endl;
                found = true;
            }
        }
        return found;

    }

	/**
	 * Task 1
	 * 
	 */
	void task01(const string &line) {
        message("task01");

        cout << "Вы ввели: "     << line        << endl;
        cout << "Длина строки: " << line.size() << endl;

		waitForEnter();
	}

	/**
	 * Task 2
	 * 
	 */
	void task02(const string &line) {
        message("task02");

		string normalized = normalizeSpaces(line);
		cout << "Нормализовано: " << normalized        << endl;
		cout << "Новая длина: "   << normalized.size() << endl;

		waitForEnter();
	}

	/**
	 * Task 3
	 * Generate Output.txt
	 */
	void task03(const string &line) {
        message("task03");

        // Generate Input.txt automatically (<=10 lines, <=60 chars each)
        vector<string> generated = {
            "Ветер    тихо   шепчет   у   окна ,",
            "Ночь приходит ,медленно   и   плавно .",
            "Город спит ,но   где-то   вдалеке",
            "Свет фонарей   горит   так   странно .",
            "Мысли   бродят   в   тишине   пустой ,",
            "Словно   тени   ищут   продолженье .",
            "И рассвет   однажды   принесёт",
            "Новое ,простое   вдохновенье ."
        };

        ofstream out((appDir + "Input.txt").c_str());
        if (!out.is_open()) {
            cout << "Не удалось создать Input.txt" << endl;
            waitForEnter();
            return;
        }

        // write UTF-8 BOM so editors detect encoding correctly
        out << "\xEF\xBB\xBF";

        // Write lines without byte-truncation (UTF-8 safe)
        for (const auto &l : generated) {
            out << l << endl;
        }

        cout << "Файл Input.txt успешно создан" << endl;
        waitForEnter();
	}

	/**
	 * Task 4
	 */
	void task04() {
        message("task04");

        processFile("Input.txt", "Output.txt");
        cout << "Файл обработан: Input.txt -> Output.txt" << endl;

		waitForEnter();
	}

	/**
	 * Task 5
	 */
	void task05() {
        message("task05");

        string word;
        cout << "Введите слово для поиска: ";
        cin  >> word;

        if (!findWordsWithSubstring("Output.txt", word)) {
            cout << "Слов не найдено" << endl;
        }

		waitForEnter();
	}

    void index() {

		// create directory if it doesn't exists
		struct stat st = {0};
		if (stat(appDir.c_str(), &st) == -1) {
			mkdir(appDir.c_str(), 0755);
		}

        message("intro");

		/**
		 * Read line from user for next usage
		 */
        cout << "Введите строку (допускаются пробелы): ";
        string line;        // define line as string
        getline(cin >> ws, line); // wait for user input and save to line

		// Task 1
		task01(line);

        // Task 2
		task02(line);

        // Task 3
		task03(line);

        // Task 4
		task04();

        // Task 5
		task05();
    }

}
