#include "stdafx.h"
#include "CppUnitTest.h"
#include "Chamois_bdd.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace evolutional;
namespace ChamoisTest
{
	class DummyBank
	{
	public:
		DummyBank() : balance_(0), transaction_count_(0) {}
		DummyBank(int balance) : balance_(balance), transaction_count_(0) {}

		void Deposit(int amount) { balance_ += amount; transaction_count_++; }
		void Withdraw(int amount) { balance_ -= amount; transaction_count_++; }

		int balance() const { return balance_; }
		void balance_set(int balance) { balance_ = balance; }

		int transaction_count() const { return transaction_count_;  }

	private:
		int balance_;
		int transaction_count_;
	};
		
	class DummyBankTest
	{
	public:
		void The_starting_balance_is_100()
		{
			bank_.balance_set(100);
		}

		void I_withdraw_80()
		{
			bank_.Withdraw(80);
		}

		void The_balance_should_be_20()
		{
			Chamois::Assert::That(bank_.balance()).Should().Be(20);
		}

	private:
		DummyBank bank_;
	};

	TEST_CLASS(Chamois_bdd_Tests)
	{
	public:

		TEST_METHOD(Chamois_Bdd_SimpleInlineLambdas)
		{
			int i = 0;
			Chamois::bdd::Given::That([&]() { i = 5; }, L"i is initialized to 5")
				.When([&]() { i++; }, L"i is incremented")
				.Then([&]() { Chamois::Assert::That(i).Should().Be(6); });
		}

		TEST_METHOD(Chamois_Bdd_DummyBank_Test)
		{
			DummyBank bank;

			Chamois::bdd::Given::That([&]() { bank.balance_set(100); })
				.When([&]() { bank.Withdraw(80); })
				.Then([&]() { Chamois::Assert::That(bank.balance()).Should().Be(20); });
		}

		TEST_METHOD(Chamois_Bdd_DummyBank_TestClass)
		{
			DummyBankTest test;

			Chamois::bdd::Given::That([&]() { test.The_starting_balance_is_100(); })
				.When([&]() { test.I_withdraw_80(); })
				.Then([&]() { test.The_balance_should_be_20(); });
		}

		TEST_METHOD(Chamois_Bdd_DummyBank_Multiple_WhenActions_AndThens)
		{
			DummyBank bank;

			Chamois::bdd::Given::That([&]() { bank.balance_set(100); })
				.When([&]() { bank.Withdraw(80); })
				  .And([&]() { bank.Withdraw(20); })
				.Then([&]() { Chamois::Assert::That(bank.balance()).Should().Be(0); })
				  .And([&]() { Chamois::Assert::That(bank.transaction_count()).Should().Be(2); });
		}

	};

}