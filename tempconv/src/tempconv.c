#include <stdio.h>
#include <stdlib.h>

float celtofah(float c), celtokel(float c), fahtokel(float f), fahtocel(float f), keltofah(float k), keltocel(float k);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please specify the conversion and define a number.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
        return 1;
    } else {
        char *input = argv[1];
        if (input[0] != '-') {
            printf("Invalid specification of conversion. Please specify.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
            
            return 2;
        } else {
            if (input[1] == 'c'){
                if (input[2] == 'f'){
                    printf("converted value: %0.2lf\n", celtofah(atof(argv[2])));
                } else if (input[2] == 'k'){
                    printf("converted value: %0.2lf\n", celtokel(atof(argv[2])));
                } else {
                    printf("Invalid specification of conversion. Please specify.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
                    
                    return 2;
                }
            } else if (input[1] == 'f'){
                if (input[2] == 'c'){
                    printf("converted value: %0.2lf\n", fahtocel(atof(argv[2])));
                } else if (input[2] == 'k'){
                    printf("converted value: %0.2lf\n", fahtokel(atof(argv[2])));
                } else {
                    printf("Invalid specification of conversion. Please specify.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
                    
                    return 2;
                }
            } else  if (input[1] == 'k'){
                if (input[2] == 'c'){
                    printf("converted value: %0.2lf\n", keltocel(atof(argv[2])));
                } else if (input[2] == 'f'){
                    printf("converted value: %0.2lf\n", keltofah(atof(argv[2])));
                } else {
                    printf("Invalid specification of conversion. Please specify.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
                    
                    return 2;
                }
            } else {
                printf("Invalid specification of conversion. Please specify.\n-cf: Celsius to Fahrenheit\n-ck: Celsius to Kelvin\n-fk: Fahrenheit to Kelvin\n-fc: Fahrenheit to Celsius\n-kf: Kelvin to Fahrenheit\n-kc: Kelvin to Celsius\n\n");
                
                return 2;
            }
        }
        
    }
}

float celtofah(float c) {
    return (c * 9/5) + 32;
}

float celtokel(float c) {
    return c + 273.15;
}

float fahtokel(float f) {
    return (f - 32) * 5/9 + 273.15;
}

float fahtocel(float f) {
    return (f - 32) * 5/9;
}

float keltofah(float k) {
    return (k - 273.15) * 9/5 + 32;
}

float keltocel(float k) {
    return k - 273.15;
}
