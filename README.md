# push_swap

The Push_swap project is a highly effective algorithm project: data will need to be sorted. 
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

#### Instructions
* `sa (swap a)` — swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* `sb (swap b)` — swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* `ss` — sa and sb at the same time.
* `pa (push a)` — take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* `pb (push b)` — take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* `ra (rotate a)` — shift up all elements of stack a by 1. The first element becomes the last one.
* `rb (rotate b)` — shift up all elements of stack b by 1. The first element becomes the last one.
* `rr` — ra and rb at the same time.
* `rra (reverse rotate a)` — shift down all elements of stack a by 1. The last element becomes the first one.
* `rrb (reverse rotate b)` — shift down all elements of stack b by 1. The last element becomes the first one.
* `rrr` — rra and rrb at the same time.

### How to install 
```
git clone https://github.com/kagestonedragon/push_swap.git ~/push_swap
```

2) Compile
```
make -C ~/push_swap
```
### How to use

```
ARG = "..."
./push_swap $ARG
```
* push swap takes a sequence of numbers (no repetitions)
* `-v` — sorting visualization

You also have a checker that checks the correctness of sorting:
```
ARG = "..."
./push_swap $ARG | ./checker $ARG
```
* `-v` — will show the state of the stack after each operation
* `-v` — will show the number of operations