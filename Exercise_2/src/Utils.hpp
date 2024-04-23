#pragma once
#include <iostream>

using namespace std;


bool ImportData (const string& inFilePath, double& S, size_t& n, double*& w, double *& r);

void RateOfReturn (const double& S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V);

void ExportData (ostream& out, const double & S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V);

string ArrayToString (const size_t& n, const double* const& v);
