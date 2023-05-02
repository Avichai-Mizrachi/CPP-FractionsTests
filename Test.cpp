#include "sources/Fraction.hpp"
#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <stdbool.h>
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("First test")
{
    Fraction a(3, 4);
    Fraction b(1, 2);

    CHECK(a == b);
    CHECK(a != b);
    CHECK(a < b);
    CHECK(a > b);
    CHECK((a++) == (b++));
}

TEST_CASE("Second test")
{
    Fraction a(4);
    Fraction b(4, 1);

    CHECK(a == b);
    CHECK(a != b);
    CHECK(a < b);
    CHECK(a > b);
    CHECK((a++) == (b++));
}

TEST_CASE("Third test")
{
    CHECK((Fraction(1,8))==0.125);
    CHECK((Fraction(1,4))==0.25);
    CHECK((Fraction(1,2))==0.5);
    CHECK((Fraction(253,1000))==0.253);
    CHECK((Fraction(3,4))==0.750);
    CHECK((Fraction(321,500))==0.642);
    CHECK((Fraction(421,500))==0.842);
    CHECK((Fraction(27,50))==0.54);
    CHECK((Fraction(1,10))==0.1);
    CHECK((Fraction(1,100))==0.01);
    CHECK((Fraction(1,1000))==0.001);
    CHECK((Fraction(2,8))==0.25);
}

TEST_CASE("Test 4") {
    CHECK_THROWS(Fraction(4, 0));
    CHECK_THROWS(Fraction(-4, 0));
    CHECK_THROWS(Fraction(0, 0));
}