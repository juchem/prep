# Coding Exercises

For items containing a `[ref]` link, a reference implementation is available. Just follow the provided link to check it out.

**NOTE:** I strongly recommend you trying your own solution before peeking at the ones provided.

  0. [[ref]](3-count_words) Find the number of words in a string
  0. [[ref]](4-binary_tree_reverse) Reverse a binary tree (left-right)
  0. [[ref]](5-most_overlapped_point) Given a list of intervals [begin,,i,,, end,,i,,], find a point which overlaps the most intervals
  0. [[ref]](6-set_intersection) Given a group of sets, find the intersection between them without using a hash-table
  0. [[ref]](7-binary_tree_depth) Calculate the depth of a binary tree (for practical reasons, assume a tree with a single element has depth = 1).
  0. [[ref]](8-is_binary_tree_balanced) Tell if a binary tree is balanced
  0. [[ref]](9-reverse_linked_list) Reverse a linked list
    0. iteratively
    0. recursively
  0. Given a tree, set the value of each node with the cumulative size of the sub-tree rooted at that node.
  0. [[ref]](11-binary_division) Implement division without using the division operator
  0. [[ref]](12-lru_cache) Implement a LRU (Least Recently Used) cache with limited size and fast look-up
  0. [[ref]](13-element-uniqueness) Determine element uniqueness in an array (find one element that appears more than once)
  0. [[ref]](14-shuffle) Shuffle an array with equal probability of generating any of the possible permutations
  0. Efficiently sort a linked list
  0. [[ref]](16-k_modes) Find the _k_ most frequent elements
    * in an array
    * in a stream
  0. [[ref]](17-find_bst_kth_element) Find _k-th_ largest element in a BST
  0. [[ref]](18-square_root) Implement the square root mathematical function: double sqrt(double n)
  0. Write a function that given a list of items and weights return a random item in the list with probability relative to the weights
  0. Given a sorted list of intervals, how do you tell if at least two overlap?
  0. Parse a string into a binary tree. E.g.:
    * Input: `A(B(D, E), C(,F))`
    * Output: the memory representation of the tree

      ```
            A
           / \
          /   \
         B     C
        / \     \
       /   \     \
      D     E     F
      ```

  0. Area under the curve approximation (Left and Right Riemann sum)
  0. Zig-zag print a tree. E.g.:
    * Input:

      ```
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
      ```

    * Output: `A, C, B, D, E, F, J, I, H, G, K, L, M, N, O, P, Q, R`
  0. Having no pointer to the parent and given only the left and right pointers, correctly set the sibling pointer of a binary tree (a given node should point to the next node on its right, in the same level - they don't need to have the same parent)

    ```c++
    struct tree_node {
      tree_node *left,
      tree_node *right,
      tree_node *sibling
    }
    ```

  0. Spiral print a 2D array
    0. From the center to the edges
    0. From the edges to the center
  0. Find all possible letter combinations out of a phone number
    * Optimize for validation over a dictionary
  0. [[ref]](27-string_permutations) Find all permutations of a string
    * You can output to stdout
  0. Find the closest predecessor of a node in a binary tree by doing an in-order traversal
  0. Check a file for unbalanced curly braces
    0. When there are no quoted strings
    0. Consider that quoted strings (between `"`) may contain curly braces
  0. [[ref]](30-parenthesis_combinations) Generate all balanced parenthesis combinations for a given amount of parenthesis pairs. For each combination, determine the maximum nesting depth.
    * for 3 pairs:

      ```
      ()()(), max depth = 1
      ()(()), max depth = 2
      (())(), max depth = 2
      (()()), max depth = 2
      ((())), max depth = 3
      ```

  0. [[ref]](31-is_bianry_tree_symmetric) Find out if a binary tree is symmetric.
    * Symmetric:

      ```
      [A [B, C]]
      ```

    * Not symmetric:

      ```
      [A [B [D], C]]
      ```

  0. [[ref]](32-pick_random_element) Pick an element in a list with uniform probability, without knowledge of the list size
  0. Pick a sample of k elements in a list with uniform probability, without knowledge of the list size
  0. Design a data structure to efficiently find all anagrams of a given string
  0. Find the median of two sorted arrays
    0. In linear time
    0. In sub-linear time
  0. Given two binary trees, A and B, implement a function to check if both are equal (structure and value-wise). You don't have a pointer to the parent on the nodes.
  0. Given two binary trees, A and B, implement a function to check if B is a sub-tree of A (structure and value-wise). You don't have a pointer to the parent on the nodes.
  0. What’s the size in bytes of a `struct { char a; int b; }` in the C programming language?
  0. Implement the power function int power(int base, int exponent)
  0. How would you implement the data structure for the code completion feature on an IDE?
  0. Given a stream of items where one element appears an odd number of times, and every other appears an even number of times, how would you find the former?
    0. When it’s a stream of integers
    0. When it’s a stream of any data type like, say, a string
  0. Describe the data structure you would use to implement a scheduler of processes. You must be able to quickly get the top priority process, and to look up for a specific process id
  0. Describe how would you implement reference counting
  0. Describe how would you implement copy on write
  0. How would you implement the trace route tool if the default ping messages are not allowed?
  0. How would you implement a function bool isMemoryWritable(void `*`p, size_t n) that checks if the current process could write N bytes to the given memory address? Assume you can catch any kind of error
  0. Describe the data structures for a jig-saw puzzle
    * Given a function that tells if two pieces fit together, design an algorithm for solving the puzzle
  0. [[ref]](48-2sum_3sum) Given an array of integers and a target value, find:
    0. Two numbers that sum to that value
    0. Three numbers that sum to that value
  0. Print a n-ary tree level by level
  0. Count the bits in an integer
  0. Find the 0-based position of the most significant bit in an integer (base two logarithm of a number, rounded down)
  0. Given a contiguous block of memory, design a data structure to ensure that no two writes will be made to the same byte, provided that data can be written in blocks
  0. Implement a data structure to keep track of non-overlapping intervals
  0. Implement a data structure to keep track of overlapping intervals
  0. Given that you have the following functionality in a library

    ```c++
    struct writer {
      // rest of class omitted
      void serialize_byte(char b);
    };

    struct reader {
      // rest of class omitted
      char deserialize_byte();
    };
    ```

    0. Implement

      ```c++
      void serialize_integer(writer &w, int n);
      int deserialize_integer(reader &r);
      ```

    0. Implement

      ```c++
      void serialize_string(writer &w, std::string const &s);
      std::string deserialize_string(reader &r);
      ```
  0. Implement serialization and deserialization of a binary tree (the structure must be kept)
  0. Implement an algorithm to tell if a given string is a palindrome.
    * what if the string is comprised of multi-byte characters?
  0. What will happen at runtime when the following C expression gets evaluated? `"a"[1]`

  0. Suppose you have an array of N items, where one item is repeated N/2 times, and the other N/2 items are unique. How do you find the former in a sub-quadratic time? What about linear time?
  0. Implement a queue with stacks
    0. In quadratic time
    0. In linear time
  0. Implement a ring buffer
  0. Implement GLOB (path wild card matching)
    * `*` matches anything
    * `?` matches exactly one character
    * for instance: pattern=foo`*`, string=foo.txt, should return true
    * for instance: pattern=foo`*`.txt, string=foo.txt.txt, should return true
  0. [[ref]](62-partition_uniques_duplicates) Given a sorted array with some duplicate elements, move the additional duplicates to to the end of the array. The unique elements of the output array should be on the left and sorted, the duplicates should be on the right in any order (the elements between curly braces in the example below):
    * Example: input=`1,2,2,2,3,3,4,5,5` output=`1,2,3,4,5,{2,2,3,5}`
    * Example: input=`1,2,2,3,4` output=`1,2,3,4,{2}`
  0. Implement text justification: given an input string, split it in multiple lines and insert spaces evenly between the words so that the line takes exactly the given width
    * You can output to stdout
    * The call `justify(“this is just a sample”, 8)` should output (dots representing white spaces):

      ```
      "this..is"
      "just...a"
      "sample"
      ```

  0. Implement a function that tells if a given string represents a valid int or float
  0. [[ref]](65-three_points_form_triangle) Tell if three points form a triangle
  0. [[ref]](66-deep_iterator) Implement a deep iterator over a list of nested lists having any depth.
    * Example:

      ```
      list1 = 1, 2, 3, list2, 9, list3
      list2 = A, B, list4, 4
      list3 = 0, 7, H
      list4 = d, v
      ```

    * Iterating over list1 yields `1, 2, 3, A, B, d, v, 4, 9, 0, 7, H`
  0. [[ref]](67-list_cycle) How do you detect a cycle in a linked list? How do you break it?
  0. Imagine you have two linked lists, and at some point they merge like in a Y shape. How do you detect at which node the merge occured?

    ```
    A -> B -> C \
                  -> D -> E
         F -> G /
    ```

  0. [[ref]](69-print_binary_tree) Suppose you must debug a program which handles binary trees, but the only tool you have at your disposal is a logging routine that outputs text to a file. Write a function that prints a binary tree using only printable characters in a way that makes it easy to visualize its structure. Assume the nodes' values are also printable (for the purpose of the exercise you can assume the node's value is a single character).
  0. Suppose there's a list of software packages to be installed on a given system. Suppose also that some packages may depend on others. In order for a package to be installed, its dependencies must have already been installed. Suppose also that there won't be any issues other than missing dependencies preventing a given package from being successfully installed.
    * Write an algorithm that sorts those packages so that all of them can be successfully installed.
    * Can you think of another situation that could prevent the installation, other than the ones mentioned above?
  0. [[ref]](1-flood_fill) Implement flood fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the _X_ (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):

    ```
    111111111     111111111
    111111111     111111111
    110000011     112222211
    1100x0011 ==> 112222211
    110000011     112222211
    111111111     111111111
    111111111     111111111
    ```

  0. [[ref]](2-edge_fill) Implement edge fill (four-way): suppose each number represents a color, suppose the currently selected color is 2 (the color that will be painted), and suppose you click on the _X_ (whose value is also 0) on the picture on the left. Your algorithm should end up with the picture on the right (as a follow up, do it in N dimensions):

    ```
    111111111     111111111
    111111111     112222211
    110000011     120000021
    1100x0011 ==> 120000021
    110000011     120000021
    111111111     112222211
    111111111     111111111
    ```

  0. [[ref]](71-cross_fill_zeroes) Given a bi-dimensional matrix of _1s_ and _0s_, write a function that, for every _0_ in the matrix, fills the whole row and column with _0s_.

    ```
    111111111     111101101
    111111101     000000000
    111111111     111101101
    111101111 ==> 000000000
    111111111     111101101
    111111111     111101101
    111111111     111101101
    ```

  0. [[ref]](72-coin_probabilities) Given a list of probabilities for _N_ coins to come up with heads, list all possible outcomes and the probability for each one
  0. [[ref]](73-string_combinations) Find all _k_-sized subsets (without replacement) of a string (where _k_ <= string size)
    * You can output to stdout
  0. [[ref]](74-find_graph_components) Given a bi-dimensional matrix, find the number of different groups of values. A group is made of equal-valued elements adjacent to each other. Adjacency is four-way (up, down, left, right).
    * Example with 9 groups (3 groups of _0s_, 2 group of _1s_, 3 groups of _2s_ and 1 group of _3s_):

      ```
      111101111
      122111101
      121211111
      111101111
      111101333
      111111333
      111111221
      ```

  0. Given a BST of _n_ integers and a target integer _v_, find the node that is the closest to _v_ (closest means diff(_v_, node.value) is minimum)
  0. Given a sequence of positive integers, find the sub-sequence of non-adjacent elements having the maximum sum.
    * Example: For the sequence `(10, 11, 15, 20, 80, 90)`, the answer is `(11, 20, 90)`
  0. [[ref]](77-array_shift) Given a sorted array with _n_ elements which has been shifted by _k_ positions, where _k < n_, find _k_. Examples:

    ```
    {1, 2, 3, 4, 5} - k = 0
    {3, 4, 5, 1, 2} - k = 3
    {1, 1, 1, 1, 1} - k = 0
    {1, 1, 1, 2, 1} - k = 4
    ```

  0. [[ref]](78-find_buggy_revision) Suppose you get an email automatically sent by your building system saying that the latest build is broken. This build includes all changes up to revision _C_ of your code repository. The previous build was fine and contained changes up to revision _A_. Write code to find what's the exact revision _B_ responsible for breaking the build.
    * Assume you know _A_ and _C_
    * There may be one or more revisions between _A_ and _C_
    * Assume that all revisions are fine prior to _B_, and all revisions after this point are broken
    * You have a function _bool build(int revision)_ that builds that revision and tells you if something went wrong
  0. Implement a function that, given the _radius_ and central _(x, y)_ point, draws a circle on the screen. Assume that you can only touch the screen with a function _drawPixel(x,y)_.
  0. [[ref]](80-reverse_print_list) Print the elements of a linked list in reverse order
    0. you can modify the input
    0. you can't modify the input and speed must be linear
    0. you can't modify the input, speed must be linear and the input may be big
    0. you can't modify the input and memory is scarce
    0. you can't modify the input, memory usage must be sub-linear and speed must be sub-quadratic
  0. Implement quicksort
    0. Implement median-of-3 pivot choosing algorithm
    0. Make quicksort O(lg n) space as opposed to the original O(n)
    0. Tweak quicksort to make it O(n lg n) time as opposed to the original O(n^2)
    0. Turn your quicksort implementation into introsort
  0. Implement deep copy of a graph data structure
  0. Implement binary search on a comma-separated values (CSV) file. The records in the file have a variable size.
