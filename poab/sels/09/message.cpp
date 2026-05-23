/**
 * @author Болотин Максим Владимирович
 * @brief  Messages for Самостоятельная работа 09
 */

#include "index.hpp"

namespace sw09 {

	void message(const string& key) {
		if (key == "intro") {
			cout << R"(
# Самостоятельная работа №9

## Задание:



Человекочитаемый вид: https://github.com/kramenob/astu-boap-sem-02/blob/main/docs/sels/09/task-statement.md

)";
		} else if (key == "else") {
			cout << R"(
## Индивидуальное задание:

...

)";
		}

		return;
	}

}
