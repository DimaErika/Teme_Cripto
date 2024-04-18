#include <iostream>
#include <string>

std::string decryptVigenere(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        char k = key[i % key.length()];
        char p = (c - k + 26) % 26 + 'a'; // Decriptare cu criptosistemul Vigenere
        plaintext.push_back(p);
    }
    return plaintext;
}

int main() {
    std::string ciphertext = "uq.2bn7CjXwV M.6wfuMbVKnNBv.ImuTfXwlyov(bTNGb;MlNLbVUb7E.'Q7-Id6whzTb.L5Nt.dQgytu(wlyDfXwV8Sd,OX6E.4WU5I02V9NSbVcfvLjVTX5A.!M7xRv ck2oj.wauLv;wTwEtAI7:I.'I76A.;Il2ou,KfuI.;I7.Rf MTNAtAI7zAs2weyAdVLXNAkBbh)r.jIbNDfVUT7Ao4I9NDb-wluotAQbNCbVUbNTfaIbNLf9IfyTjAwWyom2wb7In2v7xOb-wluou6wi8Ru(wWytb4cfNTb-M7vIo6y7:A. IbNFjBwVyEbVKXSAnVNh:T.!Mg;RvVbb7E VLT)ooBwl;IvXwsuU?VabPot4ck;A.CWkvA!VdT-Ao5wVuonaIfNPv'wkuU.4c76An2y72I.)ck If'K7yU.4I7wE'2U7zAdBb77tp(wfuI.7IVyp.cXh2ov Je ou,b7wU.3Qg2Sp-ceNPfVTT7GbVLT7SbVabNNvVQX:oe(V7wUw2Vm L.6Q7uFb-I77Id(wV og2Xmuq..QV2odBwo8Rc2y7wAd(u7pOs3I7xUm4M76UmAwTxUd6v75A.AZXvI''wauRo(Kn;od2b7:E.!WT;E;VLX)Dj4IfNSjVUT;Us2U79Rj.wVuSbVKTNO.7Imuon2ZXPoe6wgSAw6I76An2wZ)Ik2wVuNeVaXNDv4MTNUo5Moup.'Q:7TsaW7-I.,wouZ.4I76A.'Ik TbVabSMjVhbwE.4c7vLb.LX;E;V17XUn.MsyU.'I7;E.(Vs2Lf2aVuq.kWg2CbXwW)AhBT76An6Q9NSjVaTSTjVLXuoe6wm8Au6wWuRv-Qeyot2TXNCf;M7vOh2bXNDb4I7;E'(wi Ru2wV M.CIWNCbVbXNPp-bbNDfaW7vUd2bTNDfVdkyMfVQgwOb4M(NvuBVV2ofBy79E.;WVNAnVQgwEqBb7uoq;Ig0E!VabNBv4ck2A. MTNN'2wY8SuVXk8AtAI8NSjVUT2onBTmuonBam)As6wT6ot(Um2T.(V7wUh6bn5on6c7xEd2b78Rj4Igxp.";
    std::string key = "seminarul6"; // Cheia de decriptare

    std::string plaintext = decryptVigenere(ciphertext, key);
    std::cout << "Textul decriptat este: " << plaintext << std::endl;

    return 0;
}
