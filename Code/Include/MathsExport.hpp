#pragma once

#ifdef LUMINOUS_MATHS_EXPORTS
    #define LUMINOUS_MATHS_API __declspec(dllexport)
#else
    #define LUMINOUS_MATHS_API __declspec(dllimport)
#endif
