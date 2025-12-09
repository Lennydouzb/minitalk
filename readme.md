_This project has been created as part of the 42 curriculum by ldesboui._

# Description

Minitalk aim at creating a communication between a client and a server using UNIX signals

# Instructions

To compile the project :

```make
make
```
To use the program :

Launch the server first
```bash
./server
```
# Technical choice

This push_swap uses turk algorithm, see more in [resource section](#rescources)

# Resources

A nice page to learn more about turk algorithm: https://medium.com/@ayogun/push-swap-c1f5d2d41e97

AI was used in this project for a better understanding of the Turk algorithm, such as visual examples
and basic explanation.

# Understand the return

The instrucitons are :

sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one element or none.

sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one element or none.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.

rrr : rra and rrb at the same time
