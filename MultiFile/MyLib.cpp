#include "MyLib.h"

    Studentas::Studentas(){
        vardas="Testas";
        pavarde="TestasTestas";
        paz={1,5,8,7,7,4,8,9,6,3,9};
        egzaminas=10;
        rez();
        rezMediana();
        }
    Studentas::Studentas(string A,string B, vector<int> C, int D){
        vardas=A;
        pavarde=B;
        paz=C;
        egzaminas=D;
        rez();
        rezMediana();
        }
    Studentas::Studentas(const Studentas& other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        paz = other.paz;
        egzaminas = other.egzaminas;
        rezultatas = other.rezultatas;
        rezultatasMediana = other.rezultatasMediana;
    }
    Studentas& Studentas::operator=(const Studentas& other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            paz = other.paz;
            egzaminas = other.egzaminas;
            rezultatas = other.rezultatas;
            rezultatasMediana = other.rezultatasMediana;
        return *this;
    }
    void Studentas::rez(){
            rezultatas= accumulate(paz.begin(), paz.end(), 0) / paz.size() *0.4 +egzaminas*0.6;
    }
    void Studentas::rezMediana() {
        std::sort(paz.begin(), paz.end());
        size_t n = paz.size();
        double mediana;
        if (n % 2 == 0) {
            mediana = (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
        } else {
            mediana = paz[n / 2];
        }
        rezultatasMediana = 0.4 * mediana + 0.6 * egzaminas;
    }
    Studentas::~Studentas(){
            vardas.clear();
            pavarde.clear();
            paz.clear();
            egzaminas=0;
            rezultatas=0;
            rezultatasMediana = 0;
    }
   std::istream& operator>>(std::istream& is, Studentas& s) {
            cout << "Vardas: ";
            is >> s.vardas;
            cout << "Pavarde: ";
            is >> s.pavarde;

            int paz;
            for (int i = 0; i < 5; i++) {
                is >> paz;
                s.paz.push_back(paz);
            }
            cout << "Egzaminas: ";
            is >> s.egzaminas;
            s.rez();
            s.rezMediana();
            return is;
    }

    std::ostream& operator<<(std::ostream& os, const Studentas& s) {
            os << std::left << std::setw(15) << s.pavarde << std::setw(10) << s.vardas << std::right << std::fixed << std::setprecision(2) << std::setw(20) << s.rezultatas << std::setw(20) << s.rezultatasMediana;
            return os;
    }
    void Studentas::generuotiAtsitiktinai(Studentas& s, int nPazymiu) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> dist(1, 10);

        static const std::vector<std::string> vardai = {
            "Jonas", "Marius", "Lukas", "Tomas", "Paulius",
            "Dovydas", "Simonas", "Martynas", "Arnas", "Dominykas"
        };
        static const std::vector<std::string> pavardes = {
            "Petrauskas", "Kazlauskas", "Sabonis", "Jonaitis",
            "Pavardenis", "Mockus", "Butkus", "Zukauskas", "Jankauskas"
        };

        std::uniform_int_distribution<> vDist(0, vardai.size() - 1);
        std::uniform_int_distribution<> pDist(0, pavardes.size() - 1);
        s.vardas = vardai[vDist(gen)];
        s.pavarde = pavardes[pDist(gen)];

        s.paz.clear();
            for (int i = 0; i < nPazymiu; i++) {
                s.paz.push_back(dist(gen));
            }
        s.egzaminas = dist(gen);
        s.rez();
        s.rezMediana();
    }

    void Studentas::generuotas_failas(int sk) {
        std::stringstream ss;
        ss << "studentai_" << sk << ".txt";
        string failas = ss.str();
        std::ofstream outputFile(failas);
        outputFile << "Pavarde\tVardas\tND1\tND2\tND3\tND4\tND5\tEgzaminas\n";
            auto generateGrade = []() {
                return rand() % 11;
            };
        struct Studentas {
        std::string vardas;
        std::string pavarde;
        int nd1, nd2, nd3, nd4, nd5, egz;
        double getGalutinisBalas() const {
        return (nd1 + nd2 + nd3 + nd4 + nd5 + egz) / 6.0;
    }
        };
            for (int j = 1; j <= sk; j++) {
                std::string studentName = "Vardas" + std::to_string(j);
                std::string studentLastName = "Pavarde" + std::to_string(j);
                int nd1 = generateGrade();
                int nd2 = generateGrade();
                int nd3 = generateGrade();
                int nd4 = generateGrade();
                int nd5 = generateGrade();
                int exam = generateGrade();
                outputFile << studentLastName << "\t" << studentName << "\t"
                           << nd1 << "\t" << nd2 << "\t" << nd3 << "\t"
                           << nd4 << "\t" << nd5 << "\t" << exam << "\n";
            }
        outputFile.close();
        cout << "Failas " << failas << " sukurtas su " << sk << " irasais." << endl;
}

    bool nuskaitytiIsFailo(const std::string& failoVardas, std::vector<Studentas>& grupe) {
        std::ifstream in(failoVardas);
        std::string eilute;
        std::getline(in, eilute);

    while (std::getline(in, eilute)) {
        std::istringstream iss(eilute);
        std::string vardas, pavarde;
        int skaicius;
        std::vector<int> nd;
        int egzaminas;
        iss >> vardas >> pavarde;

        while (iss >> skaicius) {
            nd.push_back(skaicius);
        }
        if (nd.empty()) continue;
        egzaminas = nd.back();
        nd.pop_back();

        Studentas s(vardas, pavarde, nd, egzaminas);
        grupe.push_back(s);
    }
    return true;
};
