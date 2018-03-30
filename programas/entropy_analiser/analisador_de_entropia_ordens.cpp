#include <bits/stdc++.h>

using namespace std;




int main(int argc, char ** argv){
	ios::sync_with_stdio(false);

	long long freq [1 << 8*sizeof(char)];
	long long nOfChars = 0;
	char c;
	int n = 1 << 8*(sizeof(char));
	for(int i = 0 ;  i < n; i++){
		freq[i] = 0;
	}
	while(cin >> c){
		freq[c]+=1;
		nOfChars++;
	}
	double entropy = 0;
	for(int i = 0; i < n; i++){
		if(freq[i] != 0){
			double f = ((double)freq[i])/nOfChars;
			entropy += -f*log2(f);
		}
	}
	cout << entropy << endl;



	return 0;
}
