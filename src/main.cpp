/**
 *
 * @author  Болотин Максим Владимирович
 * @group   ДИНРб-11/2
 * @variant 3
 *
 * @brief   Entrypoint file. Magic starts here.
 *
 */

/** Everything defined here */
#include "bootstrap.hpp"

/** Main function */
int main() {

	setlocale(LC_ALL, "");

    printHeader();

    map<int, Handler> labs = {
        { 9, lw09::index},
        {10, lw10::index},
        {11, lw11::index},
        {12, lw12::index},
        {13, lw13::index},
        {14, lw14::index},
        {15, lw15::index},
        {16, lw16::index},
        {17, lw17::index}
    };

	map<int, Handler> sels = {
		{ 6, sw06::index},
		{ 7, sw07::index},
		{ 8, sw08::index},
		{ 9, sw09::index}
	};

	cout << "Доступные виды работ:" << endl
		 << " 1. Лабораторная;"     << endl
		 << " 2. Самостоятельная;"  << endl
		                            << endl;

	int mode = 0;
	while (mode < 1 || mode > 2) {
		cout << "Выберите вид работы [1-2]: ";
		cin  >>  mode;
	}
 
	auto& work = (mode == 1) ? labs : sels;
    
    int choice = 0;
	while (work.find(choice) == work.end()) {
		cout << "Выберите номер работы" << (mode == 1 ? " [9-17]" : " [6-9]") << ": ";
		cin  >>  choice;
	}

    auto it = work.find(choice);

    if (it != work.end())
        it->second();
    else
        cout << "Работа не найдена!" << endl;

	cout << endl;
    return 0;
}
