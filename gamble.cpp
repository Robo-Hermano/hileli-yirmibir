#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

void victory() {
    cout << "hocam 1 000 000 tl kazandın!" << endl;
}

void defeat() {
    cout << "hocam 1 000 000 tl kaybettin!" << endl;
}

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
    cout << "senin kartlar: " << Oyuncukartlar[0] << " " << CardTypes[rand()%4] << " ve " << Oyuncukartlar[1] << " " << CardTypes[rand()%4] << endl;
    cout << "hocam üçüncü kart alacak mısın? evet için 1 ve hayır için 0 koyunuz" << endl;
    int karar;
    cin >> karar;
    while (karar != 0 and karar != 1) {
        cout << "lütfen karara göre 1 yada 0 koyun" << endl;
        cin >> karar;
    }
    int index = 2;
    if (karar == 1){
        index++;
    }
    for (int k = 0; k != index; k++){
        oyuncuskor += CardValues[Oyuncukartlar[k]];
    }
    cout << oyuncuskor << endl;
    if (oyuncuskor > 21) {
        defeat();
    }
    else {
        rakipskor += CardValues[Rakipkartlar[0]] + CardValues[Rakipkartlar[1]];
        if (oyuncuskor > rakipskor){
            rakipskor += CardValues[Rakipkartlar[2]];
        }
        cout << rakipskor << endl;
        if (rakipskor > 21){
                victory();
            }
        else if (oyuncuskor > rakipskor){
                victory();
            }
        else {
                defeat();
            }
        }
    }


int main() {
    cout << "Blackjack'e hoşgeldin aga" << endl;
    cout << "Hocam kumarda çok para diğe birşey yok" << endl;;
    loop();
    return 0;
}

