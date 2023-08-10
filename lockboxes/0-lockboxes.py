#!/usr/bin/python3

"""
This Method determine if all boxes can be unlocked.
"""


def canUnlockAll(boxes):
    # Get the total number of boxes in the scenario
    total_boxes = len(boxes)

    # Create a set to keep track of visited boxes; start with the first box
    visited = {0}

    # Initialize with the initial keys available from the first box
    keys_to_check = boxes[0]

    while keys_to_check:
        # Take a key from the list of keys to check
        key = keys_to_check.pop()

        if key < total_boxes and key not in visited:
            # Mark the box as visited
            visited.add(key)

            # Add the keys from the unlocked box to the list
            keys_to_check.extend(boxes[key])

    # Check if all boxes were visited
    return len(visited) == total_boxes
