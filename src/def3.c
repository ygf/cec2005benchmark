/* Source file for custom initialization */
/* Hard-coded for every function based on the type and nature of input files */
/* At present hard-coded for D=2, 10, 30 and 50 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <R.h>

#include "global.h"
#include "sub.h"
#include "rand.h"

FILE *open_input_data(char *name)
{
    FILE *fpt;
    char buf[PATH_MAX];
    snprintf(buf, PATH_MAX, "%s/extdata/%s", R_PACKAGE_DIR, name);
    fpt = fopen(buf, "r");
    if (fpt == NULL) {
        error("cannot open input file for reading\n");
    }
    return fpt;
}

void initialize_f1()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("sphere_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f2()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("schwefel_102_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f3()
{
    int i, j;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("elliptic_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("elliptic_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("elliptic_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("elliptic_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("high_cond_elliptic_rot_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f4()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("schwefel_102_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -450.0;
    return;
}

void initialize_f5()
{
    int i, j;
    int index;
    FILE *fpt;
    char c;
    A_f5 = (long double **) malloc(nreal * sizeof(long double));
    for (i = 0; i < nreal; i++) {
        A_f5[i] = (long double *) malloc(nreal * sizeof(long double));
    }
    B_f5 = (long double *) malloc(nreal * sizeof(long double));
    fpt = open_input_data("schwefel_206_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &A_f5[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal % 4 == 0) {
        index = nreal / 4;
    } else {
        index = nreal / 4 + 1;
    }
    for (i = 0; i < index; i++) {
        o[0][i] = -100.0;
    }
    index = (3 * nreal) / 4 - 1;
    for (i = index; i < nreal; i++) {
        o[0][i] = 100.0;
    }
    for (i = 0; i < nreal; i++) {
        B_f5[i] = 0.0;
        for (j = 0; j < nreal; j++) {
            B_f5[i] += A_f5[i][j] * o[0][j];
        }
    }
    bias[0] = -310.0;
    return;
}

void initialize_f6()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("rosenbrock_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
            o[i][j] -= 1.0;
        }
    }
    fclose(fpt);
    bias[0] = 390.0;
    return;
}

void initialize_f7()
{
    int i, j;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("griewank_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("griewank_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("griewank_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("griewank_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("griewank_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -180.0;
    return;
}

void initialize_f8()
{
    int i, j;
    int index;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("ackley_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("ackley_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("ackley_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("ackley_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("ackley_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    index = nreal / 2;
    for (i = 1; i <= index; i++) {
        o[0][2 * i - 2] = -32.0;
    }
    bias[0] = -140.0;
    return;
}

void initialize_f9()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("rastrigin_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -330.0;
    return;
}

void initialize_f10()
{
    int i, j;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("rastrigin_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("rastrigin_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("rastrigin_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("rastrigin_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("rastrigin_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -330.0;
    return;
}

void initialize_f11()
{
    int i, j;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("weierstrass_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("weierstrass_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("weierstrass_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("weierstrass_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("weierstrass_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = 90.0;
    return;
}

void initialize_f12()
{
    int i, j;
    FILE *fpt;
    char c;
    A_f12 = (long double **) malloc(nreal * sizeof(long double));
    B_f12 = (long double **) malloc(nreal * sizeof(long double));
    alpha_f12 = (long double *) malloc(nreal * sizeof(long double));
    for (i = 0; i < nreal; i++) {
        A_f12[i] = (long double *) malloc(nreal * sizeof(long double));
        B_f12[i] = (long double *) malloc(nreal * sizeof(long double));
    }
    fpt = open_input_data("schwefel_213_data.txt");
    /* Reading A */
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &A_f12[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    if (i != 100) {
        for (i = nreal; i < 100; i++) {
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    /* Reading B */
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &B_f12[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    if (i != 100) {
        for (i = nreal; i < 100; i++) {
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    /* Reading alpha */
    for (i = 0; i < nreal; i++) {
        fscanf(fpt, "%Lf", &alpha_f12[i]);
    }
    fclose(fpt);
    bias[0] = -460.0;
    return;
}

void initialize_f13()
{
    int i, j;
    FILE *fpt;
    fpt = open_input_data("EF8F2_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
            o[i][j] -= 1.0;
        }
    }
    fclose(fpt);
    bias[0] = -130.0;
    return;
}

void initialize_f14()
{
    int i, j;
    FILE *fpt;
    if (nreal == 2) fpt = open_input_data("E_ScafferF6_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("E_ScafferF6_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("E_ScafferF6_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("E_ScafferF6_M_D50.txt");
    for (i = 0; i < nreal; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &g[i][j]);
        }
    }
    fclose(fpt);
    fpt = open_input_data("E_ScafferF6_func_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
    }
    fclose(fpt);
    bias[0] = -300.0;
    return;
}

void initialize_f15()
{
    int i, j;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func1_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0 / 12.0;
    lambda[5] = 1.0 / 12.0;
    lambda[6] = 5.0 / 32.0;
    lambda[7] = 5.0 / 32.0;
    lambda[8] = 1.0 / 20.0;
    lambda[9] = 1.0 / 20.0;
    global_bias = 120.0;
    return;
}

void initialize_f16()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func1_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func1_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func1_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func1_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func1_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0 / 12.0;
    lambda[5] = 1.0 / 12.0;
    lambda[6] = 5.0 / 32.0;
    lambda[7] = 5.0 / 32.0;
    lambda[8] = 1.0 / 20.0;
    lambda[9] = 1.0 / 20.0;
    global_bias = 120.0;
    return;
}

void initialize_f17()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func1_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func1_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func1_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func1_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func1_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    lambda[0] = 1.0;
    lambda[1] = 1.0;
    lambda[2] = 10.0;
    lambda[3] = 10.0;
    lambda[4] = 1.0 / 12.0;
    lambda[5] = 1.0 / 12.0;
    lambda[6] = 5.0 / 32.0;
    lambda[7] = 5.0 / 32.0;
    lambda[8] = 1.0 / 20.0;
    lambda[9] = 1.0 / 20.0;
    global_bias = 120.0;
    return;
}

void initialize_f18()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func2_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func2_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func2_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func2_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func2_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    for (i = 0; i < nreal; i++) {
        o[nfunc - 1][i] = 0.0;
    }
    sigma[0] = 1.0;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 5.0 / 16.0;
    lambda[1] = 5.0 / 32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0 / 10.0;
    lambda[5] = 1.0 / 20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 6.0;
    lambda[9] = 1.0 / 12.0;
    global_bias = 10.0;
    return;
}

void initialize_f19()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func2_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func2_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func2_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func2_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func2_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    for (i = 0; i < nreal; i++) {
        o[nfunc - 1][i] = 0.0;
    }
    sigma[0] = 0.1;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 0.5 / 32.0;
    lambda[1] = 5.0 / 32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0 / 10.0;
    lambda[5] = 1.0 / 20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 6.0;
    lambda[9] = 1.0 / 12.0;
    global_bias = 10.0;
    return;
}

