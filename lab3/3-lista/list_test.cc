// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// Note that the testcases outline here serve simply as inspiration
// you are not required to implement these tests, but you need to
// create tests for your list, so it might be a good idea to use
// these tests as a basis.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "List.h"

#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}

// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.

TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);
  
    REQUIRE( l.is_empty() == false );
    REQUIRE( l.size() == 1 );
  
}

SCENARIO( "Empty lists" ) 
{
  
    GIVEN( "An empty list" ) 
    {
	Sorted_List l{};

	REQUIRE( l.is_empty() );
	REQUIRE( l.size() == 0 );
  
	WHEN( "an item is inserted" )
	{

	    // insert an item
      l.insert(5);
      
	    THEN( "the size increase and the item is first in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 1 );
		REQUIRE( l.get_value(1) == 5 );
	    }
	}
    
	WHEN( "an item is removed" )
	{

	    // remove an item
      l.remove(5);
      
	    THEN( "the list is still empty" )
	    {
		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );
	    }
	}
  WHEN( "the list is copied to a new list" )
  {
			// copy your list to a new variable (copy constructor)
			Sorted_List l_copy{l};
		
			THEN( "the new list is also empty" )
			{
		// add your REQUIRE statements
		REQUIRE(l_copy.is_empty());
			}
	}

  WHEN( "the list is copied to an existing non-empty list" )
	{
			// create and fill a list to act as the existing list
			// copy (assign) your empty list to the existing
			Sorted_List l_copy{};
			l_copy = l;
           
			THEN( "the existing list is also empty" )
			{
		REQUIRE(l_copy.is_empty());
		// add your REQUIRE statements
			}
	}
	
    }
}

SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {

	// create the given scenario
  Sorted_List l{};
  l.insert(5);
  
	WHEN( "a smaller item is inserted" )
	{
			l.insert(4);
			
	    THEN( "new item is first in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 2 );
		REQUIRE( l.get_value(1) == 4 );
	    }
	}
	WHEN( "a larger item is inserted" )
	{
			l.insert(6);
			
	    THEN( "new item is last in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 2 );
		REQUIRE( l.get_value(2) == 6 );
	    }
	}
	WHEN( "an item is removed" )
	{
			l.remove(5);
			
	    THEN( "list is empty" )
	    {
		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );
	    }
	}
	WHEN( "the list is copied to a new list" )
	{
			Sorted_List l_copy{l};
			
			THEN( "new item will be the copied value" )
			{
		REQUIRE(l.get_value(1) == 5);
			}
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
			Sorted_List l_copy;
			l_copy = l;
			
			THEN( "new item will be the copied value" )
			{
		REQUIRE(l.get_value(1) == 5);
			}
	}
    }
}

SCENARIO( "Multi-item lists" )
{
  
    GIVEN( "A list with five items in it" )
    {
  
  Sorted_List l{};
  l.insert(5);
  l.insert(10);
  l.insert(15);
  l.insert(20);
  l.insert(25);
  
	// create the given scenario and all THEN statements
	// and all REQUIRE statements
    
	WHEN( "an item smaller than all other is inserted" )
	{
			l.insert(1);
			
	    THEN( "new item is first in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 6 );
		REQUIRE( l.get_value(1) == 1 );
	    }
	}
	WHEN( "an item larger than all other is inserted" )
	{
			l.insert(30);
			
	    THEN( "new item is last in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 6 );
		REQUIRE( l.get_value(6) == 30 );
	    }
	}
	WHEN( "an item smaller than all but one item is inserted" )
	{
			l.insert(7);
			
	    THEN( "new item is second first in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 6 );
		REQUIRE( l.get_value(2) == 7 );
	    }
	}
	WHEN( "an item larger than all but one item is inserted" )
	{
			l.insert(23);
			
	    THEN( "new item is second last in the list" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 6 );
		REQUIRE( l.get_value(5) == 23 );
	    }
	}
	WHEN( "an item is removed" )
	{
			l.remove(10);
			
	    THEN( "the list is 4 elements long" )
	    {
		REQUIRE( l.is_empty() == false );
		REQUIRE( l.size() == 4 );
	    }
	}
	WHEN( "all items are removed" )
	{
			l.remove(5);
			l.remove(10);
			l.remove(15);
			l.remove(20);
			l.remove(25);
			
	    THEN( "the list is 4 elements long" )
	    {
		REQUIRE( l.is_empty() );
		REQUIRE( l.size() == 0 );
	    }
	}
	WHEN( "the list is copied to a new list" )
	{
			Sorted_List l_copy{l};
			
			THEN("First num is 5 and last is 25")
			{
		REQUIRE(l.is_empty() == false);
		REQUIRE(l.size() == 5);
		REQUIRE(l.get_value(1) == 5);
		REQUIRE(l.get_value(5) == 25);
			}
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
			Sorted_List l_copy{};
			l_copy = l;
			
			THEN("First num is 5 and last is 25")
			{
		REQUIRE(l.is_empty() == false);
		REQUIRE(l.size() == 5);
		REQUIRE(l.get_value(1) == 5);
		REQUIRE(l.get_value(5) == 25);
			}
	}
    }
}

