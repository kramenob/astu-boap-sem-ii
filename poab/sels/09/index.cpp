/**
 * @author Болотин Максим Владимирович
 * @brief  Самостоятельная работа 09
 */

#include "index.hpp"

namespace sw09 {

	/**
	 * Задача 1
	 * Замена символов в строке
	 */
	void task01() {
		message("task01");

		string text;
		char ch1;
		char ch2;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите строку: ";
		getline(cin, text);

		cout << endl << "Введите символ, который нужно заменить: ";
		cin  >> ch1;

		cout << "Введите символ, на который нужно заменить: ";
		cin  >> ch2;

		for (int i = 0; i < text.length(); i++) {
			if (text[i] == ch1) {
				text[i] = ch2;
			}
		}

		cout << endl << "Результат замены символов: ";
		cout << text << endl;
	}

	/**
	 * Разворот одного слова
	 */
	string reverseWord(string word) {
		reverse(word.begin(), word.end());
		return word;
	}

	/**
	 * Задача 2
	 * Расшифровка текста, в котором слова записаны наоборот
	 */
	void task02() {
		message("task02");

		string encryptedText;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите зашифрованный текст: ";
		getline(cin, encryptedText);

		stringstream stream(encryptedText);
		string word;

		cout << endl << "Расшифрованное сообщение: ";

		while (stream >> word) {
			cout << reverseWord(word) << " ";
		}

		cout << endl;
	}

	/**
	 * Точка входа
	 */
	void index() {

		task01();

		task02();

	}

}
