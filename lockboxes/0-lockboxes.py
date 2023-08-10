#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    Determine if all boxes can be unlocked.
    Given a list of boxes where each box contains
    keys to other boxes, this function checks
    whether it is possible to unlock all boxes
    starting from the first one.
    :param boxes: A list of lists, where each sublist
                  represents a box and contains the indices
                  of other boxes that it can unlock.
    :return: True if all boxes can be unlocked, False otherwise.
    """
    total_boxes = len(boxes)
    visited = {0}
    keys_to_check = boxes[0]

    while keys_to_check:
        key = keys_to_check.pop()

        if key not in visited:
            visited.add(key)

            keys_to_check.extend(boxes[key])
    return len(visited) == total_boxes
