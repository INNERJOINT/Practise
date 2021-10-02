//
//  main.cpp
//  Fstream
//
//  Created by Yukun on 2021/9/14.
//

#include <iostream>
#include <fstream>

void file_it(std::ostream & os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main(int argc, const char * argv[]) {
    using namespace std;
    
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if (!fout.is_open()) {
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal lengths, in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for (int i = 0; i < LIMIT; ++i) {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    
    return 0;
}

void file_it(std::ostream & os, double fo, const double fe[], int n){
    std::ios_base::fmtflags initial;
    initial = os.setf(std::ios_base::fixed);
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(std::ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.l. eyepiece ";
    os.width(15);
    os << "magnificiation " << std::endl;
    for (int i = 0; i < n; i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << std::endl;
    }
    os.setf(initial);
}
