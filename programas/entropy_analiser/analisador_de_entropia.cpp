#include <bits/stdc++.h>
#include "FirstOrderEntropyAnaliser.h"

using namespace std;
using namespace entropy_analiser;

int main(){
	ios::sync_with_stdio(false);
	FirstOrderEntropyAnaliser analiser;
    analiser.analyseEntropy(std::cin);
	std::cout << analiser.getEntropy() << std::endl;
	return 0;
}
