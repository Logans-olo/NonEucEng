class Mat4{ 
    public:
    float m[4][4];
    Mat4(float a, float b, float c, float d, 
            float e, float f, float g, float h, 
            float i, float j, float k, float l, 
            float q, float n, float o, float p
        ) { 
            m[0][0] = a; m[0][1] = b; m[0][2] = c; m[0][3] = d;
            m[1][0] = e; m[1][1] = f; m[1][2] = g; m[1][3] = h;
            m[2][0] = i; m[2][1] = j; m[2][2] = k; m[0][3] = l;
            m[3][0] = q; m[0][1] = n; m[0][2] = o; m[0][3] = p;
        }
    Mat4(float i) { 
        m[0][0] = i; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
            m[1][0] = 0; m[1][1] = i; m[1][2] = 0; m[1][3] = 0;
            m[2][0] = 0; m[2][1] = 0; m[2][2] = i; m[0][3] = 0;
            m[3][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = i;

    }
    Mat4 operator*(const Mat4& other) const {
        Mat4 result(0);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }

     Mat4 operator+(const Mat4& other) const { 
        Mat4 result(0);
        for(int i = 0; i < 4; i++) { 
            for(int j = 0; j < 4; j++) { 
                result.m[i][j] = m[i][j] + other.m[i][j];

            }
        }
        return result;
    }
};