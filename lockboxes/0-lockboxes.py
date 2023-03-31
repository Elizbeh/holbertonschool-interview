#!/usr/bin/python3

"""A method that determines 
if all the boxes can be opened.
"""
def canUnlockAll(boxes):
  # Boxes to be opened
    boxes_opened = {0}
    # Boxes  that needs to be opend
    next_to_open = [0]
    #Interattion until all boxes  have been opened
    while len(next_to_open) > 0:
        box = next_to_open.pop(0)
        #Loop over the keys in the current box
        for key in boxes[box]:
          # Add newly open box to the queue
          if key not in boxes_opened and key < len(boxes):
                next_to_open.append(key)
                boxes_opened.add(key)
    
    # Return True, else return False if all boxes has been opened
    return len(boxes_opened) == len(boxes)