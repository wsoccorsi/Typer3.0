//
// Created by William  Soccorsi on 12/17/18.
//

#ifndef TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SENTENCE_H
#define TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SENTENCE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Sentence {

public:

    Sentence();

    string generateString();

    string getString() const;

    void setString(string s);

private:
    string s;

};


#endif //TYPER3_0_SHE_DIDN_T_WORK_SO_GOOD_MR_STARK_SENTENCE_H
