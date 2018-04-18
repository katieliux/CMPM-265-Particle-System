#include "curves.h"

float Sine::easeIn(float t, float b, float c, float d) {
	return -c * cos(t / d * (PI / 2)) + c + b;
}
float Sine::easeOut(float t, float b, float c, float d) {
	return c * sin(t / d * (PI / 2)) + b;
}

float Sine::easeInOut(float t, float b, float c, float d) {
	return -c / 2 * (cos(PI*t / d) - 1) + b;
}

float Circ::easeIn(float t, float b, float c, float d) {
	return -c * (sqrt(1 - (t /= d)*t) - 1) + b;
}
float Circ::easeOut(float t, float b, float c, float d) {
	return c * sqrt(1 - (t = t / d - 1)*t) + b;
}

float Circ::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
	return c / 2 * (sqrt(1 - t*(t -= 2)) + 1) + b;
}

float Quart::easeIn(float t, float b, float c, float d) {
	return c*(t /= d)*t*t*t + b;
}
float Quart::easeOut(float t, float b, float c, float d) {
	return -c * ((t = t / d - 1)*t*t*t - 1) + b;
}

float Quart::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
	return -c / 2 * ((t -= 2)*t*t*t - 2) + b;
}

float Linear::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Linear::easeIn(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Linear::easeOut(float t, float b, float c, float d) {
	return c*t / d + b;
}

float Linear::easeInOut(float t, float b, float c, float d) {
	return c*t / d + b;
}