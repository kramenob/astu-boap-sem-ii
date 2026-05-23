/**
 * @file   bootstrap.hpp
 * @brief  Header file for bootstrap
 */

#ifndef BOOTSTRAP_HPP
#define BOOTSTRAP_HPP

/**
 * Include this header file only once per compilation unit,
 * no matter how many times it’s #included
 */
#pragma once

/** Standard library headers */
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <locale>
#include <limits>
#include <map>
#include <functional>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <sys/stat.h>
#include <filesystem>
#include <cctype>
#include <codecvt>
#include <cwctype>
#include <algorithm>

/** Utility headers */
#include "utils/index.hpp"

/** Works headers */
#include "labs/index.hpp"
#include "sels/index.hpp"

/** Using namespace std */
using namespace std;

using Handler = function<void()>;

#endif // BOOTSTRAP_HPP
