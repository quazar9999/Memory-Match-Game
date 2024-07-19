#ifndef MEMORYMATCHGAME_H
#define MEMORYMATCHGAME_H
//global imports
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <math.h>
#include <windows.h>
//3 custom libs
#include "GeometryDash.hpp"
#include "Fruit.hpp"
#include "Drinks.hpp"

using namespace std;

class memoryMatchGame{
    private:
    vector<string> theme50Words;
    int difficulty;//4=easy (4x4), 6=moderate (6x6), 8=hard (8x8)
    int speed; //6=easy, 4=medium, 2=hard (measured in seconds)
    int correctAnswers=0;
    int wrongAnswers=0;
    vector<vector<int>> usedCoords;
    public:
    void themeSelect(){
    string menuStr;
    cout<<"Which theme would you like to choose?"<<endl<<"1. Geometry Dash"<<endl<<"2. Fruit"<<endl<<"3. Drinks"<<endl;
    cin>>menuStr;
    //the following converts an int to a str (even if there is not an int within the str [stoi() and atoi() would not work for these reasons])
    stringstream temp(menuStr);
    int menu;
    temp>>menu;
    switch (menu){
        case 1:
            cout<<"Theme selected: Geometry Dash"<<endl<<endl;
            for(int i=0;i<50;i++){
            theme50Words.push_back(gdValMaster[i]);
            }
            break;
        case 2:
            cout<<"Theme selected: Fruit"<<endl<<endl;
            for(int i=0;i<50;i++){
            theme50Words.push_back(fruitValMaster[i]);
            }
            break;
        case 3:
            cout<<"Theme selected: Drinks"<<endl<<endl;
            cout<<"Theme selected: Fruit"<<endl<<endl;
            for(int i=0;i<50;i++){
            theme50Words.push_back(drinkValMaster[i]);
            }
            break;
        default:
            cout<<"Error: Invalid input"<<endl<<endl;
            themeSelect();
    }
    return;
}

void difficultySelect(){
    string menuStr;
    cout<<"Which difficulty would you like to choose?"<<endl<<"1. Easy (4x4)"<<endl<<"2. Medium (6x6)"<<endl<<"3. Hard (8x8)"<<endl;
    cin>>menuStr;
    //the following converts an int to a str (even if not int is within the str [stoi() and atoi() would not work for these reasons])
    stringstream temp(menuStr);
    int menu;
    temp>>menu;
    switch (menu){
        case 1:
            cout<<"Difficulty selected: Easy"<<endl<<endl;
            difficulty=4;
            break;
        case 2:
            cout<<"Difficulty selected: Medium"<<endl<<endl;
            difficulty=6;
            break;
        case 3:
            cout<<"Difficulty selected: Hard"<<endl<<endl;
            difficulty=8;
            break;
        default:
            cout<<"Error: Invalid input"<<endl<<endl;
            difficultySelect();
    }
    return;
}
void speedSelect(){
    string menuStr;
    cout<<"Which speed would you like to choose?"<<endl<<"1. Easy (6 seconds)"<<endl<<"2. Medium (4 seconds)"<<endl<<"3. Hard (2 seconds)"<<endl;
    cin>>menuStr;
    //the following converts an int to a str (even if not int is within the str [stoi() and atoi() would not work for these reasons])
    stringstream temp(menuStr);
    int menu;
    temp>>menu;
    switch (menu){
        case 1:
            cout<<"Speed selected: Easy"<<endl<<endl;
            speed=6;
            break;
        case 2:
            cout<<"Speed selected: Medium"<<endl<<endl;
            speed=4;
            break;
        case 3:
            cout<<"Speed selected: Hard"<<endl<<endl;
            speed=2;
            break;
        default:
            cout<<"Error: Invalid input"<<endl<<endl;
            speedSelect();
    }
    return;
}


