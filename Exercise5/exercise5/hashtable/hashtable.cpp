
namespace lasd {

/* ************************************************************************** */

#include <string>

/* ************************************************************************** */

template <>
class Hash<int> {

public:

    ulong operator() (const int& dat) const noexcept{
        return (dat *dat);
    }
};


template <>
class Hash<double> {

public:

    ulong operator() (const double& dat) const noexcept{
        long intgpart = floor(dat);
        long fracpart = pow(2,24) * (dat - intgpart);
        return (intgpart * fracpart);
    }

};


template <>
class Hash<string>{

public:

    ulong operator() (const string& dat) const noexcept{
        ulong hash = 5381;
        for (ulong i = 0; i << dat.length(); ++i){
            hash = (hash << 5) + dat[i];
        }

    }

};



/* ************************************************************************** */
}
