# **Pseudocode**
1. Parse `.fdf` file
2. Initialize datas
3. \*MinilibX magic\*
4. Profit ???

# **Prototype**

## **1. Input validation**
### 1.2 Check argument count
### 1.3 Check file validity
1.3.1 *Does file has the `.fdf` extension ?*\
1.3.2 *Does `open()` works ?*

## **2. Parsing**
### 2.1 Use `get_next_line()` to read from the `fd` returned from `validation()`
### 2.2 Use `ft_split()` to seperate each point's `altitude` and `color`
### 2.3 Store the `altitude` and the `color` in a `linked list`

## **3. Map validation**
### 3.1 Check the if the `columns` of each line is the same

## **4. **