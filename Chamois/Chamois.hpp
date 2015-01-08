#pragma once

/*
 *	Copyright 2014 Oli Wilkinson
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *	http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *		distributed under the License is distributed on an "AS IS" BASIS,
 *		WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *		See the License for the specific language governing permissions and
 *		limitations under the License.
 */

#include <string>
#include <algorithm>

namespace evolutional
{
	namespace Chamois
	{
		namespace detail
		{
#ifdef MS_CPP_UNITTESTFRAMEWORK
			class MsAssert
			{
			public:
				template<typename T>
				static void Equal(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(expected_value, actual_value, because);
				}

				template<typename T>
				static void NotEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreNotEqual(expected_value, actual_value, because);
				}

				static void True(const bool &actual_value, const wchar_t *because)
				{
					Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsTrue(actual_value, because);
				}

				static void False(const bool &actual_value, const wchar_t *because)
				{
					Microsoft::VisualStudio::CppUnitTestFramework::Assert::IsFalse(actual_value, because);
				}

				static void Fail(const wchar_t *because)
				{
					Microsoft::VisualStudio::CppUnitTestFramework::Assert::Fail(because);
				}
			};
#endif

#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
			class GTestAssert
			{
			public:
				template<typename T>
				static void Equal(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					ASSERT_EQ(expected_value, actual_value) << because;
				}

				template<typename T>
				static void NotEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					ASSERT_NE(expected_value, actual_value) << because;
				}

				static void True(const bool &actual_value, const wchar_t *because)
				{
					ASSERT_TRUE(actual_value) << because;
				}

				static void False(const bool &actual_value, const wchar_t *because)
				{
					ASSERT_FALSE(actual_value) << because;
				}

				static void Fail(const wchar_t *because)
				{
					ASSERT_TRUE(false) << because;
				}
			};
#endif

			template<class TAssert>
			class TAssertInternal
			{
			public:
				template<typename T>
				void AssertEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::Equal(expected_value, actual_value, because);
				}

