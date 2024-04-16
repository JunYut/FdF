# Prototype

## 1. Input validation
### 1.2 Check argument count
### 1.3 Check file validity
1.3.1 Does file has the `.fdf` extension ?\
1.3.2 Does `open()` works ?

## 2. Parsing
### 2.1 Use `get_next_line()` to read from the `fd` returned from `validation()`
### 2.2 Use `ft_split()` to seperate each coordinate's values
### 2.3 Convert and store the values in a 2D int array