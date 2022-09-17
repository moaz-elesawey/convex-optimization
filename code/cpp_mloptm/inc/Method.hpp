#ifndef _METHOD_H_
#define _METHOD_H_

#include "Constants.hpp"
#include <cmath>


class Method {
    public:
        static float Golden   (float (f) (float), float a0, float b0, float eps);
        static float BiSection(float (f) (float), float (df) (float), float a0, float b0, int epochs);
        static float Newton   (float (f) (float), float (df) (float), float (ddf) (float), float x0, float eps);
        static float Secant   (float (f) (float), float (df) (float), float x0, float x1, float eps);
};

#endif /*_METHOD_H_*/
