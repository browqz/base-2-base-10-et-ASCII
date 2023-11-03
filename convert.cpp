#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

unsigned long long binaireVersDecimal(const string &binaire) {
    return bitset<8>(binaire).to_ulong();
}

char binaireVersASCII(const string &binaire) {
    int decimal = binaireVersDecimal(binaire);
    if (decimal >= 0 && decimal <= 255) {
        return static_cast<char>(decimal);
    } else {
        return '\0';
    }
}

int main() {
    vector<string> octets;
    int nombreOctets;
    int choixConversion;

    cout << "Choisissez le type de conversion : \n";
    cout << "1. Valeur decimale des octets\n";
    cout << "2. Valeur ASCII des octets\n";
    cin >> choixConversion;

    if (choixConversion != 1 && choixConversion != 2) {
        cout << "Choix invalide. Veuillez choisir 1 pour la valeur decimale ou 2 pour la valeur ASCII." <<endl;
        return 1;
    }

    cout << "Combien d'octets souhaites-tu convertir ? ";
    cin >> nombreOctets;

    if (nombreOctets < 1) {
        cout << "entres un nombre valide d'octets à convertir." <<endl;
        return 1;
    }

    for (int i = 0; i < nombreOctets; ++i) {
        string octet;
        cout << "Entrez l'octet #" << i + 1 << " : ";
        cin >> octet;
        octets.push_back(octet);
    }

    for (int i = 0; i < nombreOctets; ++i) {
        if (choixConversion == 1) {
            unsigned long long decimal = binaireVersDecimal(octets[i]);
            cout << "L'octet #" << i + 1 << " en decimal : " << decimal << endl;
        } else {
            char ascii = binaireVersASCII(octets[i]);
            cout << "L'octet #" << i + 1 << " en ASCII : " << ascii << endl;
        }
    }

    return 0;
}