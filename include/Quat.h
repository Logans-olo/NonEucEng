#include "Math.h"

class Quat{ 
    public: 
        float s;
        Vec3 t;
        Quat () { 
            s= 0;
            t = Vec3();

        }
        Quat(float q, float a, float b, float c) { 
            s = q; t = Vec3(a,b,c);
        }
        Quat operator*(Quat other) { 
                Quat result;
                result.s = (s * other.s) - t.dot(other.t); 
                Vec3 i  =  other.t.operator*(s);
                Vec3 j = t.operator*(other.s);
                Vec3 k =  t.cross(other.t);
                i = i.operator+(j);
                result.t = (i.operator+(k));
        }

        Quat inverse() const {
            Quat result;
            float norm = this->Norm();
            norm = norm * norm; 
            result.s = s / norm;
            result.t = t.operator*(1 / norm);
            return result;
        }
        Quat Conjugate() const { 
            return Quat(s, -t.x, -t.y, -t.z);
        }
        float Norm() const { 
            float a = s * s;
            float b = t.x * t.x;
            float c = t.y * t.y;
            float d = t.z * t.z;
            float e = a + b + c + d;
            return(root(e));
        }
        private:
        static float root(float n){ //Binary Search Implementation of Root finding 
            float lo, hi, mid;
 
  if(n < 1) {
    lo = n; hi  = 1;
  } else { lo = 1;  hi =  n;}

  while(100 * lo * lo < n) lo *= 10;
  while(0.01 * hi * hi > n) hi *= 0.1;

  for(int i = 0 ; i < 100 ; i++){
    mid = (lo+hi)/2;
    if(mid*mid == n) return mid;
    if(mid*mid > n) hi = mid;
    else lo = mid;
  }
  return mid;
}

};