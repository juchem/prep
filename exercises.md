#summary List of coding exercises

= Coding Exercises =

For items containing a `[`ref`]` link, a reference implementation is available. Just follow the provided link to check it out.

*NOTE:* I strongly recommend you trying your own solution before peeking at the ones provided.

  # [https://github.com/juchem/prep/blob/master/1-flood_fill [ref]] Implement flood fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the _X_ (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):
{{{
111111111     111111111
111111111     111111111
110000011     112222211
1100x0011    ==>    112222211
110000011     112222211
111111111     111111111
111111111     111111111
}}}
  # [https://github.com/juchem/prep/blob/master/2-edge_fill [ref]] Implement edge fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the _X_ (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):
{{{
111111111     111111111
111111111     112222211
110000011     120000021
1100x0011    ==>    120000021
110000011     120000021
111111111     112222211
111111111     111111111
}}}
  # [https://github.com/juchem/prep/blob/master/3-count_words [ref]] Find the number of words in a string
  # [https://github.com/juchem/prep/blob/master/4-binary_tree_reverse [ref]] Reverse a binary tree (left-right)
  # [https://github.com/juchem/prep/blob/master/5-most_overlapped_point [ref]] Given a list of intervals [begin,,i,,, end,,i,,], find a point which overlaps the most intervals
  # [https://github.com/juchem/prep/blob/master/6-set_intersection [ref]] Given a group of sets, find the intersection between them without using a hash-table
  # [https://github.com/juchem/prep/blob/master/7-binary_tree_depth [ref]] Calculate the depth of a binary tree (for practical reasons, assume a tree with a single element has depth = 1).
  # [https://github.com/juchem/prep/blob/master/8-is_binary_tree_balanced [ref]] Tell if a binary tree is balanced
  # [https://github.com/juchem/prep/blob/master/9-reverse_linked_list [ref]] Reverse a linked list
    # iteratively
    # recursively
  # Given a tree, set the value of each node with the cumulative size of the sub-tree rooted at that node.
  # [https://github.com/juchem/prep/blob/master/11-binary_division [ref]] Implement division without using the division operator
  # [https://github.com/juchem/prep/blob/master/12-lru_cache [ref]] Implement a LRU (Least Recently Used) cache with limited size and fast look-up
  # [https://github.com/juchem/prep/blob/master/13-element-uniqueness [ref]] Determine element uniqueness in an array (find one element that appears more than once)
  # [https://github.com/juchem/prep/blob/master/14-shuffle [ref]] Shuffle an array with equal probability of generating any of the possible permutations
  # Efficiently sort a linked list
  # [https://github.com/juchem/prep/blob/master/16-k_modes [ref]] Find the _k_ most frequent elements
    * in an array
    * in a stream
  # [https://github.com/juchem/prep/blob/master/17-find_bst_kth_element [ref]] Find _k^th^_ largest element in a BST
  # [https://github.com/juchem/prep/blob/master/18-square_root [ref]] Implement the square root mathematical function: double sqrt(double n)
  # Write a function that given a list of items and weights return a random item in the list with probability relative to the weights
  # Given a sorted list of intervals, how do you tell if at least two overlap?
  # Parse a string into a binary tree. E.g.:
    * Input: A(B(D, E), C(,F))
    * Output: the memory representation of the tree
{{{
      A
     / \
    /   \
   B     C
  / \     \
 /   \     \
D     E     F
}}}
  # Area under the curve approximation (Left and Right Riemann sum)
  # Zig-zag print a tree. E.g.:
    * Input:
{{{
           A
          / \
         /   \
        B     C
       / \     \
      /   \     \
     D     E     F
    / \         / \
   /   \       /   \
  G     H     I     J
 / \   / \   / \   / \
K   L M   N O   P Q   R
}}}
    * Output: A, C, B, D, E, F, J, I, H, G, K, L, M, N, O, P, Q, R
  # Having no pointer to the parent and given only the left and right pointers, correctly set the sibling pointer of a binary tree (a given node should point to the next node on its right, in the same level - they don't need to have the same parent)
    {{{
struct tree_node {
  tree_node *left,
  tree_node *right,
  tree_node *sibling
}
}}}
  # Spiral print a 2D array
    # From the center to the edges
    # From the edges to the center
  # Find all possible letter combinations out of a phone number
    * Optimize for validation over a dictionary
  # [https://github.com/juchem/prep/blob/master/27-string_permutations [ref]] Find all permutations of a string
    * You can output to stdout
  # Find the closest predecessor of a node in a binary tree by doing an in-order traversal
  # Check a file for unbalanced curly braces
    # When there are no quoted strings
    # Consider that quoted strings (between `"`) may contain curly braces
  # [https://github.com/juchem/prep/blob/master/30-parenthesis_combinations [ref]] Generate all balanced parenthesis combinations for a given amount of parenthesis pairs. For each combination, determine the maximum nesting depth.
    * for 3 pairs:
{{{
()()(), max depth = 1
()(()), max depth = 2
(())(), max depth = 2
(()()), max depth = 2
((())), max depth = 3
}}}
  # [https://github.com/juchem/prep/blob/master/31-is_bianry_tree_symmetric [ref]] Find out if a binary tree is symmetric.
    * Symmetric:
{{{
[A [B, C]]
}}}
    * Not symmetric:
{{{
[A [B [D], C]]
}}}
  # [https://github.com/juchem/prep/blob/master/32-pick_random_element [ref]] Pick an element in a list with uniform probability, without knowledge of the list size
  # Pick a sample of k elements in a list with uniform probability, without knowledge of the list size
  # Design a data structure to efficiently find all anagrams of a given string
  # Find the median of two sorted arrays
    # In linear time
    # In sub-linear time
  # Given two binary trees, A and B, implement a function to check if both are equal (structure and value-wise). You don't have a pointer to the parent on the nodes.
  # Given two binary trees, A and B, implement a function to check if B is a sub-tree of A (structure and value-wise). You don't have a pointer to the parent on the nodes.
  # What’s the size in bytes of a C struct { char a; int b; }?
  # Implement the power function int power(int base, int exponent)
  # How would you implement the data structure for the code completion feature on an IDE?
  # Given a stream of items where one element appears an odd number of times, and every other appears an even number of times, how would you find the former?
    # When it’s a stream of integers
    # When it’s a stream of any data type like, say, a string
  # Describe the data structure you would use to implement a scheduler of processes. You must be able to quickly get the top priority process, and to look up for a specific process id
  # Describe how would you implement reference counting
  # Describe how would you implement copy on write
  # How would you implement the trace route tool if the default ping messages are not allowed?
  # How would you implement a function bool isMemoryWritable(void `*`p, size_t n) that checks if the current process could write N bytes to the given memory address? Assume you can catch any kind of error
  # Describe the data structures for a jig-saw puzzle
    * Given a function that tells if two pieces fit together, design an algorithm for solving the puzzle
  # [https://github.com/juchem/prep/blob/master/48-2sum_3sum [ref]] Given an array of integers and a target value, find:
    # Two numbers that sum to that value
    # Three numbers that sum to that value
  # Print a n-ary tree level by level
  # Count the bits in an integer
  # Find the 0-based position of the most significant bit in an integer (base two logarithm of a number, rounded down)
  # Given a contiguous block of memory, design a data structure to ensure that no two writes will be made to the same byte, provided that data can be written in blocks
  # Implement a data structure to keep track of non-overlapping intervals
  # Implement a data structure to keep track of overlapping intervals
  # Implement serialization and deserialization of a binary tree (the structure must be kept)
  # Implement an algorithm to tell if a given string is a palindrome.
    * what if the string is comprised of multi-byte characters?
  # What will happen at runtime when the following C expression gets evaluated?
    {{{
"a"[1]
}}}
  # Suppose you have an array of N items, where one item is repeated N/2 times, and the other N/2 items are unique. How do you find the former in a sub-quadratic time? What about linear time?
  # Implement a queue with stacks
    # In quadratic time
    # In linear time
  # Implement a ring buffer
  # Implement GLOB (path wild card matching)
    * `*` matches anything
    * `?` matches exactly one character
    * for instance: pattern=foo`*`, string=foo.txt, should return true
    * for instance: pattern=foo`*`.txt, string=foo.txt.txt, should return true
  # [https://github.com/juchem/prep/blob/master/62-partition_uniques_duplicates [ref]] Given a sorted array with some duplicate elements, move the additional duplicates to to the end of the array. The unique elements of the output array should be on the left and sorted, the duplicates should be on the right in any order (the elements between curly braces in the example below):
    * Example: input=1,2,2,2,3,3,4,5,5 output=1,2,3,4,5,{2,2,3,5}
    * Example: input=1,2,2,3,4 output=1,2,3,4,{2}
  # Implement text justification: given an input string, split it in multiple lines and insert spaces evenly between the words so that the line takes exactly the given width
    * You can output to stdout
    * The call justify(“this is just a sample”, 8) should output (dots representing white spaces):
{{{
"this..is"
"just...a"
"sample"
}}}
  # Implement a function that tells if a given string represents a valid int or float
  # [https://github.com/juchem/prep/blob/master/65-three_points_form_triangle [ref]] Tell if three points form a triangle
  # [https://github.com/juchem/prep/blob/master/66-deep_iterator [ref]] Implement a deep iterator over a list of nested lists having any depth.
    * Example:
{{{
list1 = 1, 2, 3, list2, 9, list3
list2 = A, B, list4, 4
list3 = 0, 7, H
list4 = d, v
}}}
    * Iterating over list1 yields 1, 2, 3, A, B, d, v, 4, 9, 0, 7, H
  # [https://github.com/juchem/prep/blob/master/67-list_cycle [ref]] How do you detect a cycle in a linked list? How do you break it?
  # Imagine you have two linked lists, and at some point they merge like in a Y shape. How do you detect at which node the merge occured?
{{{
A -> B -> C \
              -> D -> E
     F -> G /
}}}
  # [https://github.com/juchem/prep/blob/master/69-print_binary_tree [ref]] Suppose you must debug a program which handles binary trees, but the only tool you have at your disposal is a logging routine that outputs text to a file. Write a function that prints a binary tree using only printable characters in a way that makes it easy to visualize its structure. Assume the nodes' values are also printable (for the purpose of the exercise you can assume the node's value is a single character).
  # Suppose there's a list of software packages to be installed on a given system. Suppose also that some packages may depend on others. In order for a package to be installed, its dependencies must have already been installed. Suppose also that there won't be any issues other than missing dependencies preventing a given package from being successfully installed.
    * Write an algorithm that sorts those packages so that all of them can be successfully installed.
    * Can you think of another situation that could prevent the installation, other than the ones mentioned above?
  # [https://github.com/juchem/prep/blob/master/71-cross_fill_zeroes [ref]] Given a bi-dimensional matrix of _1s_ and _0s_, write a function that, for every _0_ in the matrix, fills the whole row and column with _0s_.
{{{
111111111     111101101
111111101     000000000
111111111     111101101
111101111    ==>    000000000
111111111     111101101
111111111     111101101
111111111     111101101
}}}
  # [https://github.com/juchem/prep/blob/master/72-coin_probabilities [ref]] Given a list of probabilities for _N_ coins to come up with heads, list all possible outcomes and the probability for each one
  # [https://github.com/juchem/prep/blob/master/73-string_combinations [ref]] Find all _k_-sized subsets (without replacement) of a string (where _k_ <= string size)
    * You can output to stdout
  # [https://github.com/juchem/prep/blob/master/74-find_graph_components [ref]] Given a bi-dimensional matrix, find the number of different groups of values. A group is made of equal-valued elements adjacent to each other. Adjacency is four-way (up, down, left, right).
    * Example with 9 groups (3 groups of _0s_, 2 group of _1s_, 3 groups of _2s_ and 1 group of _3s_):
{{{
111101111
122111101
121211111
111101111
111101333
111111333
111111221
}}}
  # Given a BST of _n_ integers and a target integer _v_, find the node that is the closest to _v_ (closest means diff(_v_, node.value) is minimum)
  # Given a sequence of positive integers, find the sub-sequence of non-adjacent elements having the maximum sum.
    * Example: For the sequence {10, 11, 15, 20, 80, 90}, the answer is {11, 20, 90}
  # [https://github.com/juchem/prep/blob/master/77-array_shift [ref]] Given a sorted array with _n_ elements which has been shifted by _k_ positions, where _k < n_, find _k_. Examples:
{{{
{1, 2, 3, 4, 5} - k = 0
{3, 4, 5, 1, 2} - k = 3
{1, 1, 1, 1, 1} - k = 0
{1, 1, 1, 2, 1} - k = 4
}}}
  # [https://github.com/juchem/prep/blob/master/78-find_buggy_revision [ref]] Suppose you get an email automatically sent by your building system saying that the latest build is broken. This build includes all changes up to revision _C_ of your code repository. The previous build was fine and contained changes up to revision _A_. Write code to find what's the exact revision _B_ responsible for breaking the build.
    * Assume you know _A_ and _C_
    * There may be one or more revisions between _A_ and _C_
    * Assume that all revisions are fine prior to _B_, and all revisions after this point are broken
    * You have a function _bool build(int revision)_ that builds that revision and tells you if something went wrong
  # Implement a function that, given the _radius_ and central _(x, y)_ point, draws a circle on the screen. Assume that you can only touch the screen with a function _drawPixel(x,y)_.
  # [https://github.com/juchem/prep/blob/master/80-reverse_print_list [ref]] Print the elements of a linked list in reverse order
    # you can modify the input
    # you can't modify the input and speed must be linear
    # you can't modify the input, speed must be linear and the input may be big
    # you can't modify the input and memory is scarce
    # you can't modify the input, memory usage must be sub-linear and speed must not be quadratic
  # Implement quicksort
    # Implement median-of-3 pivot choosing algorithm
    # Make quicksort O(lg n) space as opposed to the original O(n)
    # Tweak quicksort to make it O(n lg n) time as opposet to the original (O^2^)
    # Turn your quicksort implementation into introsort
  # Implement deep copy of a graph data structure
  # Implement binary search on a comma-separated values (CSV) file. The records in the file have a variable size.
