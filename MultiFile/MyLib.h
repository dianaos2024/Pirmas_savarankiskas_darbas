#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

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
    double getRezultatas() const { return rezultatas; }
    ~Studentas();
    friend std::istream& operator>>(std::istream& is, Studentas& s);
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    std::string getVardas() const { return vardas; };
    std::string getPavarde() const { return pavarde; };
    void generuotiAtsitiktinai(Studentas& s, int nPazymiu = 5);
    void generuotas_failas(int);
};

bool nuskaitytiIsFailo(const std::string& failoVardas, std::vector<Studentas>& grupe);
