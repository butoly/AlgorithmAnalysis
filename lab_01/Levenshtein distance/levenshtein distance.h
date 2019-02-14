#pragma once

#include "pch.h"


#ifndef LEVENSHTAIN_H
#define LEVENSHTAIN_H

int min_3(int a, int b, int c);
int levenshtein_distance(const std::string & src, const std::string & dst);
int damerau_levenshtein_distance(const std::string & src, const std::string & dst);
int recur_Lev(const std::string& src, const std::string& dst);

#endif //LEVENSHTEIN_H