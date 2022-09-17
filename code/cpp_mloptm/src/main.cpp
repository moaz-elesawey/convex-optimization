#include "Method.hpp"
#include <iostream>

float f  (float x){ return 2*x*x;}
float df (float x){ return 2*2*x;}
float ddf(float x){ return 2*2;  }

int main(int argc, char **argv) {

	float min;

	min = Method::Golden(f, -2.0, 2.0, 0.0001);
	std::cout << "Golden Method Minima = " << min << std::endl;

	min = Method::BiSection(f, df, -2.0, 2.0, 20);
	std::cout << "BiSection Method Minima = " << min << std::endl;

	min = Method::Newton(f, df, ddf, -2, 0.0001);
	std::cout << "Newton Method Minima = " << min << std::endl;

	min = Method::Secant(f, df, -2.0, -1.0, 0.001);
	std::cout << "Secant Method Minima = " << min << std::endl;

	return 0;
}
