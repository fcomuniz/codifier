//
// Created by pacocas on 3/30/18.
//

#include <gtest/gtest.h>
#include "entropy_analiser/FirstOrderEntropyAnaliser.h"
#include <iostream>
#include <fstream>

TEST(FirstOrderEntropyAnaliser, simpleFileTest){
    entropy_analiser::FirstOrderEntropyAnaliser analiser;
    std::ifstream f("dna2.txt");
    analiser.analyseEntropy(f);
    std::cout << analiser.getEntropy() << std::endl;
}
