#pragma once
#include <vector>

namespace DeepNet
{
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
		Slice<T> getPool(size_t xMin, size_t yMin, size_t xMax, size_t yMax);
	private:
		// Scalar value coordinates
		size_t width;
		size_t height;
		std::vector<std::vector<T>> data;
		bool isInit = false;
	};
}

