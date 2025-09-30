#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::accumulate;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::sort;
class Studentas{
    string vardas;
    string pavarde;
    vector<int>paz;
    int egzaminas;
    double rezultatas;
    double rezultatasMediana;
public:
    Studentas();
    Studentas(string A,string B, vector<int> C, int D);
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    void rez();
    void rezMediana();
    ~Studentas();
    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    void generuotiAtsitiktinai(Studentas& s, int nPazymiu = 5);
};
