#include <stdio.h>
#include <stdlib.h>

#define CELSIUS_TO_FAHRENHEIT(c) ((c * 9.0 / 5.0) + 32.0)
#define CELSIUS_TO_KELVIN(c) (c + 273.15)
#define FAHRENHEIT_TO_KELVIN(f) ((f - 32.0) * 5.0 / 9.0 + 273.15)
#define FAHRENHEIT_TO_CELSIUS(f) ((f - 32.0) * 5.0 / 9.0)
#define KELVIN_TO_FAHRENHEIT(k) ((k - 273.15) * 9.0 / 5.0 + 32.0)
#define KELVIN_TO_CELSIUS(k) (k - 273.15)

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: <conversion> <number>\n");
    printf("  -cf: Celsius to Fahrenheit\n");
    printf("  -ck: Celsius to Kelvin\n");
    printf("  -fk: Fahrenheit to Kelvin\n");
    printf("  -fc: Fahrenheit to Celsius\n");
    printf("  -kf: Kelvin to Fahrenheit\n");
    printf("  -kc: Kelvin to Celsius\n");
    return 1;
  }

  char conversion = argv[1][1];
  float value = atof(argv[2]);

  float result;
  switch (conversion) {
    case 'c':
      if (argv[1][2] == 'f') {
        result = CELSIUS_TO_FAHRENHEIT(value);
      } else if (argv[1][2] == 'k') {
        result = CELSIUS_TO_KELVIN(value);
      } else {
        printf("Invalid conversion type.\n");
        return 1;
      }
      break;
    case 'f':
      if (argv[1][2] == 'c') {
        result = FAHRENHEIT_TO_CELSIUS(value);
      } else if (argv[1][2] == 'k') {
        result = FAHRENHEIT_TO_KELVIN(value);
      } else {
        printf("Invalid conversion type.\n");
        return 1;
      }
      break;
    case 'k':
      if (argv[1][2] == 'c') {
        result = KELVIN_TO_CELSIUS(value);
      } else if (argv[1][2] == 'f') {
        result = KELVIN_TO_FAHRENHEIT(value);
      } else {
        printf("Invalid conversion type.\n");
        return 1;
      }
      break;
    default:
      printf("Invalid conversion type.\n");
      return 1;
  }

  printf("Converted value: %.2f\n", result);
  return 0;
}
