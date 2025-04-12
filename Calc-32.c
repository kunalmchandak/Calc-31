#include <stdio.h>
#include <math.h>

long int factorial(int n)
{
    long int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

double determinant(double matrix[10][10], int n)
{
    double det = 0;
    double submatrix[10][10];
    if (n == 1)
    {
        return matrix[0][0];
    }
    if (n == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    for (int x = 0; x < n; x++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
    }
    return det;
}

void baseConversion(int num, int fromBase, int toBase)
{
    int decimal = 0, power = 1, remainder;
    while (num > 0)
    {
        remainder = num % 10;
        decimal += remainder * power;
        power *= fromBase;
        num /= 10;
    }
    int converted[50], i = 0;
    while (decimal > 0)
    {
        converted[i] = decimal % toBase;
        decimal /= toBase;
        i++;
    }
    printf("CONVERTED NUMBER: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", converted[j]);
    printf("\n");
}

void matrixTranspose()
{
    int mat[10][10], trans[10][10];
    int row, col, i, j;
    printf("ENTER ROWS AND COLUMNS: ");
    scanf("%d %d", &row, &col);
    printf("ENTER MATRIX ELEMENTS:\n");
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            trans[j][i] = mat[i][j];
    printf("TRANSPOSED MATRIX:\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }
}

void solveQuadratic()
{
    double a, b, c, discriminant, root1, root2;
    printf("ENTER COEFFICIENTS A, B AND C: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("ROOTS ARE REAL AND DIFFERENT: %.2lf, %.2lf\n", root1, root2);
    }
    else if (discriminant == 0)
    {
        root1 = -b / (2 * a);
        printf("ROOTS ARE REAL AND EQUAL: %.2lf\n", root1);
    }
    else
    {
        double real = -b / (2 * a);
        double imag = sqrt(-discriminant) / (2 * a);
        printf("ROOTS ARE COMPLEX: %.2lf + %.2lfi, %.2lf - %.2lfi\n", real, imag, real, imag);
    }
}

void interestCalculator()
{
    double p, r, t;
    printf("ENTER PRINCIPAL, RATE, AND TIME: ");
    scanf("%lf %lf %lf", &p, &r, &t);
    double si = (p * r * t) / 100;
    double ci = p * pow((1 + r / 100), t) - p;
    printf("SIMPLE INTEREST = %.2lf\n", si);
    printf("COMPOUND INTEREST = %.2lf\n", ci);
}

void findGreatest()
{
    int n, num, max = -999999;
    printf("ENTER HOW MANY NUMBERS: ");
    scanf("%d", &n);
    printf("ENTER NUMBERS:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num > max)
            max = num;
    }
    printf("GREATEST NUMBER: %d\n", max);
}

void reverseNumber()
{
    int n, rev = 0;
    printf("ENTER A NUMBER: ");
    scanf("%d", &n);
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    printf("REVERSED NUMBER: %d\n", rev);
}

void checkArmstrong()
{
    int n, original, remainder, result = 0, count = 0;
    printf("ENTER A NUMBER: ");
    scanf("%d", &n);
    original = n;
    int temp = n;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    while (n != 0)
    {
        remainder = n % 10;
        result += pow(remainder, count);
        n /= 10;
    }
    if (result == original)
        printf("%d IS AN ARMSTRONG NUMBER\n", original);
    else
        printf("%d IS NOT AN ARMSTRONG NUMBER\n", original);
}

void checkPalindrome()
{
    int n, original, rev = 0;
    printf("ENTER A NUMBER: ");
    scanf("%d", &n);
    original = n;
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    if (rev == original)
        printf("%d IS A PALINDROME\n", original);
    else
        printf("%d IS NOT A PALINDROME\n", original);
}

void toRomanNumerals()
{
    int number;
    printf("ENTER NUMBER (1-3999): ");
    scanf("%d", &number);
    if (number <= 0 || number > 3999)
    {
        printf("OUT OF RANGE!\n");
        return;
    }
    struct roman
    {
        int value;
        char *symbol;
    } romans[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    printf("ROMAN NUMERAL: ");
    for (int i = 0; i < 13; i++)
    {
        while (number >= romans[i].value)
        {
            printf("%s", romans[i].symbol);
            number -= romans[i].value;
        }
    }
    printf("\n");
}

void findASCII()
{
    char ch;
    printf("ENTER A CHARACTER: ");
    scanf(" %c", &ch);
    printf("ASCII VALUE OF %c = %d\n", ch, ch);
}

void evaluateExpression()
{
    char expr[100];
    printf("ENTER AN ARITHMETIC EXPRESSION (E.G., 3+4*2): ");
    scanf("%s", expr);
    printf("NOTE: THIS JUST SHOWS INPUT. USE PARSER FOR FULL EVALUATION.\n");
}

void main()
{
    long int choice, a, b, c, i, j;
    float sct, degree;
    long int d[10][10], e[10][10], sum[10][10], prod[10][10];
    do
    {
        printf("\n • PRESS 1 FOR ADDITION.");
        printf("\n • PRESS 2 FOR SUBTRACTION.");
        printf("\n • PRESS 3 FOR MULTIPLICATION.");
        printf("\n • PRESS 4 FOR DIVISION.");
        printf("\n • PRESS 5 FOR MODULUS.");
        printf("\n • PRESS 6 FOR TRIGONOMETRIC RATIOS.");
        printf("\n • PRESS 7 FOR MATRIX ADDITION.");
        printf("\n • PRESS 8 FOR FINDING THE POWER OF A NUMBER.");
        printf("\n • PRESS 9 FOR FINDING SQUARE ROOT AND CUBE ROOT OF A NUMBER.");
        printf("\n • PRESS 10 FOR FINDING COMMON LOGARITHM AND NATURAL LOGARITHM OF A NUMBER.");
        printf("\n • PRESS 11 FOR PRINTING MULTIPLICATION TABLE.");
        printf("\n • PRESS 12 FOR MATRIX MULTIPLICATION.");
        printf("\n • PRESS 13 FOR FACTORIAL CALCULATION.");
        printf("\n • PRESS 14 FOR GCD AND LCM CALCULATION.");
        printf("\n • PRESS 15 FOR PRIME NUMBER CHECK.");
        printf("\n • PRESS 16 FOR FIBONACCI SERIES.");
        printf("\n • PRESS 17 FOR TEMPERATURE CONVERSION.");
        printf("\n • PRESS 18 FOR BINARY, OCTAL, AND HEXADECIMAL CONVERSIONS.");
        printf("\n • PRESS 19 FOR DETERMINANT CALCULATION.");
        printf("\n • PRESS 20 FOR BASE CONVERSION.");
        printf("\n • PRESS 21 FOR PERMUTATION & COMBINATION.");
        printf("\n • PRESS 22 FOR MATRIX TRANSPOSE.");
        printf("\n • PRESS 23 FOR QUADRATIC EQUATION SOLVER.");
        printf("\n • PRESS 24 FOR SIMPLE & COMPOUND INTEREST CALCULATOR.");
        printf("\n • PRESS 25 FOR FINDING THE GREATEST OF N NUMBERS.");
        printf("\n • PRESS 26 FOR REVERSING A NUMBER.");
        printf("\n • PRESS 27 FOR ARMSTRONG NUMBER CHECKER.");
        printf("\n • PRESS 28 FOR PALINDROME NUMBER CHECKER.");
        printf("\n • PRESS 29 FOR ROMAN NUMERAL CONVERTER.");
        printf("\n • PRESS 30 FOR ASCII VALUE FINDER.");
        printf("\n • PRESS 31 FOR BASIC EXPRESSION EVALUATOR.");
        printf("\n • PRESS 32 TO EXIT.");

        printf("\n\n ENTER YOUR CHOICE :\t");
        scanf("%ld", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("\n\n ENTER FIRST NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER SECOND NUMBER :\t");
                scanf("%ld", &b);
                c = a + b;
                printf("\n ADDITION OF TWO NUMBERS :\t%ld\n", c);
                break;
            }
            case 2:
            {
                printf("\n\n ENTER FIRST NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER SECOND NUMBER :\t");
                scanf("%ld", &b);
                c = a - b;
                printf("\n SUBTRACTION OF TWO NUMBERS =\t%ld\n", c);
                break;
            }
            case 3:
            {
                printf("\n\n ENTER FIRST NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER SECOND NUMBER :\t");
                scanf("%ld", &b);
                c = a * b;
                printf("\n MULTIPLICATION OF TWO NUMBERS =\t%ld\n", c);
                break;
            }
            case 4:
            {
                printf("\n\n ENTER FIRST NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER SECOND NUMBER :\t");
                scanf("%ld", &b);
                if (b == 0)
                {
                    printf("\n ERROR: DIVISION BY ZERO!\n");
                }
                else
                {
                    c = a / b;
                    printf("\n DIVISION OF TWO NUMBERS =\t%ld\n", c);
                }
                break;
            }
            case 5:
            {
                printf("\n\n ENTER FIRST NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER SECOND NUMBER :\t");
                scanf("%ld", &b);
                if (b == 0)
                {
                    printf("\n ERROR: DIVISION BY ZERO!\n");
                }
                else
                {
                    c = a % b;
                    printf("\n MODULUS OF TWO NUMBERS =\t%ld\n", c);
                }
                break;
            }
            case 6:
            {
                printf("\n\n ENTER ANY ANGLE :\t");
                scanf("%f", &degree);
                sct = degree * (3.1416 / 180);
                printf("\n SIN OF THE ANGLE =\t%.1f", sin(sct));
                printf("\n COS OF THE ANGLE =\t%.1f", cos(sct));
                printf("\n TAN OF THE ANGLE =\t%.1f", tan(sct));
                printf("\n COSINE OF THE ANGLE =\t%.1f", sinh(sct));
                printf("\n SECANT OF THE ANGLE =\t%.1f", cosh(sct));
                printf("\n COT OF THE ANGLE =\t%.1f\n", tanh(sct));
                break;
            }
            case 7:
            {
                printf("ENTER THE NUMBER OF ROWS :\t");
                scanf("%ld", &a);
                printf("ENTER THE NUMBER OF COLUMNS :\t");
                scanf("%ld", &b);
                printf("\nENTER THE ELEMENT OF THE 1ST MATRIX :\n");
                for (i = 0; i < a; ++i)
                    for (j = 0; j < b; ++j)
                    {
                        printf("ENTER ELEMENTS A%ld%ld: ", i + 1, j + 1);
                        scanf("%ld", &d[i][j]);
                    }
                printf("\nENTER THE ELEMENTOF 2ND MATRIX :\n");
                for (i = 0; i < a; ++i)
                    for (j = 0; j < b; ++j)
                    {
                        printf("ENTER ELEMENT B%ld%ld: ", i + 1, j + 1);
                        scanf("%ld", &e[i][j]);
                    }
                for (i = 0; i < a; ++i)
                    for (j = 0; j < b; ++j)
                    {
                        sum[i][j] = d[i][j] + e[i][j];
                    }
                printf("\nSUM OF TWO MATRICES : \n");
                for (i = 0; i < a; ++i)
                    for (j = 0; j < b; ++j)
                    {
                        printf("%ld", sum[i][j]);
                        if (j == b - 1)
                        {
                            printf("\n\n");
                        }
                    }
                break;
            }
            case 8:
            {
                printf("\n ENTER THE BASE NUMBER :\t");
                scanf("%ld", &a);
                printf("\n ENTER THE EXPONENT :\t");
                scanf("%ld", &b);
                pow(a, b);
                printf("\n BASE %ld TO THE POWER %ld =\t%.2f", a, b, pow(a, b));
                break;
            }
            case 9:
            {
                printf("\n ENTER THE NUMBER :\t");
                scanf("%ld", &a);
                sqrt(a);
                cbrt(a);
                printf("\n SQUARE ROOT OF %ld IS =\t%.1f", a, sqrt(a));
                printf("\n CUBE ROOT OF %ld IS =\t%.1f", a, cbrt(a));
                break;
            }
            case 10:
            {
                printf("\n ENTER THE NUMBER :\t");
                scanf("%f", &sct);
                log(sct);
                log10(sct);
                printf("\n LOG(%.2f) =\t%.2f", a, log(sct));
                printf("\n LOG10(%.2f) =\t%.2f", a, log10(sct));
                break;
            }
            case 11:
            {
                printf("\n ENTER THE NUMBER WHOSE MULTIPLICATION TABLE IS TO BE PRINTED :\t");
                scanf("%ld", &a);
                printf("\n ENTER THE NUMBER TILL WHERE YOU WANT THE MULTIPLICATION TABLE :\t");
                scanf("%ld", &b);
                printf("\n MULTIPLICATION TABLE OF THE %ld IS :\n", a);
                for (i = 1; i <= b; i++)
                {
                    j = a * i;
                    printf("\n %ld X %ld = %ld", a, i, j);
                }
                break;
            }
            case 12:
            {
                printf("ENTER THE NUMBER OF ROWS AND COLUMNS OF MATRIX:");
                scanf("%ld %ld", &a, &b);
                printf("ENTER ELEMENTS OF FIRST MATRIX:\n");
                for (i = 0; i < a; i++)
                    for (j = 0; j < b; j++)
                        scanf("%ld", &d[i][j]);
                printf("ENTER ELEMENTS OF SECOND MATRIX:\n");
                for (i = 0; i < a; i++)
                    for (j = 0; j < b; j++)
                        scanf("%ld", &e[i][j]);
                for (i = 0; i < a; i++)
                    for (j = 0; j < b; j++)
                    {
                        prod[i][j] = 0;
                        for (int k = 0; k < b; k++)
                            prod[i][j] += d[i][k] * e[k][j];
                    }
                printf("\nMATRIX MULTIPLICATION RESULT:\n");
                for (i = 0; i < a; i++)
                {
                    for (j = 0; j < b; j++)
                        printf("%ld ", prod[i][j]);
                    printf("\n");
                }
                break;
            }
            case 13:
            {
                printf("ENTER A NUMBER TO FIND FACTORIAL:");
                scanf("%ld", &a);
                long int fact = 1;
                for (i = 1; i <= a; i++)
                    fact *= i;
                printf("FACTORIAL OF %ld IS: %ld\n", a, fact);
                break;
            }
            case 14:
            {
                printf("ENTER TWO NUMBERS FOR GCD AND LCM:");
                scanf("%ld %ld", &a, &b);
                long int x = a, y = b;
                while (y != 0)
                {
                    long int temp = y;
                    y = x % y;
                    x = temp;
                }
                long int gcd = x;
                long int lcm = (a * b) / gcd;
                printf("GCD: %ld, LCM: %ld\n", gcd, lcm);
                break;
            }
            case 15:
            {
                printf("ENTER A NUMBER TO CHECK PRIME:");
                scanf("%ld", &a);
                int is_prime = 1;
                if (a < 2)
                    is_prime = 0;
                for (i = 2; i * i <= a; i++)
                {
                    if (a % i == 0)
                    {
                        is_prime = 0;
                        break;
                    }
                }
                if (is_prime)
                    printf("%ld IS A PRIME NUMBER\n", a);
                else
                    printf("%ld IS NOT A PRIME NUMBER\n", a);
                break;
            }
            case 16:
            {
                printf("ENTER NUMBER OF TERMS FOR FIBONACCI SERIES:");
                scanf("%ld", &a);
                long int t1 = 0, t2 = 1, next;
                printf("FIBONACCI SERIES: %ld %ld ", t1, t2);
                for (i = 2; i < a; i++)
                {
                    next = t1 + t2;
                    printf("%ld ", next);
                    t1 = t2;
                    t2 = next;
                }
                printf("\n");
                break;
            }
            case 17:
            {
                printf("ENTER TEMPERATURE IN CELSIUS:");
                scanf("%f", &sct);
                printf("TEMPERATURE IN FAHRENHEIT: %.2f\n", (sct * 9 / 5) + 32);
                break;
            }
            case 18:
            {
                printf("ENTER A DECIMAL NUMBER:");
                scanf("%ld", &a);
                printf("BINARY: %ld, OCTAL: %lo, HEXADECIMAL: %lX\n", a, a, a);
                break;
            }
            case 19:
            {
                double matrix[10][10];
                int n;
                printf("ENTER THE SIZE OF THE MATRIX (n x n): ");
                scanf("%d", &n);
                printf("ENTER MATRIX ELEMENTS:\n");
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        scanf("%lf", &matrix[i][j]);
                printf("DETERMINANT: %lf\n", determinant(matrix, n));
                break;
            }
            case 20:
            {
                int num, fromBase, toBase;
                printf("ENTER NUMBER, SOURCE BASE AND TARGET BASE: ");
                scanf("%d %d %d", &num, &fromBase, &toBase);
                baseConversion(num, fromBase, toBase);
                break;
            }
            case 21:
            {
                int n, r;
                printf("ENTER n AND r FOR PERMUTATION & COMBINATION: ");
                scanf("%d %d", &n, &r);
                long int nPr = factorial(n) / factorial(n - r);
                long int nCr = nPr / factorial(r);
                printf("nPr: %ld, nCr: %ld\n", nPr, nCr);
                break;
            }
            case 22:
            {
                matrixTranspose();
                break;
            }
            case 23:
            {
                solveQuadratic();
                break;
            }
            case 24:
            {
                interestCalculator();
                break;
            }
            case 25:
            {
                findGreatest();
                break;
            }
            case 26:
            {
                reverseNumber();
                break;
            }
            case 27:
            {
                checkArmstrong();
                break;
            }
            case 28:
            {
                checkPalindrome();
                break;
            }
            case 29:
            {
                toRomanNumerals();
                break;
            }
            case 30:
            {
                findASCII();
                break;
            }
            case 31:
            {
                evaluateExpression();
                break;
            }
            case 32:
            {
                printf("\n\n THANK YOU FOR USING THE CALCULATOR. \n\n");
                break;
            }
            default:
            {
                printf("\n\n ``` PLEASE ENTER THE CORRECT OPTION. ```");
            }
        }
    } while (choice != 32);
}
