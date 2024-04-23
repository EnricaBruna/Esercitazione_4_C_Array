#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    string inFile = "./data.csv";
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportData (inFile, S, n, w, r))
    {
        cerr<< " The data could not be imported from the file"<<endl;
        return -1;
    }

    double ROR;
    double V;
    RateOfReturn(S, n, w, r, ROR, V);

    ExportData(cout, S, n, w, r, ROR, V);

    string outFile = "./result.txt";
    ofstream file;
    file.open(outFile);

    if (file.fail())
    {
        cerr<< "The output file could not be opened"<<endl;
        return -1;
    }
    else
    {
        ExportData (file, S, n, w, r, ROR, V);
    }

    file.close();

    delete[] w;
    delete[] r;

    return 0;
}

