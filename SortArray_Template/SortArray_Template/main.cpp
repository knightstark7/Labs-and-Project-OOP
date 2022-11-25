#include"SortArray.h"
#include"SATest.h"
#include "ProgramFrame.h"
#include "SelectionS.h"

int main() {
    cout << "Selection Sort: " << endl;
    SATest<int> pTestSelect(new SelectionS<int>());
    pTestSelect.run(cin, cout);
    return 0;
}