# High-Performance-Matrix-Operartions
Memory-intensive and high performant C code, with functions drawn from image processing and matrix operations. Specifically, optimizing two functions: Normalization of the matrix and Kronecker Product.


The focus is on implementing and optimizing these functions with using techniques such as:

- **Code motion**
- **Loop unrolling**
- **Cache optimization**
- **Reducing sequential dependencies**

Performance will be measured using the **Cycles Per Element (CPE)** metric. Higher speed-ups compared to baseline implementations will demonstrate successful optimizations.

---

## Algorithms:

### 1) Normalization

Normalization is a statistical process for scaling data. For this project, we use **min-max scaling** on matrices. Given a source matrix `M`, the normalized matrix `M'` is computed as:

```latex
M' = \frac{M - M_{\text{min}}}{M_{\text{max}} - M_{\text{min}}}
```

The function will:
1. Identify the minimum and maximum values in the matrix.
2. Scale each element of the matrix to a range between 0 and 1.

### 2) Kronecker Product

The Kronecker Product generates a larger matrix by scaling one matrix (`mat2`) by each element of another (`mat1`). For example:

\begin{bmatrix}
0 & 2 \\
1 & 3
\end{bmatrix}
\otimes
\begin{bmatrix}
5 & 6 & 7 \\
8 & 9 & 10 \\
11 & 12 & 13
\end{bmatrix}

produces a 6x6 matrix. The algorithm involves:
1. Scaling `mat2` by each element of `mat1`.
2. Arranging the scaled results in the correct positions to form the final matrix.

---

## Optimization Techniques

### Code Motion
Reorganize computations to reduce redundancy.

### Loop Unrolling
Process multiple iterations in a single loop to minimize overhead.

### Reducing Sequential Dependency
Split operations into independent tasks to enhance parallelism.

### Cache-Friendly Coding
Optimize memory access patterns for better cache utilization:
- **Spatial locality**: Access elements stored close together.
- **Temporal locality**: Reuse recently accessed data.

Performance is measured in terms of speed-ups achieved by the optimized code over the naive baseline. Speed-ups are calculated as:

\[
\text{Speed-up} = \frac{\text{CPE}_{\text{naive}}}{\text{CPE}_{\text{optimized}}}
\]

