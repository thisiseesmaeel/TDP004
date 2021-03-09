#include "catch.hpp"

#include "sorted_array.h"

#include <sstream>
#include <string>

TEST_CASE("default initialization")
{
    //INT
    sorted_array<int> a;
    CHECK (a.size() == 0);
    CHECK_THROWS (a.at(0));
    CHECK_THROWS (a.erase(0));
    CHECK_THROWS (a.erase(-5));
    CHECK_THROWS (a.erase(5));
    
    //DOUBLE
    sorted_array<double> b;
    CHECK (b.size() == 0);
    CHECK_THROWS (b.at(0));
    CHECK_THROWS (b.erase(0));
    CHECK_THROWS (b.erase(-5));
    CHECK_THROWS (b.erase(5));
    
    //STRING
    sorted_array<std::string> c;
    CHECK (c.size() == 0);
    CHECK_THROWS (c.at(0));
    CHECK_THROWS (c.erase(0));
    CHECK_THROWS (c.erase(-5));
    CHECK_THROWS (c.erase(5));
}

TEST_CASE("insertion")
{
    //INT
    sorted_array<int> a;
    a.insert(5);
    CHECK (a.size() == 1);
    CHECK (a.at(0) == 5);
    CHECK (a[0] == 5);

    a.insert(1);
    CHECK (a.size() == 2);
    CHECK (a[0] == 1);
    CHECK (a[1] == 5);
    
    //DOUBLE
    sorted_array<double> b;
    b.insert(5.5);
    CHECK (b.size() == 1);
    CHECK (b.at(0) == 5.5);
    CHECK (b[0] == 5.5);

    b.insert(1.5);
    CHECK (b.size() == 2);
    CHECK (b[0] == 1.5);
    CHECK (b[1] == 5.5);
    
    //STRING
    sorted_array<std::string> c;
    c.insert("a");
    CHECK (c.size() == 1);
    CHECK (c.at(0) == "a");
    CHECK (c[0] == "a");

    c.insert("b");
    CHECK (c.size() == 2);
    CHECK (c[0] == "a");
    CHECK (c[1] == "b");
}

TEST_CASE("initialization")
{
    //INT
    sorted_array<int> a{17, 9, 5, 2, -100};
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 2);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9);
    CHECK (a[4] == 17);
		
    a.insert(1);
    CHECK (a.size() == 6);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 2);
    CHECK (a[3] == 5);
    CHECK (a[4] == 9);
    CHECK (a[5] == 17);
		
    a.erase(5);
    CHECK (a.size() == 5);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 2);
    CHECK (a[3] == 5);
    CHECK (a[4] == 9);

    CHECK_THROWS(a.erase(5));

    a.erase(2);
    CHECK (a.size() == 4);
    CHECK (a[0] == -100);
    CHECK (a[1] == 1);
    CHECK (a[2] == 5);
    CHECK (a[3] == 9);
		
    sorted_array<int, Distance<int>> d{{17, 9, 5, 2, -100}, 10};
    CHECK (d.size() == 5);
    CHECK (d[0] == 9);
    CHECK (d[1] == 5);
    CHECK (d[2] == 17);
    CHECK (d[3] == 2);
    CHECK (d[4] == -100);

    d.insert(1);
    CHECK (d.size() == 6);
    CHECK (d[0] == 9);
    CHECK (d[1] == 5);
    CHECK (d[2] == 17);
    CHECK (d[3] == 2);
    CHECK (d[4] == 1);
    CHECK (d[5] == -100);
    
    d.erase(5);
    CHECK (d.size() == 5);
    CHECK (d[0] == 9);
    CHECK (d[1] == 5);
    CHECK (d[2] == 17);
    CHECK (d[3] == 2);
    CHECK (d[4] == 1);
    
    CHECK_THROWS(d.erase(5));

    d.erase(2);
    CHECK (d.size() == 4);
    CHECK (d[0] == 9);
    CHECK (d[1] == 5);
    CHECK (d[2] == 2);
    CHECK (d[3] == 1);
    
    //DOUBLE
    sorted_array<double> b{17.5, 9.5, 5.5, 2.5, -100.5};
    CHECK (b.size() == 5);
    CHECK (b[0] == -100.5);
    CHECK (b[1] == 2.5);
    CHECK (b[2] == 5.5);
    CHECK (b[3] == 9.5);
    CHECK (b[4] == 17.5);

    b.insert(1.5);
    CHECK (b.size() == 6);
    CHECK (b[0] == -100.5);
    CHECK (b[1] == 1.5);
    CHECK (b[2] == 2.5);
    CHECK (b[3] == 5.5);
    CHECK (b[4] == 9.5);
    CHECK (b[5] == 17.5);

    b.erase(5);
    CHECK (b.size() == 5);
    CHECK (b[0] == -100.5);
    CHECK (b[1] == 1.5);
    CHECK (b[2] == 2.5);
    CHECK (b[3] == 5.5);
    CHECK (b[4] == 9.5);

    CHECK_THROWS(b.erase(5));

    b.erase(2);
    CHECK (b.size() == 4);
    CHECK (b[0] == -100.5);
    CHECK (b[1] == 1.5);
    CHECK (b[2] == 5.5);
    CHECK (b[3] == 9.5);
    
    //STRING
    sorted_array<std::string> c{"c", "a", "b", "e", "d"};
    CHECK (c.size() == 5);
    CHECK (c[0] == "a");
    CHECK (c[1] == "b");
    CHECK (c[2] == "c");
    CHECK (c[3] == "d");
    CHECK (c[4] == "e");
		
    c.insert("f");
    CHECK (c.size() == 6);
    CHECK (c[0] == "a");
    CHECK (c[1] == "b");
    CHECK (c[2] == "c");
    CHECK (c[3] == "d");
    CHECK (c[4] == "e");
    CHECK (c[5] == "f");

    c.erase(5);
    CHECK (c.size() == 5);
    CHECK (c[0] == "a");
    CHECK (c[1] == "b");
    CHECK (c[2] == "c");
    CHECK (c[3] == "d");
    CHECK (c[4] == "e");

    CHECK_THROWS(c.erase(5));

    c.erase(2);
    CHECK (c.size() == 4);
    CHECK (c[0] == "a");
    CHECK (c[1] == "b");
    CHECK (c[2] == "d");
    CHECK (c[3] == "e");
}

