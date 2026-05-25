/**
 * @author Болотин Максим Владимирович
 * @brief  Utility functions to everywhere usage
 */

#include <iostream>
#include "index.hpp"

void printHeader() {

cout << \
R"(
Автор:   Болотин Максим Владимирович
Группа:  ДИНРб-11/2
Вариант: 3

)";

}

void waitForEnter() {
    cout << endl << "Enter для продолжения...";
    cin.get();
	return;
}
