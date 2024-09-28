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
    for (int i = 0; i != 2; ++i){
        int rakip_index = rand() % 12;
        int oyuncu_index = rand() % 12;
        for (int j = 0; j != sizeof(CardKeys)/sizeof(CardKeys[0]); ++j){
            if (rakip_index == j){
                Rakipkartlar[i] = CardKeys[j];
                rakipskor += CardValues[CardKeys[j]];
            }
            if (oyuncu_index == j){
                Oyuncukartlar[i] = CardKeys[j];
                oyuncuskor += CardValues[CardKeys[j]];
            }
        }
    }
    
    
}

int main() {
    cout << "Blackjack'e hoşgeldin aga" << endl;
    cout << "Hocam kumarda çok para diğe birşey yok";
    loop();
    return 0;
}

