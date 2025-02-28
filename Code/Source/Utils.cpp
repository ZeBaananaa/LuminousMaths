#include "Utils.hpp"

namespace Maths
{
    float Sqrt(const float& p_a)
    {
        float t_sqrt = p_a * 0.5f;
        float t_temp = 0.0f;
        while (t_sqrt != t_temp)
        {
            t_temp = t_sqrt;
            t_sqrt = (p_a / t_temp + t_temp) * 0.5f;
        }
        return t_sqrt;
    }
}
