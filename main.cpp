#include <iostream>
#include <sstream>
#include <string>

using namespace std;


string toString (double);
int toInt (string);
double toDouble (string);
int entraPersone(int numPersone, int capacitàMax);
int esciPersone(int numPersone, int contpersone);
void leggicomando();
int pulisciPalestra(int livelloPuliziaPerc);
int resetPalestraCapacità(int capacitaMax);
int resetPalestraPulizia(int pulizia);
int usaAttrezzi(int livelloPuliziaPerc);

int main() {
    srand(time(0));   
    
    string c;
    int capacitaMax, contPersone, numPersone;
    double livelloPuliziaPerc;
    
    contPersone = 0;
    capacitaMax = resetPalestraCapacità(50);
    livelloPuliziaPerc = resetPalestraPulizia(rand() % 101);
    do {
        visualizzaStato(capacitaMax, contPersone, livelloPuliziaPerc);
        c = leggicomando();
        if (c == "R") {
            cout << "Inserisci la capacità massima: ";
            cin >> capacitaMax;
            capacitaMax = rand() % 101;
            capacitaMax = resetPalestraCapacità(capacitaMax);
            livelloPuliziaPerc = resetPalestraPulizia((int) livelloPuliziaPerc);
            contPersone = 0;
        }
        if (c == "P") {
            livelloPuliziaPerc = pulisciPalestra((int) livelloPuliziaPerc);
        }
        if (c == "A") {
            livelloPuliziaPerc = usaAttrezzi((int) livelloPuliziaPerc);
        }
        if (c == "E") {
            cout << "Quante persone devono entrare?" << endl;
            cin >> numPersone;
            contPersone = contPersone + entraPersone(numPersone, capacitaMax, contPersone);
        }
        if (c == "U") {
            cout << "Quante persone devono uscire?" << endl;
            cin >> numPersone;
            contPersone = contPersone - esciPersone(numPersone, contPersone);
        }
    } while (c != "X");
    return 0;
}

int entraPersone(int numPersone, int capacitàMax) {
    int ingressipermessi;
    int ingressirimanenti;
    
    ingressirimanenti = (int) (capacitàMax - contpersone);
    if (ingressirimanenti >= numPersone) {
        ingressipermessi = numPersone;
    } else {
        ingressipermessi = ingressirimanenti;
        cout << "Non tutte le persone potranno entrare in palestra.Il numero attuale delle persone in palestra è" << ingressipermessi << endl;
    }
    
    return ingressipermessi;
}

int esciPersone(int numPersone, int contpersone) {
    int uscitepermesse;
    
    if (numPersone <= contpersone) {
        uscitepermesse = numPersone;
    } else {
        uscitepermesse = contpersone;
        cout << "Le persone uscite dalla palestra sono " << uscitepermesse << endl;
    }
    
    return uscitepermesse;
}

void leggicomando() {
    string c;
    
    do {
        cout << "[R] Resetpalestra | [P] pulisci| [A]Usa attrezzi | [U] esci persone |  [E]  Entrapersone | [X] esci" << endl;
        cin >> c;
    } while (c != "R" && c != "P" && c != "A" && c != "U" && c != "E" && c != "X");
}

int pulisciPalestra(int livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc + 10;
    if (livelloPuliziaPerc > 100) {
        livelloPuliziaPerc = 100;
    }
    
    return livelloPuliziaPerc;
}

int resetPalestraCapacità(int capacitaMax) {
    if (capacitaMax > 90) {
        capacitaMax = 80;
        cout << " " << capacitaMax << endl;
    } else {
        if (capacitaMax < 20) {
            capacitaMax = 10;
            cout << "Valore negativo per capacita massima. Impostato a " << capacitaMax << endl;
        }
    }
    
    return capacitàMax;
}

int resetPalestraPulizia(int pulizia) {
    if (pulizia > 100) {
        livelloPuliziaPerc = 100;
        cout << "Pulizia elevata impostata a:" << pulizia << endl;
    } else {
        if (pulizia < 0) {
            livelloPuliziaPerc = 0;
        } else {
            cout << "Pulizia carente impostata a:" << pulizia << endl;
        }
    }
    
    return pulizia;
}

int usaAttrezzi(int livelloPuliziaPerc) {
    livelloPuliziaPerc = livelloPuliziaPerc - (rand() % 10 + 1);
    if (livelloPuliziaPerc < 0) {
        livelloPuliziaPerc = 0;
    }
    
    return livelloPuliziaPerc;
}

