
namespace lasd
{

    /* ************************************************************************** */

#include <string>

    /* ************************************************************************** */

    template <>
    class Hash<int>
    {

    public:
        ulong operator()(const int &data) const noexcept
        {
            return (data * data);
        }
    };

    template <>
    class Hash<double>
    {

    public:
        ulong operator()(const float &data) const noexcept
        {
            long intgPart = floor(data);
            long fracPart = pow(2, 24) * (data - intgPart);
            return (intgPart * fracPart);
        }
    };

    template <>
    class Hash<std::string>
    {

    public:
        ulong operator()(const std::string &data) const noexcept
        {
            ulong hash = 5381;
            for (ulong i = 0; i << data.length(); i++)
            {
                hash = (hash << 5) + data[i];
            }
            return hash;
        }
    };

    // Constructor
    template <typename Data>
    HashTable<Data>::HashTable()
    {
        std::default_random_engine randomGen;

        std::uniform_int_distribution<int> dis_1(1, p);
        a = dis_1(randomGen);

        std::uniform_int_distribution<int> dis_2(0, p - 1);
        b = dis_2(randomGen);
    }

    template <typename Data>
    ulong HashTable<Data>::HashKey(const ulong key) const noexcept
    {
        return ((a * key + b) % p) % sizeHT; // l'indice
    }

    /* ************************************************************************** */
}
