#include "MyLib.h"

template <typename Container>
void testKonteineris(const std::string& failoVardas) {
    Container grupe;

    auto startNuskaitymas = std::chrono::high_resolution_clock::now();
    auto endNuskaitymas = std::chrono::high_resolution_clock::now();
    auto nuskaitymoTrukme = std::chrono::duration_cast<std::chrono::milliseconds>(endNuskaitymas - startNuskaitymas);
    std::cout << "Duomenu nuskaitymas (" << typeid(Container).name() << ") uztruko: "
              << nuskaitymoTrukme.count() << " ms\n";

    auto startRusiavimas = std::chrono::high_resolution_clock::now();

    Container vargsiukai;
    Container kietiakiai;

    for (const auto& s : grupe) {
        if (s.getRezultatas() < 5.0) {
            vargsiukai.push_back(s);
        } else {
            kietiakiai.push_back(s);
        }
    }

    auto endRusiavimas = std::chrono::high_resolution_clock::now();
    auto rusiavimoTrukme = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas);
    std::cout << "Studentu padalijimas (" << typeid(Container).name() << ") uztruko: "
              << rusiavimoTrukme.count() << " ms\n";

    auto startIrasymas = std::chrono::high_resolution_clock::now();

    std::ofstream outVargs("vargsiukai.txt");
    std::ofstream outKiet("kietiakiai.txt");

    for (const auto& s : vargsiukai) outVargs << s << "\n";
    for (const auto& s : kietiakiai) outKiet << s << "\n";

    outVargs.close();
    outKiet.close();

    auto endIrasymas = std::chrono::high_resolution_clock::now();
    auto irasymoTrukme = std::chrono::duration_cast<std::chrono::milliseconds>(endIrasymas - startIrasymas);
    std::cout << "Irasymas i failus (" << typeid(Container).name() << ") uztruko: "
              << irasymoTrukme.count() << " ms\n\n";
}

int main() {

try {
    vector<Studentas> grupe;
    int pasirinkimas;
    std::cout << "1 - Rankinis ivedimas\n2 - Atsitiktinis generavimas\n3 - Nuskaitymas is failo\n4 - Penkiu atsitiktiniu studentu sarasu failu generavimas\n";
    std::cin >> pasirinkimas;

    int kiek;
    int kiekNd;

    if (pasirinkimas == 1) {
            std::cout << "Kiek studentu norite sugeneruoti? ";
            std::cin >> kiek;
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                std::cin >> s;
                grupe.push_back(s);
            }
    } else if (pasirinkimas == 2) {
            std::cout << "Kiek studentu norite sugeneruoti? ";
            std::cin >> kiek;

            std::cout << "Kiek namu darbu pazymiu generuoti kiekvienam? ";
            std::cin >> kiekNd;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                s.generuotiAtsitiktinai(s, kiekNd);
                grupe.push_back(s);
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto trukme = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Atsitiktiniu studentu generavimas uztruko: " << trukme.count() << " ms\n";
    } else if (pasirinkimas == 3) {
            auto start = std::chrono::high_resolution_clock::now();
            if (!nuskaitytiIsFailo("kursiokai.txt", grupe)) {
                std::cerr << "Nepavyko nuskaityti failo.\n";
                return 1;
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto trukme = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Duomenu nuskaitymas uztruko: " << trukme.count() << " ms\n";
    } else if (pasirinkimas == 4) {
            srand(time(0));
            Studentas s;
            auto start = std::chrono::high_resolution_clock::now();
                s.generuotas_failas(1000);
                s.generuotas_failas(10000);
                s.generuotas_failas(100000);
                s.generuotas_failas(1000000);
                s.generuotas_failas(10000000);

            auto end = std::chrono::high_resolution_clock::now();
            auto trukme = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Failu generavimas uztruko: " << trukme.count() << " ms\n";
            return 0;
    }

    std::sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde();
        });

    cout << "Pavarde       Vardas           Galutinis (Vid.) / Galutinis (Med.)\n";
    cout << "------------------------------------------------------------------\n";
    for (const auto& s : grupe) {
        cout << s << endl;
    }
    auto startRusiavimas = std::chrono::high_resolution_clock::now();

        std::vector<Studentas> vargsiukai;
        std::vector<Studentas> kietiakiai;

        for (const auto& s : grupe) {
            if (s.getRezultatas() < 5.0) {
                vargsiukai.push_back(s);
            } else {
                kietiakiai.push_back(s);
            }
        }
    auto endRusiavimas = std::chrono::high_resolution_clock::now();
    auto rusiavimasTrukme = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas);
    std::cout << "Studentu padalijimas uztruko: " << rusiavimasTrukme.count() << " ms\n";
    auto startIrasymas = std::chrono::high_resolution_clock::now();
        std::ofstream outVargs("vargsiukai.txt");
        std::ofstream outKiet("kietiakiai.txt");

        outVargs << "Pavarde       Vardas           Galutinis (Vid.) / Galutinis (Med.)\n";
        outVargs << "------------------------------------------------------------------\n";
        for (const auto& s : vargsiukai) {
            outVargs << s << "\n";
        }

        outKiet << "Pavarde       Vardas           Galutinis (Vid.) / Galutinis (Med.)\n";
        outKiet << "------------------------------------------------------------------\n";
        for (const auto& s : kietiakiai) {
            outKiet << s << "\n";
        }

        std::cout << "\nStudentai suskirstyti:\n"
                  << " - 'vargsiukai.txt' (galutinis < 5.0)\n"
                  << " - 'kietiakiai.txt' (galutinis >= 5.0)\n";


        outVargs.close();
        outKiet.close();

    auto endIrasymas = std::chrono::high_resolution_clock::now();
    auto irasymasTrukme = std::chrono::duration_cast<std::chrono::milliseconds>(endIrasymas - startIrasymas);
    std::cout << "Irasymas i failus uztruko: " << irasymasTrukme.count() << " ms\n";

    std::string failoVardas = "kursiokai.txt";

        std::cout << "== Testuojame std::vector ==\n";
        testKonteineris<std::vector<Studentas>>(failoVardas);

        std::cout << "== Testuojame std::list ==\n";
        testKonteineris<std::list<Studentas>>(failoVardas);

        std::cout << "== Testuojame std::deque ==\n";
        testKonteineris<std::deque<Studentas>>(failoVardas);

        return 0;
   } catch (const std::exception& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return 1;
    }
};
