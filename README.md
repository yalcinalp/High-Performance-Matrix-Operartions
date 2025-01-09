# High-Performance-Matrix-Operations
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

The function will:
1. Identify the minimum and maximum values in the matrix.
2. Scale each element of the matrix to a range between 0 and 1.

### 2) Kronecker Product

The Kronecker Product generates a larger matrix by scaling one matrix (`mat2`) by each element of another (`mat1`)

**Examples:**

![image](https://github.com/user-attachments/assets/019f8b1b-1296-4086-8256-3e0f537f0f06)

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

Performance is measured in terms of speed-ups achieved by the optimized code over the naive baseline:

![image](https://github.com/user-attachments/assets/dd2cf9d3-9a87-41d0-a39d-f6681a6f404c)

![image](https://github.com/user-attachments/assets/4663a683-daf4-49c2-8aed-ba88707dde3d)



