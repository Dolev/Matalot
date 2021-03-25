 /* 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <DOLEV HINDY>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));
    /* Add more checks here */
    CHECK(snowman(11114412) == string("_===_\n(.,.)\n( : )\n(" ")"));
    CHECK(snowman(11114414) == string("_===_\n(.,.)\n( : )\n(   )"));
    CHECK(snowman(11114413) == string("_===_\n(.,.)\n( : )\n(___)"));
    CHECK(snowman(11114434) == string("_===_\n(.,.)\n(> <)\n(   )"));
    CHECK(snowman(11114433) == string("_===_\n(.,.)\n(> <)\n(___)"));
    CHECK(snowman(11114432) == string("_===_\n(.,.)\n(> <)\n(" ")"));
    CHECK(snowman(11114424) == string("_===_\n(.,.)\n([ ])\n(   )"));
    CHECK(snowman(11114423) == string("_===_\n(.,.)\n([ ])\n(___)"));
    CHECK(snowman(11114422) == string("_===_\n(.,.)\n([ ])\n(" ")"));
    CHECK(snowman(11114444) == string("_===_\n(.,.)\n(   )\n(   )"));
    CHECK(snowman(11114443) == string("_===_\n(.,.)\n(   )\n(___)"));
    CHECK(snowman(11114342) == string("_===_\n(.,.)/\n(   )\n(" ")"));

}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));  // 5- out of options
    /* Add more checks here */
    CHECK_THROWS(snowman(444));//not enough parameters   *maybe
    //CHECK_THROWS(snowman(1234a32)); //Char
    CHECK_THROWS(snowman(15114411));
    CHECK_THROWS(snowman(66666666)); //6 - out of options
    CHECK_THROWS(snowman(111144111));// 9 -Chars   
    CHECK_THROWS(snowman(1+114411)); // WRONG INPUT
    CHECK_THROWS(snowman(15114411));
    CHECK_THROWS(snowman(15176411));
    CHECK_THROWS(snowman(15*14411));
    CHECK_THROWS(snowman(187876711));
    CHECK_THROWS(snowman(4911));
    CHECK_THROWS(snowman(14411));
    CHECK_THROWS(snowman(1975411));
    CHECK_THROWS(snowman(1511>11));
    CHECK_THROWS(snowman(1+114411));

}


/* Add more test cases here */
TEST_CASE("More bad snowman code") {

}
