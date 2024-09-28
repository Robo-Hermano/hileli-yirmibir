#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

void loop() {
    int rakipskor = 0;
    int oyuncuskor = 0;
    vector<string> Rakipkartlar(3);
    vector<string> Oyuncukartlar(3);
    unordered_map <string, int> CardValues;
    vector<string> CardTypes = {"Kalp", "Elmas", "Maça", "Sinek"};
    CardValues["ikili"] = 2; CardValues["üçlü"] = 3; CardValues["dörtlü"] = 4;
    CardValues["beşli"] = 5; CardValues["altılı"] = 6; CardValues["yedili"] = 7;
    CardValues["sekizli"] = 8; CardValues["dokuzlu"] = 9; CardValues["onlu"] = 10;
    CardValues["Jack"] = 10; CardValues["Kraliçe"] = 10; CardValues["Kral"] = 10; 
    //CardValues["aslı"] = list<int>[1, 11];

    vector<string> CardKeys = {"ikili","üçlü","dörtlü","beşli","altılı","yedili","sekizli","dokuzlu","onlu","Jack","Kraliçe","Kral"};
    for (int i = 0; i != 3; ++i){
        int rakip_index = rand() % 12;
        int oyuncu_index = rand() % 12;
        for (int j = 0; j != sizeof(CardKeys)/2; ++j){
            if (rakip_index == j){
                Rakipkartlar[i] = CardKeys[j];
            }
            if (oyuncu_index == j){
                Oyuncukartlar[i] = CardKeys[j];
            }
        }
    }
    cout << "rakibin ilk kartı: " << Rakipkartlar[0] << " " << CardTypes[rand()%4] << endl;
    cout << "senin kartlar: " << Oyuncukartlar[0] << " " << CardTypes[rand()%4] << " ve " << Oyuncukartlar[1] << " " << CardTypes[rand()%4];
    cout << "hocam üçüncü kart alacak mısın? evet için 1 ve hayır için 0 koyunuz" << endl;
    string karar;
    cin >> karar;
}

int main() {
    cout << "Blackjack'e hoşgeldin aga" << endl;
    cout << "Hocam kumarda çok para diğe birşey yok" << endl;;
    loop();
    return 0;
}

