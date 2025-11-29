#include "Math.h"

class Mat3{ 
    public:
    float m[3][3];
    Mat3(float a, float b, float c,
         float d, float e, float f,
         float g, float h, float i) {
        m[0][0] = a; m[0][1] = b; m[0][2] = c;
        m[1][0] = d; m[1][1] = e; m[1][2] = f;
        m[2][0] = g; m[2][1] = h; m[2][2] = i;
    }
    Mat3(float i) {
        m[0][0] = i; m[0][1] = 0; m[0][2] = 0;
        m[1][0] = 0; m[1][1] = i; m[1][2] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = i;
    }
    Mat3(const Vec3& v1, const Vec3& v2, const Vec3& v3) {
        m[0][0] = v1.x; m[0][1] = v1.y; m[0][2] = v1.z;
        m[1][0] = v2.x; m[1][1] = v2.y; m[1][2] = v2.z;
        m[2][0] = v3.x; m[2][1] = v3.y; m[2][2] = v3.z;
    }
    Mat3 operator*(const Mat3& other) const {
        Mat3 result(0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }
    Mat3 operator*( const Vec3& other) const {
        Mat3 result(0);
        for (int i = 0; i < 3; ++i) {
            result.m[i][0] = m[i][0] * other.x + m[i][1] * other.y + m[i][2] * other.z;
        }
        return result;
    }
    Mat3 operator+(const Mat3& other) const { 
        Mat3 result(0);
        for(int i = 0; i < 3; i++) { 
            for(int j = 0; j < 3; j++) { 
                result.m[i][j] = m[i][j] + other.m[i][j];

            }
        }
        return result;
    }
};