Chamois - Fluent Assertions for C++
===================================

Chamois is a header-only Assertion library for C++11 which facilitates TDD/BDD style testing through the provision of a natural language syntax. 

This library is inspired by the brilliant [Fluent Assertions] for .NET.

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
Chamois::Assert::ThatArray(A).Should().Be(B, L"arrays are equal");
```

Verify that two string are equal:

```cpp
Chamois::Assert::That("hello").Should().Be("hello", L"strings equal");
```

Verify a boolean is true:

```cpp
Chamois::Assert::That(true).Should().BeTrue(L"true is true");
```

Currently Supported Types
---

* Integral numerics (short, int, long, float, double)
* String (via std::string/std::wstring, including const char* / const wchar_t*)
* Arrays (simple arrays)
* Pointers (naked pointers only)
* Any object by reference that supports the equality operator

Support for more standard library containers, smart pointers, etc is planned.


Supported Test Frameworks
---

At this time, only Microsoft's CppUnitTestFramework is supported. Adding additional frameworks is a future goal for this project.


[Fluent Assertions]:https://github.com/dennisdoomen/fluentassertions