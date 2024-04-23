#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportData (const string& inFilePath, double& S, size_t& n, double*& w, double *& r)
{
    ifstream file;
    file.open(inFilePath);
    if(file.fail())
    {
        cerr<< "The input file could not be opened" <<endl;
        return false;
    }

    string weight;
    string rate;
    string line;
    string word;
    istringstream strW;
    istringstream strR;
    int i = 1;

    while(!file.eof())
    {
        if(i==1)
        {
            getline(file,word, ';');
            getline(file,line);
            istringstream strS;
            strS.str(line);
            strS >> S;
        }
        else if(i==2)
        {
            getline(file,word, ';');
            getline(file,line);
            istringstream strN;
            strN.str(line);
            strN >> n;
            w = new double[n];
            r = new double[n];
        }

        else if(i==3)
        {
            getline(file,word);
        }
        else
        {
            getline(file,weight, ';');
            getline(file,rate);
            strW.str(weight);
            strR.str(rate);
            strW >> w[i-4];
            strR >> r[i-4];
            strW.clear();
            strR.clear();
        }
        i = i+1;

    }

    file.close();
    return true;
}

void RateOfReturn (const double& S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V)
{
    V = 0;
    for (unsigned int j=0; j<n; j++)
        V += S*w[j]*(1+r[j]);
    rateOfReturn = (V/S) - 1;
}

void ExportData (ostream& out, const double & S, const size_t& n, const double* const& w, const double* const& r, double& rateOfReturn, double& V)
{
    out<< fixed<< showpoint<< setprecision(2)<< "S = "<< S << ", n = "<< n<< endl;

    out<< "w = "<< ArrayToString(n,w)<< endl;

    out<< "r = "<< ArrayToString(n,r)<< endl;

    out<< fixed<< showpoint<< setprecision(4)<< "Rate of return of the portfolio: "<< rateOfReturn<< endl;

    out<< fixed<< showpoint<< setprecision(2)<< "V: "<< V<< endl;
}

string ArrayToString (const size_t& n, const double* const& v)
{
    ostringstream toString;
    toString << "[ ";
    for (unsigned int k = 0; k<n; k++)
        toString<< v[k]<< " ";
    toString << "]";

    return toString.str();
}
