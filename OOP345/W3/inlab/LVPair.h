/******************************/
/* Author: Citlalli Mastache */
/* Date: January 30, 2019. */
/* Student ID: 126275189 */
/* File: LVPair.h */
/******************************/
#ifndef LVPAIR_H
#define LVPAIR_H
#include <iostream>
namespace sict
{
	template<typename L, typename V>
	class LVPair
	{
		L label;
		V value;
	public:
		LVPair() {}
		LVPair(const L& l, const V& v)
		{
			label = l;
			value = v;
		}
		void display(std::ostream& os) const
		{
			os << label << " : " << value << std::endl;
		}
	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& obj)
	{
		obj.display(os);
		return os;
	}
}
#endif
