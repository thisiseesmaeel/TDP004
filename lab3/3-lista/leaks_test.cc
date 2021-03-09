#include "catch.hpp"
#include "List.h"


TEST_CASE("searching for leaks in insert/remove")
{
	Sorted_List l{};
	l.insert(5);
	l.insert(10);
	l.insert(15);
	l.insert(20);
	l.insert(25);

	l.remove(10);

	REQUIRE(l.is_empty() == false);
	REQUIRE(l.size() == 4);
}
