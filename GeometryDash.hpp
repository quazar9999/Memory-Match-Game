#include <string>
#include <vector>
#ifndef GEOMETRYDASH_H
#define GEOMETRYDASH_H
using namespace std;
vector<string> gdValMaster={"Acheron", "Avernus", "Kyouki", "KOCMOC", "Firework", "MINUSdry", "Deimos", "LIMBO", "poocubed", "UNKNOWN", "arcturus", "Tarturus", "Jigsaw", "Kuzureta", "Kenos", "Sigma", "ICDX", "SWI", "APT", "decode", "Phobos", "Hatred", "DownBass", "Erebus", "ZAPHKIEL", "SubSonic", "Nhelv", "Catalyze", "Acu", "TOE2", "kowareta", "NEUTRA", "Zodiac", "Th3Dev0n", "CITRA", "Requiem", "Killbot", "FusionZ", "Brownoix", "Epsilon", "TANTRUM", "Idols", "GodEater", "BB", "BL", "ABP", "SPEEDRUN", "xo", "OVERKILL", "VSC"};
//My code breaks if this block of code isn't defined in this file (Why? I have 0 idea)
class game{
    private:
    string val;
    const string hiddenVal="[?]";
    const string takenVal="[X]";
    string displayVal;
    public:
    void enterVal(string x){
        val=x;
        displayVal=val;
        return;
    }
    string out(){
        return displayVal;
    }
    void hide(){
        if (displayVal!=takenVal){
        displayVal=hiddenVal;
        }
    }
    void take(){
        displayVal=takenVal;
    }
    string getVal(){
        return val;
    }
    void reveal(){
        displayVal=val;
    }
    bool isTaken(){
        if (displayVal==takenVal){
            return true;
        }
        return false;
    }
    game(){
        displayVal=hiddenVal;
    }
    
};
game a1,a2,a3,a4,a5,a6,a7,a8,b1,b2,b3,b4,b5,b6,b7,b8,c1,c2,c3,c4,c5,c6,c7,c8,d1,d2,d3,d4,d5,d6,d7,d8,e1,e2,e3,e4,e5,e6,e7,e8,f1,f2,f3,f4,f5,f6,f7,f8,g1,g2,g3,g4,g5,g6,g7,g8,h1,h2,h3,h4,h5,h6,h7,h8;
game gameArrayIn[8][8]={
    {a1,a2,a3,a4,a5,a6,a7,a8},
    {b1,b2,b3,b4,b5,b6,b7,b8},
    {c1,c2,c3,c4,c5,c6,c7,c8},
    {d1,d2,d3,d4,d5,d6,d7,d8},
    {e1,e2,e3,e4,e5,e6,e7,e8},
    {f1,f2,f3,f4,f5,f6,f7,f8},
    {g1,g2,g3,g4,g5,g6,g7,g8},
    {h1,h2,h3,h4,h5,h6,h7,h8}

};
#endif