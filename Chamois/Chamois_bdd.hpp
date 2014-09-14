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

#include <functional>

namespace evolutional
{
	namespace Chamois
	{
		namespace bdd
		{
			namespace detail
			{
				typedef std::function<void()> Action_t;

				class ThenImpl
				{
				public:
					ThenImpl And(Action_t action, const wchar_t *reason = 0)
					{
						action();
						return ThenImpl();
					}
				};

				class WhenImpl
				{
				public:
					WhenImpl()
					{
					}

					WhenImpl And(Action_t action, const wchar_t *reason = 0)
					{
						action();
						return WhenImpl();
					}

					ThenImpl Then(Action_t action, const wchar_t *reason = 0)
					{
						action();
						return ThenImpl();
					}

				private:
				};

				class GivenThatImpl
				{
				public:
					GivenThatImpl()
					{
					}

					GivenThatImpl AndThat(Action_t action, const wchar_t *reason = 0)
					{
						action();
						return GivenThatImpl();
					}

					WhenImpl When(Action_t action, const wchar_t *reason = 0)
					{
						action();
						return WhenImpl();
					}

				private:

				};
			}

			class Given
			{
			public:

				static detail::GivenThatImpl That(detail::Action_t action, const wchar_t *reason = 0)
				{ 
					action();
					return detail::GivenThatImpl();
				}
			};
		}

	}

}