/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 18:54
 */

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    short pos, i, l, prev;
    bool test = false;
    while (getline(stream, line)) {
        l = line.length();
        for (i = 0; i < l; i++) {
            if (line[i] == 'C') {
                pos = i;
                break;
            }
            if (line[i] == '_') {
                pos = i;
            }
        }
        
        if (test) {
            if (prev < pos) {
                line[pos] = '\\';
                prev = pos;
            }
            else if (prev > pos) {
                line[pos] = '/';
                prev = pos;
            }
            else {
                line[pos] = '|';
                prev = pos;
                
            }
        }
        else {  
            line[pos] = '|';
            prev = pos;
        }
        
        cout << line << endl;
        test = true;
    }
    return 0;
}