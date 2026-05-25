/**
 * @author Болотин Максим Владимирович
 * @brief  Лабораторная работа 15
 */

#include "index.hpp"

namespace lw15 {

	static const string appDir  = string(getenv("HOME")) + "/Documents/BoapSemTwo";
	static const string iFile = ( appDir + "/15/Input.txt"  );
	static const string oFile = ( appDir + "/15/Output.txt" );

	/**
	 * 
	 */
    // Checks if a word starts and ends with the same letter (case-insensitive), supports UTF-8 Cyrillic
    bool fu(const wstring& word) {
        if (word.empty()) return false;

        // Strip punctuation from start and end
        size_t start = 0;
        size_t end = word.size();
        while (start < end && iswpunct(word[start])) ++start;
        while (end > start && iswpunct(word[end - 1])) --end;
        if (start >= end) return false;

        wstring trimmed = word.substr(start, end - start);

        wchar_t first = towlower(trimmed.front());
        wchar_t last  = towlower(trimmed.back());

        return first == last;
    }

    void indy() {

		// create directory if it doesn't exists
		struct stat st = {0};
		if (stat(  ( appDir + "/15" ).c_str(), &st) == -1) {
			mkdir( ( appDir + "/15" ).c_str(), 0755);
		}

        message("intro");

        // Open input file
        wifstream fif(iFile);
        if (!fif.is_open()) {
            wcout << L"Не удалось открыть входной файл" << endl;
            exit(1);
        }

        // Prepare output file
        wofstream fof(oFile);
        if (!fof.is_open()) {
            wcout << L"Не удалось создать выходной файл" << endl;
            exit(1);
        }

        wstring word;
        while (fif >> word) {
            if (fu(word)) {
				wcout << word << endl; // Debug output
                fof << word << endl;
            }
        }
		exit(0);
    }

	void index() {

		indy();

	}

}
