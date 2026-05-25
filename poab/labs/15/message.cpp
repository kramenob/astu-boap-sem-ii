/**
 * @author Болотин Максим Владимирович
 * @brief Messages for Лабораторная работа 15
 */

#include "index.hpp"

namespace lw15 {

	void message(const string& key) {
		if (key == "intro") {
			cout << R"(
Лабораторная работа №15

Задание:

Написать функцию (при необходимости функций может быть несколько) для обработки файла в соответствии с заданием своего варианта.

`Вариант 3`

Занести в новый файл слова, которые начинаются и оканчиваются одной и той же буквой;

Человекочитаемый вид: https://github.com/kramenob/astu-boap-sem-ii/blob/main/docs/labs/15/task-statement.md

)";
		}

		return;
	}

}