SCENARIO( "Lists can be copied" )
{

	GIVEN( "A list with five items in it, and a new copy of that list" )
	{
		Sorted_List l{};
		l.insert(6);
		l.insert(7);
		l.insert(7);
		l.insert(7);
		l.insert(9);
		Sorted_List l_copy{l};
      
	WHEN( "the original list is changed" )
	{
		l.insert(8);
		
		THEN( "the copy remain unmodified" )
		{
	REQUIRE(l.size() == 6);
		}
	}
	
	WHEN( "the copied list is changed" )
	{
		l_copy.insert(8);
		
		THEN( "the original remain unmodified" )
		{
	REQUIRE(l.size() == 5);
		}
	}
	
   }
}

SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
    
	// create the given list with 1000 random items
	std::random_device rd;
	std::uniform_int_distribution<int> uniform(1,1000);
  
  Sorted_List l{};
   
	for (int i{0}; i < 1000; ++i)
	{
	    int random { uniform(rd) }; // generate a random number
	    l.insert(random); // insert into list
	}
    
	WHEN( "the list have 1000 random numbers inserted" )
	{
	    for (int i{0}; i < 1000; ++i)
			{
			  int random { uniform(rd) }; // generate a random number
			  l.insert(random); // insert into list
			}
			
	    // (assumes unique inserts or duplicates allowed)
	    THEN( "the list have 2000 items in correct order" )
	    {
		REQUIRE( l.size() == 2000 );
		
		for (int i{0}; i < 2000; ++i)
		{
			REQUIRE( l.get_value(i) <= l.get_value(i+1) );
		}
	    }
	}
	
	WHEN( "the list have 2000 random numbers removed" )
	{
			for (int i{0}; i < 2000; ++i)
			{
			  int element = l.get_value(1);
			  l.remove(element);
			}
			
	    // (assumes successful removes)
	    THEN( "the list is empty" )
	    {
		REQUIRE( l.is_empty() );
	    }
	}
	
    }
}

Sorted_List trigger_move(Sorted_List l)
{
	// do some (any) modification to list
	l.remove(5);
	return l;
}

SCENARIO( "Lists can be passed to functions" )
{

	GIVEN( "A list with 5 items in it" )
		{

			Sorted_List given{};
			
			// insert 5 items
			given.insert(5);
			given.insert(6);
			given.insert(7);
			given.insert(8);
			given.insert(9);
        
	WHEN( "the list is passed to trigger_move()" )
	{
           
		Sorted_List l{ trigger_move(given) };
           
		THEN( "the given list remain and the result have the change" )
		{
	REQUIRE(given.size() == 5);
	REQUIRE(l.size() == 4);
		}
	}
	   
    }
}

// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert): 
 
void use_const_list(Sorted_List const& l)
{
   Sorted_List l2;
   // perform every operation that do not modify the list here
   l2.get_value(1) == 5;
   l2.size();
   l2.is_empty() == false;

}

