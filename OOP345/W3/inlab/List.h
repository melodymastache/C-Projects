/******************************/
/* Author: Citlalli Mastache */
/* Date: January 30, 2019. */
/* Student ID: 126275189 */
/* File: List.h */
/******************************/
#ifndef LIST_H
#define LIST_H
namespace sict
{
	template<typename T, size_t N>
	class List
	{
		T list[N];
		size_t cnt {0u};
	public:
		size_t size() const
		{
			return cnt;
		}
		const T& operator[](size_t num) const
		{
			return list[num];
		}
		void operator+=(const T& obj)
		{
			if (cnt < N)
			{
				list[cnt++] = obj;
			}
		}
	};
}
#endif
