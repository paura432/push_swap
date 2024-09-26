# push_swap

**push_swap** is a sorting algorithm project designed to efficiently sort a stack of integers using two stacks and a set of predefined operations. The goal is to sort the numbers using the fewest possible moves, adhering to specific rules and constraints.

## Overview

- **Objective**: Sort a stack of integers with the fewest possible operations.
- **Data Structures**: The project uses two stacks (usually named `a` and `b`).
- **Operations**: A set of predefined commands is used to manipulate the stacks.

## Operations

Here are the main operations available to manipulate the stacks:

- **`sa`**: Swap the first two elements of stack `a`.
- **`sb`**: Swap the first two elements of stack `b`.
- **`ss`**: Perform `sa` and `sb` simultaneously.
- **`pa`**: Push the top element from stack `b` onto stack `a`.
- **`pb`**: Push the top element from stack `a` onto stack `b`.
- **`ra`**: Rotate stack `a` upwards (the first element becomes the last).
- **`rb`**: Rotate stack `b` upwards.
- **`rr`**: Perform `ra` and `rb` simultaneously.
- **`rra`**: Reverse rotate stack `a` (the last element becomes the first).
- **`rrb`**: Reverse rotate stack `b`.
- **`rrr`**: Perform `rra` and `rrb` simultaneously.

## Algorithm

The sorting algorithm needs to be implemented using these operations. The challenge lies in designing an efficient strategy to sort the numbers in as few moves as possible. Some common techniques include:

- **Simple Sort**: Directly sorting small sets of numbers (e.g., 3 or 5 integers).
- **Radix Sort**: Often used for larger sets of numbers (up to 100 or 500 integers).

## Algorithm Used: Stack Sorting

In this project, the **push_swap** sorting algorithm utilizes stack-based operations to efficiently sort a stack of integers. The approach leverages two stacks and a set of predefined operations to achieve the sorting goal.

### How It Works

1. **Two Stack Approach**: The algorithm operates using two stacks, typically referred to as `a` and `b`. Stack `a` is used as the main stack to sort, while stack `b` serves as an auxiliary stack to assist with sorting operations.

2. **Operations**: The algorithm uses a series of operations to manipulate the stacks. These operations include:
   - **Swap** operations (`sa`, `sb`) to interchange the top elements of the stacks.
   - **Push** operations (`pa`, `pb`) to transfer elements between the stacks.
   - **Rotate** operations (`ra`, `rb`) to shift elements within a stack.
   - **Reverse Rotate** operations (`rra`, `rrb`) to shift elements backward.

3. **Sorting Strategy**: The sorting strategy involves:
   - **Sorting Small Stacks**: For small sets of numbers (e.g., 3 to 5 integers), simple sorting techniques are applied directly on stack `a`.
   - **Partitioning and Sorting**: For larger sets of numbers, the algorithm may involve partitioning the numbers into smaller groups, sorting these groups, and then merging them efficiently.
   - **Minimizing Operations**: The goal is to sort the stack with the minimum number of operations. This requires optimizing the sequence of operations to reduce redundancy and improve efficiency.

4. **Algorithm Efficiency**: The efficiency of the algorithm is crucial, especially for larger stacks. The implemented algorithm aims to minimize the number of moves required to sort the stack, making it suitable for stacks of varying sizes.

### Benefits of Using Stack-Based Algorithm

- **Memory Efficiency**: Using stacks allows for efficient memory management and manipulation of data with minimal overhead.
- **Logical Operations**: Stack operations provide a clear and logical approach to sorting, making it easier to track and implement sorting strategies.
- **Flexibility**: The algorithm can be adapted and optimized based on the size of the input stack, allowing for efficient sorting across different scenarios.

By leveraging these stack-based operations, the **push_swap** project demonstrates an effective method for sorting integers while adhering to constraints and optimizing performance.

## Constraints

- You can only use the operations described above to manipulate the stacks.
- The goal is to use the fewest number of operations to sort the stack.
- You are evaluated based on the number of moves performed and the efficiency of your algorithm.

## Example Usage

```bash
./push_swap 4 67 3 87 23
```
The above command sorts the numbers `4 67 3 87 23` by outputting the series of operations needed to sort the stack.

### Example Output

```bash
pb
pb
sa
ra
pa
pa
```
This sequence of commands will sort the given input using the operations described.

