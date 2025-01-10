#include <cmath>

namespace qlexengine
{
    namespace maths
    {
        inline float degreesToRadian(const float &degrees)
        {
            return degrees * (M_PI / 180.0);
        }
    } // maths
} // qlexengine