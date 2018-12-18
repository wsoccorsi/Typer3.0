//
// Created by William  Soccorsi on 12/17/18.
//

#include "Sentence.h"


Sentence::Sentence() {
    s = "";
}

string Sentence::generateString() {

    //reading sentences out of a file into an array
    ifstream f_in("sentences.txt"); //why can't it find...

    int numOfLines = 0;
    vector <string> lines(numOfLines); // # of lines here (instead of using push_back)

    string Line;

    while (getline(f_in, Line, '\n')) {
        lines.push_back(Line);
        numOfLines++;
    }

    //reading selected sentence into an array
    ifstream f_in2("sentences.txt");
    int max = numOfLines;
    int min = 0;
    int randNum = min + rand() % max;
    string sentenceSelected = lines[randNum];
    cout << "This is the selected sentence: " << sentenceSelected << endl;
    return sentenceSelected;


}

string Sentence::getString() const{
    return s;
}

void Sentence::setString(string sentence) {
    s = sentence;
}