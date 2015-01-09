Chamois - Fluent Assertions for C++
===================================

Chamois is a header-only fluent assertion library for C++11 which is designed to facilitate TDD and BDD through the provision of a natural language syntax. Chamois is inspired by the brilliant [Fluent Assertions] for .NET.

The primary way of expressing a test in Chamois is in the form:

```cpp
Chamois::Assert::That(<actual_value>).Should().Be(<expected_value>);
Chamois::Assert::That(<actual_value>).Should().NotBe(<expected_value>);
```


Examples
---

Verify that an integer matches the expected value:

```cpp
Chamois::Assert::That(10).Should().Be(10, L"10 is equal to 10");
```

Verify that two arrays are the same:

```cpp
int A[5] = { 1, 2, 3, 4, 5 };
int B[5] = { 1, 2, 3, 4, 5 };
Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays whould be equal");
```

Verify that two strings are equal:

```cpp
Chamois::Assert::That("hello").Should().Be("hello", L"strings should be equal");
```

Or that a string starts with a prefix:

```cpp
Chamois::Assert::That("hello").Should().StartWith("he", L"string should start with he");
```

Verify a boolean is true:

```cpp
Chamois::Assert::That(true).Should().BeTrue(L"true is true");
```

Currently Supported Types
---

* Integral numerics (char, short, int, long, float, double)
* String (via std::string/std::wstring, including const char*/const wchar_t*)
* Arrays (simple arrays)
* Pointers (naked pointers only)
* Any object by reference that supports the equality operator

Support for more standard library containers, smart pointers, etc is planned.


Supported Test Frameworks
---

* Microsoft's C++ Unit Test Framework
* Google Test (GTest)
* Boost Unit Test Framework (UTF)
* Others may be added in the future

Usage
---

In the majority of cases, you include your test framework header first and then Chamois.hpp. Generally, you should ensure that your types are comparable (== and !=)

**Microsoft C++ Unit Test**

Occasionally, you may get compilation errors in your tests; more often than not this is due to the MS framework not knowing how to compare two values; this is due to the framework converting your type to a string for comparisions.
 To achieve this, you must provide a template specialization for the Microsoft::VisualStudio::CppUnitTestFramework::ToString method. 

**Boost Unit Test Framework**

Ensure that you have included the unit_test.hpp file and defined BOOST_TEST_MODULE before including the Chamois.hpp header.

There are a few limitations in the Boost framework support at present. As a result, the Asserts fall back to a simple BOOST_CHECK( a == b ) and we lose the ability to see the expected and actual values.


BDD
---

Chamois includes a simple fluent BDD wrapper, allowing tests to be expressed in the "Given, When, Then" form using C++11's lambda functionality.

For example, testing a class behaviour directly:

```cpp
DummyBank bank;

Chamois::bdd::Given::That([&]() { bank.balance_set(100); })
	.When([&]() { bank.Withdraw(80); })
	.Then([&]() { Chamois::Assert::That(bank.balance()).Should().Be(20); });
```

Or creating a class which performs the test actions:

```cpp
DummyBankTest test;

Chamois::bdd::Given::That([&]() { test.The_starting_balance_is_100(); })
	.When([&]() { test.I_withdraw_80(); })
	.Then([&]() { test.The_balance_should_be_20(); });
```



[Fluent Assertions]:https://github.com/dennisdoomen/fluentassertions
