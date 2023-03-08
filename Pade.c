// PadeEdit.c
#include <stdio.h>
#include <math.h>

float cosine(float x){
    float k = 0;
    while (x > 3.1415926535){ /* Deals with large values of x */
        x = x - 3.1415926535;
        k = k + 1; /* Variable k counts how many times pi is subtracted */
    }
    while (x < 0){ /* Deals with negative values of x */
        x = x + 3.1415926535;
        k = k + 1; /* k also counts how many times pi is added */
    }
    float pade_cos = (313*(pow(x,4)) - 6900*(pow(x,2)) + 15120) / (13*(pow(x,4)) + 660*(pow(x,2)) + 15120);
    return pade_cos * pow(-1, k); /* Times -1 if k is odd*/
}
float sine(float x){
    return cosine(1.5707963268 - x); /* sin(x) = cos(pi/2 - x) */
}
float tangent(float x){
    return sine(x) / cosine(x); /* tan(x) = sin(x) / cos(x) */
}

int main(){
    float x;
    printf("cos(x) = \nsin(x) = \ntan(x) = \nEnter x in radians: ");
    scanf("%f", &x); /* Prints out approximated trig. values */
    printf("cos(%.4f) = %.4f\n", x, cosine(x));     
    printf("sin(%.4f) = %.4f\n", x, sine(x));
    printf("tan(%.4f) = %.4f\n", x, tangent(x));
    return 0;
}
