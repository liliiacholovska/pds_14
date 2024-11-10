#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_14/pds_14.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestAsymmetricAndTransitive)
        {
            std::ofstream testInput("testInput.txt");
            testInput << "3 3\n";
            testInput << "1 2\n";
            testInput << "2 3\n";
            testInput << "1 3\n";
            testInput.close();

            std::ifstream inputFile("testInput.txt");
            inputFile >> n >> m;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++) {
                int u, v;
                inputFile >> u >> v;
                u--; v--;
                graph[u][v] = 1;
            }
            inputFile.close();

            Assert::IsTrue(isAsymmetric(), L"The relation is not asymmetric.");

            Assert::IsTrue(isTransitive(), L"The relation is not transitive.");

            std::remove("testInput.txt");
        }
	};
}
