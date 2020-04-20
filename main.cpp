//
//  main.cpp
//  Hangman
//
//  Created by Mani Kireeti on 09/04/20.
//  Copyright © 2020 Mani Kireeti. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>

// o
///|\
// |
// /\

using namespace std;
string line[500];
char A[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


void game(){
    int B[26];
    int num=rand()%213;
    for(int i=0;i<26;i++){
        B[i]=0;
    }
    string word=line[num];
    int length=0;
    while (word[length])
        length++;
    int c[length];
    for(int i=0;i<length;i++){
        c[i]=0;
    }
    int number=0;
    cout<<word<<" "<<length<<endl;
    while(true){
        system("clear");
        cout<<"####################################"<<endl;
        if(number==0){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==1){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==2){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==3){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|                 #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==4){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|\\                #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==5){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|\\                #"<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                                   #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==6){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|\\                #"<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                /                  #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==7){
            cout<<endl;
            cout<<endl;
            cout<<"#                                   #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|\\                #"<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                / \\                #"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(number==8){
            cout<<endl;
            cout<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                 O                 #"<<endl;
            cout<<"#                /|\\                #"<<endl;
            cout<<"#                 |                 #"<<endl;
            cout<<"#                / \\                #"<<endl;
            cout<<endl;
            cout<<"####################################"<<endl;
            cout<<"SORRY YOU DIDNT GUESS THE WORD"<<endl;
            cout<<"want to play again press p or q to quit: ";
            char x;
            cin>>x;
            if(x=='p' || x=='P') game();
            else return;
        }
        cout<<"####################################"<<endl;
        int i=0;
        cout<<"#   ";
        for(;i<15;i++){
            if(B[i]==0)cout<<A[i]<<" ";
            if(B[i]==1)cout<<"  ";
        }
        cout<<" #"<<endl;
        cout<<"#       ";
        for(;i<26;i++){
            if(B[i]==0)cout<<A[i]<<" ";
            if(B[i]==1)cout<<"  ";
        }
        cout<<"     #"<<endl;
        cout<<"####################################"<<endl;
        cout<<"THE WORD: ";
        for(int i=0;i<length;i++){
            if(c[i]==0) cout<<" * ";
            if(c[i]==1) cout<<" "<<word[i]<<" ";
        }
        cout<<endl;
        cout<<"GUESS THE LETTER: ";
        char a;
        cin>>a;
        int count3=0;
        for(int j=0;j<length;j++){
            char s=a-32;
            for(int i=0;i<26;i++){
                if(A[i]==s) B[i]=1;
            }
            if(word[j]==a){
                c[j]=1;
                count3=1;
            }
        }
        if(count3==0) number++;
        int count=0;
        for(int i=0;i<length;i++){
            if(c[i]==1) count++;;
        }
        if(count==length){
            cout<<"CONGRATULATIONS YOU WON THE GAME"<<endl;
            cout<<"want to play again press p or q to quit: ";
            char x;
            cin>>x;
            if(x=='p' || x=='P') game();
            else return;
        }
    }
}

int main() {
    //213 words in the file
    srand(static_cast<unsigned int>(time(0)));
    ifstream f;
    f.open("wordlist.txt");
    int count=0;
    while(f){
        getline(f,line[count]);
        count++;
    }
    f.close();
    system("clear");
    cout<<"WELCOME TO TH EHANGMAN GAME"<<endl;
    cout<<"press P to play or Q to quit: ";
    char a;
    cin >> a;
    if(a=='p' || a=='P'){
        game();
    }
    else{
        return 0;
    }
}
