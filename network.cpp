#include "network.h"
#include <algorithm>

void resize(const size_t&)
{
	
}

bool add_link(const size_t&, const size_t&)
{
	
}

size_t random_connect(const double&)
{
	
	
}

size_t set_values(const std::vector<double>&)
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

std::vector<size_t> neighbors(const size_t&) const
{
	
	
}