void initialize_f20()
{
    int i, j, k;
    int index;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func2_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    index = nreal / 2;
    for (i = 1; i <= index; i++) {
        o[0][2 * i - 1] = 5.0;
    }
    if (nreal == 2) fpt = open_input_data("hybrid_func2_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func2_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func2_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func2_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    for (i = 0; i < nreal; i++) {
        o[nfunc - 1][i] = 0.0;
    }
    sigma[0] = 1.0;
    sigma[1] = 2.0;
    sigma[2] = 1.5;
    sigma[3] = 1.5;
    sigma[4] = 1.0;
    sigma[5] = 1.0;
    sigma[6] = 1.5;
    sigma[7] = 1.5;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 5.0 / 16.0;
    lambda[1] = 5.0 / 32.0;
    lambda[2] = 2.0;
    lambda[3] = 1.0;
    lambda[4] = 1.0 / 10.0;
    lambda[5] = 1.0 / 20.0;
    lambda[6] = 20.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 6.0;
    lambda[9] = 1.0 / 12.0;
    global_bias = 10.0;
    return;
}

void initialize_f21()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func3_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func3_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func3_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func3_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func3_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0 / 4.0;
    lambda[1] = 1.0 / 20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 8.0;
    lambda[9] = 1.0 / 40.0;
    global_bias = 360.0;
    return;
}

void initialize_f22()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func3_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func3_HM_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func3_HM_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func3_HM_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func3_HM_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0 / 4.0;
    lambda[1] = 1.0 / 20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 8.0;
    lambda[9] = 1.0 / 40.0;
    global_bias = 360.0;
    return;
}

void initialize_f23()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func3_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func3_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func3_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func3_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func3_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    sigma[0] = 1.0;
    sigma[1] = 1.0;
    sigma[2] = 1.0;
    sigma[3] = 1.0;
    sigma[4] = 1.0;
    sigma[5] = 2.0;
    sigma[6] = 2.0;
    sigma[7] = 2.0;
    sigma[8] = 2.0;
    sigma[9] = 2.0;
    lambda[0] = 1.0 / 4.0;
    lambda[1] = 1.0 / 20.0;
    lambda[2] = 5.0;
    lambda[3] = 1.0;
    lambda[4] = 5.0;
    lambda[5] = 1.0;
    lambda[6] = 50.0;
    lambda[7] = 10.0;
    lambda[8] = 1.0 / 8.0;
    lambda[9] = 1.0 / 40.0;
    global_bias = 360.0;
    return;
}

void initialize_f24_f25()
{
    int i, j, k;
    FILE *fpt;
    char c;
    fpt = open_input_data("hybrid_func4_data.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            fscanf(fpt, "%Lf", &o[i][j]);
        }
        do {
            fscanf(fpt, "%c", &c);
        } while (c != '\n');
    }
    fclose(fpt);
    if (nreal == 2) fpt = open_input_data("hybrid_func4_M_D2.txt");
    if (nreal == 10) fpt = open_input_data("hybrid_func4_M_D10.txt");
    if (nreal == 30) fpt = open_input_data("hybrid_func4_M_D30.txt");
    if (nreal == 50) fpt = open_input_data("hybrid_func4_M_D50.txt");
    for (i = 0; i < nfunc; i++) {
        for (j = 0; j < nreal; j++) {
            for (k = 0; k < nreal; k++) {
                fscanf(fpt, "%Lf", &l[i][j][k]);
            }
            do {
                fscanf(fpt, "%c", &c);
            } while (c != '\n');
        }
    }
    for (i = 0; i < nfunc; i++) {
        sigma[i] = 2.0;
    }
    lambda[0] = 10.0;
    lambda[1] = 1.0 / 4.0;
    lambda[2] = 1.0;
    lambda[3] = 5.0 / 32.0;
    lambda[4] = 1.0;
    lambda[5] = 1.0 / 20.0;
    lambda[6] = 1.0 / 10.0;
    lambda[7] = 1.0;
    lambda[8] = 1.0 / 20.0;
    lambda[9] = 1.0 / 20.0;
    global_bias = 260.0;
    return;
}
