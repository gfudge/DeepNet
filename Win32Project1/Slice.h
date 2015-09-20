#pragma once
#include <vector>

template<typename T>
class Slice
{
public:
	Slice();
	Slice(size_t width, size_t height);
	virtual ~Slice();
	std::vector<T> row(size_t row);
	std::vector<T> column(size_t column);
	T getElement(size_t x, size_t y);
	void setElement(size_t x, size_t y, T value);
private:
	// Scalar value coordinates
	size_t width;
	size_t height;
	std::vector<std::vector<T>> data;
	bool isInit = false;
};

