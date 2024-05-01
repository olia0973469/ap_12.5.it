#include "pch.h"
#include "CppUnitTest.h"
#include <stack>
#include "../ap_12.5.it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            const std::string filename = "test.txt";
            std::ofstream file(filename);
            file << "54321";
            file.close();

            Elem* top = createStackFromFile(filename);

            Assert::IsNotNull(top);
        }
	};
}
