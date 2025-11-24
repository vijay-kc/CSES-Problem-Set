#include<bits/stdc++.h>
using namespace std;
int main (){
 int n;
    cin >> n;
    vector<string> gray_code;
    gray_code.push_back("");
    for (int i = 0; i < n; i++) {
        int size = gray_code.size();
        for (int j = size - 1; j >= 0; j--) {
            gray_code.push_back(gray_code[j]);
        }
        size *= 2;
        for (int j = 0; j < size; j++) {
            if (j < gray_code.size() / 2) {
                gray_code[j] += "0";
            } else {
                gray_code[j] += "1";
            }
        }
    }
    for (int i = 0; i < gray_code.size(); i++) {
        cout << gray_code[i] << endl;
    }
    	
return 0;
}