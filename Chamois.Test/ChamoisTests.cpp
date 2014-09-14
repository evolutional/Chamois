#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace evolutional;
namespace ChamoisTest
{		
	TEST_CLASS(ChamoisTests)
	{
	public:
		
		TEST_METHOD(Chamois_Assert_Equal_int_10)
		{		
			Chamois::Assert::That(10).Should().Be(10, L"10 is equal to 10");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_int_10)
		{		
			Chamois::Assert::That(10).Should().NotBe(5, L"10 is not equal to five");
		}

		TEST_METHOD(Chamois_Assert_BeGreaterThan_int_10)
		{		
			Chamois::Assert::That(10).Should().BeGreaterThan(5, L"10 is greater than five");
		}
		
		TEST_METHOD(Chamois_Assert_BeGreaterThan_int_10_5)
		{		
			Chamois::Assert::That(10).Should().BeGreaterThanOrEqual(5, L"10 is greater than or equal to five");
		}

		TEST_METHOD(Chamois_Assert_BeGreaterThanOrEqual_int_10)
		{		
			Chamois::Assert::That(10).Should().BeGreaterThanOrEqual(10, L"10 is greater or equal to 10");
		}
		
		TEST_METHOD(Chamois_Assert_BeLessThan_int_10_20)
		{		
			Chamois::Assert::That(10).Should().BeLessThan(20, L"10 is greater than twenty");
		}

		TEST_METHOD(Chamois_Assert_BeLessThanOrEqual_int_10_10)
		{		
			Chamois::Assert::That(10).Should().BeLessThanOrEqual(10, L"10 is less than or equal 10");
		}

		TEST_METHOD(Chamois_Assert_BeLessThanOrEqual_int_10_20)
		{		
			Chamois::Assert::That(10).Should().BeLessThanOrEqual(20, L"10 is less than or equal twenty");
		}

		TEST_METHOD(Chamois_Assert_10_BeInRange_int_5_20)
		{		
			Chamois::Assert::That(10).Should().BeInRange(5, 20, L"10 between 5 and 20");
		}

		TEST_METHOD(Chamois_Assert_10_NotBeInRange_int_5_9)
		{		
			Chamois::Assert::That(10).Should().NotBeInRange(5, 9, L"10 is not between 5 and 9");
		}


		TEST_METHOD(Chamois_Assert_Equal_char_10)
		{
			Chamois::Assert::That((char)10).Should().Be((char)10, L"10 is equal to 10");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_char_10)
		{
			Chamois::Assert::That((char)10).Should().NotBe((char)5, L"10 is not equal to five");
		}



		TEST_METHOD(Chamois_Assert_Equal_float_2_4)
		{		
			Chamois::Assert::That(2.4f).Should().Be(2.4f, L"2.4 is equal to 2.4");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_float_2_4)
		{		
			Chamois::Assert::That(2.4f).Should().NotBe(2.5f, L"2.4 is not equal to 2.5");
		}

		TEST_METHOD(Chamois_Assert_True_bool)
		{		
			Chamois::Assert::That(true).Should().BeTrue(L"true is true");
		}

		TEST_METHOD(Chamois_Assert_False_bool)
		{		
			Chamois::Assert::That(false).Should().BeFalse(L"false is false");
		}

		TEST_METHOD(Chamois_Assert_Equal_Strings)
		{		
			const wchar_t *A = L"hello";
			const wchar_t *B = L"hello";
			Chamois::Assert::That(A).Should().Be(B, L"strings equal");
		}

		TEST_METHOD(Chamois_Assert_Equal_Strings_Inline)
		{		
			Chamois::Assert::That(L"hello").Should().Be(L"hello", L"strings equal");
		}

		TEST_METHOD(Chamois_Assert_Equal_Strings_Inline_char)
		{		
			Chamois::Assert::That("hello").Should().Be("hello", L"strings equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Strings_Inline)
		{		
			Chamois::Assert::That(L"hello").Should().NotBe(L"goodbye", L"strings not equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Strings_Inline_char)
		{		
			Chamois::Assert::That("hello").Should().NotBe("goodbye", L"strings not equal");
		}

		TEST_METHOD(Chamois_Assert_String_StartsWith)
		{		
			Chamois::Assert::That(L"hello").Should().StartWith(L"hel", L"string starts with hel");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Strings)
		{		
			const wchar_t *A = L"hello";
			const wchar_t *B = L"goodbye";
			Chamois::Assert::That(A).Should().NotBe(B, L"strings not equal");
		}

		TEST_METHOD(Chamois_Assert_Equal_Array)
		{		
			int A[5] = { 1, 2, 3, 4, 5 };
			int B[5] = { 1, 2, 3, 4, 5 };
			Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays are equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Length_Array)
		{		
			int A[5] = { 1, 2, 3, 4, 5 };
			int B[6] = { 1, 2, 3, 4, 5, 6 };
			Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Array)
		{		
			int A[5] = { 1, 2, 3, 4, 5 };
			int B[5] = { 5, 4, 3, 2, 1 };
			Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
		}

		/* 
			Negative tests - These WILL fail
		*/

		TEST_METHOD(Chamois_Assert_NotEqual_Strings_DemonstratingFailure)
		{		
			const wchar_t *A = L"hello";
			const wchar_t *B = L"hello";
			Chamois::Assert::That(A).Should().NotBe(B, L"strings not equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Length_Array_DemonstratingFailure)
		{		
			int A[5] = { 1, 2, 3, 4, 5 };
			int B[5] = { 1, 2, 3, 4, 5 };
			Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
		}

		TEST_METHOD(Chamois_Assert_NotEqual_Array_Differs_DemonstratingFailure)
		{
			int A[5] = { 1, 2, 3, 4, 5 };
			int B[5] = { 1, 2, 4, 4, 5 };
			Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays are not equal");
		}
	};
}