1. Do not implement any code this week!
2. Based on what we know about linked lists, stacks, and queues, design a queue data structure:

    1. What functions are we likely to need for a queue to function like the one discussed in class?

        - An array to store internal stack values
        - a way of pushing onto a stack (enqueue())
        - a way to pop off stack (dequeue())
        - possibly have a way to peek at the top of the stack
        - Optional helper: is empty
        - Optional Helper: is full
        - error handling

    2. What values will we need to know about the structure for our queue to function properly?

        - Needs to track the front of the queue
        - New value we're pushing
        - The array we're messing with
            - storage size
            - current size

3. Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):

    1. What functions are we likely to need for a list to function like this?

        - A way to create a collection of nodes that will become the linked list
            - A struct for data
        - A way to insert at a specific postion (insert(value,position))
        - A way to delete from a specific postion (delete(position))
        - a way to traverse through the list


    2. What values will we need to know about the structure for our list to function properly?

        - Number of nodes in the list
        - the "head" : A pointer to the first node in the list 


4. Commit changes to your design into your git repo frequently while designing (in an obvious assignment 2 folder or repo),
(Also remember to double check that I am a collaborator on your project or the git repo is otherwise accessible by the instructor)

5. Submit a link to your git repo to Moodle to remind us to grade it.