#include "MyLib.h"
#include <chrono>

using namespace std::chrono;

int main() {
    vector<int> dydziai = {1000, 10000, 100000, 1000000};

    for (int kiek : dydziai) {
        std::string failas = "studentai_" + std::to_string(kiek) + ".txt";

        auto start = high_resolution_clock::now();
        Studentas::generuotiFaila(failas, kiek);
        auto end = high_resolution_clock::now();
        std::cout << "Failo " << failas << " kurimas uztruko "
                  << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        auto grupe = Studentas::nuskaitytiIsFailo(failas);
        end = high_resolution_clock::now();
        std::cout << "Failo " << failas << " nuskaitymas uztruko "
                  << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        vector<Studentas> vargsai;
        vector<Studentas> kietai;
        for (auto& s : grupe) {
            if (s.getRezultatas() < 5.0)
                vargsai.push_back(s);
            else
                kietai.push_back(s);
        }
        end = high_resolution_clock::now();
        std::cout << "Studentu rusiavimas uztruko "
                  << duration_cast<milliseconds>(end - start).count() << " ms\n";

        start = high_resolution_clock::now();
        std::ofstream outVargsai("vargsiukai_" + std::to_string(kiek) + ".txt");
        std::ofstream outKietai("kietiakiai_" + std::to_string(kiek) + ".txt");

        outVargsai << "Pavarde Vardas Vidurkis Mediana\n";
        for (auto& s : vargsai) outVargsai << s << "\n";

        outKietai << "Pavarde Vardas Vidurkis Mediana\n";
        for (auto& s : kietai) outKietai << s << "\n";
        end = high_resolution_clock::now();
        std::cout << "Isvedimas i failus uztruko "
                  << duration_cast<milliseconds>(end - start).count() << " ms\n\n";
    }
    return 0;
}
