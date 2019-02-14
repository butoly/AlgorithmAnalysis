#pragma once
#include "Header.h"

using namespace std;

vector <vector<int>> multiplyStandart(vector <vector <int>> aMatrix, vector <vector <int>> bMatrix, int nA, int mA, int nB, int mB);
vector <vector<int>> multiplyVinograd(vector <vector <int>> aMatrix, vector <vector <int>> bMatrix, int nA, int mA, int nB, int mB);
vector <vector<int>> multiplyVinogradImprove(vector <vector <int>> aMatrix, vector <vector <int>> bMatrix, int nA, int mA, int nB, int mB);