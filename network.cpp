#include "network.h"
#include "random.h"
#include <algorithm>
#include <iterator>

typedef std::multimap <size_t, size_t> iterator MIterator;

void resize(const size_t& n)
{
	values.resize(n);
	RandomNumbers::normal(values);
}

bool Network::add_link(const size_t& a, const size_t& b)
{
	if((a > Network::size())||(b > Network::size())){
		return false;
	}
	for(auto I : links)
	{
		if(((I->first == a)&&(I->second == b))||((I->first == b) && (I->second == a)))
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
	links.clear();
	
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
	std::vector<size_t> neighborslist;
	std::pair<MIterator, MIterator> range = links.equal_range(values[a]);
	for(MIterator it = range->first; it != range->second; it++)
	{
		neighborslist.pushback(it->second);
	}
	return neighborslist;
}
