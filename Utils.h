#pragma once
#include <list>
#include <random>
#include <iostream>
using namespace std;

class Utils
{
public:
	static int getRandomInteger(int min, int max)
	{
		random_device rd;
		mt19937 gen(rd());

		uniform_int_distribution<size_t> dist(min, max);
		return dist(gen);
	}

	template <typename T> static T getRandomElementFromList(list<T> myList)
	{
		if (myList.empty()) {
			throw out_of_range("The list is empty.");
		}

		int randomIndex = getRandomInteger(0, myList.size() - 1);

		auto it = begin(myList);
		advance(it, randomIndex);

		return *it;
	}

	static void Debug() {
		cout << endl;
	}

	template <typename T, typename... Args> static void Debug(const T& arg, const Args&... args)
	{
		cout << arg;
		Debug(args...);
	}
};