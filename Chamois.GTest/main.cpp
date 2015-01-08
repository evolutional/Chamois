#include "gtest/gtest.h"
#include "Chamois.hpp"

#include <vector>
#include <map>

#pragma comment(lib, "gtest.lib")

using namespace evolutional;

TEST(ChamoisTest, Chamois_Assert_Equal_int_10)
{		
	Chamois::Assert::That(10).Should().Be(10, L"10 is equal to 10");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_int_10)
{
	Chamois::Assert::That(10).Should().NotBe(5, L"10 is not equal to five");
}

TEST(ChamoisTest, Chamois_Assert_BeGreaterThan_int_10)
{
	Chamois::Assert::That(10).Should().BeGreaterThan(5, L"10 is greater than five");
}

TEST(ChamoisTest, Chamois_Assert_BeGreaterThan_int_10_5)
{
	Chamois::Assert::That(10).Should().BeGreaterThanOrEqual(5, L"10 is greater than or equal to five");
}

TEST(ChamoisTest, Chamois_Assert_BeGreaterThanOrEqual_int_10)
{
	Chamois::Assert::That(10).Should().BeGreaterThanOrEqual(10, L"10 is greater or equal to 10");
}

TEST(ChamoisTest, Chamois_Assert_BeLessThan_int_10_20)
{
	Chamois::Assert::That(10).Should().BeLessThan(20, L"10 is greater than twenty");
}

TEST(ChamoisTest, Chamois_Assert_BeLessThanOrEqual_int_10_10)
{
	Chamois::Assert::That(10).Should().BeLessThanOrEqual(10, L"10 is less than or equal 10");
}

TEST(ChamoisTest, Chamois_Assert_BeLessThanOrEqual_int_10_20)
{
	Chamois::Assert::That(10).Should().BeLessThanOrEqual(20, L"10 is less than or equal twenty");
}

TEST(ChamoisTest, Chamois_Assert_10_BeInRange_int_5_20)
{
	Chamois::Assert::That(10).Should().BeInRange(5, 20, L"10 between 5 and 20");
}

TEST(ChamoisTest, Chamois_Assert_10_NotBeInRange_int_5_9)
{
	Chamois::Assert::That(10).Should().NotBeInRange(5, 9, L"10 is not between 5 and 9");
}


TEST(ChamoisTest, Chamois_Assert_Equal_char_10)
{
	Chamois::Assert::That((char)10).Should().Be((char)10, L"10 is equal to 10");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_char_10)
{
	Chamois::Assert::That((char)10).Should().NotBe((char)5, L"10 is not equal to five");
}



TEST(ChamoisTest, Chamois_Assert_Equal_float_2_4)
{
	Chamois::Assert::That(2.4f).Should().Be(2.4f, L"2.4 is equal to 2.4");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_float_2_4)
{
	Chamois::Assert::That(2.4f).Should().NotBe(2.5f, L"2.4 is not equal to 2.5");
}

TEST(ChamoisTest, Chamois_Assert_True_bool)
{
	Chamois::Assert::That(true).Should().BeTrue(L"true is true");
}

TEST(ChamoisTest, Chamois_Assert_False_bool)
{
	Chamois::Assert::That(false).Should().BeFalse(L"false is false");
}

TEST(ChamoisTest, Chamois_Assert_Equal_Strings)
{
	const wchar_t *A = L"hello";
	const wchar_t *B = L"hello";
	Chamois::Assert::That(A).Should().Be(B, L"strings equal");
}

TEST(ChamoisTest, Chamois_Assert_Equal_Strings_Inline)
{
	Chamois::Assert::That(L"hello").Should().Be(L"hello", L"strings equal");
}

