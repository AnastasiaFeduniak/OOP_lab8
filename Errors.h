#pragma once
#include <csignal>
#include <string>
using namespace std;
class InvalidListSizeException : public exception
{
public:
	const char* what() const noexcept override {
		return "List is empty\n";
	}
};
class InvalidListAccessException : public exception
{
public:
	const char* what() const noexcept override {
		return "Going outside the array\n";
	}
};
class ReadAccesViolation : public exception {
public:
	const char* what() const noexcept override
	{
		return "List is empty\n";
	}
};
class InvalidListAdditionSizeException : public exception
{
public:
	const char* what() const noexcept override {
		return "Lists have different size\n";
	}
};
class OutOfMemoryException : public exception {
public:
	const char* what() const noexcept override {
		return "Out of memory.";
	}
};
class IOException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "IOException: Input/Output Error";
	}
};

class InvalidInputException : public IOException {
public:
	virtual const char* what() const noexcept {
		return "InvalidInputException: Invalid Input";
	}
};

class InvalidOutputException : public IOException {
public:
	virtual const char* what() const noexcept {
		return "InvalidOutputException: Invalid Output";
	}
};
//class InvalidListSizeException : public exception_ptr
