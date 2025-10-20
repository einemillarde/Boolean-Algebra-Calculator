# Boolean Algebra Calculator

Boolean algebra is a branch of algebra that deals with only two values where `true` and `false` which are represented by `1` and `0` respectively. It is used in computer science and digital logic.

## Introduction

### Operators

Operators in boolean algebra take two inputs and return a single output

| **Operator** | **Symbol** | **Use Case** | **Precedence** | **Description** |
|---|---|---|---|---|
| NOT | `'` | `A'` | First | Inverts the value of A |
| AND | `*` | `A * B` | Second | Returns true only if both A and B are true |
| OR | `+` | `A + B` | Third | Returns true if either A or B is true |

There are more operators used in boolean algebra, but I will only be using these three as they make the most sense in terms of regular algebra. Here are the other operators, just in case you are curious:

| **Operator** | **Description** |
|---|---|
| XOR | Returns true if either A or B is true, but not both |
| NAND | Returns true if at least one of A or B is false |
| NOR | Returns true if both A and B are false |
| XNOR | Returns true if A and B are the same value |

### Truth Tables

Truth tables are a way to represent the output of boolean expressions based on all possible combinations of inputs. Below are the truth tables for the basic operations: NOT, AND, and OR.

**NOT**
| **Input** | **Output** |
|---|---|
| `0` | `1` |
| `1` | `0` |

**AND**
| **Input1** | **Input2** | **Output** |
|---|---|---|
| `0` | `0` | `0` |
| `0` | `1` | `0` |
| `1` | `0` | `0` |
| `1` | `1` | `1` |

**OR**
| **Input1** | **Input2** | **Output** |
|---|---|---|
| `0` | `0` | `0` |
| `0` | `1` | `1` |
| `1` | `0` | `1` |
| `1` | `1` | `1` |

### Laws

Just like regular algebra, boolean algebra has laws that govern how expressions can be simplified or manipulated. Below are some of the fundamental laws of boolean algebra, along with their OR and AND forms.

| **Law** | **OR Form** | **AND Form** |
|---|---|---|
| Identity Law | `P + 0 = P` | `P * 1 = P` |
| Idempotent Law | `P + P = P` | `P * P = P` |
| Commutative Law | `P + Q = Q + P` | `P * Q = Q * P` |
| Associative Law | `P + (Q + R) = (P + Q) + R` | `P * (Q * R) = (P * Q) * R` |
| Distributive Law | `P + (Q * R) = (P + Q) * (P + R)` | `P * (Q + R) = (P * Q) + (P * R)` |
| De Morgan's Law | `(P + Q)' = P' * Q'` | `(P * Q)' = P' + Q'` |
| Complement Law | `P + P' = 1` | `P * P' = 0` |
| Domination Law | `P + 1 = 1` | `P * 0 = 0` |
| Double Negation Law | `(P')' = P` | `(P')' = P` |
| Absorption Law | `P + (P * Q) = P` | `P * (P + Q) = P` |

---

Thanks to [GeeksforGeeks](https://www.geeksforgeeks.org/boolean-algebra/) for providing the information above.

## Method of Simplification

The method used to simplify boolean expressions in this project (currently) is the Quine-McCluskey algorithm. It is a tabular method for minimizing boolean functions and is particularly useful for functions with a large number of variables.

It takes the function's variables and minterms as input.

<pre>
Enter variables (e.g. ABC for 3 variables): <span style="color: #78b2ff;">ABCD</span>
Enter minterms (e.g. 0 1 2 5 6 7): <span style="color: #78b2ff;">0 1 3 7 8 9 10 11 13 14</span>
</pre>

and spits out the simplified expression.

```
B' * C' + B' * D + A * B'
```

**More on the way this works will be added in a later commit. For now please refer to [this article](https://en.wikipedia.org/wiki/Quine%E2%80%93McCluskey_algorithm) for more information.*


## Checklist

- [x] Research
- [x] Implement method
- [x] Optimise code (to the best of my ability)
- [ ] Write clean code
- [ ] Create release
- [ ] Maintain project