				template<typename T>
				void AssertNotEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::NotEqual(expected_value, actual_value, because);
				}

				template<typename T>
				void AssertGreater(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::True(actual_value > expected_value, because);
				}

				template<typename T>
				void AssertLess(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::True(actual_value < expected_value, because);
				}

				template<typename T>
				void AssertGreaterEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::True(actual_value >= expected_value, because);
				}

				template<typename T>
				void AssertLessEqual(const T &expected_value, const T &actual_value, const wchar_t *because)
				{
					TAssert::True(actual_value <= expected_value, because);
				}

				template<typename T>
				void AssertInRange(const T &actual_value, const T &min_value, const T &max_value, const wchar_t *because)
				{
					TAssert::True(actual_value >= min_value, because);
					TAssert::True(actual_value <= max_value, because);
				}

				template<typename T>
				void AssertNotInRange(const T &actual_value, const T &min_value, const T &max_value, const wchar_t *because)
				{
					TAssert::False(actual_value >= min_value && actual_value <= max_value, because);
				}

				template<typename T>
				void AssertArrayEqual(const T *expected_values, const size_t expected_values_len, const T *actual_values, const size_t actual_values_len, const wchar_t *because)
				{
					TAssert::Equal(expected_values_len, actual_values_len, L"Array lengths differ");
					for (size_t i = 0; i < expected_values_len; ++i)
					{
						if (expected_values[i] != actual_values[i])
						{
							std::wstring message(L"Array contents differ at index: ");
							message += std::to_wstring(i);
							TAssert::Fail(message.c_str());
						}

					}
				}

				template<typename T>
				void AssertArrayNotEqual(const T *expected_values, const size_t expected_values_len, const T *actual_values, const size_t actual_values_len, const wchar_t *because)
				{
					if (expected_values_len != actual_values_len)
						return;

					auto min_len = std::min(actual_values_len, expected_values_len);
					bool expected_lhs = false;
					if (expected_values_len < actual_values_len)
					{
						expected_lhs = true;
					}

					const T* lhs = expected_lhs ? expected_values : actual_values;
					const T* rhs = !expected_lhs ? expected_values : actual_values;

					for (size_t i = 0; i < min_len; ++i)
					{
						if (lhs[i] != rhs[i])
						{
							return;
						}
					}
					TAssert::Fail(L"Array contents the same");
				}

				void AssertTrue(const bool &actual_value, const wchar_t *because)
				{
					TAssert::True(actual_value, because);
				}

				void AssertFalse(const bool &actual_value, const wchar_t *because)
				{
					TAssert::False(actual_value, because);
				}

				template<typename T>
				void AssertEqual(const T* expected_value, const T* actual_value, const wchar_t *because)
				{
					TAssert::Equal(expected_value, actual_value, because);
				}

				template<typename T>
				void AssertNotEqual(const T* expected_value, const T* actual_value, const wchar_t *because)
				{
					TAssert::NotEqual(expected_value, actual_value, because);
				}


				void AssertStringLength(const size_t expected_length, const std::wstring &actual_string, const wchar_t *because)
				{
					TAssert::Equal(expected_length, actual_string.length(), because);
				}

				void AssertNotStringLength(const size_t expected_length, const std::wstring &actual_string, const wchar_t *because)
				{
					TAssert::NotEqual(expected_length, actual_string.length(), because);
				}

				void AssertStringEmpty(const std::wstring &actual_string, const wchar_t *because)
				{
					TAssert::Equal(size_t(0), actual_string.length(), because);
				}

				void AssertNotStringEmpty(const std::wstring &actual_string, const wchar_t *because)
				{
					TAssert::NotEqual(size_t(0), actual_string.length(), because);
				}

				void AssertStringStartsWith(const std::wstring &expected_prefix, const std::wstring &actual_string, const wchar_t *because)
				{
					TAssert::True(actual_string.substr(0, expected_prefix.length()) == expected_prefix, because);
				}

				void AssertStringLength(const size_t expected_length, const std::string &actual_string, const wchar_t *because)
				{
					TAssert::Equal(expected_length, actual_string.length(), because);
				}

				void AssertNotStringLength(const size_t expected_length, const std::string &actual_string, const wchar_t *because)
				{
					TAssert::NotEqual(expected_length, actual_string.length(), because);
				}

				void AssertStringEmpty(const std::string &actual_string, const wchar_t *because)
				{
					TAssert::Equal(size_t(0), actual_string.length(), because);
				}

				void AssertNotStringEmpty(const std::string &actual_string, const wchar_t *because)
				{
					TAssert::NotEqual(size_t(0), actual_string.length(), because);
				}

				void AssertStringStartsWith(const std::string &expected_prefix, const std::string &actual_string, const wchar_t *because)
				{
					TAssert::True(actual_string.substr(0, expected_prefix.length()) == expected_prefix, because);
				}

				void AssertFail(const wchar_t *because) 
				{
					TAssert::Fail(because);
				}
			};


#ifdef MS_CPP_UNITTESTFRAMEWORK
			typedef TAssertInternal<MsAssert> AssertInternal;
#else 
#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
			typedef TAssertInternal<GTestAssert> AssertInternal;
	#else
	#error No supported test framework found
	#endif
