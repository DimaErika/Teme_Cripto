#include <iostream>
#include <string>

using namespace std;

// Functie pentru decriptarea unui singur caracter folosind criptarea afină
char decriptareAfina(char ch, int a, int b) {
    // Inversarea criptarii afinului: (a * x + b) % 95
    int inverse = 0;
    for (int i = 0; i < 95; i++) {
        if ((a * i) % 95 == 1) {
            inverse = i;
            break;
        }
    }
    int index = ((inverse * ((ch - 32) - b)) + 95) % 95;
    return static_cast<char>(index + 32);
}

// Functie pentru decriptarea unui text folosind criptarea afină
string decriptareAfinaText(const string& text, int a, int b) {
    string decriptat = "";
    for (char ch : text) {
        if (isalnum(ch) || ispunct(ch) || ch == ' ') {  // Caracterele permise
            decriptat += decriptareAfina(ch, a, b);
        }
    }
    return decriptat;
}

int main() {
    string text = "9'p-PZplp-P-C4fis-CvGfsp!pk-Gp-lPpls-C4fivfsR-9p-4y8fpSs-P-!Ppils-v!l'spJp-Z4ip-c'p!p-Sv-!4-JpSvSs-!vGpv'vR-HpGp!Z4USs-Fv4p-pf8pk-C4fisp-vsSs-fp-yp'Jv!sp-Z'4y4f4v-Sv-Ss-G4fGp-S48-P-l4)pk-Jp!Zv!Z4USs-Gs-Sp-ypv-)pGpk-Gp-Sp-iPplp-JpSv-GsCp-Zs-yp!Gp'sR-SpFp!Z-C4fisp-G4-8Pl4f-v!lv!S-is-fp8sfs-Zs-Zv!pv!lsk-vv-Cv!s-yv'PS-Zs-isSlsR-6l4!Gv-sp-'pZvGp-i4lv!-Gpi4f-Svk-4vlp!Z4USs-fp-Cpfsk-v!-f4!J4f-Z'4y4f4vk-Fp'sSls-Cs!v!Z-4!-Gp'-l'pS-Zs-8PvR-UE4!3-Jp!Zv-C4fispR-:pGp-c'p!p-GsUP-pSlsilpy-s4R-Sv-v!Zplp-vsSs-Zs-S48-l4)p-Sv-Ss-f4!JsSls-v!-yv fPG4f-Z'4y4f4vk-Gp-Sv-G4y-p'-)v-)PSl-yPp'lpR-Xp'4f-pi'Pivv!Z4USs-Zs-C4fisk-lp'p!4f-Gs-yp!p-8Pvv-P-CsZs-Svk-G'sFp!Z-GpUv-yPp'lp-G4-pZsCp'plk-Sl'vJp-fp-8Pvh-6cP3-6cP3-EPvv-Ss-Pi'sSGR-lp'p!4f-Cv!s-Si's-C4fisk-Ss-4vlp-fp-sp-Zs-pi'Ppis-Svk-CpFp!Z-Gp-!vGv-!4-S4)fpk-FvGsh-UE's3-Zp-G4y-!pv8p-p-y4'vl-C4fisp-pSlp-pvGvB3-2v3RRR-Gs-)'4yPpSp-GplpCsvGp-py-Sp-)pG-!sCsSlsv-ysfs-Zv!-8fp!p-vSl4v-C4fiPv43-WvGp!Z-pSpk-pi4Gp-C4fisp-Zs-Z4ip-Gpi-Svk-lp'p!ZUP-ip!p-fp-Gp'k-Ss-Piv!lsSls-SUP-p'4!Gp-ZspS4i'p-isSlsf4vR-6iPv-Sl'vJp-fp-8Pvh-tpvS3-KPvp!k-Gsp3-EP4'sp!R";

    int a = 7;  // Cheia de criptare
    int b = 22; // Cheia de criptare

    string decriptat = decriptareAfinaText(text, a, b);
    cout << "Textul decriptat este: " << decriptat << endl;

    return 0;
}
