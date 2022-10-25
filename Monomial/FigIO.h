#pragma once
#include "Monomial.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

istream& operator>>(istream& in, monomial& mono);

ostream& operator<<(ostream& out, monomial& mono);
