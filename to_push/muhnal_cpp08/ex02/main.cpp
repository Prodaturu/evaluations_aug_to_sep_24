#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

void printSeparator(const std::string &testName) {
	std::cout << "\n==== " << testName << " ====\n";
}

void test_basic_operations() {
	printSeparator("Test 1: Basic Operations");
	MutantStack<int> mstack;
	std::cout << "Is empty: " << (mstack.empty() ? "true" : "false") << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Expected: Is empty: true, Size: 0\n";
}

void test_single_element() {
  printSeparator("Test 2: Single Element");
  MutantStack<int> mstack;
  mstack.push(42);

  std::cout << "1. Checking top element:\n";
  std::cout << "   Top: " << mstack.top() << "\n";
  std::cout
	  << "   Expected: 42 (This should be the only element we pushed)\n\n";

  std::cout << "2. Verifying size:\n";
  std::cout << "   Size: " << mstack.size() << "\n";
  std::cout << "   Expected: 1 (We only pushed one element)\n\n";

  std::cout << "3. Examining begin iterator:\n";
  std::cout << "   *begin(): " << *mstack.begin() << "\n";
  std::cout << "   Expected: 42 (Should point to our single element)\n\n";

  std::cout << "4. Comparing begin and end iterators:\n";
  bool begin_equals_end = (mstack.begin() == mstack.end());
  std::cout << "   begin() == end(): " << (begin_equals_end ? "true" : "false")
			<< "\n";
  std::cout << "   Expected: false\n";
  std::cout << "   Explanation: begin() should point to the element, while "
			   "end() points past the last element.\n";
  std::cout << "                If they were equal, it would indicate an empty "
			   "container.\n\n";

  std::cout << "5. Demonstrating iterator increment:\n";
  MutantStack<int>::iterator it = mstack.begin();
  ++it;
  std::cout << "   After incrementing begin iterator, begin() == end(): "
			<< ((it == mstack.end()) ? "true" : "false") << "\n";
  std::cout << "   Expected: true (Now we've moved past our single element)\n";
}

void test_multiple_elements() {
	printSeparator("Test 3: Multiple Elements");
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(13);
	mstack.push(75);
	mstack.push(20);
	mstack.push(98);
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
			 ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nExpected: Size: 5, Elements: 42 13 75 20 98\n";
}

void test_copy_constructor() {
	printSeparator("Test 4: Copy Constructor");
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(13);
	mstack.push(75);
	MutantStack<int> copy(mstack);
	std::cout << "Original: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
			 ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nCopy: ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nExpected: Original and Copy should be identical\n";
}

void test_different_data_types() {
	printSeparator("Test 5: Different Data Types");
	MutantStack<std::string> mstack;
	mstack.push("Hello");
	mstack.push("World");
	mstack.push("!");
	std::cout << "Elements: ";
	for (MutantStack<std::string>::iterator it = mstack.begin();
			 it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nExpected: Elements: Hello World !\n";
}

void testComparisonWithList() {
	printSeparator("Test 6: Comparison with std::list");
	std::list<int> lst;
	MutantStack<int> mstack;

	int elements[] = {5, 17, 3, 5, 737, 0};
	int num_elements = sizeof(elements) / sizeof(elements[0]);

	for (int i = 0; i < num_elements; ++i) {
		lst.push_back(elements[i]);
		mstack.push(elements[i]);
	}

	std::cout << "std::list:    ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nMutantStack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
			 ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nExpected: Both should be identical\n";

	std::cout << "\nLIFO Behavior:\n";
	std::cout << "std::list pop order:    ";
	while (!lst.empty()) {
		std::cout << lst.back() << " ";
		lst.pop_back();
	}
	std::cout << "\nMutantStack pop order: ";
	while (!mstack.empty()) {
		std::cout << mstack.top() << " ";
		mstack.pop();
	}
	std::cout << "\nExpected: Both should show reverse order (0 737 5 3 17 5)\n";
}

int main() {
	test_basic_operations();
	test_single_element();
	test_multiple_elements();
	test_copy_constructor();
	test_different_data_types();
	testComparisonWithList();
	return 0;
}