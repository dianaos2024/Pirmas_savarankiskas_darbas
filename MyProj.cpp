#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
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
class Studentas{
    string vardas;
    string pavarde;
    vector<int>paz;
    int egzaminas;
    double rezultatas;
public:
    Studentas(){
        vardas="Testas";
        pavarde="TestasTestas";
        paz={1,5,8,7,7,4,8,9,6,3,9};
        egzaminas=10; 
        rez();
        }
    Studentas(string A,string B, vector<int> C, int D){
        vardas=A;
        pavarde=B;
        paz=C;
        egzaminas=D; 
        rez();
        }
    Studentas(const Studentas& other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        paz = other.paz;
        egzaminas = other.egzaminas;
        rezultatas = other.rezultatas;
    }
    Studentas& operator=(const Studentas& other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = other.paz;
            egzaminas = other.egzaminas;
            rezultatas = other.rezultatas;
        return *this;
    }
    void rez(){
            rezultatas= accumulate(paz.begin(), paz.end(), 0) / paz.size() *0.4 +egzaminas*0.6;
    }
    ~Studentas(){
            vardas.clear();
            pavarde.clear();
            paz.clear();
            egzaminas=0; 
            rezultatas=0;
    }
    friend std::istream& operator>>(std::istream& is, Studentas& s) {
            cout << "Vardas: ";
            is >> s.vardas;
            cout << "Pavardė: ";
            is >> s.pavarde;

            int paz;
            for (int i = 0; i < 5; i++) {
                is >> paz;
                s.paz.push_back(paz);
            }
            cout << "Egzaminas: ";
            is >> s.egzaminas;
            s.rez();
            return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) {
            os << std::left << std::setw(15) << s.pavarde << std::setw(10) << s.vardas << std::right << std::fixed << std::setprecision(2) << std::setw(20) << s.rezultatas;
            return os;
    }
};

int main() {
    vector<Studentas> grupe;

    for (int i = 0; i < 2; i++) {
        Studentas s;
        cin >> s;
        grupe.push_back(s);
    }

    cout << "Pavardė       Vardas           Galutinis (Vid.)\n";
    cout << "----------------------------------------------\n";

    for (const auto& s : grupe) {
        cout << s << endl;
    }
    return 0;
};
