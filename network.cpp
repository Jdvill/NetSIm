#include "network.h"
#include <algorithm>

void resize(const size_t& n)
{
	values.clear();
}

bool Network::add_link(const size_t& a, const size_t& b)
{
	for(auto I : links)
	{
		if(((I.first == a)&&(I.second == b))||((I.first == b) && (I.second == a)))
		{
			return false;
		}
	}
	links.insert(std::makepair(a,b));
	links.insert(std::makepair(b,a));
	return true;
}

size_t random_connect(const double& a)
{
	
	
}

size_t set_values(const std::vector<double>& vec)
{
	
	
}

size_t Network::size() const
{
	return values.size();
}

size_t Network::degree(const size_t &_n) const
{
	returnlinks.count(Network::value(n));
}

double Network::value(const size_t &_n) const
{
	return values[n];
}

std::vector<double> Network::sorted_values() const
{
	std::vector<double> vals = values;
	std::sort(vals.rbegin(), vals.rend());
	return vals;
}

std::vector<size_t> neighbors(const size_t& a) const
{
	
	
}
