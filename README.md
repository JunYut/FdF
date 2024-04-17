# **Prototype**

## **1. Input validation**
### 1.2 Check argument count
### 1.3 Check file validity
1.3.1 *Does file has the `.fdf` extension ?*\
1.3.2 *Does `open()` works ?*

## **2. Parsing**
### 2.1 Use `get_next_line()` to read from the `fd` returned from `validation()`
### 2.2 Use `ft_split()` to seperate each point's `values`
### 2.3 Store the `values` in a `linked list`

## **3. Map validation**
### 3.1 Check the if the `columns` of each line is the same
### 3.2 Validate the `value`'s formatting
3.2.1 *Check if there are other characters other than `alphanumeric`, `-` & `,`*\
3.2.2 *Check if the `first character` of each `value` is a `numeric` or a `-`*\
3.2.3 *Check if there are more than `1` commas in each `value`*\
3.2.4 *If there is only `1` comma, check if there is only `numeric` before it*\
3.2.5 *Then, check if the next consecutive `2` characters are `0x`: `,0x`*