TEST(ChamoisTest, Chamois_Assert_Equal_Strings_Inline_char)
{
	Chamois::Assert::That("hello").Should().Be("hello", L"strings equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Strings_Inline)
{
	Chamois::Assert::That(L"hello").Should().NotBe(L"goodbye", L"strings not equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Strings_Inline_char)
{
	Chamois::Assert::That("hello").Should().NotBe("goodbye", L"strings not equal");
}

TEST(ChamoisTest, Chamois_Assert_String_StartsWith)
{
	Chamois::Assert::That(L"hello").Should().StartWith(L"hel", L"string starts with hel");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Strings)
{
	const wchar_t *A = L"hello";
	const wchar_t *B = L"goodbye";
	Chamois::Assert::That(A).Should().NotBe(B, L"strings not equal");
}

TEST(ChamoisTest, Chamois_Assert_Equal_Array)
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[5] = { 1, 2, 3, 4, 5 };
	Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays are equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Length_Array)
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[6] = { 1, 2, 3, 4, 5, 6 };
	Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Array)
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[5] = { 5, 4, 3, 2, 1 };
	Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
}

/*
Container tests
*/
TEST(ChamoisTest, Chamois_Assert_Container_Vector_Equal)
{
	std::vector<int> A = { 1, 2, 3, 4, 5 };
	std::vector<int> B = { 1, 2, 3, 4, 5 };

	Chamois::Assert::ThatContainer(A).Should().Be(B, L"vectors are equal.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Vector_NotEqual)
{
	std::vector<int> A = { 1, 2, 3, 4, 5 };
	std::vector<int> B = { 5, 4, 3, 2, 1 };

	Chamois::Assert::ThatContainer(A).Should().NotBe(B, L"vectors are not equal.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Vector_Empty)
{
	std::vector<int> A = {};

	Chamois::Assert::ThatContainer(A).Should().BeEmpty(L"vectors empty.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Vector_NotEmpty)
{
	std::vector<int> A = { 1, 2, 3, 4, 5 };

	Chamois::Assert::ThatContainer(A).Should().NotBeEmpty(L"vectors not empty.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Map_Equal)
{
	std::map<int, int> A;
	std::map<int, int> B;

	for (int i = 0; i < 5; ++i) {
		A.insert(std::make_pair(i, i));
		B.insert(std::make_pair(i, i));
	}

	Chamois::Assert::ThatContainer(A).Should().Be(B, L"map are equal.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Map_NotEqual)
{
	std::map<int, int> A;
	std::map<int, int> B;

	for (int i = 0; i < 5; ++i) {
		A.insert(std::make_pair(i, i));
		B.insert(std::make_pair(5 - i, i));
	}

	Chamois::Assert::ThatContainer(A).Should().NotBe(B, L"map are not equal.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Map_Empty)
{
	std::map<int, int> A;

	Chamois::Assert::ThatContainer(A).Should().BeEmpty(L"map empty.");
}

TEST(ChamoisTest, Chamois_Assert_Container_Map_NotEmpty)
{
	std::map<int, int> A;

	for (int i = 0; i < 5; ++i) {
		A.insert(std::make_pair(i, i));
	}

	Chamois::Assert::ThatContainer(A).Should().NotBeEmpty(L"map not empty.");
}

#ifdef CHAMOIS_TEST_ENABLE_FAILING_TESTS
TEST(ChamoisTest, Chamois_Assert_NotEqual_Strings_DemonstratingFailure)
{
	const wchar_t *A = L"hello";
	const wchar_t *B = L"hello";
	Chamois::Assert::That(A).Should().NotBe(B, L"strings not equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Length_Array_DemonstratingFailure)
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[5] = { 1, 2, 3, 4, 5 };
	Chamois::Assert::ThatArray(A).Should().NotBe(B, L"arrays are not equal");
}

TEST(ChamoisTest, Chamois_Assert_NotEqual_Array_Differs_DemonstratingFailure)
{
	int A[5] = { 1, 2, 3, 4, 5 };
	int B[5] = { 1, 2, 4, 4, 5 };
	Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays are not equal");
}
#endif

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