#endif



			/* Default */
			template<typename T>
			class ShouldImpl
			{
			public:
				ShouldImpl(AssertInternal &assert_obj, const T& value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				void Be(const T&expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(expected_value, value_, because);
				}

				void NotBe(const T&expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(expected_value, value_, because);
				}

			private:
				const T& value_;
				AssertInternal &assert_obj_;
			};


			template<typename T>
			class ThatImpl
			{
			public:
				ThatImpl(AssertInternal &assert_obj, const T& value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				const T& value() const { return value_; }

				ShouldImpl<T> Should() { return ShouldImpl<T>(assert_obj_, value_); }

			protected:
				const T& value_;
				AssertInternal &assert_obj_;
			};




			/* Numeric Types */
			template<typename T>
			class ShouldNumImpl
			{
			public:
				ShouldNumImpl(AssertInternal &assert_obj, const T value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				void Be(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(expected_value, value_, because);
				}

				void BeZero(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(0, value_, because);
				}

				void BePositive(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertGreaterEqual<T>(0, value_, because);
				}

				void BeNegative(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertLess<T>(0, value_, because);
				}

				void BeGreaterThan(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertGreater<T>(expected_value, value_, because);
				}

				void BeGreaterThanOrEqual(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertGreaterEqual<T>(expected_value, value_, because);
				}

				void BeLessThan(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertLess<T>(expected_value, value_, because);
				}

				void BeLessThanOrEqual(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertLessEqual<T>(expected_value, value_, because);
				}

				void BeInRange(const T min_value, const T max_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertInRange<T>(value_, min_value, max_value, because);
				}

				void NotBe(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(expected_value, value_, because);
				}

				void NotBeZero(const T expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(0, value_, because);
				}

				void NotBeInRange(const T min_value, const T max_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotInRange<T>(value_, min_value, max_value, because);
				}

			private:
				const T value_;
				AssertInternal &assert_obj_;
			};

			template<typename T>
			class ThatNumImpl
			{
			public:
				ThatNumImpl(AssertInternal &assert_obj, const T value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				const T value() const { return value_; }

				ShouldNumImpl<T> Should() { return ShouldNumImpl<T>(assert_obj_, value_); }

			protected:
				const T value_;
				AssertInternal &assert_obj_;
			};



			/* Boolean */
			class ShouldBoolImpl
			{
			public:
				ShouldBoolImpl(AssertInternal &assert_obj, const bool& value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				void Be(const bool&expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual(expected_value, value_, because);
				}

				void NotBe(const bool&expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual(expected_value, value_, because);
				}

				void BeTrue(const wchar_t *because = '\0')
				{
					assert_obj_.AssertTrue(value_, because);
				}

				void BeFalse(const wchar_t *because = '\0')
				{
					assert_obj_.AssertFalse(value_, because);
				}

				void NotBeTrue(const wchar_t *because = '\0')
				{
					assert_obj_.AssertFalse(value_, because);
				}

				void NotBeFalse(const wchar_t *because = '\0')
				{
					assert_obj_.AssertTrue(value_, because);
				}

			private:
				const bool& value_;
				AssertInternal &assert_obj_;
			};

			class ThatBoolImpl
			{
			public:
				ThatBoolImpl(AssertInternal &assert_obj, const bool& value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				const bool& value() const { return value_; }

				ShouldBoolImpl Should() { return ShouldBoolImpl(assert_obj_, value_); }

			protected:
				const bool& value_;
				AssertInternal &assert_obj_;
			};

			/* String */
			template<class T>
			class ShouldStrImpl
			{
			public:
				ShouldStrImpl(AssertInternal &assert_obj, const T &value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				void Be(const T &expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(expected_value, value_, because);
				}

				void NotBe(const T &expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(expected_value, value_, because);
				}

				void HaveLength(const size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertStringLength(expected_length, value_, because);
				}

				void NotHaveLength(const size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotStringLength(expected_length, value_, because);
				}

				void BeEmpty(const wchar_t *because = '\0')
				{
					assert_obj_.AssertStringEmpty(value_, because);
				}

				void NotBeEmpty(const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotStringEmpty(value_, because);
				}

				void StartWith(const T &expected_prefix, const wchar_t *because = '\0')
				{
					assert_obj_.AssertStringStartsWith(expected_prefix, value_, because);
				}

				void StartWith(const char *expected_prefix, const wchar_t *because = '\0')
				{
					StartWith(std::string(expected_prefix), because);
				}

				void StartWith(const wchar_t *expected_prefix, const wchar_t *because = '\0')
				{
					StartWith(std::wstring(expected_prefix), because);
				}

			private:
				const T value_;
				AssertInternal &assert_obj_;
			};

			template<class T>
			class ThatStrImpl
			{
			public:
				ThatStrImpl(AssertInternal &assert_obj, const T &value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				ShouldStrImpl<T> Should() { return ShouldStrImpl<T>(assert_obj_, value_); }

			protected:
				const T value_;
				AssertInternal &assert_obj_;
			};


			/* Pointer */
			template<typename T>
			class ShouldPtrImpl
			{
			public:
				ShouldPtrImpl(AssertInternal &assert_obj, const T * value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				void Be(const T *expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(expected_value, value_, because);
				}

				void NotBe(const T *expected_value, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(expected_value, value_, because);
				}

				void BeNull(const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual<T>(nullptr, value_, because);
				}

				void NotBeNull(const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual<T>(nullptr, value_, because);
				}

			private:
				const T * value_;
				AssertInternal &assert_obj_;
			};

			template<typename T>
			class ThatPtrImpl
			{
			public:
				ThatPtrImpl(AssertInternal &assert_obj, const T * value) :
					value_(value),
					assert_obj_(assert_obj)
				{}

				ShouldPtrImpl<T> Should() { return ShouldPtrImpl<T>(assert_obj_, value_); }

			protected:
				const T * value_;
				AssertInternal &assert_obj_;
			};









			/* Array */
			template<typename T, int N>
			class ShouldArrImpl
			{
			public:

				ShouldArrImpl(AssertInternal &assert_obj, const T(&value)[N]) :
					value_(value),
					assert_obj_(assert_obj),
					length_(N)
				{
				}

				template<int O>
				void Be(const T(&expected_value)[O], const wchar_t *because = '\0')
				{
					assert_obj_.AssertArrayEqual(expected_value, O, value_, length_, because);
				}

				template<int O>
				void NotBe(const T(&expected_value)[O], const wchar_t *because = '\0')
				{
					assert_obj_.AssertArrayNotEqual<T>(expected_value, O, value_, length_, because);
				}

				void HaveLength(size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual(expected_length, length_, because);
				}

				void NotHaveLength(size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual(expected_length, length_, because);
				}

			private:
				const size_t length_;
				const T(&value_)[N];
				AssertInternal &assert_obj_;
			};

			template<typename T, int N>
			class ThatArrImpl
			{
			public:
				ThatArrImpl(AssertInternal &assert_obj, const T(&value)[N]) :
					value_(value),
					assert_obj_(assert_obj)
				{
					length_ = N;
				}

				const T* value() const { return &value_; }
				size_t length() const { return length_; }

				ShouldArrImpl<T, N> Should() { return ShouldArrImpl<T, N>(assert_obj_, value_); }

			protected:
				const T(&value_)[N];
				size_t length_;
				AssertInternal &assert_obj_;
			};

			template<typename Container>
			class ShouldContainerImpl {
			public:
				typedef typename Container::value_type value_type;
				typedef typename Container::iterator iterator;

				ShouldContainerImpl(AssertInternal &assert_obj, Container const& c) : assert_obj_(assert_obj), container_(c) {}

				void Be(Container const& other, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual(other.size(), container_.size(), because);
					for (auto actual = container_.begin(), expected = other.begin(); actual != container_.end(); ++actual, ++expected)
					{
						assert_obj_.AssertEqual(*expected, *actual, because);
					}
				}

				void NotBe(Container const& other, const wchar_t *because = '\0')
				{
					if (other.size() != container_.size())
						return;

					for (auto actual = container_.begin(), expected = other.begin(); actual != container_.end() && expected != other.end(); ++actual, ++expected) 
					{
						if (*actual != *expected)
						{
							return;
						}
					}

					assert_obj_.AssertFail(because);
				}

				void HaveLength(const size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertEqual(expected_length, container_.size(), because);
				}

				void NotHaveLength(const size_t expected_length, const wchar_t *because = '\0')
				{
					assert_obj_.AssertNotEqual(expected_length, container_.size(), because);
				}

				void BeEmpty(const wchar_t *because = '\0')
				{
					assert_obj_.AssertTrue(container_.empty(), because);
				}

				void NotBeEmpty(const wchar_t *because = '\0')
				{
					assert_obj_.AssertFalse(container_.empty(), because);
				}
			private:
				Container const& container_;
				AssertInternal &assert_obj_;
			};

			template<typename Container>
			class ThatContainerImpl {
			public:
				ThatContainerImpl(AssertInternal &assert_obj, Container const& c) : assert_obj_(assert_obj), container_(c) {}

				ShouldContainerImpl<Container> Should() { return ShouldContainerImpl<Container>(assert_obj_, container_); }
			private:
				Container const& container_;
				AssertInternal &assert_obj_;
			};

		} // namespace detail




		template<class TAssertImpl>
		class BasicAssert
		{
		public:
			/* Default */
			template<typename T>
			static detail::ThatImpl<T> That(const T& value)
			{
				return detail::ThatImpl<T>(TAssertImpl(), value);
			}

			/* Numeric */
			static detail::ThatNumImpl<char> That(const char value)
			{
				return detail::ThatNumImpl<char>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<unsigned char> That(const unsigned char value)
			{
				return detail::ThatNumImpl<unsigned char>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<short> That(const short value)
			{
				return detail::ThatNumImpl<short>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<unsigned short> That(const unsigned short value)
			{
				return detail::ThatNumImpl<unsigned short>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<int> That(const int value)
			{
				return detail::ThatNumImpl<int>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<unsigned int> That(const unsigned int value)
			{
				return detail::ThatNumImpl<unsigned int>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<long> That(const long value)
			{
				return detail::ThatNumImpl<long>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<unsigned long> That(const unsigned long value)
			{
				return detail::ThatNumImpl<unsigned long>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<float> That(const float value)
			{
				return detail::ThatNumImpl<float>(TAssertImpl(), value);
			}

			static detail::ThatNumImpl<double> That(const double value)
			{
				return detail::ThatNumImpl<double>(TAssertImpl(), value);
			}

			/* Boolean */
			static detail::ThatBoolImpl That(const bool& value)
			{
				return detail::ThatBoolImpl(TAssertImpl(), value);
			}

			/* Array */
			template<typename T, int N>
			static detail::ThatArrImpl<T, N> ThatArray(const T (&value)[N])
			{
				return detail::ThatArrImpl<T, N>(TAssertImpl(), value);
			}

			/* String */
			static detail::ThatStrImpl<std::wstring> That(const std::wstring &value)
			{
				return detail::ThatStrImpl<std::wstring>(TAssertImpl(), value);
			}

			static detail::ThatStrImpl<std::string> That(const std::string & value)
			{
				return detail::ThatStrImpl<std::string>(TAssertImpl(), value);
			}

			static detail::ThatStrImpl<std::wstring> That(const wchar_t * value)
			{
				return detail::ThatStrImpl<std::wstring>(TAssertImpl(), std::wstring(value));
			}

			static detail::ThatStrImpl<std::string> That(const char * value)
			{
				return detail::ThatStrImpl<std::string>(TAssertImpl(), std::string(value));
			}

			/* Pointer */

			template<typename T>
			static detail::ThatPtrImpl<T> That(const T * value)
			{
				return detail::ThatPtrImpl<T>(TAssertImpl(), value);
			}

			template<typename T>
			static detail::ThatContainerImpl<T> ThatContainer(T const& container) {
				return detail::ThatContainerImpl<T>(TAssertImpl(), container);
			}
			/* Char Array */
			/*
			template<int N>
			static detail::ThatPtrImpl<wchar_t> That(const wchar_t (&value)[N])
			{
				return detail::ThatPtrImpl<wchar_t>(TAssertImpl(), value);
			}

			template<int N>
			static detail::ThatPtrImpl<char> That(const char (&value)[N])
			{
				return detail::ThatPtrImpl<char>(TAssertImpl(), value);
			}*/
		};



		typedef BasicAssert<detail::AssertInternal> Assert;

	}

}