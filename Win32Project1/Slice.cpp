#include "Slice.h"

// Generic container class for 2D 'slice' object (think matrix)
// Designed for storing ints or floats,etc, for convolution, maxpooling operations etc.
template<typename T>
Slice<T>::Slice()
{
}

// Initialise with zeros
template<typename T>
Slice<T>::Slice(size_t width, size_t height)
{
	this->width = width;
	this->height = height;
	// For each row, column assign zero
	for (auto &row : this->height) {
		for (auto &column : this->width) {
			this->data[row][column] = 0;
		}
	}
	this->isInit = true;
}

template<typename T>
Slice<T>::~Slice()
{
}

template<typename T>
std::vector<T> Slice<T>::row(size_t row)
{
	if (this->isInit) {
		std::vector<T> returnRow;
		// Iterate over row in slice (0 -> column)
		for (auto &x : this->column) {
			returnRow.push_back(this->data[x][row]);
		}
		return (std::vector<T>)returnRow;
	}
	else {
		throw std::runtime_error("Slice not initialised");
	}
}

template<typename T>
std::vector<T> Slice<T>::column(size_t column)
{
	if (this->isInit) {
		std::vector<T> returnColumn;
		// Iterate over column in slice (0 -> row)
		for (auto &y : this->column) {
			returnColumn.push_back(this->data[column][y]);
		}
		return (std::vector<T>)returnColumn;
	}
	else {
		throw std::runtime_error("Slice not initialised");
	}
}

template<typename T>
void Slice<T>::setElement(size_t x, size_t y, T value)
{
	if (this->isInit) {
		this->data[x][y] = (T)value;
	}
	else {
		throw std::runtime_error("Slice not initialised");
	}
}

template<typename T>
Slice<T> Slice<T>::getPool(size_t xMin, size_t yMin, size_t xMax, size_t yMax)
{
	size_t height = yMax - yMin;
	size_t width = xMax - xMin;
	Slice<T> returnPool(width, height);
	for (int i = yMin; i < yMax; i++) {
		for (int j = xMin; j < xMax; i++) {
			returnPool.setElement(i, j, value);
		}
	}
	return (Slice<T>)returnPool;
}

template<typename T>
T Slice<T>::getElement(size_t x, size_t y)
{
	if (this->isInit) {
		return (T)this->data[x][y];
	}
	else {
		throw std::runtime_error("Slice not initialised");
	}
}
