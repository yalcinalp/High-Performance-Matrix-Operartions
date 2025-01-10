/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

team_t team = {
        "eXXXXXX",      
        "Alp",       
};

/********************
 * NORMALIZATION KERNEL
 ********************/

/*
 * naive_normalize - The naive baseline version of convolution
 */
char naive_normalize_descr[] = "naive_normalize: Naive baseline implementation";
void naive_normalize(int dim, float *src, float *dst) {
    float min, max;
    min = src[0];
    max = src[0];

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
	
            if (src[RIDX(i, j, dim)] < min) {
                min = src[RIDX(i, j, dim)];
            }
            if (src[RIDX(i, j, dim)] > max) {
                max = src[RIDX(i, j, dim)];
            }
        }
    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            dst[RIDX(i, j, dim)] = (src[RIDX(i, j, dim)] - min) / (max - min);
        }
    }
}


char normalize_descr[] = "Normalize: Current working version";
void normalize(int dim, float *src, float *dst) {
    if (dim <= 0) return;

    float min = src[0];
    float max = src[0];
    
    int i;
    int limit = dim * dim;
    int unroll = 4;
    
    for (i = 0; i < limit; i += unroll) {
        float val1 = src[i];
        float val2 = src[i+1];
        float val3 = src[i+2];
        float val4 = src[i+3];
        
        min = val1 < min ? val1 : min;
        min = val2 < min ? val2 : min;
        min = val3 < min ? val3 : min;
        min = val4 < min ? val4 : min;
        
        max = val1 > max ? val1 : max;
        max = val2 > max ? val2 : max;
        max = val3 > max ? val3 : max;
        max = val4 > max ? val4 : max;
    }

    float scale = 1.0f / (max - min);
    
    for (i = 0; i < limit; i += unroll) {
        dst[i] = (src[i] - min) * scale;
        dst[i+1] = (src[i+1] - min) * scale;
        dst[i+2] = (src[i+2] - min) * scale;
        dst[i+3] = (src[i+3] - min) * scale;
    }
    
}


void register_normalize_functions() {
    add_normalize_function(&naive_normalize, naive_normalize_descr);
    add_normalize_function(&normalize, normalize_descr);
    /* ... Register additional test functions here */
}




/************************
 * KRONECKER PRODUCT KERNEL
 ************************/

/*
 * naive_kronecker_product - The naive baseline version of k-hop neighbours
 */
char naive_kronecker_product_descr[] = "Naive Kronecker Product: Naive baseline implementation";
void naive_kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim1; j++) {
            for (int k = 0; k < dim2; k++) {
                for (int l = 0; l < dim2; l++) {
                    prod[RIDX(i, k, dim2) * (dim1 * dim2) + RIDX(j, l, dim2)] = mat1[RIDX(i, j, dim1)] * mat2[RIDX(k, l, dim2)];
                }
            }
        }
    }
}

char kronecker_product_descr[] = "Kronecker Product: Current working version";
void kronecker_product(int dim1, int dim2, float *mat1, float *mat2, float *prod)
{
    int i, j, k, l;

    for (i = 0; i < dim1; i++) {
    
    	int c = 0;
        for (j = 0; j < dim1; j++) {
            float scalar = mat1[RIDX(i, j, dim1)];

            for (k = 0; k < dim2; k++) {
                int    r = (i * dim2 + k) * (dim1 * dim2);
                
                float *mat2_ptr = &mat2[RIDX(k, 0, dim2)];
                float *prod_ptr = &prod[r + c];

                for (l = 0; l < dim2; l += 4) {
                    prod_ptr[l] = scalar * mat2_ptr[l];
                    prod_ptr[l + 1] = scalar * mat2_ptr[l + 1];
                    prod_ptr[l + 2] = scalar * mat2_ptr[l + 2];
                    prod_ptr[l + 3] = scalar * mat2_ptr[l + 3];
                }
            }
            
            c += dim2;
        }
    }
}

void register_kronecker_product_functions() {
    add_kronecker_product_function(&naive_kronecker_product, naive_kronecker_product_descr);
    add_kronecker_product_function(&kronecker_product, kronecker_product_descr);
    /* ... Register additional test functions here */
}

