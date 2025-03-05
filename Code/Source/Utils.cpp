#include "Utils.hpp"
#include <cmath>

namespace Maths
{
    float Sqrt(const float& a_a)
    {
        float l_sqrt = a_a * 0.5f;
        float l_temp = 0.0f;
        while (l_sqrt != l_temp)
        {
            l_temp = l_sqrt;
            l_sqrt = (a_a / l_temp + l_temp) * 0.5f;
        }
        return l_sqrt;
    }

    float DegToRad(const float& a_deg)
    {
        return a_deg * (m_PI / 180.0f);
    }

    float RadToDeg(const float& a_rad)
    {
        return a_rad * (180.0f / m_PI);
    }

    float Precise(const float& a_f)
    {
        float t_f = a_f;
        if (fabs(t_f) < PRECISION)
        {
            t_f = 0.0f;
        }
        return t_f;
    }
}
