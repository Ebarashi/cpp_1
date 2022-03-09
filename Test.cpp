#include <algorithm>
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input") {

	//regular cases
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces( "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"));
	
	CHECK(mat(7,7,'(',')') == nospaces( "(((((((\n"
										"()))))(\n"
										"()((()(\n"
										"()()()(\n"
										"()((()(\n"
										"()))))(\n"
										"(((((((\n"));
	
	CHECK(nospaces(mat(11, 5, '@', '-')) == nospaces("@@@@@@@@@@@\n"
													 "@---------@\n"
													 "@-@@@@@@@-@\n"
													 "@---------@\n"
													 "@@@@@@@@@@@\n"));												 
	
	
	CHECK(nospaces(mat(5, 3, '^', '&')) == nospaces("^^^^^\n"
													"^&&&^\n"
													"^^^^^\n"));
	
	//same characters
	CHECK(nospaces(mat(1, 1, '-', '-')) == "-");

	CHECK(mat(1,1,'*','*') == "*");

	CHECK(mat(5,5,'*','*') == nospaces("*****\n"
									   "*****\n"
									   "*****\n"
									   "*****\n"
									   "*****\n"));
	
	CHECK(mat(3,7,'<','<') == nospaces("<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"
									   "<<<<<\n"));

	//different characters  
    CHECK(mat(1,1,'*','-') == "*");
    CHECK(mat(1,1,'-','*') == "-");



	//letters
	CHECK((mat(5, 1, 'z', '+')) == nospaces("zzzzz\n"));
    CHECK((mat(1, 5, 'p', '+')) == nospaces("p\n"
											"p\n"
											"p\n"
											"p\n"
											"p\n"));


    CHECK(mat(19,17,'X','#') == nospaces("XXXXXXXXXXXXXXX\n"
										 "X#############X\n"
										 "X#XXXXXXXXXXX#X\n"
										 "X#X#########X#X\n"
										 "X#X#XXXXXXX#X#X\n"
										 "X#X#X#####X#X#X\n"
										 "X#X#X#XXX#X#X#X\n"
										 "X#X#X#####X#X#X\n"
										 "X#X#XXXXXXX#X#X\n"
										 "X#X#########X#X\n"
										 "X#XXXXXXXXXXX#X\n"
										 "X#############X\n"
										 "XXXXXXXXXXXXXXX\n"));


	CHECK(mat(0,0,'/','\\') == nospaces("\n"));

}

TEST_CASE("Bad input") {
    
	CHECK_THROWS(mat(10, 5, '$', '%'));


	//negtive values
	for (int j = -1; j > -5; j--)
    {
        
            CHECK_THROWS(mat(j, j, 'e', 'i'));
            CHECK_THROWS(mat(2, j, 'l', 'o'));
            CHECK_THROWS(mat(j, 5, 'n', 'b'));
    }
	
	//even values
	for (int j = 1; j < 5; j++)
    {
        if (j % 2 == 0)
        {
            CHECK_THROWS(mat(j, j, 'e', 'i')); 
            CHECK_THROWS(mat(3, j, 'l', 'o'));
            CHECK_THROWS(mat(j, 5, 'n', 'b'));
        }
    }

	


}







