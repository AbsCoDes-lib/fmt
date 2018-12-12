#include "stdafx.h"
#include "CppUnitTest.h"

#include "fmt\fmt.h"

#ifdef FMT_API
#endif

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//
struct date {
	int year, month, day;
};

//
template <>
struct fmt::formatter<date> {
	template <typename ParseContext>
	constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }

	template <typename FormatContext>
	auto format(const date &d, FormatContext &ctx) {
	return format_to(ctx.out(), "{}-{}-{}", d.year, d.month, d.day);
	}
};

namespace fmtTests
{		



	TEST_CLASS(fmt_Tests)
	{


	public:

		TEST_METHOD(Examples)
		{
			// This prints Hello, world! to stdout:
			fmt::print("Hello, {}!", "world");  // uses Python-like format string syntax
			fmt::print("Hello, %s!", "world"); // uses printf format string syntax

			// Arguments can be accessed by position and arguments' indices can be repeated:
			std::string s1 = fmt::format("{0}{1}{0}", "abra", "cad");
			Assert::IsTrue(s1 == "abracadabra");

			// {fmt} can be used as a safe portable replacement for itoa (godbolt):
			fmt::memory_buffer buf;
			format_to(buf, "{}", 42);    // replaces itoa(42, buffer, 10)
			format_to(buf, "{:x}", 42);  // replaces itoa(42, buffer, 16)
			// access the string using to_string(buf) or buf.data()

			// Formatting of user-defined types is supported via a simple extension API:
			std::string s2 = fmt::format("The date is {}", date{2012, 12, 9});
			Assert::IsTrue(s2 == "The date is 2012-12-9");
		}

	};
}