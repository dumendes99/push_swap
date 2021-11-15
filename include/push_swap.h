/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:17:46 by elima-me          #+#    #+#             */
/*   Updated: 2021/11/14 17:47:27 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"
# define SIZE_ERROR 4
# define MAX_INT 2147483647

enum e_prints {
	sa,
	sb,
	ra,
	rb,
	rra,
	rrb
};

enum e_errors {
	ERR_FEW_PARAMETERS,
	ERR_INVALID_INPUT,
	ERROR,
	ERR_NOT_IS_DIGIT,
};

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *temp;
	int		size_a;
	int		size_b;
	int 	group_size;
	int		groups;
	int		rest;
}	t_info;

void	print_stack(t_stack **stack);

/**
 * @brief freed all pointers 
 * 
 * @param s 
 */
void	freeall(char **s);

/**
 * @brief freeded at all stack 
 * 
 * @param stack stack to be free
 */
void	freelist(t_stack *stack);

/**
 * @brief check if arguments gived are all digits 
 * 
 * @param argv arguments 
 * @return int 1 to ok, 0 to error 
 */
int		check_isdigit(char *argv[]);

/**
 * @brief check the amount of inputs 
 * 
 * @param argc 
 * @return int 
 */
int		minimal_args(int argc);

/**
 * @brief function that call all others checkers function 
 * 
 * @param argc amount of arguments 
 * @param argv arguments 
 * @param swap strcut that I'll fill in the numbers  
 * @return int 
 */
int		handler_inputs(int argc, char *argv[], t_info *info);

/**
 * @brief create new node of linked list and add the int value 
 * 
 * @param num value 
 * @return t_stack* 
 */
t_stack	*new_node(long int num);

/**
 * @brief checks if the number passed as parameter already exists 
 * 
 * @param **stack 
 * @param num the num to be added
 * @return int 0 to errorr, 1 to ok 
 */
int		check_double(t_stack **stack, long long int num);

/**
 * @brief added a struct as last element
 * 
 * @param lst the pointer of pointer of a list
 * @param new the new node to be added
 */
void	ps_lstadd_back(t_stack **lst, t_stack *new);

/**
 * @brief print each type error gived
 * 
 * @param error enum describe the error
 * @return int 
 */
int		print_error(int error);

/**
 * @brief swap the first 2 elements of stack passed as parameter
 * 
 * @param stack stack to be swaped   
 */
void	swap(t_stack **stack, int print);

void	swap_s(t_info *info);

/**
 * @brief add new node in the front of stack 
 * 
 * @param stack 
 * @param new new node 
 */
void	ps_lstadd_front(t_stack **stack, t_stack *new);

/**
 * @brief push the first node of stack a to stack b 
 * 
 * @param stacks a pointer to struct that contains the two stacks
 */
void	push_b(t_info *info);

/**
 * @brief push te first node of stack b to stack a 
 * 
 * @param stacks a pointer to struct that contains the two stacks
 */
void	push_a(t_info *info);

/**
 * @brief shift up all elements of stack. The first becomes the last one. 
 * 
 * @param stack 
 */
void	rotate(t_stack **stack, int print);

/**
 * @brief shift up both stacks 
 * 
 * @param stacks 
 */
void	rotate_r(t_info *stacks);

/**
 * @brief shift down all elements of stack. The last becomes the first one. 
 * 
 * @param stack 
 */
void	reverse_rotate(t_stack **stack, int print);
void	reverse_rotate_r(t_info *info);

/**
 * @brief delete a node that was passed as parameter
 * 
 * @param stack node 
 */
void	del_first_node(t_stack **stack);

/**
 * @brief delete the last node of list 
 * 
 * @param stack 
 */
void	del_last(t_stack **stack);

/**
 * @brief advances to the last node of the list
 * 
 * @param lst 
 * @return t_stack* 
 */
t_stack	*ps_lstlast(t_stack *lst);

/**
 * @brief depends of amount elements to be sorted choose the step sequences
 * 
 * @param info 
 */
void	short_sort(t_info *info);

/**
 * @brief function to sort random numbers above 5 elements
 * 
 * @param info 
 */
void	big_sort(t_info *info);

/**
 * @brief send a samallest number to stack b 
 * 
 * @param info 
 * @return void* 
 */
void	send_smallest(t_info *info);

/**
 * @brief algorithm for to organize untill 5 random numbers in order smallest to bigger
 * 
 * @param info struct with the 2 stacks
 */
void	five_elements(t_info *info);

/**
 * @brief check what is the better moviment between rotate or reverse rotate
 * 
 * @param info struct with stacks and info about them. 
 * @param position where the number was find
 * @return 1 to reverse rotate or 2 to rotate
 */
int		rotate_or_reverse(int size, int position);

/**
 * @brief converts the values ​​to the given input range
 * 
 * @param info 
 */
void	normalize(t_info *info);

/**
 * @brief verify witch one is the better approach to small sorts
 * 
 * @param stack 
 * @return int 
 */
int	find_algo(t_stack **stack);

/**
 * @brief send smallest element to stack_b 
 * 
 * @param info 
 */
void	send_smallest(t_info *info);


#endif
