#include"SortArray.h"
#include"SelectionS.h"
#include"SATest.h"


int main() {
    cout << "Selection Sort: " << endl;
    SATest pTestSelect(new SelectionS());
    pTestSelect.run(cin, cout);
    return 0;
}