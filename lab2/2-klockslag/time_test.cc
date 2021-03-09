//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"

#include <iostream>

// här lägger ni era testfall. 
// Jobba enligt TDD; 
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

// Kommentar: Bra tester!

TEST_CASE("Test constructor and to_string()") {
	Time t1{};
	REQUIRE(t1.to_string() == "00:00:00");
	REQUIRE(t1.to_string(true) == "00:00:00 am");
	
	Time t2{12, 40, 50};
	REQUIRE(t2.to_string() == "12:40:50");
	REQUIRE(t2.to_string(true) == "12:40:50 pm");
}

TEST_CASE("Test is_valid()") {
	Time t1{25, 23, 32};
	Time t2{23, 61, 45};
	Time t3{22, 34, 63};
	Time t4{23, 23, 34};

	REQUIRE(t1.is_valid() == false);
	REQUIRE(t2.is_valid() == false);
	REQUIRE(t3.is_valid() == false);
	REQUIRE(t4.is_valid() == true);
}

TEST_CASE("Test operator ++ (pre-increment)") {
	Time t1{};
	++t1;
	REQUIRE(t1.to_string() == "00:00:01");
	
	Time t2{23, 59, 59};
	++t2;
	REQUIRE(t2.to_string() == "00:00:00");
	
	Time t3{12, 59, 59};
	++t3;
	REQUIRE(t3.to_string() == "13:00:00");
	
	Time t4{12, 24, 59};
	++t4;
	REQUIRE(t4.to_string() == "12:25:00");
}

TEST_CASE("Test operator ++ (post-increment)") {
	Time t1{};
	Time j1 = t1++;
	REQUIRE(j1.to_string() == "00:00:00");
	REQUIRE(t1.to_string() == "00:00:01");
	
	Time t2{23, 59, 59};
	t2++;
	REQUIRE(t2.to_string() == "00:00:00");
	
	Time t3{12, 59, 59};
	t3++;
	REQUIRE(t3.to_string() == "13:00:00");
	
	Time t4{12, 24, 59};
	t4++;
	REQUIRE(t4.to_string() == "12:25:00");
}

TEST_CASE("Test operator -- (pre-increment)") {
	Time t1{12, 24, 15};
	--t1;
	REQUIRE(t1.to_string() == "12:24:14");
	
	Time t2{};
	--t2;
	REQUIRE(t2.to_string() == "23:59:59");
	
	Time t3{12, 0, 0};
	--t3;
	REQUIRE(t3.to_string() == "11:59:59");
	
	Time t4{12, 24, 0};
	--t4;
	REQUIRE(t4.to_string() == "12:23:59");
}

TEST_CASE("Test operator -- (post-increment)") {
	Time t1{12, 24, 15};
	Time j1 = t1--;
	REQUIRE(j1.to_string() == "12:24:15");
	REQUIRE(t1.to_string() == "12:24:14");
	
	Time t2{};
	t2--;
	REQUIRE(t2.to_string() == "23:59:59");
	
	Time t3{12, 0, 0};
	t3--;
	REQUIRE(t3.to_string() == "11:59:59");
	
	Time t4{12, 24, 0};
	t4--;
	REQUIRE(t4.to_string() == "12:23:59");
}

TEST_CASE("Test operator +") {
	Time t1{};
	Time t2{t1 + 5};
	REQUIRE(t1.to_string() == "00:00:00");
	REQUIRE(t2.to_string() == "00:00:05");
	
	Time t3{t1 + 121};
	REQUIRE(t3.to_string() == "00:02:01");
	
	Time t4{t1 + 10000};
	REQUIRE(t4.to_string() == "02:46:40");
	
	Time t5{t1 + 100000};
	REQUIRE(t5.to_string() == "03:46:40");
}
	
TEST_CASE("Test operator -") {
	Time t1{};
	Time t2{t1 - 1};
	REQUIRE(t1.to_string() == "00:00:00");
	REQUIRE(t2.to_string() == "23:59:59");
	
	Time t3{t1 - 61};
	REQUIRE(t3.to_string() == "23:58:59");
	
	Time t4{t1 - 80000};
	REQUIRE(t4.to_string() == "01:46:40");
	
	Time t5{t1 - 100000};
	REQUIRE(t5.to_string() == "20:13:20");
}

TEST_CASE("Test operator == and !=") {
	Time t1{};
	Time t2{};
	Time t3{12, 30, 40};
	
	REQUIRE((t1 == t2) == true);
	REQUIRE((t1 == t3) == false);
	
	REQUIRE((t1 != t2) == false);
	REQUIRE((t1 != t3) == true);
}

TEST_CASE("Test operator > and <") {
  Time t1{};
  Time t2{};
  Time t3{13, 12, 12};

  REQUIRE((t1 > t2) == false);
  REQUIRE((t1 > t3) == false);
  
  REQUIRE((t1 < t2) == false);
  REQUIRE((t1 < t3) == true);
}

TEST_CASE("Test operator >= and <=") {
  Time t1{};
  Time t2{};
  Time t3{12, 14, 45};
  
  REQUIRE((t1 >= t2) == true);
  REQUIRE((t1 >= t3) == false);

  REQUIRE((t1 <= t2) == true);
  REQUIRE((t1 <= t3) == false);
}

TEST_CASE("Test operator <<") {
	Time t1{};
	
	std::ostringstream a;
  
  a << t1;
  REQUIRE(a.str() == "00:00:00");
}

TEST_CASE("Test operator >>") {
  Time t1{};
  Time t2{25, 00, 00};
  Time t3{00, 61, 00};
  Time t4{00, 00, 61};
  
  std::istringstream a("00:00:00");
  std::istringstream b("25:00:00");
  std::istringstream c("00:61:00");
  std::istringstream d("00:00:61");
  
	a >> t1;
	REQUIRE(a.fail() == false);
	
	b >> t2;
	REQUIRE(b.fail()); //true
	
	c >> t3;
	REQUIRE(c.fail()); //true
	
	d >> t4;
	REQUIRE(d.fail()); //true
}

//g++ -c test_main.cc
//g++ test_main.o Time.cc time_test.cc
//./a.out

