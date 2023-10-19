#include <array>
#include <vector>


#include "../../EducationLibs/Containers/List.h"
#include "../../EducationLibs/Containers/Vector.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ContainersTests
{
	TEST_CLASS(ContainersTests)
	{
	public:
		
		TEST_METHOD( Test_std_array )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_MyArray )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_std_vector )
		{
			// push_back
			// capacity
			// size
			// at

			std::vector<int> vec;
			vec.push_back( 3 );	// rvalue
			Assert::AreEqual( 1, ( int )vec.capacity() );
			vec.push_back( 2 );
			Assert::AreEqual( 2, ( int )vec.capacity() );
			vec.push_back( 1 );
			Assert::AreEqual( 3, ( int )vec.capacity() );
			vec.push_back( 0 );
			Assert::AreEqual( 4, ( int )vec.capacity() );
			int a = 0;
			vec.push_back( a );	// lvalue
			Assert::AreEqual( 6, ( int )vec.capacity() );
			Assert::AreEqual( 5, ( int )vec.size() );
			Assert::AreEqual( 3, ( int )vec.at(0) );
			Assert::AreEqual( 2, ( int )vec.at(1) );
			Assert::AreEqual( 1, ( int )vec.at(2) );
			Assert::AreEqual( 0, ( int )vec.at(3) );
			struct  Functor {
				std::vector<int> vec_;
				void operator () () {
					vec_.at( 5 );
				}
			};
			Assert::ExpectException < std::out_of_range, Functor >( Functor{ vec } );

			// pop_back
			// empty

			Assert::IsTrue( !vec.empty() );
			vec.pop_back();
			Assert::AreEqual( 4, ( int )vec.size() );
			vec.pop_back();
			Assert::AreEqual( 3, ( int )vec.size() );
			vec.pop_back();
			Assert::AreEqual( 2, ( int )vec.size() );
			vec.pop_back();
			Assert::AreEqual( 1, ( int )vec.size() );
			vec.pop_back();
			Assert::AreEqual( 0, ( int )vec.size() );
			Assert::AreEqual( 6, ( int )vec.capacity() );
			Assert::IsTrue( vec.empty() );

			// reserve (about capacity)

			vec.reserve(8);
			Assert::AreEqual( 8, ( int )vec.capacity() );
			vec.reserve( 6 );															// doesn't reduce as shrink_to_fit!
			Assert::AreEqual( 8, ( int )vec.capacity() );	// doesn't reduce as shrink_to_fit!
			vec.push_back( 10 );
			Assert::AreEqual( 1, ( int )vec.size() );
			Assert::AreEqual( 10, ( int )vec.at(0) );
			vec.reserve( 16 );
			Assert::AreEqual( 16, ( int )vec.capacity() );
			Assert::AreEqual( 1, ( int )vec.size() );
			Assert::AreEqual( 10, ( int )vec.at( 0 ) );

			// clear

			vec.clear();
			Assert::AreEqual( 16, ( int )vec.capacity() );
			Assert::AreEqual( 0, ( int )vec.size() );
			vec.shrink_to_fit();
			Assert::AreEqual( 0, ( int )vec.capacity() );
			Assert::IsTrue( vec.empty() );

			// shrink_to_fit (C++11)

			vec.push_back( 11 );
			vec.push_back( 12 );
			vec.push_back( 13 );
			Assert::AreEqual( 3, ( int )vec.size() );
			vec.shrink_to_fit();
			Assert::AreEqual( 3, ( int )vec.capacity() );
			
			//resize (about size)
			vec.resize( 1 );
			Assert::AreEqual( 1, ( int )vec.size() );
			Assert::AreEqual( 3, ( int )vec.capacity() );
			Assert::AreEqual( 11, ( int )vec.at( 0 ) );
			vec.resize( 5 );
			Assert::AreEqual( 5, ( int )vec.size() );
			Assert::AreEqual( 5, ( int )vec.capacity() );
			Assert::AreEqual( 11, ( int )vec.at( 0 ) );
			vec.resize( 1, 3 );
			Assert::AreEqual( 1, ( int )vec.size() );
			Assert::AreEqual( 5, ( int )vec.capacity() );
			Assert::AreEqual( 11, ( int )vec.at( 0 ) );
			vec.resize( 7, 66 );
			Assert::AreEqual( 7, ( int )vec.size() );
			Assert::AreEqual( 7, ( int )vec.capacity() );
			Assert::AreEqual( 11, ( int )vec.at( 0 ) );
			Assert::AreEqual( 66, ( int )vec.at( 6 ) );
			Assert::AreEqual( 66, ( int )vec.at( 6 ) );
			Assert::AreEqual( 66, ( int )vec.at( 6 ) );

			{
				std::vector<int> vec;
				vec.resize(1);
				auto it = vec.begin();
				//vec.resize( 16 );
				auto it2 = vec.begin();	// realloc!
				//Assert::IsTrue( it != it2 );
			}

			{
				std::vector<int> vec( 5, 3 );
				Assert::AreEqual( 5, ( int )vec.size() );
				Assert::AreEqual( 5, ( int )vec.capacity() );

				vec.resize( 1, 3 );
				Assert::AreEqual( 1, ( int )vec.size() );
				Assert::AreEqual( 5, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );

				vec.resize( 3, 66 );
				Assert::AreEqual( 3, ( int )vec.size() );
				Assert::AreEqual( 5, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );
				Assert::AreEqual( 66, ( int )vec.at( 1 ) );
				Assert::AreEqual( 66, ( int )vec.at( 2 ) );

				vec.resize( 7, 77 );
				Assert::AreEqual( 7, ( int )vec.size() );
				Assert::AreEqual( 7, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );
				Assert::AreEqual( 66, ( int )vec.at( 1 ) );
				Assert::AreEqual( 66, ( int )vec.at( 2 ) );
				Assert::AreEqual( 77, ( int )vec.at( 3 ) );
				Assert::AreEqual( 77, ( int )vec.at( 4 ) );
				Assert::AreEqual( 77, ( int )vec.at( 5 ) );
				Assert::AreEqual( 77, ( int )vec.at( 6 ) );
			}

			// default constructor
			{
				std::vector<int> vec(3);
				Assert::AreEqual( 3, ( int )vec.size() );
				Assert::AreEqual( 3, ( int )vec.capacity() );
			}

			// []
			{
				std::vector<int> vec( 3 );
				vec.push_back( 4 );
				Assert::AreEqual( 4, ( int )vec.capacity() );
				vec.push_back( 6 );
				Assert::AreEqual( 6, ( int )vec.capacity() );
				Assert::AreEqual( 4, ( int )vec[ 3 ] );
				Assert::AreEqual( 6, ( int )vec[ 4 ] );
				const std::vector<int> const_vec( 5 );
				auto & elem = const_vec[ 4 ];
				//elem = 3;	// error: const elem
			}
			{
				std::vector<int> vec;
				vec.push_back( 1 );
				Assert::AreEqual( 1, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 2, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 3, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 4, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 6, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 6, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 9, ( int )vec.capacity() );
				vec.push_back( 1 );
				vec.push_back( 1 );
				Assert::AreEqual( 9, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 13, ( int )vec.capacity() );
				vec.push_back( 1 );
				vec.push_back( 1 );
				vec.push_back( 1 );
				Assert::AreEqual( 13, ( int )vec.capacity() );
				vec.push_back( 1 );
				Assert::AreEqual( 19, ( int )vec.capacity() );
			}
			// back
			{
				std::vector<int> vec;
				vec.push_back( 1 );
				vec.push_back( 2 );
				Assert::AreEqual( 2, ( int )vec.back() );
		  }
		}

		TEST_METHOD( Test_MyVector)
		{
			// default_ctr
			// push_back
			// capacity
			// size
			// at
			{
			  Vector<int> vec;
			  vec.push_back( 3 );	// rvalue
			  Assert::AreEqual( 1, ( int )vec.capacity() );
			  vec.push_back( 2 );
			  Assert::AreEqual( 2, ( int )vec.capacity() );
			  vec.push_back( 1 );
			  Assert::AreEqual( 4, ( int )vec.capacity() );
			  int a = 0;
			  vec.push_back( a );	// lvalue
			  Assert::AreEqual( 4, ( int )vec.capacity() );
			  Assert::AreEqual( 4, ( int )vec.size() );
			  Assert::AreEqual( 3, ( int )vec.at( 0 ) );
			  Assert::AreEqual( 2, ( int )vec.at( 1 ) );
			  Assert::AreEqual( 1, ( int )vec.at( 2 ) );
			  Assert::AreEqual( 0, ( int )vec.at( 3 ) );
			  //todo:
			  //struct  Functor {
			  //	std::vector<int> vec_;
			  //	void operator () () {
			  //		vec_.at( 5 );
			  //	}
			  //};
			  //Assert::ExpectException < std::out_of_range, Functor >( Functor{ vec } );
			}

			// default_ctr
			// pop_back
			// empty
			{
				Vector<int> vec(4);
				Assert::AreEqual( 4, ( int )vec.size() );
				Assert::AreEqual( 4, ( int )vec.capacity() );
			  Assert::IsTrue( !vec.empty() );
			  vec.pop_back();
			  Assert::AreEqual( 3, ( int )vec.size() );
			  vec.pop_back();
			  Assert::AreEqual( 2, ( int )vec.size() );
			  vec.pop_back();
			  Assert::AreEqual( 1, ( int )vec.size() );
			  vec.pop_back();
				vec.pop_back();
			  Assert::AreEqual( 0, ( int )vec.size() );
			  Assert::AreEqual( 4, ( int )vec.capacity() );
			  Assert::IsTrue( vec.empty() );
			}

			// reserve (about capacity)
		  {
				Vector<int> vec;
		    vec.reserve( 8 );
			  Assert::AreEqual( 8, ( int )vec.capacity() );
			  vec.reserve( 6 );															// doesn't reduce as shrink_to_fit!
			  Assert::AreEqual( 8, ( int )vec.capacity() );	// doesn't reduce as shrink_to_fit!
			  vec.push_back( 10 );
			  Assert::AreEqual( 1, ( int )vec.size() );
			  Assert::AreEqual( 10, ( int )vec.at( 0 ) );
			  vec.reserve( 16 );
			  Assert::AreEqual( 16, ( int )vec.capacity() );
			  Assert::AreEqual( 1, ( int )vec.size() );
			  Assert::AreEqual( 10, ( int )vec.at( 0 ) );
		  }

			// clear
		  {
				Vector<int> vec( 16, 3 );
		    vec.clear();
			  Assert::AreEqual( 16, ( int )vec.capacity() );
			  Assert::AreEqual( 0, ( int )vec.size() );
		  }

			// shrink_to_fit (C++11)
		  {
				Vector<int> vec;
				vec.reserve( 16 );
				Assert::AreEqual( 0, ( int )vec.size() );
		    vec.push_back( 11 );
			  vec.push_back( 12 );
			  vec.push_back( 13 );
			  Assert::AreEqual( 3, ( int )vec.size() );
			  Assert::AreEqual( 16, ( int )vec.capacity() );
			  vec.shrink_to_fit();
			  Assert::AreEqual( 3, ( int )vec.capacity() );
			  vec.clear();
			  vec.shrink_to_fit();
			  Assert::AreEqual( 0, ( int )vec.capacity() );
		  }

			//resize (about size)
			{
				Vector<int> vec;
				vec.resize( 1 );
				Assert::AreEqual( 1, ( int )vec.size() );
				Assert::AreEqual( 1, ( int )vec.capacity() );
				vec.push_back( 11 );
				Assert::AreEqual( 2, ( int )vec.size() );
				Assert::AreEqual( 2, ( int )vec.capacity() );
				Assert::AreEqual( 0, ( int )vec.at( 0 ) );
				Assert::AreEqual( 11, ( int )vec.at( 1 ) );
			}
			{
				Vector<int> vec( 2, 3 );
				Assert::AreEqual( 2, ( int )vec.size() );
				Assert::AreEqual( 2, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );
				Assert::AreEqual( 3, ( int )vec.at( 1 ) );
				vec.resize( 5 );
				Assert::AreEqual( 5, ( int )vec.size() );
				Assert::AreEqual( 5, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );
				Assert::AreEqual( 3, ( int )vec.at( 1 ) );
			}
			{
				Vector<int> vec( 5, 3 );
				Assert::AreEqual( 5, ( int )vec.size() );
				Assert::AreEqual( 5, ( int )vec.capacity() );
				
			  vec.resize( 1, 3 );
			  Assert::AreEqual( 1, ( int )vec.size() );
			  Assert::AreEqual( 5, ( int )vec.capacity() );
			  Assert::AreEqual( 3, ( int )vec.at( 0 ) );

			  vec.resize( 3, 66 );
			  Assert::AreEqual( 3, ( int )vec.size() );
			  Assert::AreEqual( 5, ( int )vec.capacity() );
			  Assert::AreEqual( 3, ( int )vec.at( 0 ) );
			  Assert::AreEqual( 66, ( int )vec.at( 1 ) );
			  Assert::AreEqual( 66, ( int )vec.at( 2 ) );

				vec.resize( 7, 77 );
				Assert::AreEqual( 7, ( int )vec.size() );
				Assert::AreEqual( 7, ( int )vec.capacity() );
				Assert::AreEqual( 3, ( int )vec.at( 0 ) );
				Assert::AreEqual( 66, ( int )vec.at( 1 ) );
				Assert::AreEqual( 66, ( int )vec.at( 2 ) );
				Assert::AreEqual( 77, ( int )vec.at( 3 ) );
				Assert::AreEqual( 77, ( int )vec.at( 4 ) );
				Assert::AreEqual( 77, ( int )vec.at( 5 ) );
				Assert::AreEqual( 77, ( int )vec.at( 6 ) );
		  }
			// []
			{
				Vector<int> vec( 3 );
				vec.push_back( 4 );
				Assert::AreEqual( 6, ( int )vec.capacity() );
				vec.push_back( 6 );
				Assert::AreEqual( 4, ( int )vec[ 3 ] );
				Assert::AreEqual( 6, ( int )vec[ 4 ] );
				const Vector<int> const_vec( 5 );
				auto& elem = const_vec[ 4 ];
				//elem = 3;	// error: const elem
			}

			// back
			{
				Vector<int> vec;
				vec.push_back( 1 );
				vec.push_back( 2 );
				Assert::AreEqual( 2, ( int )vec.back() );
			}

			// destructor
			{
				Vector<int> vec( 3, 4 );
				vec.~Vector();
				Assert::IsTrue( vec.empty() );
			}
		}

		TEST_METHOD( Test_std_list )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_MyList )
		{
			// push_back
			// push_front
			// size
		  {
		    List<int> list;
		    list.push_back( 1 );
		    list.push_back( 2 );
		    list.push_back( 3 );
		    list.push_front( 0 );
		    Assert::AreEqual( 4, ( int )list.size() );
		  }
			// pop_back
			// pop_front
			{
				List<int> list;
				list.push_back( 1 );
				list.push_back( 2 );
				list.push_back( 3 );
				list.pop_front();
				list.pop_back();
				Assert::AreEqual( 1, ( int )list.size() );
				Assert::AreEqual( 2, ( int )list.back() );
				Assert::AreEqual( 2, ( int )list.front() );
			}
			// back
			// front
			{
				List<int> list;
				list.push_back( 1 );
				list.push_back( 2 );
				list.push_back( 3 );
				Assert::AreEqual( 1, ( int )list.front() );
				Assert::AreEqual( 3, ( int )list.back() );
			}
			// clear
			// empty
			{
				List<int> list;
				list.push_back( 1 );
				list.push_back( 2 );
				list.push_back( 3 );
				list.clear();
				Assert::AreEqual( 0, ( int )list.size() );
				Assert::IsTrue( list.empty() );
			}
			// reverse
			{
				List<int> list;
				list.push_back( 1 );
				list.push_back( 2 );
				list.push_back( 3 );
				Assert::AreEqual( 1, ( int )list.front() );
				Assert::AreEqual( 3, ( int )list.back() );
				list.reverse();
				Assert::AreEqual( 3, ( int )list.front() );
				Assert::AreEqual( 1, ( int )list.back() );
			}
			// sort
		  {
				List<int> list;
				list.push_back( 8 );
				list.push_back( 3 );
				list.push_back( 5 );
				list.push_back( 2 );
				list.push_back( 1 );
				list.sort();
				Assert::AreEqual( 1, ( int )list.front() );
				list.pop_front();
				Assert::AreEqual( 2, ( int )list.front() );
				list.pop_front();
				Assert::AreEqual( 3, ( int )list.front() );
				list.pop_front();
				Assert::AreEqual( 5, ( int )list.front() );
				list.pop_front();
				Assert::AreEqual( 8, ( int )list.front() );
		  }
		}

		TEST_METHOD( Test_std_set )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_MySet )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_std_unordered_set )
		{
			Assert::IsTrue( false );
		}

		TEST_METHOD( Test_MyUnorderedSet )
		{
			Assert::IsTrue( false );
		}
	};
}
