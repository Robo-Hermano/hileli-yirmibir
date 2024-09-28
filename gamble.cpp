//Sorry for confusion in understanding due to hybrid of English and Turkish
//Türkçe ve İngilizce karışımdan dolayı okuma zorluğunu affedersiniz.

#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

//Just so I don't have to write them out on every combination of conditions
//Her son durumda zafer yada yenilgi cümlesini yapmak yerine böyle işlev kurup çağırmak daha kolay
void victory() {
    cout << "hocam 1 000 000 tl kazandın! Zafere devam!" << endl;
}

void defeat() {
    cout << "hocam 1 000 000 tl kaybettin! Merak etme diğer rauntda geri kazanırsın." << endl;
}

void loop() {
    //initialising scores and arrays
    //bunları kart ve puan toplamak için kullanıyoruz
    int rakipskor = 0;
    int oyuncuskor = 0;
    vector<string> Rakipkartlar(3);
    vector<string> Oyuncukartlar(3);
    
    //assign to the number values to make it more realistic
    //gerçeklik için, bir kart türü numara değerine bağlıyor daha sonra
    vector<string> CardTypes = {"Kalp", "Elmas", "Maça", "Sinek"};

    //maps the cards to their respective values
    //kart ismini koyduğunda bağlantılı puanı veriyor
    unordered_map <string, int> CardValues;
    CardValues["ikili"] = 2; CardValues["üçlü"] = 3; CardValues["dörtlü"] = 4;
    CardValues["beşli"] = 5; CardValues["altılı"] = 6; CardValues["yedili"] = 7;
    CardValues["sekizli"] = 8; CardValues["dokuzlu"] = 9; CardValues["onlu"] = 10;
    CardValues["Jack"] = 10; CardValues["Kraliçe"] = 10; CardValues["Kral"] = 10; 

    //simulates dealer handing out cards using randomization; then puts the cards of player and house in list for later
    //gerçek hayatta krupiyenin kart dağıtmasını simüle ediyor. Daha sonra operaysonlar için senin ve evin kartları liste koyuyoruz
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
    cout << "hocam üçüncü kart alacak mısın? evet için 1 ve hayır için 0 koyunuz" << endl; //decision to hit or stand
    int karar;
    cin >> karar;
    while (karar != 0 and karar != 1) {
        cout << "lütfen karara göre 1 yada 0 koyun" << endl; //validation check just to prevent errors
        cin >> karar;
    }

    //there's a third card in the list which will be included in the loop for tallying score if players decided to hit
    //listede üçüncü kart var, oyuncu evet derse puan toplamada bu kartda kullanılıyor
    int index = 2;
    if (karar == 1){
        index++; 
    }

    //the rest is tallying out scores and calling defeat or victory depending on who wins
    //kalanı puan toplamak ve kimin kazandığını görüp uyan işlevi çağırmak
    for (int k = 0; k != index; k++){
        oyuncuskor += CardValues[Oyuncukartlar[k]];
    }
    cout << oyuncuskor << endl;
    if (oyuncuskor > 21) {
        defeat();
    }
    else {
        rakipskor += CardValues[Rakipkartlar[0]] + CardValues[Rakipkartlar[1]];
        //if player is higher but not past 21, house will stand, which is why it's technically even more unfair blackjack
        //evin üçüncü kart alması komple oyuncunun durumuna bağlı, ve beyler bu yüzden dolayı bu hileli yirmibir (ve başka şeyler)
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


//decided put initial text here and separate actual calculations and operations to make it simpler
//başlangıç konuşumu ve asıl yazılımı bakması daha kolay olsun diye böldüm
int main() {
    cout << "Blackjack'e hoşgeldin aga" << endl;
    cout << "" << endl;
    cout << "Ekstra kurallar: şansa güvenmen lazım. O yüzden ham ası kaldırdık (böyle bir kara verebilmek şansına güvenmiyorsun demek) " << endl;
    cout << "ve aynı puan durumunde ev kazanıyor. Ama senin için fark etmemeli kumarcı kendi şansına RUHLA inanır." << endl;
    cout << "" << endl;
    cout << "Kalan para: Hocam kumarda çok para diye birşey yok" << endl;
    cout << "" << endl;
    cout << "" << endl;
    loop();
    return 0;
}

