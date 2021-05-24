#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        
            cout << std::hex << std::left << std::showbase << std::nouppercase; // formatting
            cout << (long long) A << endl; // actual printed part

            
            cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2); // formatting
            cout << B << endl; // actual printed part

            
            cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9); // formatting
            cout << C << endl; // actual printed part
    }
    return 0;

}