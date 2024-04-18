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

// Functie pentru decriptarea unui text folosind criptarea afină pe blocuri de lungime 2
string decriptareAfinaBlocuri(const string& text, int a, int b) {
    string decriptat = "";
    for (int i = 0; i < text.length(); i += 2) {
        char ch1 = text[i];
        char ch2 = text[i + 1];
        decriptat += decriptareAfina(ch1, a, b);
        decriptat += decriptareAfina(ch2, a, b);
    }
    return decriptat;
}

int main() {
    string text = "mKTa.xDcSY.xAWX0RWhVRW5vXLW 8ZxxjT v)bePsLcvZP3vFHqHmZwvTH.KCJIvMPBHjTcHIHqTSY6x-S vaV(vnHuPFLIvZYTaGS5v6H8LwvHLXvTHwvTHcLIvqH,MuY'UlZ8LeJAYuZUueJvJwvtbTHwvDH.KQU0bXvuPhPkJ vDHDchV.K9b vKVPbeP.K-UmZTafLaHeJTavb3vJPcL(vRHaH(PaxeJSY5vsLeJ0JlHHWPSlH.K5v1bXPnPFHW SYVwmZwvTHeJQP8LrJfLVv-UjT-U6xeJHTmZrV.K4bIvFHmZ vtbjT vnY-UVH;vUUeYVvTHwv-U6Hwv-UeJ3Z v5TrSFPmZwvTH,MvJdHeJJY5v!LU(zH4xmZ vlL.KCJrT-S vrJPSVHqwP0.boPdHFHqHU(VUIvMPsLjTTaKZ vpHePzHaHhvc0 vfb(vPbjT8Z806HVvnHuPFLmZmIeJKaTa6x-S v-vtOmb vZP3viV YHUxxmZkHfbFH'UlZ8LmZHTQUMwR4vJwveYBIFP5vqHDc vNWsUeJ vDH49HTrSuZ(PCaXYZvuP,MKaGS5vuP IyPKagPIvuP,MrTpPFLmZwv(H)ITagPhvuPmZ5v1HZvdbxa5vAPGbeP.K5v0bTHnPIvuP-SyPIvuP.K5vqVTaHUIvFHcLmZ5vRHAKmZwv.HtbaHIvuPeJKZvaUumZwvvJUS'xAW5vKVax-S vlLGbPaXYwvSYVLnPIvTLnP(PhPjHZPsZ.K-UdHxa5v6HdNuYvt370JqHnPIvLHFHWx9-5TQUIvHHdN80vYHT8ZIvuP.K5v!LdHmbcL.xAWcLPbnvuPAW5vDHhPSYTHhVvJ5v-UCazH8LAWSY(PFL;vlbdHPa vsL!OaHlLrJjTyPjTrSFvWbdbFLPaHUgPIvaHKLuP,MSY v.HTHIauYxxmZwvPb'UoNKZ;VeP vZP3v-PJPzHcLRvVP8LIvFHxxAWXYJPIv3PIviYQUIHIvDHjHIvUS3PIvqHcLmZwv1H-U vXLAWRWKZ3Phv0bTHlLjTSYxxgNHUsUtOJY5vuPmZSYVHHLhvBaSYxx IJYlLVPJPIvFHVLxVyP6x-SyPHLcLmZwvrJXY,bePhPBMKVeP8LhvPaJY!HcL.K-U IXYQUAPZvPSuZ6xmZwvPS8L-SCJkbePIvHL-S5vfbHL4b-SsUlHhP3v6HdN.K5vRHLgSY6xmZ4b?Q3P v!L-S vTHjHPaAY?S5vXLjTyPHLIvFHhVaH-S5vVPlLeJ0TAWuZ8LjTQU v6HdNrS;v";

    int a = 17;  // Cheia de criptare
    int b = 8;   // Cheia de criptare

    string decriptat = decriptareAfinaBlocuri(text, a, b);
    cout << "Textul decriptat este: " << decriptat << endl;

    return 0;
}