TEST_CASE("const array")
{
    //INT
    sorted_array<int> const a{1, 2, 3, 4, 5};

    CHECK (a.size() == 5);
    CHECK (a[0] == 1);
    CHECK (a[0] == a.at(0));
    CHECK (a[1] == 2);
    CHECK (a[1] == a.at(1));
    CHECK (a[2] == 3);
    CHECK (a[2] == a.at(2));
    CHECK (a[3] == 4);
    CHECK (a[3] == a.at(3));
    CHECK (a[4] == 5);
    CHECK (a[4] == a.at(4));
    CHECK_THROWS (a.at(5));
    
    //DOUBLE
    sorted_array<double> const b{1.5, 2.5, 3.5, 4.5, 5.5};

    CHECK (b.size() == 5);
    CHECK (b[0] == 1.5);
    CHECK (b[0] == b.at(0));
    CHECK (b[1] == 2.5);
    CHECK (b[1] == b.at(1));
    CHECK (b[2] == 3.5);
    CHECK (b[2] == b.at(2));
    CHECK (b[3] == 4.5);
    CHECK (b[3] == b.at(3));
    CHECK (b[4] == 5.5);
    CHECK (b[4] == b.at(4));
    CHECK_THROWS (b.at(5));
    
    //STRING
    sorted_array<std::string> const c{"1", "2", "3", "4", "5"};

    CHECK (c.size() == 5);
    CHECK (c[0] == "1");
    CHECK (c[0] == c.at(0));
    CHECK (c[1] == "2");
    CHECK (c[1] == c.at(1));
    CHECK (c[2] == "3");
    CHECK (c[2] == c.at(2));
    CHECK (c[3] == "4");
    CHECK (c[3] == c.at(3));
    CHECK (c[4] == "5");
    CHECK (c[4] == c.at(4));
    CHECK_THROWS (c.at(5));
}

TEST_CASE("print empty")
{
    //INT
    std::ostringstream oss;
    sorted_array<int> empty;
    oss << empty;
    CHECK (oss.str() == "{}");
    
    //DOUBLE
    std::ostringstream oss1;
    sorted_array<double> empty1;
    oss1 << empty1;
    CHECK (oss1.str() == "{}");
    
    //STRING
    std::ostringstream oss2;
    sorted_array<std::string> empty2;
    oss2 << empty2;
    CHECK (oss2.str() == "{}");
}

TEST_CASE("print")
{

    //INT
    std::ostringstream oss;
    sorted_array<int> array{2, 3, 5, 7, 11, 13};
    oss << array;
    CHECK (oss.str() == "{2, 3, 5, 7, 11, 13}");
    
    std::ostringstream oss3;
    sorted_array<int, Distance<int>> array3{{2, 3, 5, 7, 11, 12}, 8};
    oss3 << array3;
    CHECK (oss3.str() == "{7, 5, 11, 12, 3, 2}");
    
    //DOUBLE
    std::ostringstream oss1;
    sorted_array<double> array1{2.5, 3.5, 5.5, 7.5, 11.5, 13.5};
    oss1 << array1;
    CHECK (oss1.str() == "{2.5, 3.5, 5.5, 7.5, 11.5, 13.5}");
    
    std::ostringstream oss4;
    sorted_array<double, Distance<double>> array4{{2.5, 3.5, 5.5, 7.5, 11.5, 13.5}, 4.2};
    oss4 << array4;
    CHECK (oss4.str() == "{3.5, 5.5, 2.5, 7.5, 11.5, 13.5}");
		
    //STRING
    std::ostringstream oss2;
    sorted_array<std::string> array2{"ba", "ab", "gt", "ge", "e", "f"};
    oss2 << array2;
    CHECK (oss2.str() == "{ab, ba, e, f, ge, gt}");
}

//g++ -c test_main.cc
//g++ test_main.o sorted_array.h sorted_array_test.cc
//./a.out
