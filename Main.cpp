#include <iostream>
#include<vector>
#include<minmax.h>

using namespace std;


vector<string> transMatrix(vector<string> vectorA) {
     
    //vectorA isn't const because in other way operation "+=" for elements won't work
   
    size_t siz = 0;
    vector<string> vectorB;
    
    for (auto& line : vectorA) {
        siz = max(siz, size(line));
    }

    vectorB.reserve(siz);

    for (auto& x : vectorA) {
        size_t curSize = size(x);
            if (curSize < siz) {
                for (int j = 0; j < (siz - curSize); j++) {
                    x += " ";
            }
        }
    }



    for (size_t i = 0; i < siz; i++) {
        
        string cur;

        for (size_t j = 0; j < size(vectorA) ;j++) {

            cur += vectorA[j][i];
            
        }

        vectorB.push_back(cur);
    }

    

    return vectorB;
}

int main() {

    vector<string> vector = {
    "alpha",
    "beta",
    "gamma",
    "epsilon",
    "lambda"
    };

    for (auto& x : transMatrix(vector)) {
        cout << "\""<< x <<"\"\n";
    }
    
    return 0;
}