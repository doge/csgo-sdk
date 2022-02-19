#include <cstring>
#include <cstdint>

namespace fnv
{
    inline constexpr uint32_t base = 0x811C9DC5;
    inline constexpr uint32_t prime = 0x1000193;

    constexpr uint32_t hash_const(const char* data, const uint32_t value = base) noexcept
    {
        return (data[0] == '\0') ? value : hash_const(&data[1], (value ^ uint32_t(data[0])) * prime);
    }

    // runtime hash
    inline uint32_t hash(const char* data) noexcept
    {
        uint32_t hashed = base;

        for (size_t i = 0U; i < strlen(data); ++i)
        {
            hashed ^= data[i];
            hashed *= prime;
        }

        return hashed;
    }
}