    bool isValidCoordinate(int x, int y){
        vector<int> check={x,y};
        if (usedCoords.size()<1){
            usedCoords.push_back(check);
            return true;
        }
        for(int i=0; i<usedCoords.size();i++){
            if(check==usedCoords[i]){
                //cout<<"Failed "<< usedCoords[i][0]<<" "<<usedCoords[i][1]<<endl;
                return false;   
            }}

                usedCoords.push_back(check);
                return true;
        
        
    }
    void sort(){
        Sleep(100);
        srand(GetTickCount());
        int r1I1=rand()%difficulty; //1st object, 1st dimension parameter. Stands for random 1 index 1
        int r1I2=rand()%difficulty; //1st object, 2nd dimension parameter. Stands for random 1 index 2
        int r2I1=rand()%difficulty; //2nd object, 1st dimension parameter. Stands for random 2 index 1
        int r2I2=rand()%difficulty; //2nd object, 2nd dimension parameter. Stands for random 2 index 2
        while (true) {
            r1I1 = rand() % difficulty;
            r1I2 = rand() % difficulty;
            if (isValidCoordinate(r1I1, r1I2)) {
                break;
            }
        }
        while (true) {
           
            r2I1 = rand() % difficulty;
            r2I2 = rand() % difficulty;
            if (isValidCoordinate(r2I1, r2I2)) {
                break;
            }
        }
        int randomName=rand()%theme50Words.size();; //random theme50words index
        gameArrayIn[r1I1][r1I2].enterVal(theme50Words[randomName]);
        //cout<<r1I1<<" "<<r1I2<<" "<<gameArrayIn[r1I1][r1I2].out()<<endl;
        gameArrayIn[r2I1][r2I2].enterVal(theme50Words[randomName]);
        //cout<<r2I1<<" "<<r2I2<<" "<<gameArrayIn[r1I1][r1I2].out()<<endl;
        theme50Words.erase(theme50Words.begin()+randomName);
        return;
    }
    void printArray(bool x){ //if values are being dislayed, x->true (changes spacing of the [A] [B]...)
        if (x and difficulty==8){
            cout<<"   [A]     [B]     [C]     [D]     [E]     [F]     [G]     [H]"<<endl;
        }else if (x and difficulty==6){
            cout<<"   [A]     [B]     [C]     [D]     [E]     [F]"<<endl;
        }else if (x and difficulty==4){
            cout<<"   [A]     [B]     [C]     [D]"<<endl;
        }else if (!x and difficulty==8){
            cout<<"    [A] [B] [C] [D] [E] [F] [G] [H]"<<endl;
        }else if (!x and difficulty==6){
            cout<<"    [A] [B] [C] [D] [E] [F]"<<endl;
        }else{
            cout<<"    [A] [B] [C] [D]"<<endl;
        }
        for (int i=0; i<difficulty;i++){
            cout<<"["<<i+1<<"] ";
                for (int x=0; x<difficulty;x++){
                    cout<<gameArrayIn[i][x].out()<<" ";
                }
                cout<<endl;
            }
    }
    void hideArray(){
        for (int i=0; i<difficulty;i++){
                for (int x=0; x<difficulty;x++){
                    gameArrayIn[i][x].hide();
                }
            }   
    }
    void inputAnswer(){
        char response[5]; //compiling using g++ -O3 --static shaves off the last char in the array. Changing array length to    5 corrects this
        int o1I1; //object 1, index 1 (contrals char, second [])
        int o1I2; //object 1, index 2 (controls int, first [])
        int o2I1; //object 2, index 1 (controls char, second[])
        int o2I2; //object 2, index 2 (controls int, first[])
        cout<<"Input 2 matching coordinate points (letter before number), without a space inbetween (e.g. a1b1 -> is valid, a1 b1->not valid)"<<endl<<endl<<"Input your coordinate point: "<<endl;
        cin>>response;
        cout<<response[0]<<response[1]<<response[2]<<response[3]<<endl;
        Sleep(10);
        switch(response[0]){ //int vals in ascii 3:
            case 65: o1I1=0; break; //assigns object 1 index 1 to 0
            case 97: o1I1=0; break; //assigns object 1 index 1 to 0 
            case 66: o1I1=1; break; //assigns object 1 index 1 to 1
            case 98: o1I1=1; break; //assigns object 1 index 1 to 1
            case 67: o1I1=2; break; //assigns object 1 index 1 to 2
            case 99: o1I1=2; break; //...
            case 68: o1I1=3; break; //...
            case 100: o1I1=3; break; //...
            case 69: o1I1=4; break; //...
            case 101: o1I1=4; break; //...
            case 70: o1I1=5; break; //...
            case 102: o1I1=5; break; //...
            case 71: o1I1=6; break; //...
            case 103: o1I1=6; break; //...
            case 72: o1I1=7; break; //...
            case 104: o1I1=7; break; //...
            default:
                cout<<"That's an invalid response! Try again (incorrect first letter)"<<endl;
                goto recurse;
                break;
        };
        switch(response[1]){ //int vals in ascii 3:
            case 49: o1I2=0; break; //assigns object 1 index 2 to 0
            case 50: o1I2=1; break; //assigns object 1 index 2 to 1
            case 51: o1I2=2; break; //assigns object 1 index 2 to 2
            case 52: o1I2=3; break; //...
            case 53: o1I2=4; break; //...
            case 54: o1I2=5; break; //...
            case 55: o1I2=6; break; //...
            case 56: o1I2=7; break;
            default:
                cout<<"That's an invalid response! Try again (incorrect first int)"<<endl;
                goto recurse;
                break;
        };
        switch(response[2]){ //int vals in ascii 3:
            case 65: o2I1=0; break; //assigns object 2 index 1 to 0
            case 97: o2I1=0; break; //assigns object 2 index 1 to 0
            case 66: o2I1=1; break; //assigns object 2 index 1 to 1
            case 98: o2I1=1; break; //assigns object 2 index 1 to 1
            case 67: o2I1=2; break; //assigns object 2 index 1 to 2
            case 99: o2I1=2; break; //...
            case 68: o2I1=3; break; //...
            case 100: o2I1=3; break; //...
            case 69: o2I1=4; break; //...
            case 101: o2I1=4; break; //...
            case 70: o2I1=5; break; //...
            case 102: o2I1=5; break; //...
            case 71: o2I1=6; break; //...
            case 103: o2I1=6; break; //...
            case 72: o2I1=7; break; //...
            case 104: o2I1=7; break; //...
            default:
                cout<<"That's an invalid response! Try again (incorrect second letter)"<<endl;
                goto recurse;
                break;
        };
        switch(response[3]){ //int vals in ascii 3:
            case 49: o2I2=0; break; //assigns object 1 index 2 to 0
            case 50: o2I2=1; break; //assigns object 1 index 2 to 1
            case 51: o2I2=2; break; //assigns object 1 index 2 to 2
            case 52: o2I2=3; break; //assigns object 1 index 2 to 3
            case 53: o2I2=4; break; //assigns object 1 index 2 to 4
            case 54: o2I2=5; break; //...
            case 55: o2I2=6; break; //...
            case 56: o2I2=7; break;
            default:
                cout<<"That's an invalid response! Try again (incorrect 2nd int)"<<endl;
                goto recurse;
                break;
            };
        if (o1I1==o2I1 and o1I2==o2I2){
            cout<<"Cheater... You can't input the same coordinate point twice!";
            inputAnswer();
        }
        if(gameArrayIn[o1I2][o1I1].isTaken()){
            cout<<"You already chose that one silly! :3"<<endl;
            inputAnswer();
        }
        if(gameArrayIn[o2I2][o2I1].isTaken()){
            cout<<"You already chose that one silly! :3"<<endl;
            inputAnswer();
        }
        gameArrayIn[o1I2][o1I1].reveal();
        gameArrayIn[o2I2][o2I1].reveal();
        printArray(false);
        Sleep(1500);
        gameArrayIn[o1I2][o1I1].hide();
        gameArrayIn[o2I2][o2I1].hide();
        if (gameArrayIn[o1I2][o1I1].getVal()==gameArrayIn[o2I2][o2I1].getVal()){
            correctAnswers++;
            gameArrayIn[o1I2][o1I1].take();
            gameArrayIn[o2I2][o2I1].take();
            return;
        }else{
            wrongAnswers++;
            return;
        }

        recurse:
        gameArrayIn[o1I1][o1I2].hide();
        gameArrayIn[o2I1][o2I2].hide();
        inputAnswer();
    }

    
    int start(){
        system("pause");
        system("cls");
        themeSelect();
        system("cls");
        difficultySelect();
        system("cls");
        speedSelect();
        system("cls");
        cout<<"Loading..."<<endl<<"This should take about: "<<.1*pow(difficulty,2)/2<<" seconds";
        for (int i=0; i<pow(difficulty,2)/2; i++){ //squaring the difficulty yields the total number of elements
            //Divide by 2 since sort assigns vals to 2 elements
            sort();
        }
        system("cls");
        printArray(true);
        hideArray();
        Sleep(speed*1000);
        auto start=chrono::steady_clock::now();
        do{
            auto now=chrono::steady_clock::now();
            chrono::duration<double> elapsedSeconds = now - start;
            system("cls");
            cout<<"Answers correct: "<<correctAnswers<<endl;
            cout<<"Time spent: "<<elapsedSeconds.count()<<endl;
            printArray(false);
            inputAnswer();
        }while (correctAnswers<pow(difficulty,2)/2);
        auto now=chrono::steady_clock::now();
        chrono::duration<double> elapsedSeconds = now - start;
        system("cls");
        cout<<"Answers correct: "<<correctAnswers<<endl;
        cout<<"Answers incorrect: "<<wrongAnswers<<endl;
        cout<<"Time spent: "<<elapsedSeconds.count()<<endl;
        cout<<"Total points: "<<correctAnswers*100+10-wrongAnswers*10-speed*5-elapsedSeconds.count()<<endl;
        return 0;
    }

};

#endif