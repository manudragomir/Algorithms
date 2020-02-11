#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.in");

const int NMax = (int)2e5+5;
char s[NMax];

bool areLower(int x, int visi[]){
    for(int i=0; i<x; i++){
        if(visi[i]){
            return true;
        }
    }
    return false;
}

int main()
{
    int T; fin >> T;
    while(T--){
        int dig; cin >> dig;
        cin.get();
        cin >> s;
        string res{""};
        int visi[10];
        for(int i=0; i<10; i++){
            visi[i] = 0;
        }

        for(int i=0; i < dig; i++){
            visi[ s[i] - '0' ]++;
        }

        int lowest2{0};
        bool not_ok{false};
        for(int i=0; i < dig; i++){
            int currDigit = s[i] - '0';
            if(areLower(currDigit, visi) == false){
                res.push_back('1');
                visi[currDigit]--;
            }
            else{
                if(lowest2 > currDigit){
                    not_ok = true;
                    break;
                }
                else{
                    res.push_back('2');
                    lowest2 = currDigit;
                }
            }
        }

        if(not_ok == true){
            cout << "-\n";
        }
        else{
            cout << res << '\n';
        }
    }
    return 0;
}
