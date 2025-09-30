#include "MyLib.h"

int main() {
try {
    vector<Studentas> grupe;
    int pasirinkimas;
    std::cout << "1 - Rankinis ivedimas\n2 - Atsitiktinis generavimas\n";
    std::cin >> pasirinkimas;

    int kiek;
    std::cout << "Kiek studentu norite sugeneruoti? ";
    std::cin >> kiek;

    if (pasirinkimas == 1) {
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                std::cin >> s;
                grupe.push_back(s);
            }
    } else if (pasirinkimas == 2) {
            int kiekNd;
            std::cout << "Kiek namu darbu pazymiu generuoti kiekvienam? ";
            std::cin >> kiekNd;
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                s.generuotiAtsitiktinai(s, kiekNd);
                grupe.push_back(s);
            }
    }

    cout << "Pavarde       Vardas           Galutinis (Vid.) / Galutinis (Med.)\n";
    cout << "------------------------------------------------------------------\n";
    for (const auto& s : grupe) {
        cout << s << endl;
    }
    return 0;
   } catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
};
