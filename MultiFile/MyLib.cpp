#include "MyLib.h"

Studentas::Studentas() : vardas("Testas"), pavarde("TestasTestas"), paz({1,5,8,7,7}), egzaminas(10), rezultatas(0), rezultatasMediana(0) {
    rez();
    rezMediana();
}

Studentas::Studentas(string A, string B, vector<int> C, int D)
    : vardas(A), pavarde(B), paz(C), egzaminas(D), rezultatas(0), rezultatasMediana(0) {
    rez();
    rezMediana();
}

Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde), paz(other.paz), egzaminas(other.egzaminas),
      rezultatas(other.rezultatas), rezultatasMediana(other.rezultatasMediana) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        paz = other.paz;
        egzaminas = other.egzaminas;
        rezultatas = other.rezultatas;
        rezultatasMediana = other.rezultatasMediana;
    }
    return *this;
}

Studentas::~Studentas() {}

void Studentas::rez() {
    double vid = 0;
    if (!paz.empty()) {
        vid = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    }
    rezultatas = 0.4 * vid + 0.6 * egzaminas;
}

void Studentas::rezMediana() {
    if (paz.empty()) {
        rezultatasMediana = 0;
        return;
    }
    vector<int> temp = paz;
    sort(temp.begin(), temp.end());
    double mediana = 0;
    size_t n = temp.size();
    if (n % 2 == 0) {
        mediana = (temp[n / 2 - 1] + temp[n / 2]) / 2.0;
    } else {
        mediana = temp[n / 2];
    }
    rezultatasMediana = 0.4 * mediana + 0.6 * egzaminas;
}

std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << left << setw(15) << s.pavarde << setw(10) << s.vardas
       << right << fixed << setprecision(2)
       << setw(10) << s.rezultatas << setw(10) << s.rezultatasMediana;
    return os;
}

std::istream& operator>>(std::istream& is, Studentas& s) {
    s.paz.clear();
    is >> s.pavarde >> s.vardas;
    int nd;
    for (int i = 0; i < 5; i++) {
        is >> nd;
        s.paz.push_back(nd);
    }
    is >> s.egzaminas;
    s.rez();
    s.rezMediana();
    return is;
}

void Studentas::generuotiAtsitiktinai(Studentas& s, int nPazymiu) {
    static std::default_random_engine gen((std::random_device())());
    std::uniform_int_distribution<int> dist(1, 10);

    s.vardas = "Vardas" + std::to_string(dist(gen));
    s.pavarde = "Pavarde" + std::to_string(dist(gen));

    s.paz.clear();
    for (int i = 0; i < nPazymiu; i++) {
        s.paz.push_back(dist(gen));
    }
    s.egzaminas = dist(gen);
    s.rez();
    s.rezMediana();
}

bool nuskaitytiIsFailo(const std::string& failoVardas, std::vector<Studentas>& grupe) {
    std::ifstream in(failoVardas);
    if (!in.is_open()) return false;

    grupe.clear();
    std::string eilute;
    std::getline(in, eilute);

    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        Studentas s;
        iss >> s;
        grupe.push_back(s);
    }
    return true;
}
