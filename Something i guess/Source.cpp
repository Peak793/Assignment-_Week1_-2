#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char unit[4][11] = { "Celsius", "Fahrenheit", "Kelvin", "Romer" };
void availableUnits(void) {
	for (int i = 0; i < 4; i++) {
		printf("[%d] : %s\n", i + 1,unit[i]);
	}
}
double convertTocel(int in,double inTemp) {
	int x = in;
	switch (x) {
	case 1:
		return inTemp;
		break;
	case 2://Fahrenheit to Celcius
		return ((inTemp - 32.0) * (5.0 / 9.0));
		break;
	case 3://Kelvin to Celcius
		return (inTemp-273.15);
		break;
	case 4://Romer to Celcius
		return (inTemp*1.25);
		break;
	}
}
double convertToanswer(int out, double tempo) {
	int x = out;
	double y = 0;
	switch (x) {
	case 1: //Celcius to Celcius
		return tempo;
		break;
	case 2: //Celcius to Fahrenheit
		return(tempo * 9.0 / 5.0) + 32;
		break;
	case 3: //Celcius to Kelvin
		return(tempo + 273.15);
		break;
	case 4: //Celcius to Romer
		return tempo * 0.8;
		break;
	}
}
int main() {
	int in=0, out=0;
	double inTemp=0,tempo=0;
	printf("---Temperature converter system---\n\nAll of available units\n");
	availableUnits();
	printf("Please select an input unit(number of unit)  : ");
	scanf(" %d", &in);
	printf("Please select an output unit(number of unit) : ");
	scanf(" %d", &out);
	if ((in == out) || in > 4 || in < 1 || out>4 || out < 1) {
		printf("\n\n===Error the unit number should be in the list and shouldn't be the same..===\n\n");
		printf("--------End---------\n");
	}
	else {
		printf("\n\n===Start converting [%s] to [%s]===\n\n", unit[in-1], unit[out-1]);
		printf("Value of [%s] = ", unit[in-1]);
		scanf("%lf", &inTemp);
		tempo = convertTocel(in, inTemp);
		printf("\n\n%.2lf [%s] is %.2lf [%s]\n\n",inTemp,unit[in-1],convertToanswer(out, tempo),unit[out-1]);
		printf("--------End---------\n");
	}
}