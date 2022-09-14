#include<stdio.h>
int main()
{
    double w,h,cal;
    scanf("%lf %lf",&w,&h);
    cal = w/(h*h/10000);
    if(cal>30.0)
    {
        printf("BMI: %.4f and you are obese",cal);
    }
    else if(cal>25.0)
    {

        printf("BMI: %.4f and you are overweight",cal);
    }
    else if(cal>18.6)
    {

        printf("BMI: %.4f and you are healthy",cal);
    }
    else
    {

        printf("BMI: %.4f and you are underweight",cal);
    }
    return 0;
}
