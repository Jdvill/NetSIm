#include "network.h"
#include "random.h"
#include <algorithm>
#include <iterator>
#include <utility>

// typedef std::multimap <size_t, size_t>::iterator MMPIterator;

void Network::resize(const size_t& n)
{
    values.resize(n);
    RNG.normal(values,0,1);
}

bool Network::add_link(const size_t &a, const size_t &b)
{
    if((a >= this->size())||(b >= this->size())||(a==b))
    {
        return false;
    }
    for(auto const I : links)
    {
        if(((I.first == a)&&(I.second == b))||((I.first == b) && (I.second == a)))
        {
            return false;
        }
    }
    links.insert(std::make_pair(a,b));
    links.insert(std::make_pair(b,a));
    return true;
}

size_t Network::random_connect(const double& mean_deg)
{
    links.erase(links.begin(), links.end());
    std::vector<size_t> vec;
    size_t nlinks;
    size_t linkcount(0);
    
    for(size_t i(0); i<this->size(); i++) vec.push_back(i);
    
    for(size_t valpos(0); valpos<this->size();valpos++)
    {
        nlinks = RNG.poisson(mean_deg);
        RNG.shuffle(vec);
        size_t linkto(0);
        
        while((linkto<nlinks)&&(nlinks<vec.size()))
        {
            if(this->add_link(valpos,linkto))
            {
                ++linkcount;
            }else{
                ++nlinks;
            }
            ++linkto;
        }
    }
    return linkcount;
}
    
size_t Network::set_values(const std::vector<double>& vec)
{
    size_t n(vec.size()), no(this->size());
    if(n>no){
        n = no;
    }
    values = vec;
    return n;
}

size_t Network::size() const
{
    return values.size();
}

size_t Network::degree(const size_t& _n) const
{
    return links.count(_n);
}

double Network::value(const size_t& _n) const
{
    return values[_n];
}

std::vector<double> Network::sorted_values() const
{
    std::vector<double> vals = values;
    std::sort(vals.rbegin(), vals.rend());
    return vals;
}

std::vector<size_t> Network::neighbors(const size_t& a) const
{
    std::vector<size_t> neighborslist;
    auto range = links.equal_range(a);
    
    for(auto it = range.first; it != range.second; it++)
    {
        neighborslist.push_back(it->second);
    }
    return neighborslist;
}
