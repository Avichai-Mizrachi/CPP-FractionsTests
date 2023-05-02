#pragma once

#include <math.h>
#include <iostream>
#include <string>
using namespace std;



namespace ariel
{
    class Fraction
    {
    private:
        float numerator;
        float denominator;

    public:
        Fraction(float, float);
        Fraction(float);
        Fraction();
        Fraction(const Fraction &other);
        ~Fraction() = default;

        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;
        bool operator>(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;

        Fraction operator+(float other);
        Fraction operator-(float other);
        Fraction operator*(float other);
        Fraction operator/(float other);
        bool operator<(float other);
        bool operator<=(float other);
        bool operator>(float other);
        bool operator>=(float other);
        bool operator==(float other);
        bool operator!=(float other);

        Fraction &operator++();
        Fraction operator++(int);
        Fraction &operator--();
        Fraction operator--(int);

        // Getters
        float getNumerator()
        {
            return numerator;
        }
        float getDenominator()
        {
            return denominator;
        }

        // Reduce
        static void reduce(float &numerator, float &denominator)
        {
            float min;
            if (numerator < denominator) {
                min = numerator;
            } else {
                min = denominator;
            }
            float gcd = 1;
            for (int i = 2; (float)i <= min; i++)
            {
                if ((int)round(numerator) % i == 0 && (int)round(denominator) % i == 0)
                {
                    gcd = (float)i;
                }
            }

            gcd = round(gcd);
            numerator /= gcd;
            denominator /= gcd;
        }

        friend Fraction operator+(float other, const Fraction &fraction2)
        {
            Fraction c = fraction2;
            float numerator = other * c.getDenominator() + c.getNumerator();
            float denominator = c.getDenominator();
            return Fraction(numerator, denominator);
        }
        friend Fraction operator-(float other, const Fraction &fraction2)
        {
            Fraction c = fraction2;
            float numerator = other * c.getDenominator() - c.getNumerator();
            float denominator = c.getDenominator();
            return Fraction(numerator, denominator);
        }
        friend Fraction operator*(float other, const Fraction &fraction2)
        {
            Fraction c = fraction2;
            float numerator = other * c.getDenominator() + c.getNumerator();
            float denominator = c.getDenominator();
            return Fraction(numerator, denominator);
        }
        friend Fraction operator/(float other, const Fraction &fraction2){
            return Fraction(1,1);
        }
        friend bool operator==(float other, const Fraction &fraction2){
            return false;
        }
        friend bool operator!=(float other, const Fraction &fraction2){
            return false;
        }
        friend bool operator>(float other, const Fraction &fraction2){
            return false;
        }
        friend bool operator>=(float other, const Fraction &fraction2){
            return false;
        }
        friend bool operator<(float other, const Fraction &fraction2){
            return false;
        }
        friend bool operator<=(float other, const Fraction &fraction2){
            return false;
        }

        friend std::ostream &operator<<(std::ostream &, const Fraction &);
        friend std::istream &operator>>(std::istream &, const Fraction &);
    };
}