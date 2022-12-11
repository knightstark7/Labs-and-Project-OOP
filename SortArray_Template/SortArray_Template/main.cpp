#include"SortArray.h"
#include"SATest.h"
#include "ProgramFrame.h"
#include "SelectionS.h"
#include "InsertionS.h"
#include "InterchangeS.h"

int main() {
    cout << "Selection Sort: " << endl;
    SATest<int> pTestSelect(new InterchangeS<int>());
    pTestSelect.run(cin, cout);
    return 0;
}