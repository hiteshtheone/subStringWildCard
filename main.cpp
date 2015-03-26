//
//  main.cpp
//  substrigWildCard
//
//  Created by hambarkh on 25/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char master[20];
    char substr[20];
    cout << "Enter master string = " ;
    cin >> master;
    cout << "Enter substring string = " ;
    cin >> substr;
    bool isSub = false;
    int i=0,j=0,missedJ = 0;
    while (master[i] != '\0') {
        if (master[i] == substr[j] && substr[j] != '*') {
            isSub = true;
            i++;
            j++;
            if (substr[j] == '\0') {
                break;
            }
        }
        else if (substr[j] == '\\'){
            if (substr[j+1] == '*') {
                if (master[i] == substr[j+1]) {
                    isSub = true;
                    i++;
                    j++;
                    j++;
                    if (substr[j] == '\0') {
                        break;
                    }
                }
                else{
                    isSub = false;
                    i++;
                    j=0;
                }
            }
        }
                 
        else if (substr[j] == '*'){
            isSub = true;
            
            if (master[i] == '*') {
                missedJ++;
            }
            i++;
            if (master[i] == substr[j+1]) {
                j++;
            }
            if (substr[j+1] == '\0') {
                break;
            }
        }
        else{
            j=0;
            isSub = false;
            i++;
        }
    }
    // to take care of case when element after '*' in substr is absent
    if (j + missedJ < strlen(substr)) {
        isSub  = false;
    }
    cout << "IsSub = " << isSub << endl;
    return 0;
}
