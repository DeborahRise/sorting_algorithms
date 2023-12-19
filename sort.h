#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/**
 * enum bool - struct for bool type
 *@false: false is equivalent to 0
 *@true: equivalent to 1
 *Return: nothing
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * enum kind_e - Doubly linked list node
 * @SPADE: Integer stored in the node
 * @HEART: Pointer to the previous element of the list
 * @CLUB: Pointer to the next element of the list
 * @DIAMOND: another card shape
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;


/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* FOLLOW COME FUNCTIONS*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Helper Functions*/
void element_swap(int *a, int *b);
void swap_list(listint_t **head, listint_t **node1, listint_t *node2);
int partition(int *array, int start, int end, size_t size);
void quicky(int *array, int start, int end, size_t size);
void helper_heap(int *array, int sub_array, int super_node, size_t size);
void partition_sort_hoare(int *array, size_t size, int low, int high);
int partition_hoare(int *array, size_t size, int low, int high);

/* PROJECT FUNCTIONS*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);

#endif
