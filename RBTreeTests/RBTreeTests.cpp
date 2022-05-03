#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\cherk\source\repos\RB tree\RB tree\Map.cpp"
#include "C:\Users\cherk\source\repos\RB tree\RB tree\Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RBTreeTests
{
	TEST_CLASS(RBTreeTests)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			Map <int, int> ar;
			Assert::IsTrue(ar.getSize() == 0);
		}

		TEST_METHOD(removeNodeTest)
		{
			Map<int, int> ar;
			ar.insert(30, 0);
			ar.insert(0, 0);
			ar.insert(60, 0);
			ar.removeNode(ar.getHead()->right);
			Assert::IsTrue(ar.getHead()->right == nullptr);
		}

		TEST_METHOD(clearTest)
		{
			Map <int, int> ar;
			ar.insert(1, 0);
			ar.insert(2, 0);
			ar.insert(3, 0);
			ar.clear();
			Assert::IsTrue(ar.getSize() == 0 && ar.getHead() == nullptr);
		}

		TEST_METHOD(insertTest)
		{
			Map <int, int> ar;
			ar.insert(80, 80);
			ar.insert(90, 90);
			Assert::IsTrue(ar.getHead()->key == 80 && ar.getHead()->color == 0);
			Assert::IsTrue(ar.getHead()->right->key == 90 && ar.getHead()->right->color == 1);
		}

		TEST_METHOD(balanceInsertTest1)
		{
			Map<int, int> ar;
			ar.insert(80, 1);
			ar.insert(100, 2);
			ar.insert(40, 3);
			ar.insert(10, 4);

			Assert::IsTrue(ar.getHead()->key == 80 && ar.getHead()->color == 0);
			Assert::IsTrue(ar.getHead()->right->key == 100 && ar.getHead()->right->color == 0);
			Assert::IsTrue(ar.getHead()->left->key == 40 && ar.getHead()->left->color == 0);
			Assert::IsTrue(ar.getHead()->left->left->key == 10 && ar.getHead()->left->left->color == 1);
		}

		TEST_METHOD(removeTest)
		{
			Map<int, int> ar;
			for (int i = 0; i < 60; i += 10)ar.insert(i, i);
			ar.remove(50);
			Assert::IsTrue(ar.getSize() == 5);
		}

		TEST_METHOD(removeBalanceTest)
		{
			Map<int, int> ar;
			ar.insert(70, 0);
			ar.insert(80, 0);
			ar.insert(60, 0);
			ar.insert(90, 0);
			ar.insert(75, 0);
			ar.insert(50, 0);
			ar.remove(80);

			Assert::IsTrue(ar.getHead()->key == 70 && ar.getHead()->color == 0);
			Assert::IsTrue(ar.getHead()->right->key == 90 && ar.getHead()->right->color == 0);
			Assert::IsTrue(ar.getHead()->right->left->key == 75 && ar.getHead()->right->left->color == 1);
		}

		TEST_METHOD(leftRotateTest)
		{
			Map<int, int> ar;
			ar.insert(35, 0);
			ar.insert(45, 0);
			ar.insert(25, 0);
			ar.insert(55, 0);
			ar.insert(40, 0);
			ar.leftRotate(ar.getHead());

			Assert::IsTrue(ar.getHead()->key == 45 && ar.getHead()->left->key == 35 && ar.getHead()->left->left->key == 25 && ar.getHead()->left->right->key == 40 && ar.getHead()->right->key == 55);
		}

		TEST_METHOD(rightRotateTest) {
			Map<int, int> ar;
			ar.insert(35, 0);
			ar.insert(45, 0);
			ar.insert(25, 0);
			ar.insert(20, 0);
			ar.rightRotate(ar.getHead());

			Assert::IsTrue(ar.getHead()->key == 25 && ar.getHead()->left->key == 20 && ar.getHead()->right->key == 35 && ar.getHead()->right->right->key == 45);
		}

		TEST_METHOD(getSizeTest) {
			Map<int, int> ar;
			ar.insert(0, 0);
			Assert::IsTrue(ar.getSize() == 1);
		}

		TEST_METHOD(getHeadTest) {
			Map<int, int> ar;
			ar.insert(0, 0);
			Assert::IsTrue(ar.getHead()->key == 0 && ar.getHead()->value == 0);
		}

		TEST_METHOD(findTest) {
			Map<int, int> ar;
			for (int i = 0; i < 6; i++) ar.insert(10 + i, i);
			Assert::IsTrue(ar.find(13) == 3);
		}
		TEST_METHOD(getKeysTest) {
			Map<int, int> ar;
			std::list<int> keys;
			for (int i = 0; i < 5; i++)ar.insert(20 + i, i);
			ar.insert(19, -1);
			ar.remove(19);
			keys = ar.getKeys();
			Assert::IsTrue(keys.size() == 5);
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(std::find(keys.begin(), keys.end(), 20 + i) != keys.end());
			}
		}

		TEST_METHOD(getValuesTest) {
			Map<int, int> ar;
			std::list<int> values;
			for (int i = 0; i < 5; i++)ar.insert(20 + i, i);
			ar.insert(19, -1);
			ar.remove(19);
			values = ar.getValues();
			Assert::IsTrue(values.size() == 5);
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(std::find(values.begin(), values.end(), i) != values.end());
			}
		}
	};
}
